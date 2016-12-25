/*
 * Advent of Code 2016: Day 02
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 25/12/16
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "day02.h"

char Keypad::traverse(const std::string& directions)
{
    for (const auto dir : directions) {
        switch (dir) {
            case 'U':
                if (row_ > 0 && keypad_layout_[row_ - 1][col_] != ' ') --row_;
                break;
            case 'L':
                if (col_ > 0 && keypad_layout_[row_][col_ - 1] != ' ') --col_;
                break;
            case 'D':
                if (row_ < keypad_layout_.size() - 1 && keypad_layout_[row_ + 1][col_] != ' ') ++row_;
                break;
            case 'R':
                if (col_ < keypad_layout_.size() - 1 && keypad_layout_[row_][col_ + 1] != ' ') ++col_;
                break;
        }
    }
    return keypad_layout_[row_][col_];
}

int main()
{
    const auto keypad_layout1 = keypadlayout{
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
    };

    const auto keypad_layout2 = keypadlayout{
        { ' ', ' ', '1', ' ', ' ' },
        { ' ', '2', '3', '4', ' ' },
        { '5', '6', '7', '8', '9' },
        { ' ', 'A', 'B', 'C', ' ' },
        { ' ', ' ', 'D', ' ', ' ' },
    };

    auto keypad1 = Keypad{keypad_layout1, 1, 1};
    auto keypad2 = Keypad{keypad_layout2, 2, 0};

    std::string code1;
    std::string code2;

    std::string line;
    auto infile = std::ifstream{"input.txt"};
    while (infile >> line) {
        code1 += keypad1.traverse(line);
        code2 += keypad2.traverse(line);
    }

    std::cout << "Part 1: Bathroom code is " << code1 << '\n';
    std::cout << "Part 2: Bathroom code is " << code2 << '\n';
}
