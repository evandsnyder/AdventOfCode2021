#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "Solver.hpp"

class DayNineSolver: public Solver
{
private:
    std::string fileName;
    std::vector<std::vector<int>> lavaMap;
    int rowSize, colSize;
public:
    DayNineSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    std::vector<std::pair<int, int>> findLowestPoints();
    int findBasinSize(int y, int x, std::unordered_map<int, std::unordered_map<int, bool>> *visited);
};