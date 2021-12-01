#include "DayOneSolver.hpp"

DayOneSolver::DayOneSolver(std::string fileName) : fileName(fileName){}

void DayOneSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayOneSolver::readFile(){
    std::ifstream infile(this->fileName);
    int t;
    while(infile >> t){
        this->values.push_back(t);
    }
    infile.close();
}

void DayOneSolver::partOne()
{
    int currentValue = -1;
    int increasedCount = -1;

    for(int &t : this->values){
        if( t > currentValue) increasedCount++;
        currentValue = t;
    }

    std::cout << "Part 1 Solution: " << increasedCount << std::endl;
}

void DayOneSolver::partTwo(){
    // create iterator -2
    int increasedCount = -1;
    int currentValue = -1;
    
    for(std::vector<int>::iterator it = this->values.begin(); it != this->values.end() -2; it++){
        int sum = *it + *(it+1) + *(it+2);
        if(sum > currentValue) increasedCount++;
        currentValue = sum;
    }

    std::cout << "Part 2 Solution: " << increasedCount << std::endl;
}