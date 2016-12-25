/*
 * Advent of Code 2016: Day 03
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 25/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

inline bool is_valid_triangle(int a, int b, int c)
{
    return (a + b > c && a + c > b && b + c > a);
}

int main()
{
    auto a = 0;
    auto b = 0;
    auto c = 0;
    auto num_valid_horiz = 0;
    auto num_valid_verti = 0;
    auto triangles = std::vector<std::vector<int>>{};
    auto infile = std::ifstream{"input.txt"}; 

    while (infile >> a >> b >> c)
        triangles.push_back({a, b, c});

    for (auto sides : triangles)
        if (is_valid_triangle(sides[0], sides[1], sides[2]))
            ++num_valid_horiz;

    for (auto row = 0U; row < triangles.size(); row += 3)
        for (auto col = 0U; col < triangles[row].size(); ++col)
            if (is_valid_triangle(triangles[row][col], triangles[row + 1][col], triangles[row + 2][col]))
                ++num_valid_verti;

    std::cout << "Part 1: " <<  num_valid_horiz << " valid triangles\n";
    std::cout << "Part 2: " <<  num_valid_verti << " valid triangles\n";
}
