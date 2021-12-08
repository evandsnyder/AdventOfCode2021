#include <iostream>
#include <vector>
#include <ctime>

#include "SolverFactory.hpp"

int main(int argc, char **argv)
{
    std::vector<Solver *> solvers;
    SolverFactory solverFactory;

    if (strcmp(argv[1],"-a") == 0)
    {
        // Run all challenges...
        for (int i = 1; i < 26; i++)
        {
            solvers.push_back(solverFactory.CreateSolver(i));
        }
    } else if(argc >= 2){
        // convert to int and add to solver...
        for(int i = 1; i < argc; i++){
            solvers.push_back(solverFactory.CreateSolver(atoi(argv[i])));
        }
    }
    else
    {
        // get current time
        time_t now = time(0);
        tm *date_info = gmtime(&now);
        int monthDay = date_info->tm_mday;

        solvers.push_back(solverFactory.CreateSolver(monthDay));
    }

    for (auto &solver : solvers)
    {
        solver->solve();
    }

    return EXIT_SUCCESS;
}
