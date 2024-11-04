// Corbyn Ledbetter
// COSC 2425
// Programm Set 2
// References: https://www.youtube.com/watch?v=r01r8mEs9I4
// https://www.ibm.com/docs/en/iis/11.7?topic=tables-ebcdic-ascii
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

// used a unordered map to store the EBCDIC to ASCII mapping. I look up videos on how to use unordered maps and how to use them with strings.

unordered_map<string, char> EBCDICtoASCIIMap() {
    unordered_map<string, char> ebcidicToAsciiMap;

    // lowercase letters
    ebcidicToAsciiMap["81"] = 'a'; ebcidicToAsciiMap["82"] = 'b'; ebcidicToAsciiMap["83"] = 'c';
    ebcidicToAsciiMap["84"] = 'd'; ebcidicToAsciiMap["85"] = 'e'; ebcidicToAsciiMap["86"] = 'f';
    ebcidicToAsciiMap["87"] = 'g'; ebcidicToAsciiMap["88"] = 'h'; ebcidicToAsciiMap["89"] = 'i';
    ebcidicToAsciiMap["91"] = 'j'; ebcidicToAsciiMap["92"] = 'k'; ebcidicToAsciiMap["93"] = 'l';
    ebcidicToAsciiMap["94"] = 'm'; ebcidicToAsciiMap["95"] = 'n'; ebcidicToAsciiMap["96"] = 'o';
    ebcidicToAsciiMap["97"] = 'p'; ebcidicToAsciiMap["98"] = 'q'; ebcidicToAsciiMap["99"] = 'r';
    ebcidicToAsciiMap["A2"] = 's'; ebcidicToAsciiMap["A3"] = 't'; ebcidicToAsciiMap["A4"] = 'u';
    ebcidicToAsciiMap["A5"] = 'v'; ebcidicToAsciiMap["A6"] = 'w'; ebcidicToAsciiMap["A7"] = 'x';
    ebcidicToAsciiMap["A8"] = 'y'; ebcidicToAsciiMap["A9"] = 'z';

    // Uppercase letters
    ebcidicToAsciiMap["C1"] = 'A'; ebcidicToAsciiMap["C2"] = 'B'; ebcidicToAsciiMap["C3"] = 'C';
    ebcidicToAsciiMap["C4"] = 'D'; ebcidicToAsciiMap["C5"] = 'E'; ebcidicToAsciiMap["C6"] = 'F';
    ebcidicToAsciiMap["C7"] = 'G'; ebcidicToAsciiMap["C8"] = 'H'; ebcidicToAsciiMap["C9"] = 'I';
    ebcidicToAsciiMap["D1"] = 'J'; ebcidicToAsciiMap["D2"] = 'K'; ebcidicToAsciiMap["D3"] = 'L';
    ebcidicToAsciiMap["D4"] = 'M'; ebcidicToAsciiMap["D5"] = 'N'; ebcidicToAsciiMap["D6"] = 'O';
    ebcidicToAsciiMap["D7"] = 'P'; ebcidicToAsciiMap["D8"] = 'Q'; ebcidicToAsciiMap["D9"] = 'R';
    ebcidicToAsciiMap["E2"] = 'S'; ebcidicToAsciiMap["E3"] = 'T'; ebcidicToAsciiMap["E4"] = 'U';
    ebcidicToAsciiMap["E5"] = 'V'; ebcidicToAsciiMap["E6"] = 'W'; ebcidicToAsciiMap["E7"] = 'X';
    ebcidicToAsciiMap["E8"] = 'Y'; ebcidicToAsciiMap["E9"] = 'Z';

    // Special characters
    ebcidicToAsciiMap["40"] = ' '; ebcidicToAsciiMap["4B"] = '.'; ebcidicToAsciiMap["6B"] = ',';
    ebcidicToAsciiMap["5A"] = '!';

    return ebcidicToAsciiMap;
}

int main() {
    unordered_map<string, char> ebcidicToAsciiMap = EBCDICtoASCIIMap();
    char runAgain; // variable to run code again

    do {
        int numCodes; // Varaiable to store the number of EBCIDIC codes
        cout << "Number of codes: ";
        cin >> numCodes;

        cin.ignore();

        cout << "Enter codes: ";
        string codesLines; // Varaiable to store the line of EBCIDIC codes
        getline(cin, codesLines);

        stringstream ss(codesLines); /// create a stringstream from the input line
        string code; // Varaiable stroing each individual EBCIDIC code
        string result; //  variable storing the resulting ASCII string

        //Processing each ESBCIDIC code
        while (ss >> code) {
            // check if the code is in the map and that it exists
            if(ebcidicToAsciiMap.find(code) != ebcidicToAsciiMap.end()) {
                result += ebcidicToAsciiMap[code]; //  Appending corresping ASCII character to the result
            } else {
                result += '?'; // If the code is not found, print a question mark
            }
        }

        cout << "Translated ASCII: " << result << endl;

        cout << "Run again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
