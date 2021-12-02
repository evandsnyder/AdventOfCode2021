#include "DayTwoSolver.hpp"

DayTwoSolver::DayTwoSolver(std::string fileName) : fileName(fileName) {}

void DayTwoSolver::solve(){
    readFile();
    partOne();
    partTwo();
}

void DayTwoSolver::readFile(){
    std::ifstream infile(this->fileName);
    int t;
    std::string action;

    while(infile >> action >> t){
        this->values.emplace_back(action, t);
    }
    infile.close();
}

void DayTwoSolver::partOne(){
    int depth = 0, horizontal = 0;
    for(auto &action : this->values){
        if(action.first.compare("forward") == 0){
            horizontal += action.second;
        } else if(action.first.compare("down") == 0){
            depth += action.second;
        }else if(action.first.compare("up") == 0){
            depth -= action.second;
        }
    }

    std::cout << "Part One Solution: " << horizontal*depth << std::endl;
}

void DayTwoSolver::partTwo(){
    int depth = 0, horizontal = 0, aim = 0;
    for(auto &action : this->values){
        if(action.first.compare("forward") == 0){
            horizontal += action.second;
            depth += aim * action.second;
        } else if(action.first.compare("down") == 0){
            aim += action.second;
        }else if(action.first.compare("up") == 0){
            aim -= action.second;
        }
    }

    std::cout << "Part Two Solution: " << horizontal*depth << std::endl;
}