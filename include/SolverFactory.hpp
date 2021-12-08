#pragma once

#include "Solver.hpp"
#include "DayOneSolver.hpp"
#include "DayTwoSolver.hpp"
#include "DayThreeSolver.hpp"
#include "DayFourSolver.hpp"
#include "DayFiveSolver.hpp"
#include "DaySixSolver.hpp"
#include "DaySevenSolver.hpp"
#include "DayEightSolver.hpp"
#include "DayNineSolver.hpp"
#include "DayTenSolver.hpp"
#include "DayElevenSolver.hpp"
#include "DayTwelveSolver.hpp"
#include "DayThirteenSolver.hpp"
#include "DayFourteenSolver.hpp"
#include "DayFifteenSolver.hpp"
#include "DaySixteenSolver.hpp"
#include "DaySeventeenSolver.hpp"
#include "DayEighteenSolver.hpp"
#include "DayNineteenSolver.hpp"
#include "DayTwentySolver.hpp"
#include "DayTwentyOneSolver.hpp"
#include "DayTwentyTwoSolver.hpp"
#include "DayTwentyThreeSolver.hpp"
#include "DayTwentyFourSolver.hpp"
#include "DayTwentyFiveSolver.hpp"

class SolverFactory
{
public:
    static Solver *CreateSolver(int date);
};