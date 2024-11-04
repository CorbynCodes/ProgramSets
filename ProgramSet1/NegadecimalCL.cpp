// Corbyn Ledbetter
// COSC 2425
// Set Program 2
// References: https://www.geeksforgeeks.org/convert-number-negative-base-representation/
// https://www.geeksforgeeks.org/convert-negative-base-number-decimal-base-number/
// This program converts decimal to negadecimal and vice versa.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// My Notes For how to change decimal to negadecimal:
// 1. If the decimal is 0, return 0

// Function to convert decimal to negadecimal I hope
string decimalToNegadecimal(int decimal) {
    if (decimal == 0) return 0; // user-case because couldnt run the program without it for some reason. Zero Case

    string negadecimal = "";
    while (decimal != 0) {
        int remainder = decimal % -10;
        decimal /= -10;
        if (remainder < 0) {
            remainder += 10;
            decimal += 1;
        }
        negadecimal += to_string(remainder);
    }

    reverse(negadecimal.begin(), negadecimal.end()); // reversing the string and somehow it works
    return negadecimal;
}

// Funcaiton to convert negadecimal to decimal I hope
int negadecimalToDecimal(const string& negadecimal) {
    int decimal = 0;
    int power = 1; // this represents the power of (-10)^0

    for (int i = negadecimal.length() - 1; i >= 0; i--) {
        int digit = negadecimal[i] - '0';
        decimal += digit * power;
        power *= -10;
    }
    return decimal;
}

int main() {
   char run_again;

    do {
        char DorN;
        cout << "N to D (N) or D to N (D): ";
        cin >> DorN;

        if(DorN == 'D' || DorN == 'd') {
            int decimal;
            cout << "Enter Value [-10000-10000]: ";
            cin >> decimal;
            string negadecimal = decimalToNegadecimal(decimal); // callng the logic of the function
            cout << "Result: " << negadecimal << endl;
        } else if(DorN == 'N'|| DorN == 'n') {
            string negadecimal;
            cout << "Enter Value [-10000-10000]: ";
            cin >> negadecimal;
            int decimal = negadecimalToDecimal(negadecimal); // calling the logic of the function
            cout << "Result: " << decimal << endl;
        } else {
            cout << "Invalid Input" << endl;
        }

        cout << "Do you want to run again? (Y/N): ";
        cin >> run_again;
    } while(run_again == 'Y' || run_again == 'y');

    return 0;
}
