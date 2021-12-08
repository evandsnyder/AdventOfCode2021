#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DaySevenSolver: public Solver
{
private:
    std::string fileName;
    std::vector<int> crabIds;
public:
    DaySevenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};