#include <EEPromProgressStoreStrategy.h>
#include <FourDigitDisplay.h>
#include <GeographicLock.h>
#include <GeographicLockState.h>
#include <Latch.h>
#include <LedProgressIndicatorsStrategy.h>
#include <Menu.h>
#include <MenuOption.h>
#include <PhysicalPushButtonStrategy.h>
#include <ProgressIndicators.h>
#include <ProgressStore.h>
#include <PushButton.h>
#include <UBloxGpsCurrentLocationStrategy.h>
#include <Zone.h>

const int LOCKBOX_MODE = 0;
const int MENU_MODE = 1;
int current_mode;

GeographicLock* lockbox;
FourDigitDisplay* display;
Latch* latch;
PushButton* button;
Menu* menu;
ProgressIndicators* progress_indicators;
ProgressStore* progress_store;

void enter_lockbox_mode() {
  current_mode = LOCKBOX_MODE;
  update_lockbox_state();
}

void enter_menu_mode() {
  current_mode = MENU_MODE;
  display_current_menu_option();
}

void open_latch() {
  latch->open();
}

void close_latch() {
  latch->close();
}

void set_number_of_zones_visited_to_0() {
  set_number_of_zones_visited_to(0);
}

void set_number_of_zones_visited_to(int number_of_zones_visited) {
  lockbox->set_number_of_zones_visited(number_of_zones_visited);
  set_progress(number_of_zones_visited);
}

void set_number_of_zones_visited_to_1() {
  set_number_of_zones_visited_to(1);
}

void set_number_of_zones_visited_to_2() {
  set_number_of_zones_visited_to(2);
}

void set_number_of_zones_visited_to_3() {
  set_number_of_zones_visited_to(3);
}

void set_number_of_zones_visited_to_4() {
  set_number_of_zones_visited_to(4);
}

const int NUMBER_OF_ZONES = 4;
const int PROGRESS_INDICATOR_PINS[NUMBER_OF_ZONES] = { 3, 2, 6, 5 };
const int PUSH_BUTTON_MOMENTARY_SWITCH_PIN = 8;
const int PUSH_BUTTON_LED_PIN = 7;
const int LATCH_SERVO_PIN = 9;
const int FOUR_DIGIT_DISPLAY_I2C_ADDRESS = 0x71;
const int LATCH_ANGLE_FOR_OPENED = 20;
const int LATCH_ANGLE_FOR_CLOSED = 130;
const int MINIMUM_MILLISECONDS_FOR_LONG_BUTTON_PRESS = 2000;
const int PROGRESS_STORE_EEPROM_ADDRESS = 0;

Zone zones[NUMBER_OF_ZONES] = {
    Zone(42.359285, -71.068276, 0.020),
    Zone(42.354963, -71.091383, 0.030),
    Zone(42.369772, -71.112643, 0.020),
    Zone(42.353042, -71.109666, 0.030)
};
const int NUMBER_OF_MENU_OPTIONS = 8;
MenuOption menu_options[NUMBER_OF_MENU_OPTIONS] = {
    // Menu options are initialized with byte values that 
    // represent how the option is displayed on the four-digit
    // seven segment display.
    MenuOption(
        (uint8_t[4]) { 'E', 0b01110110, 0b00110000, 0b01111000 },
        enter_lockbox_mode
    ),
    MenuOption(
        (uint8_t[4]) { 'O', 0b01110011, 0b01111001, 0b00110111 },
        open_latch
    ),
    MenuOption(
        (uint8_t[4]) { 'C', 0b01110110, 0b00111110, 0b01111000 },
        close_latch
    ),
    MenuOption(
        (uint8_t[4]) { '0', 0b01111001, 0b01111000, 0b00111111 },
        set_number_of_zones_visited_to_0
    ),
    MenuOption(
        (uint8_t[4]) { '1', 0b01111001, 0b01111000, 0b00000110 },
        set_number_of_zones_visited_to_1
    ),
    MenuOption(
        (uint8_t[4]) { '2', 0b01111001, 0b01111000, 0b01011011 },
        set_number_of_zones_visited_to_2
    ),
    MenuOption(
        (uint8_t[4]) { '3', 0b01111001, 0b01111000, 0b01001111 },
        set_number_of_zones_visited_to_3
    ),
    MenuOption(
        (uint8_t[4]) { '4', 0b01111001, 0b01111000, 0b01100110 },
        set_number_of_zones_visited_to_4
    )
};

void setup() {
  UBloxGpsCurrentLocationStrategy* current_location_strategy = new UBloxGpsCurrentLocationStrategy();
  lockbox = new GeographicLock(current_location_strategy);
  lockbox->set_zones(zones, NUMBER_OF_ZONES);

  EEPromProgressStoreStrategy* progress_store_strategy = new EEPromProgressStoreStrategy(
    PROGRESS_STORE_EEPROM_ADDRESS,
    NUMBER_OF_ZONES
  );
  progress_store = new ProgressStore(progress_store_strategy);
  lockbox->set_number_of_zones_visited(progress_store->get_number_of_zones_visited());

  display = new FourDigitDisplay(FOUR_DIGIT_DISPLAY_I2C_ADDRESS);

  latch = new Latch(LATCH_SERVO_PIN);
  latch->set_angle_for_opened(LATCH_ANGLE_FOR_OPENED);
  latch->set_angle_for_closed(LATCH_ANGLE_FOR_CLOSED);
  latch->close();

  menu = new Menu(menu_options, NUMBER_OF_MENU_OPTIONS);

  PhysicalPushButtonStrategy* push_button_strategy = new PhysicalPushButtonStrategy(
    PUSH_BUTTON_MOMENTARY_SWITCH_PIN,
    PUSH_BUTTON_LED_PIN
  );
  button = new PushButton(push_button_strategy);
  button->minimum_milliseconds_for_long_press = MINIMUM_MILLISECONDS_FOR_LONG_BUTTON_PRESS;
  button->on_short_press = handle_short_button_press;
  button->on_long_press = handle_long_button_press;

  LedProgressIndicatorsStrategy* progress_indicators_strategy = new LedProgressIndicatorsStrategy(
    PROGRESS_INDICATOR_PINS,
    NUMBER_OF_ZONES
  );
  progress_indicators = new ProgressIndicators(progress_indicators_strategy);

  display->clear();
  delay(500);
  enter_lockbox_mode();
}

void loop() {
  button->update_with_timestamp(millis());
}

void handle_short_button_press() {
  if (current_mode == LOCKBOX_MODE) {
    update_lockbox_state();
  } else if (current_mode == MENU_MODE) {
    menu->next_option();
    display_current_menu_option();
  }
}

void handle_long_button_press() {
  if (current_mode == LOCKBOX_MODE) {
    enter_menu_mode();
  } else if (current_mode == MENU_MODE) {
    menu->select_current_option();
  }
}

void update_lockbox_state() {
  GeographicLockState state = lockbox->get_state();
  set_progress(state.number_of_zones_visited);
  if (state.have_all_zones_been_visited) {
    open_latch();
    display->clear();
  } else { 
    display->clear();
    display->display_number(state.miles_to_next_zone);
  }
}

void set_progress(int number_of_zones_visited) {
  progress_indicators->set_number_of_zones_visited(number_of_zones_visited);
  progress_store->set_number_of_zones_visited(number_of_zones_visited);
}

void display_current_menu_option() {
  display->clear();
  MenuOption option = menu->get_current_option();
  display->write_byte(option.digit_values[0]);
}
