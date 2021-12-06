#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DaySixSolver: public Solver
{
private:
    std::string fileName;
    std::unordered_map<long, long> fish_count;
public:
    DaySixSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    long simulateFish(int numberOfDays);
};