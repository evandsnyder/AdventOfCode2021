#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Solver.hpp"

using Board = std::vector<std::vector<std::pair<int, bool>>>;

class DayFourSolver: public Solver
{
private:
    std::string fileName;
    std::vector<int> numbers;
    std::vector<Board> boards;

public:
    DayFourSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

private:
    Board createBoard(const std::vector<int> values);
    void printBoard(Board board);

    bool isBoardSolved(Board board);
    int findSumOfBoard(Board board);
};