#ifndef DAY02_H
#define DAY02_H

/*
 * Advent of Code 2016: Day 02
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 25/12/16
 */

#include <string>
#include <vector>

using keypadlayout = std::vector<std::vector<char>>;

class Keypad
{
public:
    Keypad(const keypadlayout& keypad_layout, unsigned int row, unsigned int col) :
        row_{row}, col_{col}, keypad_layout_{keypad_layout} { }
    char traverse(const std::string& directions);
private:
    unsigned int row_;
    unsigned int col_;
    const keypadlayout keypad_layout_;
};

#endif
