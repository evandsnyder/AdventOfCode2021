#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayTwentySevenSolver: public Solver
{
private:
    std::string fileName;
public:
    DayTwentySevenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};