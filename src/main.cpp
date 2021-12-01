#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

// #include "DayOneSolver.hpp"
#include "SolverFactory.hpp"

int main(int argc, char** argv) {
    // get current time
    time_t now = time(0);
    tm *date_info = gmtime(&now);
    int monthDay = date_info->tm_mday;

    std::vector<Solver*> solvers;
    SolverFactory solverFactory;
    solvers.push_back(solverFactory.CreateSolver(monthDay));

    for(auto &solver : solvers){
        solver->solve();
    }

    return EXIT_SUCCESS;
}
