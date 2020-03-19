#ifndef FOUR_DIGIT_DISPLAY_H 
#define FOUR_DIGIT_DISPLAY_H

class FourDigitDisplay {
    public:
        FourDigitDisplay();
        FourDigitDisplay(int);
        void write_bytes(uint8_t*, int);
        void write_byte(uint8_t);
        void display_number(double);
        void clear();
        void set_brightness_out_of_100(uint8_t);
    private:
        uint8_t i2c_address;
        int get_power_of_ten(double);
        void turn_on_decimal_point_at_index(int);
        int strip_decimal_from_number(double);
        uint8_t get_digit_value(int, double);
        int get_number_in_thousands(double);
};

#endif


