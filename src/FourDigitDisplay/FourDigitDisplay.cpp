#include <math.h>
#include <Wire.h>
#include "./FourDigitDisplay.h"

const int DEFAULT_I2C_ADDRESS = 0x71;

FourDigitDisplay::FourDigitDisplay() {
    FourDigitDisplay(DEFAULT_I2C_ADDRESS);
}

FourDigitDisplay::FourDigitDisplay(int initial_i2c_address) {
    Wire.begin();
    i2c_address = initial_i2c_address;
}

void FourDigitDisplay::write_bytes(uint8_t* bytes, int number_of_bytes) {
    Wire.beginTransmission(i2c_address);
    for (int byte_number = 0; byte_number<number_of_bytes; byte_number++) {
        Wire.write(bytes[byte_number]);
    }
    Wire.endTransmission(i2c_address);
}

void FourDigitDisplay::write_byte(uint8_t byte_to_write) {
    write_bytes(&byte_to_write, 1);
}

void FourDigitDisplay::display_number(double number) {
    int decimal_point_index = get_power_of_ten(number);
    turn_on_decimal_point_at_index(decimal_point_index);

    uint8_t bytes_to_write[4] = {
        get_digit_value(1, number),
        get_digit_value(2, number),
        get_digit_value(3, number),
        get_digit_value(4, number)
    };
    write_bytes(bytes_to_write, 4);
}

int FourDigitDisplay::get_power_of_ten(double number) {
    for (int power_of_ten=3; power_of_ten>-4; power_of_ten--) {
        if (number >= pow(10, power_of_ten)) {
            return power_of_ten;
        }
    }
    return 0;
}

void FourDigitDisplay::turn_on_decimal_point_at_index(int index) {
    uint8_t bytes_to_write[2] = {
        0x77,
        (uint8_t)(0b1 << index)
    };
    write_bytes(bytes_to_write, 2);
}

uint8_t FourDigitDisplay::get_digit_value(int digit_number, double number) {
    int number_in_thousands = get_number_in_thousands(number);
    if (pow(10, 4 - digit_number) > number_in_thousands) {
        return 0;
    }
    int multiplier = pow(10, 4 - digit_number);
    int number_with_digit_in_ones_place = number_in_thousands / multiplier;
    return number_with_digit_in_ones_place % 10;
}

int FourDigitDisplay::get_number_in_thousands(double number) {
    int power_of_ten = get_power_of_ten(number);
    int multiplier;
    if (power_of_ten >= 0) {
        multiplier = round(pow(10, 3 - power_of_ten));
    } else {
        multiplier = 1000;
    }
    return number * multiplier;
}

int FourDigitDisplay::strip_decimal_from_number(double number) {
    int power_of_ten = get_power_of_ten(number);
    return number * pow(10, power_of_ten);
}

void FourDigitDisplay::clear() {
    write_byte(0x76);
}

void FourDigitDisplay::set_brightness_out_of_100(uint8_t brightness) {
    uint8_t bytes_to_write[2] = { 0x7A, brightness };
    write_bytes(bytes_to_write, 2);
}

