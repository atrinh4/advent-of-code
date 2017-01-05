/*
 * Advent of Code 2016: Day 09
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 04/01/17
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>

unsigned long d_len(const std::string& data, const bool d_all)
{
    const auto regex = std::regex{R"(\((\d+)x(\d+)\))"};
    auto match = std::smatch{};
    if (!std::regex_search(data, match, regex)) return data.size();
    auto num = std::stoi(match.str(1));
    auto times = std::stoi(match.str(2));
    auto next_pos = match.position() + match.length();
    return match.position() + 
            (d_all ? d_len(data.substr(next_pos, num), d_all) : num) * times + 
            d_len(data.substr(next_pos + num), d_all);
}

int main()
{
    using namespace std::literals::string_literals;
    auto compressed = ""s;
    auto infile = std::ifstream{"input.txt"};
    infile >> compressed;

    std::cout << "-- Day 09 --\n";
    std::cout << "Part 1: " << d_len(compressed, false) << '\n';
    std::cout << "Part 2: " << d_len(compressed, true) << '\n';
}
