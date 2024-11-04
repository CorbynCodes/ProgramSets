// Corbyn Ledbetter
// COCS 2425
// Set Problem 4
// References: ChatGPT on line 60, GeekForGeek.org for u_int32_t on line 10, and StackOverflow for the IEEE 754 floating point representation on line 16. StackOverFlow for sign problems i had. This problem took me about 9 hours to complete. Hardest one for sure.
// https://www.youtube.com/watch?v=VCgY4evLdik
// https://www.geeksforgeeks.org/data-types-in-c/
// https://www.youtube.com/watch?v=e_J9lXnU_vs
//
// This program converts an integer to its IEEE 754 floating point representation
#include <cmath>
#include <iostream>
#include <cstdint>
#include <iomanip>
using namespace std;

// I Have no clue what the uint32_t is, but I'm assuming it's a 32 bit integer type. You might not look at this but just going to to assume you do. Can you please explain what it is? Please pleas please because i had to look everywhere for these lines of code and I still don't understand it. I'm sorry for the inconvenience.

float intToIEEE754Float(uint32_t num) {
    uint32_t sign = (num >> 31) & 1; // Getting the assigned bits ( Bit 31 )
    // cout << "Input Value: " << num << endl; // coming out as 4294967295 for some reason?
    uint32_t exponent = (num >> 23) & 0xFF; // Get the exponent bits ( Bits 30 - 23 )
    // cout << "Exponent Value: " << exponent << endl;
    uint32_t mantissa = num & 0x7FFFFF; // Get the mantissa bits ( Bits 22 - 0 )
    // cout << "Mantissa Value: " << mantissa << endl;

    //Use Cases because I cant figure this out. Because I kept getting 4294967295 as the input value. which is double the max value of a 32 bit integer.
    if(exponent == 0xFF) {
        if(mantissa == 0) {
            return (sign == 0) ? INFINITY : -INFINITY; // Return infinity
        } else {
            return NAN; // Return NaN
        }
    }

    int e = exponent - 127; // Adjusting the exponent by subtracting 127
    float mantissa_val = 1.0f;
    // calculating the mantissa value with the floating point formula
    for(int i = 0; i < 23; i++) {
        if(mantissa & (1 << (22 - i))) {
            mantissa_val += 1.0 / (1 << (i + 1));
        }
    }

    float float_val = pow(-1, sign) * mantissa_val * pow(2, e); // Calculating the floating point value
    // cout << "Calculated IEEE 754 Float: " << float_val << endl; // getting nothing out of this at all.

    return float_val;
}

int main() {
    char choice = 'Y';
    uint32_t num;

    do {
        uint32_t num;
        cout << "Enter an integer: ";
        cin >> num;

        float float_val = intToIEEE754Float(num); // Converting the integer to IEEE 754 floating point representation
        cout << fixed << setprecision(25) << "IEEE 754 Float: " << float_val << endl; // Displaying the IEEE 754 floating point representation
        cout << "Run Again (Y/N): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the input buffer
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
