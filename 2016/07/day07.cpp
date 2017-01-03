/*
 * Advent of Code 2016: Day 07
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 28/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool supports_tls(const std::string& addr)
{
    auto in_hypernet = false;
    auto has_abba = false;

    for (auto i = 0U; i < addr.size() - 3; ++i) {
        if (addr[i] == '[') {
            in_hypernet = true;
        } else if (addr[i] == ']') {
            in_hypernet = false;
        } else if (addr[i] != addr[i+1] && addr[i] == addr[i+3] && addr[i+1] == addr[i+2]) {
            if (in_hypernet)
                return false;
            else
                has_abba = true;
        }
    }

    return has_abba;
}

bool supports_ssl(const std::string& addr)
{
    auto aba_supernet = std::vector<std::pair<char, char>>{};
    auto bab_hypernet = std::vector<std::pair<char, char>>{};
    auto in_hypernet = false;

    for (auto i = 0U; i < addr.size() - 2; ++i) {
        if (addr[i] == '[') {
            in_hypernet = true;
        } else if (addr[i] == ']') {
            in_hypernet = false;
        } else if (addr[i] != addr[i+1] && addr[i] == addr[i+2]) {
            if (in_hypernet)
                bab_hypernet.push_back({addr[i+1], addr[i]});
            else
                aba_supernet.push_back({addr[i], addr[i+1]});
        }
    }

    for (const auto& aba : aba_supernet)
        if (std::find(bab_hypernet.cbegin(), bab_hypernet.cend(), aba) != bab_hypernet.cend())
            return true;

    return false;
}

int main()
{
    auto num_support_tls = 0;
    auto num_support_ssl = 0;
    auto infile = std::ifstream{"input.txt"};
    std::string line;

    while (infile >> line) {
        if (supports_tls(line)) ++num_support_tls;
        if (supports_ssl(line)) ++num_support_ssl;
    }

    std::cout << "Part 1: " << num_support_tls << '\n';
    std::cout << "Part 2: " << num_support_ssl << '\n';
}
