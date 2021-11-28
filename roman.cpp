/*
(c) Nathan Barnett
MIT License
due 02 Dec 2021
roman.cpp

main execution.
Asks user to input valid roman numeral sequence and prints conversion
to a decimal integer represented by (ASCII) Arabic numerals.
*/


#include <iostream>
#include <string>
#include "roman.h"

using std::cout, std::cin, std::endl, std::string, std::getline;

int main()
{
    string input;
    string text;

    cout << "Roman Numeral to Decimal Converter\nEnter a Roman numeral less than MMMCMXCIX (3,999) in CAPS: ";
    cin.clear();
    cin.sync();
    
    do 
    {
        getline(cin, input);
        text += input + '\n';
    } while (input.empty());

    romanType romans(input);

    if (romans.parse())
    {
        cout << "error: invalid input from user" << endl;
        return 1;
    }
    else
    {
        cout << "\nRoman numeral entered: " << input
            << "\nDecimal equivalent: " << romans.getNum() << endl;
    }

    return 0;
}