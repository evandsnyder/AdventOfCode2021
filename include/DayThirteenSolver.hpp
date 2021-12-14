#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DayThirteenSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::string> instructions;
    int maxX;
    int maxY;
    std::vector<std::vector<bool>> grid;

public:
    DayThirteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    void fold();
};