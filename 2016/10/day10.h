#ifndef DAY10_H
#define DAY10_H

/*
 * Advent of Code 2016: Day 10
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 05/01/17
 */

#include <limits>
#include <map>
#include <memory>
#include <vector>

class BotNetwork
{
    struct Bot;
    struct Instruction;

public:
    bool bot_exists(const int id) const { return bots_.find(id) != bots_.cend(); }
    void add_bot(const int id) { bots_.insert(std::make_pair(id, std::make_unique<Bot>(id))); }
    void add_val(int id, int val);
    void add_instruction(int src, int dest_lo, int dest_hi, bool lo_out, bool hi_out);
    void execute_instructions();

    int get_p1_ans() const { return p1_ans; }
    int get_p2_ans() const { return outputs_.at(0)[0] * outputs_.at(1)[0] * outputs_.at(2)[0]; }

    friend std::ostream& operator<<(std::ostream& os, const BotNetwork& botnet);

private:
    std::map<int, std::unique_ptr<Bot>> bots_;
    std::map<int, std::pair<int, int>> compare_;
    std::map<int, std::vector<int>> outputs_;
    std::vector<std::unique_ptr<Instruction>> instructions_;

    int p1_ans;

    struct Bot
    {
        Bot (const int id) : id_{id} { }
        bool is_filled() const;
        void reset();
        int id_;
        int lo_{std::numeric_limits<int>::max()};
        int hi_{std::numeric_limits<int>::min()};
    };

    struct Instruction
    {
        Instruction (const int src, const int dest_lo, const int dest_hi, 
                const bool lo_out, const bool hi_out) :
                src_{src}, dest_lo_{dest_lo}, dest_hi_{dest_hi}, 
                lo_out_{lo_out}, hi_out_{hi_out} { }
        int src_;
        int dest_lo_;
        int dest_hi_;
        bool lo_out_;
        bool hi_out_;
        bool executed_{false};
    };
};

std::ostream& operator<<(std::ostream& os, const BotNetwork& botnet);

#endif
