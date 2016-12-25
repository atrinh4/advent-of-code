/*
 * Advent of Code 2016: Day 01
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 24/12/16
 */

#include <algorithm>
#include <fstream>
#include <iostream>

#include "day01.h"

void Location::turn_left()
{
    switch (dir_) {
        case Direction::north: dir_ = Direction::west; break;
        case Direction::south: dir_ = Direction::east; break;
        case Direction::east: dir_ = Direction::north; break;
        case Direction::west: dir_ = Direction::south; break;
    }
}

void Location::turn_right()
{
    switch (dir_) {
        case Direction::north: dir_ = Direction::east; break;
        case Direction::south: dir_ = Direction::west; break;
        case Direction::east: dir_ = Direction::south; break;
        case Direction::west: dir_ = Direction::north; break;
    }
}

void Location::move_forward(int blocks)
{
    for (auto i = 0; i < blocks; ++i) {
        switch (dir_) {
            case Direction::north: ++y_; break;
            case Direction::south: --y_; break;
            case Direction::east: ++x_; break;
            case Direction::west: --x_; break;
        }

        auto it = std::find_if(visited_.cbegin(), visited_.cend(),
                [this] (const auto& coord) { return coord.first == x_ && coord.second == y_; });
        auto coord = std::make_pair(x_, y_);
        if (it != visited_.cend())
            visited_twice_.push_back(coord);
        visited_.push_back(coord);
    }
}

int main()
{
    std::string instruction;
    auto loc = Location();
    auto infile = std::ifstream("input.txt");

    while (std::getline(infile, instruction, ',')) {
        infile.ignore(); 
        auto turn = instruction.front(); 
        instruction.erase(0, 1);
        auto blocks = std::stoi(instruction);
        turn == 'L' ? loc.turn_left() : loc.turn_right();
        loc.move_forward(blocks);
    }

    std::cout << "Part 1: Easter Bunny HQ is "
              << std::abs(loc.get_x()) + std::abs(loc.get_y())
              << " blocks away\n";    
    std::cout << "Part 2: The first location visited twice is "
              << std::abs(loc.get_visited_twice().front().first) + 
                 std::abs(loc.get_visited_twice().front().second)
              << " blocks away\n";
}
