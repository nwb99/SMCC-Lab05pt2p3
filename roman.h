/*
(c) Nathan Barnett
MIT License
due 02 Dec 2021
roman.h

this header file establishes the class romanType
*/


#include <vector>
#include <string>

class romanType
{
    public:

        romanType(const std::string&);

        int parse();
        int getNum();

    private:
       
        const std::vector< std::vector<std::string> > valids = {
        {"MMM", "MM", "M"},                                         // thousands
        {"DCCC", "DCC", "CCC", "DC", "CD", "CM", "CC", "D", "C"},   // hundreds
        {"LXXX", "LXX", "XXX", "XC", "XL", "XX", "LX", "L", "X"},   // tens
        {"VIII", "VII", "III", "IX", "VI", "IV", "II", "V", "I"}    // ones
        };

        const std::vector< std::vector<int> > rtoint = {
        {3000, 2000, 1000},
        {800, 700, 300, 600, 400, 900, 200, 500, 100},
        {80, 70, 30, 90, 40, 20, 60, 50, 10},
        {8, 7, 3, 9, 6, 4, 2, 5, 1}
        }; 
        std::string inlet;
        int number;
};