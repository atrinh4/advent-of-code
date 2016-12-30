/*
 * Advent of Code 2016: Day 06
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 28/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    auto frequency = std::vector<std::vector<int>>(8, std::vector<int>(26));
    std::string line;
    auto infile = std::ifstream{"input.txt"};
    while (infile >> line)
        for (auto i = 0U; i < line.size(); ++i)
            ++frequency[i][line[i] - 'a'];

    std::string msg_1;
    std::string msg_2;
    for (const auto& col : frequency) {
        msg_1 += char(std::distance(col.cbegin(), std::max_element(col.cbegin(), col.cend())) + 'a');
        msg_2 += char(std::distance(col.cbegin(), std::min_element(col.cbegin(), col.cend())) + 'a');
    }

    std::cout << "Part 1: Original message is " << msg_1 << '\n';
    std::cout << "Part 2: Original message is " << msg_2 << '\n';
}
