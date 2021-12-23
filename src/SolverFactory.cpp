#include "SolverFactory.hpp"

Solver *SolverFactory::CreateSolver(int date)
{
    switch (date)
    {
    case 1:
        return new DayOneSolver("../resources/day_one_input.txt");
    case 2:
        return new DayTwoSolver("../resources/day_two_input.txt");
    case 3:
        return new DayThreeSolver("../resources/day_three_input.txt");
    case 4:
        return new DayFourSolver("../resources/day_four_input.txt");
    case 5:
        return new DayFiveSolver("../resources/day_five_input.txt");
    case 6:
        return new DaySixSolver("../resources/day_six_input.txt");
    case 7:
        return new DaySevenSolver("../resources/day_seven_input.txt");
    case 8:
        return new DayEightSolver("../resources/day_eight_input.txt");
    case 9:
        return new DayNineSolver("../resources/day_nine_input.txt");
    case 10:
        return new DayTenSolver("../resources/day_ten_input.txt");
    case 11:
        return new DayElevenSolver("../resources/day_eleven_input.txt");
    case 12:
        return new DayTwelveSolver("../resources/day_twelve_input.txt");
    case 13:
        return new DayThirteenSolver("../resources/day_thirteen_input.txt");
    case 14:
        return new DayFourteenSolver("../resources/day_fourteen_input.txt");
    case 15:
        return new DayFifteenSolver("../resources/day_fifteen_input.txt");
    case 16:
        return new DaySixteenSolver("../resources/day_sixteen_input.txt");
    case 17:
        return new DaySeventeenSolver("../resources/day_seventeen_input.txt");
    case 18:
        return new DayEighteenSolver("../resources/day_eighteen_input.txt");
    case 19:
        return new DayNineteenSolver("../resources/day_nineteen_input.txt");
    case 20:
        return new DayTwentySolver("../resources/day_twenty_input.txt");
    case 21:
        return new DayTwentyOneSolver("../resources/day_twentyone_input.txt");
    case 22:
        return new DayTwentyTwoSolver("../resources/day_twentytwo_input.txt");
    case 23:
        return new DayTwentyThreeSolver("../resources/day_twentythree_input.txt");
    case 24:
        return new DayTwentyFourSolver("../resources/day_twentyfour_input.txt");
    case 25:
        return new DayTwentyFiveSolver("../resources/day_twentyfive_input.txt");
    default:
        break;
    }

    return nullptr;
}