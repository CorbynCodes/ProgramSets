# Convert EBCDICL to ASCII Program

This program converts a series of EBCDIC (Extended Binary Coded Decimal Interchange Code) codes to their corresponding ASCII characters. The program uses an `unordered_map` to store the EBCDIC codes and their corresponding ASCII characters. It reads the EBCDIC codes from the user and displays the corresponding ASCII

## Complication and Execution
To compile the program and run the program, follow the steps below:
1. Open the terminal.
2. Compile the program using a C++ complier, for example,

```sh
   g++ -std=c++11 -o ebcdic_to_ascii ConvertEBCDICL.cpp
```
3. Run the program using the following command:

```sh
   ./ebcdic_to_ascii
```
4. Enter the EBCDIC code when prompted.
5. There you go! That simple

## EBCDIC to ASCII Mapping Function

```cpp
unordered_map<string, char> EBCDICtoASCIIMap() {
    unordered_map<string, char> ebcidicToAsciiMap;

    // Lowercase letters
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
```
- this function intializes an unordered_map with the EBCDIC code and the corresponding ASCII character. The function returns the unordered_map.
- the map includes mappings for lowercase letters, uppercase letters, and special characters.

## Main Function

```cpp
int main() {
    unordered_map<string, char> ebcidicToAsciiMap = EBCDICtoASCIIMap();
    char runAgain; // Variable to run the code again

    do {
        int numCodes; // Variable to store the number of EBCDIC codes
        cout << "Number of codes: ";
        cin >> numCodes;

        cin.ignore();

        cout << "Enter codes: ";
        string codesLines; // Variable to store the line of EBCDIC codes
        getline(cin, codesLines);

        stringstream ss(codesLines); // Create a stringstream from the input line
        string code; // Variable storing each individual EBCDIC code
        string result; // Variable storing the resulting ASCII string

        // Processing each EBCDIC code
        while (ss >> code) {
            // Check if the code is in the map and that it exists
            if (ebcidicToAsciiMap.find(code) != ebcidicToAsciiMap.end()) {
                result += ebcidicToAsciiMap[code]; // Append corresponding ASCII character to the result
            } else {
                result += '?'; // If the code is not found, append a question mark
            }
        }

        cout << "Translated ASCII: " << result << endl;

        cout << "Run again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
```
- it prompts the user to enter the number of EBCDIC codes and the code themselves.
- it processes each EBCDIC code, coverts it to the corresponding ASCII character using the unordered_map, and constructs the resulting ASCII string.
- it displays the translated ASCII string.
- it prompts the user to run the code again.

## Sample Run
```sh
Number of codes: 17
Enter codes: E5 85 95 89 6B 40 A5 89 84 89 6B 40 A5 89 83 89 4B
Translated ASCII: Veni, vidi, vici.
Run again (Y/N): n

Number of codes: 10
Enter Coded: 85 95 89 6B 40 A5 89 84 89 6B
Translated ASCII: eni, vidi,
```

---

# Color Compromise Program

The Program reads two RBG values from the user and calculates the compromise color between the two colors. The compromise color is calculated by averaging the red, green, and blue values of the two colors. (0, 0, 255) becomes #0000FF, and (191, 87, 0) becomes #BF5700 as an example. The program then displays the compromise color in hexadecimal format.

## Complication and Execution
To compile the program and run the program, follow the steps below:
1. Open the terminal.
2. Compile the program using a C++ complier, for example,

```sh
   g++ -std=c++11 -o color_compromise ColorCompCL.cpp
```
3. Run the program using the following command:

```sh
   ./color_compromise
```
4. Enter the two RGB values when prompted.
5. There you go! That simple

## Color Compromise Calculation Function

This function calculates the compromise color between two RGB colors. The function takes two RGB colors as input and returns the compromise color.

```cpp
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
```
I had trouble with this problem so i am going to explain each part of the code.
 - Extracts the RGB components from the hexidecimal color strings.
 - Calculates the average of each RGB component.
 - Adjusts the average the minimize and maximize the difference between the original colors.
 - Converts the average RGB components to a hexadecimal string.

## Main Function

The main function handles user input, compromise color calculation, and output display.

```cpp
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

    } while(runAgain == 'y' || runAgain == 'Y');
}
```
- It prompts the user to enter two hexadecimal color strings.
- it converts the input colors to uppercase and removes the '#' character if present.
- it calculates the compromise color using  'findCompromiseColor' function.
- it displays the calculated compromise color.

---

# Hamming Distance Calculation

This program calcuates the Hamming Distance between two hexadecimal strings. The Hamming Distance is the number of postions at which the corresponding bits are different. The program converts the hexidecimal strings to binary and then computes the Hamming Distance from the binary strings.

## Complication and Execution

To compile the program and run the program, follow the steps below:
1. Open the terminal.
2. Compile the program using a C++ complier, for example,

```sh
   g++ -std=c++11 -o  hamming_distance HammingDistanceCL.cpp
```
3. Run the program using the following command:

```sh
   ./hamming_distance
```
4. Enter the two hexadecimal strings when prompted.
5. There you go! That simple

## Hamming Distance Calculation Function
This function calculates the Hamming Distance between two binary strings. The function takes two binary strings as input and returns the Hamming Distance between them.

```cpp
int hammingDistance(string &bin1, string &bin2) {
    int distance = 0;
    for(size_t i = 0; i < bin1.size(); ++i) {
        if(bin1[i] != bin2[i]) {
            ++distance;
        }
    }
    return distance;
}
```
- creates distance variable to store the hamming distance.
- iterates through bin1 size, then goes through each index of the binary string and compares the two binary strings. If they are not equal, it increments the distance variable.
- returns the distance variable.


## Main Function
The main function handles user input, binary conversion, and output display.
I did use some bitset<4> that i learned from the CRCSum problem from youtube. Which worked in this case other than having to create a whole another function to convert the hex to binary.

```cpp
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
```
- it prompts the user to enter two hexadecimal strings.
- it converts the hexadecimal strings to binary strings.
- it calculates the Hamming Distance between the binary strings.
- it displays the calculated Hamming Distance.

## Sample Run
Here is a sample run of the program:

```sh
Enter the hex string: FFFFFFFF
Enter the hex string: 00000000
Distance: 32
Do you want to run again?: y
Enter the hex string: AAAAA57D
Enter the hex string: AAAAA3B6
Distance: 7
Do you want to run again?: n`
```

---

# IP Address Classification Program

This program reads the binaray IP address from a file, converts them to dotted decimal format, classifies them into IP Class (A, B, C, D, E), and displays the results.

## Complication and Execution
To compile the program and run the program, follow the steps below:
1. Open the terminal.
2. create a file with the anyname and add the binary IP addresses to the file. (Input will be from a text file in which the first line of input will contain a single integer n in the range [1,100] indicating the number of IP addresses to follow)
3. Compile the program using a C++ complier, for example,

```sh
   g++ -std=c++11 -o  ip_classifier IPAddressCL.cpp
```
4. Run the program using the following command:

```sh
   ./ip_classifier
```

## Binary to Dotted Decimal Conversion Function
This function converts a binary IP address to a dotted decimal format. The only part i had trouble understanding when writing this code was the dotteddecimal formula and how to convert the binary to decimal. I had to do some research to understand how to convert binary to decimal and how to convert the binary to a dotted decimal format. Also, to_ulong() function was founded on the C++ docs website.

  ```cpp
  string binaryToDottedDecimal(const string &binary) {
      if(binary.length() != 32) {
          cerr << "Error: Binary string length is not 32 bits." << endl;
          return "";
      }

      string dottedDecimal;
      for(int i = 0; i < 4; i++) {
          bitset<8> octet(binary.substr(i * 8, 8));
          dottedDecimal += to_string(octet.to_ulong());
          if(i < 3) {
              dottedDecimal += ".";
          }
      }

      return dottedDecimal;
  }
  ```
- if loop to check if the binary string length is not 32 bits. Which is a edge case or to check for edge cases.
- create string dottedDecimal to store the converted binary to decimal.
- for loop to convert the binary to decimal and store it in the dottedDecimal string. Using bitset<8> to convert the binary to decimal and to_ulong() to convert the binary to decimal.
- return the dottedDecimal string.

## classifyIP Function
This function classifies an IP Address based on its first octet.

  ```cpp
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
  ```
- create firstOctet variable to store the first octet of the IP address.
- classify the IP address based on the first octet. The IP address is classified as Class A if the first octet is in the range [0,127], Class B if the first octet is in the range [128,191], Class C if the first octet is in the range [192,223], Class D if the first octet is in the range [224,239], and Class E if the first octet is in the range [240,255].
- return the classification of the IP address.

## Main Function
The Main function handles user input, file reading, and output display.

  ```cpp
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
```
- prompt the user to enter the file name.
- open the file and read the number of IP addresses and the binary IP addresses.
- for loop to read the binary IP addresses from the file. Then, converts the binary IP address to a dotted decimal format and classifies the IP address. Finally, displays the binary IP address, dotted decimal IP address, and the classification of the IP address.
- prompt the user if they want to run the program again.

## Sample file (address.txt)
6
01111111000000000000000000000001
11011010110111101010101101010101
10011010110111101010101101010101
10111010110111101010101101010101
11100000111111111111111111111111
11111111111111111111111111111111


## Sample Run
```sh
Enter file name: addresses.txt
01111111000000000000000000000001 -> 127.0.0.1 [ CLASS A]
11011010110111101010101101010101 -> 218.222.171.85 [ CLASS C]
10011010110111101010101101010101 -> 154.222.171.85 [ CLASS B]
10111010110111101010101101010101 -> 186.222.171.85 [ CLASS B]
11100000111111111111111111111111 -> 224.255.255.255 [ CLASS D]
11111111111111111111111111111111 -> 255.255.255.255 [ CLASS E]
Do you want to run the program again? (y/n): n
```
