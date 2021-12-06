#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <sstream>

#include "Solver.hpp"

struct Line
{
    int startX {0}, startY {0};
    int endX {0}, endY {0};
    Line(int startX, int startY, int endX, int endY);
};

class DayFiveSolver : public Solver
{
private:
    std::string fileName;
    std::vector<Line> lines;

public:
    DayFiveSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    bool isDiagonal(Line line);
    std::string printLine(Line line);
    std::vector<std::pair<int, int>> getDiagonalPoints(Line line);
};