#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayEighteenSolver: public Solver
{
private:
    std::string fileName;
public:
    DayEighteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};