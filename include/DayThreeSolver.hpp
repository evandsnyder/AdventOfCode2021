#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DayThreeSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::string> values;
    std::string gamma;
public:
    DayThreeSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

private:
    int BinaryToInt(std::string binary);
};