#pragma once

#include "Solver.hpp"
#include "DayOneSolver.hpp"
#include "DayTwoSolver.hpp"

class SolverFactory
{
public:
    static Solver *CreateSolver(int date);
};