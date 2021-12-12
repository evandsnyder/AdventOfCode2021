#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

#include "Solver.hpp"

class DayTwelveSolver : public Solver
{
private:
    std::string fileName;
    std::unordered_map<std::string, std::set<std::string>> caveMap;
    std::set<std::string> smallCaves;

public:
    DayTwelveSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    bool isBigCave(std::string cave);
    std::vector<std::vector<std::string>> recurseCave(std::string cave, std::vector<std::string> visited);
    std::vector<std::vector<std::string>> partTwoRecurse(std::string cave, std::unordered_map<std::string, int> visited, bool doubleVisited);
};