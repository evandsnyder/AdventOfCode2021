#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#include "Solver.hpp"

class DayElevenSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::vector<int>> grid;
public:
    DayElevenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    int step();
    bool incrementNeighbor(int i, int j, std::set<std::pair<int, int>> *reset);
};