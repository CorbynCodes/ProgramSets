// Corbyn Ledbetter
// COSC 2425
// Set Program 1
// References: What I can remeber from doing this problem is StackOverflow for get_min_base function. Everything else i can explain with great matter. Just needed a way to find the ranges in c++ and had to use std=c++ extension for it. Probably another way of doing it.
//
//This Program finds the minimum base of a number given in a string format.
#include <string>
#include <iostream>
using namespace std;

int get_min_base(const string& number_string) {
    char highest_char;

    // Finding the highest character in the string
    for(char c : number_string) { // Got this for loop from StackOverflow
        if(c > highest_char) {
            highest_char = c;
        }
    }

    if(isdigit(highest_char)) {
        return highest_char - '0' + 1; // if the digit is (0-9)
    } else {
        return highest_char - 'A' + 11; // if its a letter (A-Z)
    }
}

int main() {
    string number;
    char run_again;

    do {
        cout << "Enter value: ";
        cin >> number;

        int min_base = get_min_base(number);
        cout << "Minimum base: " << min_base << endl;
        cout << "Run again (Y/N): ";
        cin >> run_again;

    } while(run_again == 'Y' || run_again == 'y');

    return 0;
}
