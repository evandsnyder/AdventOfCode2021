#include "DaySevenSolver.hpp"

DaySevenSolver::DaySevenSolver(std::string fileName) : fileName(fileName) {}

void DaySevenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DaySevenSolver::readFile()
{
    std::string numbers_string;
    std::ifstream infile(this->fileName);

    infile >> numbers_string;
    size_t pos = 0;
    std::string token;
    std::string delim = ",";
    while ((pos = numbers_string.find(delim)) != std::string::npos)
    {
        token = numbers_string.substr(0, pos);
        this->crabIds.push_back(std::stoi(token));

        numbers_string.erase(0, pos + 1);
    }

    this->crabIds.push_back(std::stoi(numbers_string));
}

void DaySevenSolver::partOne()
{
    // find max
    int minimumFuelCost = INT_MAX;
    int upperBound = 0, lowerBound = INT_MAX;
    for (auto &v : this->crabIds)
    {
        upperBound = std::max(upperBound, v);
        lowerBound = std::min(lowerBound, v);
    }

    for (lowerBound; lowerBound < upperBound; lowerBound++)
    {
        // calculate fuel cost to get to this positio
        int currentFuelCost = 0;
        for (auto &crab : this->crabIds)
        {
            currentFuelCost += std::abs(lowerBound - crab);
        }
        minimumFuelCost = std::min(minimumFuelCost, currentFuelCost);
    }
    std::cout << "Part One Solution: " << minimumFuelCost << std::endl;
}

void DaySevenSolver::partTwo()
{
    // can we calculate the fuel only knowing the distance??
    // find max
    int minimumFuelCost = INT_MAX;
    int upperBound = 0, lowerBound = INT_MAX;
    for (auto &v : this->crabIds)
    {
        upperBound = std::max(upperBound, v);
        lowerBound = std::min(lowerBound, v);
    }

    std::unordered_map<int, int> memory;

    for (lowerBound; lowerBound < upperBound; lowerBound++)
    {
        // calculate fuel cost to get to this positio
        int currentFuelCost = 0;
        for (auto &crab : this->crabIds)
        {
            int steps = std::abs(lowerBound - crab);
            int cost = 0;
            if (memory.find(steps) == memory.end())
            {
                std::cout << "Calculating cost of: " << steps << std::endl;
                // calculate here
                memory[steps] = 0;
                for (int i = 1; i <= steps; i++)
                {
                    memory[steps] += i;
                }
            }

            currentFuelCost += memory[steps];
        }
        minimumFuelCost = std::min(minimumFuelCost, currentFuelCost);
    }

    std::cout << "Part Two Solution: " << minimumFuelCost << std::endl;
}