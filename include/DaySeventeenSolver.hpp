#pragma once

#include <iostream>
#include <fstream>

#include "Solver.hpp"

class DaySeventeenSolver: public Solver
{
private:
    std::string fileName;
    int minimumXTarget = 235;
    int maximumXTarget = 259;
    int minimumYTarget = -62;
    int maximumYTarget = -118;

    int currentXVelocity = 0;
    int currentYVelocity = 0;
    int currentXPosition = 0;
    int currentYPosition = 0;


public:
    DaySeventeenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    void step();
    void reset();

    bool simulate();
};