#include <iostream>
#include <vector>

#include "DayOneSolver.hpp"

int main(int, char**) {
    std::vector<Solver*> solvers;

    solvers.push_back(new DayOneSolver("../resources/day_one_input.txt"));

    for(auto &solver : solvers){
        solver->solve();
    }

    return EXIT_SUCCESS;
}
