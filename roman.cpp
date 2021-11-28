/*
(c) Nathan Barnett
MIT License
due 02 Dec 2021
roman.cpp

main execution.
Asks user to input valid roman numeral sequence and prints conversion
to a decimal integer represented by (ASCII) Arabic numerals.

clang++ -std=c++17 -o roman roman.cpp romanImp.cpp
bought to you by vscode with vim emulation

*/


#include <iostream>
#include <string>
#include <limits>
#include "roman.h"

using std::cout, std::cin, std::endl, std::string, std::getline;

int main()
{
    string input;

    cout << "Roman Numeral to Decimal Converter\nEnter a Roman numeral less than MMMCMXCIX (3,999) in CAPS: ";

    do 
    {
        getline(cin, input);
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
//----------------------------------------------------------------------        
        if (romans.egg())
        {
            char c[5] = {0x6e, 0x69, 0x63, 0x65, 0x00};
            for (int i = 0; i < 5; i++)
            {
                printf("%c", c[i]);
            }
            cout << endl;
        }
    }

    return 0;
}