/*
(c) Nathan Barnett
MIT License
due 02 Dec 2021
romanImp.cpp
this source file defines the functions of class romanType from 'roman.h'
*/

#include <iostream>
#include "roman.h"

using std::cout, std::endl, std::string, std::vector;



romanType::romanType(const string& in)
{
    number = 0;
    inlet = in;

    // max 3,999 MMMCMXCIX
    // honestly couldn't think of another way to do this and it correctly parse
}

int romanType::getNum()
{
    return number;
}

int romanType::parse()                              // so much pain went into writing this. so many exceptions to check when parsing input.
{                                                   // I think this was the sixth time I had erased and rewrote the logic for this function.
    int curpos = 0;                                 // bless VSCode and its lldb support. I had to compile and follow the logic no less than 50 times.
    size_t subbegin = 0, sublen = 0;                // No, I didn't write this one in CS50 IDE. That's suicide for this.
    string substr, curcheck;
    bool badfound;

    for (size_t j = 0; j < valids.size(); j++)
    {
        for (size_t i = 0; i < valids[j].size(); i++)
        {
            subbegin = inlet.find(valids[j][i]);    // return std::string::npos if no match
            curcheck = valids[j][i]; // debug
            if ((subbegin != string::npos))     // if match found
            {
                if ((inlet.at(subbegin) == 'C') && (subbegin > 0))
                {
                    if (inlet.at(subbegin - 1) == 'X')
                    {
                        badfound = true;
                        break;
                    }
                }
                else if((inlet.at(subbegin) == 'X') && (subbegin > 0))
                {    
                    if (inlet.at(subbegin - 1) == 'I')
                    {
                        badfound = true;
                        break;
                    }
                }
            
                sublen = valids[j][i].length();
                curpos = i;
                badfound = false;
                break;
            }
        }
        if ((subbegin == string::npos) || (badfound == true))   // prevent out of range if 10^n is missing
            continue;                                        // also continue if out of order numerals were found

        substr += inlet.substr(subbegin, sublen);
        if (substr.empty())
            break;
        else
            number += rtoint[j][curpos];
            if (substr == inlet)
            break;
    }

    if ((number == 0) || (substr != inlet))
        return 1;
    else
        return 0;
}