//Corbyn Ledbetter
// COSC 2425
// Set Program Extra Credit
// Refercences: //   https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c++/
// https://discuss.kotlinlang.org/t/how-do-you-round-a-number-to-n-decimal-places/8843
//
// This Program rounds the additon of the values in the file to the number of decimal places specified in the file.
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
using namespace std;

double roundToDecimalPlaces(double number, int decimalPlaces) {
    double factor = pow(10.0, decimalPlaces);
    return round(number * factor) / factor; // learned this function today was wondering if i can use these type of functions in my code for the class?
}

int main() {
    char choice;
    do {
        string filename;
        cout << "Enter File Name: ";
        cin >> filename;

        ifstream inputFile(filename);
        if (!inputFile) {
            cout << "Error opening file." << endl;
            return 1;
        }

        int decimalPlaces;
        inputFile >> decimalPlaces; // Reading the number of decimal places from the file

        // checking to see if the decimal places ranges are withing [1,3];
        if(decimalPlaces < 1 || decimalPlaces > 3) {
            cout << "Error: Invalid number of decimal places." << endl;
            return 1;
        }

        double value, total = 0.0;
        while(inputFile >> value) {
            double roundedValue = roundToDecimalPlaces(value, decimalPlaces); // calling the function to round the value
            total += roundedValue; // adding the rounded value to the total
        }

        inputFile.close();
        cout << fixed << setprecision(2);
        cout << "Value: " << total << endl;

        cout << "Run Again (Y/N): ";
        cin >> choice;

    }while(choice == 'Y' || choice == 'y');

    return 0;
}
