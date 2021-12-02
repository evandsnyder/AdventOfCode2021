#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayTwentyThreeSolver: public Solver
{
private:
    std::string fileName;
public:
    DayTwentyThreeSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};