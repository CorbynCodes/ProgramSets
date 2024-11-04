// Corbyn Ledbetter
// COSC 2425
// Program Set 2
// References: https://www.geeksforgeeks.org/hamming-distance-two-strings/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int hammingDistance(string &bin1, string &bin2) {
    int distance = 0;
    for(size_t i = 0; i < bin1.size(); ++i) {
        if(bin1[i] != bin2[i]) {
            ++distance;
        }
    }
    return distance;
}

int main() {
    string hex1, hex2;
    char runAgain;

    do {
        cout << "Enter the hex string: ";
        cin >> hex1;
        cout << "Enter the hex string: ";
        cin >> hex2;

        // Converting hex to binary just using bitset<4> faster than manuallly typing the conversion from website
        string bin1, bin2;
        for(char c : hex1) {
            bin1 += bitset<4>(stoi(string(1, c), nullptr, 16)).to_string();
        }
        for(char c : hex2) {
            bin2 += bitset<4>(stoi(string(1, c), nullptr, 16)).to_string();
        }

        int distance = hammingDistance(bin1, bin2);
        cout << "Distance: " << distance << endl;

        cout << "Do you want to run again?: ";
        cin >> runAgain;

    } while (runAgain == 'Y' || runAgain == 'y');

    return 0;
}
