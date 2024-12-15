// assemply project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this program has to convert anz base to decimal and then convert decimal to target base
// accept number as string and then covert and displaz number as string
//0  9 A   F


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to convert a character digit to its integer value
int charToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1; // Return -1 for invalid characters
}

// Function to convert an integer value to its character representation
char valueToChar(int value) {
    if (value >= 0 && value <= 9) {
        return '0' + value;
    }
    else if (value >= 10 && value <= 15) {
        return 'A' + (value - 10);
    }
    return '?'; // Return '?' for invalid values
}

// Function to check if a number string is valid for the given base
bool isValidNumber(const string& number, int base) {
    for (char c : number) {
        int value = charToValue(c);
        if (value == -1 || value >= base) {
            return false; // Invalid character or character out of range for the base
        }
    }
    return true;
}

// Function to convert a number from any base to decimal
int baseToDecimal(const string& number, int base) {
    int decimalValue = 0;
    for (size_t i = 0; i < number.length(); i++) {
        decimalValue = decimalValue * base + charToValue(number[i]);
    }
    return decimalValue;
}

// Function to convert a decimal number to any base
string decimalToBase(int decimal, int base) {
    string result = "";
    if (decimal == 0) {
        return "0";
    }
    while (decimal > 0) {
        int remainder = decimal % base;
        result = valueToChar(remainder) + result;
        decimal /= base;
    }
    return result;
}

int main() {
    int inputBase, targetBase;
    string number;

    cout << "Enter the base of the input number: ";
    cin >> inputBase;

    // Validate the input base
    if (inputBase < 2 || inputBase > 16) {
        cerr << "Base must be between 2 and 16." << endl;
        return 1;
    }

    cout << "Enter the number: ";
    cin >> number;

    // Validate the input number for the given base
    if (!isValidNumber(number, inputBase)) {
        cerr << "Invalid number for base " << inputBase << "." << endl;
        return 1;
    }

    cout << "Enter the base of the target system: ";
    cin >> targetBase;

    // Validate the target base
    if (targetBase < 2 || targetBase > 16) {
        cerr << "Target base must be between 2 and 16." << endl;
        return 1;
    }

    // Convert the input number to decimal
    int decimalValue = baseToDecimal(number, inputBase);

    // Convert the decimal value to the target base
    string convertedNumber = decimalToBase(decimalValue, targetBase);

    cout << "Converted number in base " << targetBase << ": " << convertedNumber << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
