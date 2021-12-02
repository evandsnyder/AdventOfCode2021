#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayTwentyEightSolver: public Solver
{
private:
    std::string fileName;
public:
    DayTwentyEightSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};