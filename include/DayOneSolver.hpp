#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Solver.hpp"

class DayOneSolver: public Solver
{
private:
    std::vector<int> values;
    std::string fileName;
public:
    DayOneSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};