#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DayFourteenSolver: public Solver
{
private:
    std::string fileName;
    std::string polymerTemplate;
    std::unordered_map<std::string, std::string> rules;

    std::unordered_map<std::string, long> pairs;
    std::unordered_map<char, long> count;
public:
    DayFourteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    long evaluatePolymer(int steps);
};