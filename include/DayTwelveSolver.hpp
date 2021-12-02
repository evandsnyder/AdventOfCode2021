#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayTwelveSolver: public Solver
{
private:
    std::string fileName;
public:
    DayTwelveSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};