#pragma once

#include "Solver.hpp"
#include "DayOneSolver.hpp"

class SolverFactory
{
public:
    static Solver *CreateSolver(int date);
};