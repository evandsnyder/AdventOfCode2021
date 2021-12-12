#include "DayTwelveSolver.hpp"

DayTwelveSolver::DayTwelveSolver(std::string fileName) : fileName(fileName) {}

void DayTwelveSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayTwelveSolver::readFile()
{
    // keep a std::unordered_map where key is place and
    std::ifstream infile(this->fileName);
    std::string line;
    while (infile >> line)
    {
        auto seperator = line.find('-');
        std::string first(line.begin(), line.begin() + seperator);
        std::string second(line.begin() + 1 + seperator, line.end());

        if (this->caveMap.find(first) == this->caveMap.end())
        {
            this->caveMap[first] = std::set<std::string>();
        }
        this->caveMap[first].insert(second);

        if (this->caveMap.find(second) == this->caveMap.end())
        {
            this->caveMap[second] = std::set<std::string>();
        }
        this->caveMap[second].insert(first);

        if (!isBigCave(first))
        {
            this->smallCaves.insert(first);
        }

        if (!isBigCave(second))
        {
            this->smallCaves.insert(second);
        }
    }
}

void DayTwelveSolver::partOne()
{
    auto result = this->recurseCave("start", std::vector<std::string>());

    std::cout << "Part One Solution: " << result.size() << std::endl;
}

// This method should return a list of all valid connections from here?
std::vector<std::vector<std::string>> DayTwelveSolver::recurseCave(std::string cave, std::vector<std::string> visited)
{
    // If we are at "end" that completes the path regardless of where we are...
    if (cave.compare("end") == 0)
    {
        auto result = std::vector<std::vector<std::string>>();
        result.push_back(std::vector<std::string>());
        result[0].push_back("end");
        return result;
    }

    if (!isBigCave(cave) && std::find(visited.begin(), visited.end(), cave) != visited.end())
    {
        return std::vector<std::vector<std::string>>();
    }

    if (!isBigCave(cave))
    {
        visited.push_back(cave);
    }

    std::vector<std::vector<std::string>> results;
    for (auto &connectedCave : this->caveMap[cave])
    {
        auto result = recurseCave(connectedCave, std::vector<std::string>(visited));
        results.insert(results.end(), result.begin(), result.end());
    }

    // append cave to any values and return?
    for (auto &v : results)
    {
        v.push_back(cave);
    }
    return results;
}

void DayTwelveSolver::partTwo()
{
    // Now a single small cave can be visited twice...
    // All the rest can only be visited once...
    std::unordered_map<std::string, int> visited;
    for (auto &c : this->smallCaves)
    {
        visited[c] = 0;
    }

    auto result = this->partTwoRecurse("start", visited, false);

    std::cout << "Part Two Solution: " << result.size() << std::endl;
}

std::vector<std::vector<std::string>> DayTwelveSolver::partTwoRecurse(std::string cave, std::unordered_map<std::string, int> visited, bool doubleVisited)
{
    // Somehow missing AbAbAcA..
    auto results = std::vector<std::vector<std::string>>();
    if (cave.compare("start") == 0 && visited["start"] == 1)
    {
        return results;
    }
    if (cave.compare("end") == 0)
    {
        results.push_back(std::vector<std::string>());
        results[0].push_back("end");
        return results;
    }

    if (!isBigCave(cave))
    {
        // This is wrong!
        if (doubleVisited && visited[cave] >= 1)
        {
            return results;
        }

        visited[cave]++;
        if(visited[cave] == 2){
            doubleVisited = true;
        }
    }

    for (auto &connectedCave : this->caveMap[cave])
    {
        auto result = partTwoRecurse(connectedCave, std::unordered_map<std::string, int>(visited), doubleVisited);
        results.insert(results.end(), result.begin(), result.end());
    }

    // append cave to any values and return?
    for (auto &v : results)
    {
        v.push_back(cave);
    }
    return results;
}

bool DayTwelveSolver::isBigCave(std::string cave)
{
    // if first character is uppercase, yes it is
    return cave[0] < 'a';
}