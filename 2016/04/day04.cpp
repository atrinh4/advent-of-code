/*
 * Advent of Code 2016: Day 04
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 25/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

std::string decrypt(const std::string& ciphertext, int shift)
{
    shift = shift % 26;
    std::string plaintext;
    for (const auto chr : ciphertext)
        plaintext += (chr == '-') ? ' ' : ((chr - 97 + shift) % 26) + 97;
    return plaintext;
}

std::string calc_checksum(const std::string& name)
{
    auto frequencies = std::vector<std::pair<char, int>>{};
    for (auto i = 0; i < 26; ++i)
        frequencies.push_back({'a' + i, 0});
    for (const auto letter : name)
        if (letter != '-')
            ++frequencies[letter - 'a'].second;
    std::stable_sort(frequencies.begin(), frequencies.end(),
            [] (const auto& freq1, const auto& freq2)
            {
                return freq1.second > freq2.second;
            });
    std::string checksum;
    for (auto i = 0; i < 5; ++i)
        checksum += frequencies[i].first;
    return checksum;
}

int main()
{
    std::string line;
    auto north_pole_sector = 0;
    auto num_real_sector = 0;
    auto infile = std::ifstream{"input.txt"};
    while (infile >> line) {
        auto regex = std::regex{R"(^([\w-]+)-(\d+)\[(\w+)\]$)"};
        std::smatch res;
        std::regex_match(line, res, regex);
        auto name = res.str(1);
        auto sector_id = std::stoi(res.str(2));
        auto checksum = res.str(3);
        if (calc_checksum(name) == res.str(3)) {
            num_real_sector += sector_id;
            if (decrypt(name, sector_id).find("north") != std::string::npos)
                north_pole_sector = sector_id;
        }
    }
    std::cout << "Part 1: Sum of sector IDs of real rooms is " << num_real_sector << '\n';
    std::cout << "Part 2: Sector ID of room with North Pole objects is " << north_pole_sector << '\n';
}
