#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DayThirtySolver: public Solver
{
private:
    std::string fileName;
public:
    DayThirtySolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;
};