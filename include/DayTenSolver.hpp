#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

#include "Solver.hpp"

class DayTenSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::string> input;
    std::vector<std::stack<char>> incompleteStrings;
public:
    DayTenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    void useSample();
};