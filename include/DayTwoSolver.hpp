#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Solver.hpp"

class DayTwoSolver: public Solver
{
private:
    std::vector<std::pair<std::string, int>> values;
    std::string fileName;
public:
    DayTwoSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};