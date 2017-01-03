#ifndef DAY08_H
#define DAY08_H

/*
 * Advent of Code 2016: Day 08
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 28/12/16
 */

#include <vector>

class Screen
{
public:
    int num_pixels_on() const;
    void rect(int width, int height);
    void rotate_row(int row, int shift);
    void rotate_col(int col, int shift);

    friend std::ostream& operator<<(std::ostream& os, const Screen& screen);

private:
    std::vector<std::vector<bool>> scr_{6, std::vector<bool>(50)};
};

std::ostream& operator<<(std::ostream& os, const Screen& screen);

#endif
