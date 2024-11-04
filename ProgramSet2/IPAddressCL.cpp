// Corbyn Ledbetter
// COSC 2425
// Program Set 2
// References: https://stackoverflow.com/questions/33574127/binary-and-dotted-decimal-conversion-for-looping-over-ip-addresses
//

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;

string binaryToDottedDecimal(const string &binary) {
    if(binary.length() != 32) {
        cerr << "Error: Binary string length is not 32 bits." << endl;
        return "";
    }

    string dottedDecimal;
    for(int i = 0; i < 4; i++) {
        bitset<8> octet(binary.substr(i * 8, 8));
        dottedDecimal += to_string(octet.to_ulong()); // convert octet to unsigned long and then to string
        if(i < 3) {
            dottedDecimal += ".";
        }
    }

    return dottedDecimal;
}

string classifyIP(const string &dottedDecimal) {
    int firstOctet = stoi(dottedDecimal.substr(0, dottedDecimal.find('.')));
    if(firstOctet >= 0 && firstOctet <= 127) {
        return "CLASS A";
    } else if(firstOctet >= 128 && firstOctet <= 191) {
        return "CLASS B";
    } else if(firstOctet >= 192 && firstOctet <= 223) {
        return "CLASS C";
    } else if(firstOctet >= 224 && firstOctet <= 239) {
        return "CLASS D";
    } else if(firstOctet >= 240 && firstOctet <= 255) {
        return "CLASS E";
    } else {
        return "Unknown class";
    }
}


int main() {
    string fileName;
    char runAgain;

    do {
        cout << "Enter file name: ";
        cin >> fileName;

        ifstream inputFile(fileName);
        if(!inputFile) {
            cout << "Error opening file" << endl;
            return 1;
        }

        int n;
        inputFile >> n;
        vector<string> binaryIPs(n);

        for(int i = 0; i < n; i++) {
            inputFile >> binaryIPs[i];
        }

        inputFile.close();

        for(const auto &binaryIP : binaryIPs) {
            string dottedDecimal = binaryToDottedDecimal(binaryIP);
            string classification = classifyIP(dottedDecimal);
            cout << binaryIP << " -> " << dottedDecimal << " [ " << classification << "]" << endl;
        }

        cout << "Do you want to run the program again? (y/n): ";
        cin >> runAgain;

    } while(runAgain == 'y' || runAgain == 'Y');
    return 0;
}
