#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DaySixteenSolver: public Solver
{
private:
    std::string fileName;
public:
    DaySixteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};