#ifndef DAY01_H
#define DAY01_H

/*
 * Advent of Code 2016: Day 01
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 24/12/16
 */

#include <vector>

enum class Direction { north, east, south, west };

class Location
{
public:
    int get_x() const { return x_; }
    int get_y() const { return y_; }
    const std::vector<std::pair<int, int>>& get_visited_twice() const { return visited_twice_; }
    void turn_left();
    void turn_right();
    void move_forward(int blocks);
private:
    Direction dir_{Direction::north};
    int x_;
    int y_;
    std::vector<std::pair<int, int>> visited_;
    std::vector<std::pair<int, int>> visited_twice_;
};

#endif
