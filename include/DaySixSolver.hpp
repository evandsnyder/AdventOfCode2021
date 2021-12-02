#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DaySixSolver: public Solver
{
private:
    std::string fileName;
public:
    DaySixSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};