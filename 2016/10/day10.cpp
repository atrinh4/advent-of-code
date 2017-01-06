/*
 * Advent of Code 2016: Day 10
 * Alex Trinh (alex.trinh4@gmail.com)
 * https://github.com/atrinh4/
 * 05/01/17
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>

#include "day10.h"

void BotNetwork::add_val(const int id, const int val)
{
    if (bots_.find(id) == bots_.cend()) return;
    auto& lo = bots_[id]->lo_;
    auto& hi = bots_[id]->hi_;
    if (val < lo) {
        if (lo != std::numeric_limits<int>::max()) hi = lo;
        lo = val;
    } else if (val > hi) {
        if (hi != std::numeric_limits<int>::min()) lo = hi; 
        hi = val;
    }
}

void BotNetwork::add_instruction(const int src, const int dest_lo, 
        const int dest_hi, const bool lo_out, const bool hi_out)
{
    instructions_.push_back(std::make_unique<Instruction>(src, dest_lo, dest_hi, lo_out, hi_out));
}

void BotNetwork::execute_instructions()
{
    auto itr = instructions_.begin();
    while (!instructions_.empty()) {
        if (itr == instructions_.end()) itr = instructions_.begin();
        const auto& inst = *itr;
        const auto& bot = bots_.find(inst->src_)->second;
        if (bot->is_filled()) {
            if (bot->lo_ == 17 && bot->hi_ == 61) p1_ans = bot->id_;
            if (!inst->lo_out_)
                add_val(inst->dest_lo_, bot->lo_);
            else
                outputs_[inst->dest_lo_].push_back(bot->lo_);
            if (!inst->hi_out_)
                add_val(inst->dest_hi_, bot->hi_);
            else
                outputs_[inst->dest_hi_].push_back(bot->hi_);
            bot->reset();
            itr = instructions_.erase(itr);
        } else { ++itr; }
    }
}

bool BotNetwork::Bot::is_filled() const
{ 
    return lo_ != std::numeric_limits<int>::max() && hi_ != std::numeric_limits<int>::min(); 
}

void BotNetwork::Bot::reset()
{
    lo_ = std::numeric_limits<int>::max();
    hi_ = std::numeric_limits<int>::min();
}

std::ostream& operator<<(std::ostream& os, const BotNetwork& botnet)
{
    os << "Output Bins\n-----------\n";
    for (const auto& out : botnet.outputs_) {
        os << out.first << ": ";
        std::copy(out.second.cbegin(), out.second.cend() - 1,
                std::ostream_iterator<int>(os, ", "));
        os << *(out.second.cend() - 1);
        if (out != *(botnet.outputs_.crbegin())) os << '\n';
    }
    return os;
}

int main()
{
    using namespace std::literals::string_literals;
    auto line = ""s;
    auto infile = std::ifstream{"input.txt"};
    const auto value_regex = std::regex{R"(value (\d+) goes to bot (\d+))"};
    const auto give_regex = std::regex{R"(bot (\d+) gives low to (\w+) (\d+) and high to (\w+) (\d+))"};
    auto match = std::smatch{};
    auto botnet = BotNetwork{};
    
    while (std::getline(infile, line)) {
        if (std::regex_match(line, match, value_regex)) {
            auto val = std::stoi(match.str(1));
            auto id = std::stoi(match.str(2));
            if (!botnet.bot_exists(id)) botnet.add_bot(id);
            botnet.add_val(id, val);
        } else if (std::regex_match(line, match, give_regex)) {
            auto src = std::stoi(match.str(1));
            auto lo_dest = std::stoi(match.str(3));
            auto hi_dest = std::stoi(match.str(5));
            auto lo_out = match.str(2) == "output";
            auto hi_out = match.str(4) == "output";
            if (!botnet.bot_exists(src)) botnet.add_bot(src);
            botnet.add_instruction(src, lo_dest, hi_dest, lo_out, hi_out);
        } 
    }

    botnet.execute_instructions();
    // std::cout << botnet << '\n';
    
    std::cout << "-- Day 10 --\n";
    std::cout << "Part 1: " << botnet.get_p1_ans() << '\n';
    std::cout << "Part 2: " << botnet.get_p2_ans() << '\n';
}
