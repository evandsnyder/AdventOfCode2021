#include "DaySixSolver.hpp"

DaySixSolver::DaySixSolver(std::string fileName) : fileName(fileName) {}

void DaySixSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DaySixSolver::readFile()
{
    std::string numbers_string;
    std::ifstream infile(this->fileName);
    std::string action;

    infile >> numbers_string;
    size_t pos = 0;
    std::string token;
    std::string delim = ",";
    int fish_id;
    while ((pos = numbers_string.find(delim)) != std::string::npos)
    {
        token = numbers_string.substr(0, pos);
        fish_id = std::stol(token);
        if (this->fish_count.find(fish_id) == this->fish_count.end())
        {
            this->fish_count[fish_id] = 0;
        }
        this->fish_count[fish_id] += 1;
        numbers_string.erase(0, pos + 1);
    }

    fish_id = std::stol(numbers_string);
    if (this->fish_count.find(fish_id) == this->fish_count.end())
    {
        this->fish_count[fish_id] = 0;
    }
    this->fish_count[fish_id] += 1;
}

void DaySixSolver::partOne()
{
    std::cout << "Part One Solution: " << simulateFish(80) << std::endl;
}

long DaySixSolver::simulateFish(int numberOfDays)
{
    long fishies[9] = {0};
    for(auto &[k,v] : this->fish_count){
        fishies[k] = v;
    }
    for(int day = 0; day < numberOfDays; day++){
        long newFishies = fishies[0];
        // Iterate over fishes...
        // Need to move all down to 
        for(int i = 1; i < 9; i++){
            fishies[i-1] = fishies[i];
        }
        fishies[6] += newFishies;
        fishies[8] = newFishies;
    }
    long fishSum = 0;
    for(auto& fish : fishies){
        fishSum += fish;
    }

    return fishSum;
}

void DaySixSolver::partTwo()
{
    std::cout << "Part Two Solution: " << simulateFish(256) << std::endl;
}