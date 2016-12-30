/*
 * Advent of Code 2016: Day 05
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 27/12/16
 */

#include <array>
#include <iostream>
#include <iomanip>

#include <openssl/md5.h>

std::string md5_hex_digest(const std::string& msg)
{
    auto digest = std::array<unsigned char, MD5_DIGEST_LENGTH>{};
    MD5(reinterpret_cast<const unsigned char*>(msg.c_str()), msg.size(), digest.data());
    auto ss = std::stringstream{};
    for (const auto chr : digest)
        ss << std::hex << std::setfill('0') << std::setw(2) << int{chr};
    return ss.str();
}

int main()
{
    using namespace std::literals::string_literals;
    auto input = "uqwqemis"s;
    auto pw_1 = ""s;
    auto pw_2 = "********"s;
    auto idx = 0;

    while (true) {
        auto guess = input + std::to_string(idx);
        auto md5_guess = md5_hex_digest(guess);
        if (md5_guess.substr(0, 5) == "00000") {
            if (pw_1.size() < 8)
                pw_1 += md5_guess[5];
            auto pos = int{md5_guess[5] - '0'};
            if (pos < 8 && pw_2[pos] == '*')
                pw_2[pos] = md5_guess[6];
            if (pw_1.size() == 8 && pw_2.find('*') == std::string::npos)
                break;
        }
        ++idx;
    }

    std::cout << "Part 1: Password is " << pw_1 << '\n';
    std::cout << "Part 2: Password is " << pw_2 << '\n';
}
