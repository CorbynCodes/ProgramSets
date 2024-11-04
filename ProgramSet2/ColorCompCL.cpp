// Corbyn Ledbetter
// COSC 2425
// Program set 2
// References: https://stackoverflow.com/questions/15804149/rgb-color-permutation

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
// 1. Convert the hexidecimal color values to their integer RGB components.
// 2. Calculate the average of each RGB component.
// 3. Adjust the average to minimize the maximum difference between to each of the original colors.
// 4. convert the resulting RGB components back to hexidecimal values.

int hexToInt(const string& hexStr) {
    int value;
    stringstream ss;
    ss << hex << hexStr;
    ss >> value;
    return value;
}

string intToHex(int value) {
    stringstream ss;
    ss << setw(2) << setfill('0') << hex << uppercase << value;
    return ss.str();
}

// Function to find the compromise color
string findCompromiseColor(const string color1, const string color2) {
    int r1 = hexToInt(color1.substr(0, 2));
    int g1 = hexToInt(color1.substr(2, 2));
    int b1 = hexToInt(color1.substr(4, 2));

    int r2 = hexToInt(color2.substr(0, 2));
    int g2 = hexToInt(color2.substr(2, 2));
    int b2 = hexToInt(color2.substr(4, 2));

    int rComp = (r1 + r2 + 1) / 2;
    int gComp = (g1 + g2 + 1) / 2;
    int bComp = (b1 + b2 + 1) / 2;

    int maxDiff1 = max(max(abs(r1 - rComp), abs(g1 - gComp)), abs(b1 - bComp));
    int maxDiff2 = max(max(abs(r2 - rComp), abs(g2 - gComp)), abs(b2 - bComp));

    if(maxDiff1 > maxDiff2) {
        rComp = (r1 + r2) / 2;
        gComp = (g1 + g2) / 2;
        bComp = (b1 + b2) / 2;
    } else {
        rComp = (r1 + r2 + 1) / 2;
        gComp = (g1 + g2 + 1) / 2;
        bComp = (b1 + b2 + 1) / 2;
    }

    string compromiseColor = "#" + intToHex(rComp) + intToHex(gComp) + intToHex(bComp);
    return compromiseColor;
}

int main() {
    string colorOne, colorTwo;
    char runAgain;

    do {
        cout << "Enter hex first color: ";
        cin >> colorOne;
        transform(colorOne.begin(), colorOne.end(), colorOne.begin(), ::toupper);
        cout << "Enter hex second color: ";
        cin >> colorTwo;
        transform(colorTwo.begin(), colorTwo.end(), colorTwo.begin(), ::toupper);

        if(colorOne[0] == '#') colorOne = colorOne.substr(1);
        if(colorTwo[0] == '#') colorTwo = colorTwo.substr(1);

        string compromiseColor = findCompromiseColor(colorOne, colorTwo);
        cout << "Compromise: " << compromiseColor << endl;
        cout << "Run Again (Y/N): ";
        cin >> runAgain;

    }while(runAgain == 'y' || runAgain == 'Y');
}
