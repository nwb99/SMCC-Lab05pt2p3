/*
(c) Nathan Barnett
MIT License
due 02 Dec 2021
romanImp.cpp
this source file defines the functions of class romanType from 'roman.h'
*/

#include <iostream>
#include <cstring>
#include <sstream>
#include "roman.h"

using std::cout, std::endl, std::string, std::vector;


romanType::romanType(const string& in)
{
    number = 0;
    inlet = in;
}

int romanType::getNum()
{
    return number;
}

int romanType::parse()                              // so much pain went into writing this. so many exceptions to check when parsing input.
{                                                   // I think this was the sixth time I had erased and rewritten the logic for this function.
    int curpos = 0;                                 // bless VSCode and its lldb support. I had to compile and follow the logic no less than 50 times.
    size_t subbegin = 0, sublen = 0;                // No, I didn't write this one in CS50 IDE. That's suicide for this.
    //string curcheck;
    bool badfound;

    for (size_t j = 0; j < valids.size(); j++)
    {
        for (size_t i = 0; i < valids[j].size(); i++)
        {
            subbegin = inlet.find(valids[j][i]);    // return std::string::npos if no match
            //curcheck = valids[j][i]; // debug
            if ((subbegin != string::npos))     // if match found
            {
                if ((inlet.at(subbegin) == 'C') && (subbegin > 0))      // XC fails // if C found
                {
                    if (inlet.at(subbegin - 1) == 'X')                  // check that it isn't actually XC
                    {
                        badfound = true;
                        break;                  // break to j loop if XC.
                    }
                }
                else if ((inlet.at(subbegin) == 'X') && (subbegin > 0)) // IX fails
                {    
                    if (inlet.at(subbegin - 1) == 'I')
                    {
                        badfound = true;
                        break;
                    }
                }
                else if ((inlet.at(subbegin)) == 'M' && (subbegin > 0)) // CM fails
                {
                    if (inlet.at(subbegin - 1) == 'C')
                    {
                        badfound = true;
                        break;
                    }
                }
             /*
             For the above checks:
             std::string::find matches whole strings, but only returns pos (size_t) of first character of substr.
             See 'roman.h'. It is possible to match the last letter in every valids[j] (M, C, X) when the actual
             string value reads "CM", "XC", or "IX". The above if-else statements check if char at position returned
             by string::find is one of the trouble letters. If true, also check that it isn't the first char in string.
             Skip if either requirement is false. If both are true, check if the pos-1 letter is what is probably expected.
             If so, set badfound to true and break the 'i' loop to advance 'j'. The check (subbegin > 0) must be true,
             otherwise "inlet.at(subbegin - 1)" will underflow size_t and std::string will throw exception out_of_range.
             */         

                // if match (subbegin != string::npos)
                sublen = valids[j][i].length();         // find length needed to extract
                curpos = i;                             // so accessible outside of loop
                badfound = false;
                break;                                  // leave i loop and do not test any more elements in [j]
            }
        }
        if ((subbegin == string::npos) || (badfound == true))   // prevent out of range if a 10^n position is missing
            continue;                                        // also continue if out of order numerals were found

        substr += inlet.substr(subbegin, sublen);           // extract parsed characters to substr
        if (substr.empty())                                 // if substr is empty, break out of loop and fail
            break;
        else
            number += rtoint[j][curpos];          // ji positions in matrix 'valids' is equivalent to ji positions in 'rotint'
            if (substr == inlet)
            break;
    }

    if ((number == 0) || (substr != inlet))       // if parsed string doesn't match input string, return failure
        return 1;
    else
        return 0;
}

// don't worry about this. not necessary for program function...
bool romanType::egg()
{
    std::stringstream s;
    size_t len = substr.length() + 1;
    char * t = new char [len];
    strcpy(t, substr.c_str());

    for (size_t i = 0; i < len; i++)
    {
        s << std::hex << (int)t[i]; 
    }
    if (s.str() == "4c5849580")
    {
        delete [] t;
        return true;
    }
    else
    {
        delete [] t;
        return false;
    }
}