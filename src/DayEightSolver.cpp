#include "DayEightSolver.hpp"

DayEightSolver::DayEightSolver(std::string fileName) : fileName(fileName) {}

void DayEightSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayEightSolver::readFile()
{
    // Split on | and then on ' '
    std::ifstream infile(this->fileName);
    std::string data;

    while (getline(infile, data))
    {
        parseData(data);
    }
    infile.close();
}

void DayEightSolver::parseData(std::string data)
{
    size_t pos = 0;
    std::string token;
    std::string delim = "|";
    std::pair<std::string, std::string> entry;
    while ((pos = data.find(delim)) != std::string::npos)
    {
        token = data.substr(0, pos);
        entry.first = token;
        data.erase(0, pos + 1);
    }

    entry.second = data;
    this->data.push_back(entry);
}

std::vector<std::string> DayEightSolver::parseEntry(std::string data){
    std::istringstream ss(data);
    std::string e;
    std::vector<std::string> result;
    while(ss >> e){
        result.push_back(e);
    }

    return result;
}

void DayEightSolver::partOne()
{
    // Need to parse into 10 and 4 ?
    // Need to map the strings to integers...
    // What points to what???
    // Start with the unique values...
    int totalUnique = 0;
    for(auto& pair : this->data){
        auto output = parseEntry(pair.second);

        // If there is a string of length 2, it must be 1
        // If there is a string of length 3, it must be 7
        // if there is a string of length 4, it must be 4
        // if there is a string of length 7, it must be 8
        
        // Find count of output values where length is 2,3,4, or 7
        for(auto &e : output){
            switch(e.length()){
                case 2:
                case 3:
                case 4:
                case 7:
                    totalUnique++;
                    break;
                default:
                    break;
            }
        }
    }
    


    std::cout << "Part One Solution: " << totalUnique << std::endl;
}

void DayEightSolver::partTwo()
{

    std::cout << "Part Two Solution: " << 0 << std::endl;
}