#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Solver.hpp"

class DayOneSolver: public Solver
{
private:
    std::vector<int> values;
public:
    DayOneSolver(std::string inputFilename);
    void solve();

protected:
    void partOne();
    void partTwo();
};