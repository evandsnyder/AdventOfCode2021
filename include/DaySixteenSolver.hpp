#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "Solver.hpp"

using ull = unsigned long long int;

enum ID
{
    SUM = 0,
    PRODUCT = 1,
    MINIMUM = 2,
    MAXIMUM = 3,
    LITERAL = 4,
    GREATER_THAN = 5,
    LESS_THAN = 6,
    EQUAL_TO = 7
};

class DaySixteenSolver : public Solver
{
private:
    std::string fileName;

    std::string binary;
    int versionNumbers;

public:
    DaySixteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    ull processPacket();
};