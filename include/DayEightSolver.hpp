#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <set>

#include "Solver.hpp"

class DayEightSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::pair<std::string, std::string>> data;
public:
    DayEightSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    void parseData(std::string data);
    std::vector<std::string> parseEntry(std::string data);
};