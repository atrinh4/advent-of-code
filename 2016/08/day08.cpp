/*
 * Advent of Code 2016: Day 08
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 28/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

#include "day08.h"

int Screen::num_pixels_on() const
{
    auto num = 0;
    for (const auto& row : scr_)
        for (const auto pixel : row)
            if (pixel) ++num;
    return num;
}

void Screen::rect(int width, int height)
{
    for (auto row = 0; row < height; ++row)
        for (auto col = 0; col < width; ++col)
            scr_[row][col] = true;
}

void Screen::rotate_row(int row, int shift)
{
    std::rotate(scr_[row].rbegin(), scr_[row].rbegin() + shift, scr_[row].rend());
}

void Screen::rotate_col(int col, int shift)
{
    auto tmp = std::vector<bool>{};
    for (const auto& row : scr_)
        tmp.push_back(row[col]);
    std::rotate(tmp.rbegin(), tmp.rbegin() + shift, tmp.rend());
    for (auto i = 0; i < 6; ++i) 
        scr_[i][col] = tmp[i]; 
}

std::ostream& operator<<(std::ostream& os, const Screen& screen)
{
    for (const auto& row : screen.scr_) {
        for (const auto pixel : row)
            os << (pixel ? '*' : ' ');
        if (row != *(screen.scr_.end() - 1)) os << '\n';
    }
    return os;
}

int main()
{
    Screen scr;
    std::smatch match;
    std::string line;

    auto rect_regex = std::regex{R"(rect (\d+)x(\d+))"};
    auto rotate_row_regex = std::regex{R"(rotate row y=(\d+) by (\d+))"};
    auto rotate_col_regex = std::regex{R"(rotate column x=(\d+) by (\d+))"};
    auto infile = std::ifstream{"input.txt"};

    while (std::getline(infile, line)) {
        if (std::regex_match(line, match, rect_regex))
            scr.rect(std::stoi(match.str(1)), std::stoi(match.str(2)));
        else if (std::regex_match(line, match, rotate_row_regex))
            scr.rotate_row(std::stoi(match.str(1)), std::stoi(match.str(2)));
        else if (std::regex_match(line, match, rotate_col_regex))
            scr.rotate_col(std::stoi(match.str(1)), std::stoi(match.str(2)));
    }

    std::cout << "-- Day 08 --\n";
    std::cout << "Part 1: " << scr.num_pixels_on() << '\n';
    std::cout << "Part 2: " << '\n' << scr << '\n';
}
