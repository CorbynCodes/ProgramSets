// Corbyn Ledbetter
// COSC 2425
// Program Set 2
// References: https://en.cppreference.com/w/cpp/utility/bitset
//             https://www.geeksforgeeks.org/modulo-2-binary-division/
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;

// Using bitset for creating the hexToBin function because it will not work when i put the hex to binary numebers manually.
string hexToBin(const string hex) {
    stringstream ss;
    for (char c : hex) {
        // I want to breakdown this line of code beacuse i want to understand how it works.
        // 1. string(1, c) - Creates a string with a singlecharacter 'c'.
        // 2. stoi(string(1, c), nullptr, 16) - Converts the single-character string to an integer, interpreting it as a hexadecimal number.
        // 3. < bitset<4> - Converts the interger to a bitset of size 4.
        // ss << ... >> - appends the binary representation of the bitset to the stringstream.
        int value = stoi(string(1, c), nullptr, 16);
        bitset<4> bits(value);
        ss << bits;
    }
    return ss.str();
}

string xorStrings(const string a, const string b) {
    string result;
    for(size_t i = 1; i < b.size(); i++) {
        result += (a[i] == b[i] ? '0' : '1');
    }
    return result;
}

string crcString(const string& message, const string& key) {
    size_t keyLen = key.size();
    string appenedMessage = message + string(keyLen - 1, '0');
    string remainder = appenedMessage.substr(0, keyLen);

    for(size_t i = keyLen; i <=appenedMessage.size(); i++) {
        if(remainder[0] == '1') {
            remainder = xorStrings(remainder, string(keyLen, '0'));
            cout << "1st remainder check: " << remainder << endl;
        } else {
            remainder = xorStrings(remainder, key) ;
            cout << "2nd remainder check: " << remainder << endl;
        }
        if(i < appenedMessage.size()) {
            remainder = remainder.substr(1) + appenedMessage[i];
        }
    }
    return remainder.substr(1);
}



int main() {
    while(true) {
        string message, key;
        cout << "Enter the message: ";
        cin >> message;
        cout << "Enter the key: ";
        cin >> key;

        string messageBinary = hexToBin(message);
        string keyBinary = hexToBin(key);

        string checkSum = crcString(messageBinary, keyBinary);
        cout << "CheckSum: " << checkSum << endl;

        char runAgain;
        cout << "Do you want to run again? (y/n): ";
        cin >> runAgain;
        if(tolower(runAgain) != 'y') {
            break;
        }
    }

    return 0;
}
