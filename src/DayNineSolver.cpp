#include "DayNineSolver.hpp"

DayNineSolver::DayNineSolver(std::string fileName) : fileName(fileName) {}

void DayNineSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayNineSolver::readFile()
{
    // We should read the data as an int of ints vector
    std::ifstream infile(this->fileName);
    std::string line;
    while (infile >> line)
    {
        std::vector<int> row;
        for (auto &c : line)
        {
            row.push_back(c - '0');
        }
        this->lavaMap.push_back(row);
    }

    this->rowSize = this->lavaMap[0].size();
    this->colSize = this->lavaMap.size();
}

void DayNineSolver::partOne()
{
    int rowSize = this->lavaMap[0].size();
    int cols = this->lavaMap.size();
    int knownRisk = 0;

    for (auto &point : findLowestPoints())
    {
        knownRisk += 1 + this->lavaMap[point.first][point.second];
    }

    std::cout << "Part One Solution: " << knownRisk << std::endl;
}

void DayNineSolver::partTwo()
{
    auto lowPoints = findLowestPoints();
    std::cout << "Number of basins: " << lowPoints.size() << std::endl;

    // start searching outwards until we find the 9s ?
    std::vector<int> allBasins;
    std::unordered_map<int, std::unordered_map<int, bool>> visited;
    for (auto &point : lowPoints)
    {
        allBasins.push_back(findBasinSize(point.first, point.second, &visited));
    }

    std::sort(allBasins.rbegin(), allBasins.rend());
    int result = allBasins[0] * allBasins[1] * allBasins[2];

    std::cout << "Part Two Solution: " << result << std::endl;
}

int DayNineSolver::findBasinSize(int y, int x, std::unordered_map<int, std::unordered_map<int, bool>> *visited)
{
    if (y < 0 || y >= this->colSize)
    {
        return 0;
    }

    if (x < 0 || x >= this->rowSize)
    {
        return 0;
    }
    // is this a valid value?
    if (this->lavaMap[y][x] == 9)
        return 0;

    // Have we already visited??
    if(visited->find(y) != visited->end()){
        auto &map = *visited;
        if(map[y].find(x) != map[y].end()){
            return 0;
        }
    } else {
        (*visited)[y] = std::unordered_map<int, bool>();
    }

    (*visited)[y][x] = true;

    return 1 +
           findBasinSize(y + 1, x, visited) +
           findBasinSize(y - 1, x, visited) +
           findBasinSize(y, x + 1, visited) +
           findBasinSize(y, x - 1, visited);
}

std::vector<std::pair<int, int>> DayNineSolver::findLowestPoints()
{
    std::vector<std::pair<int, int>> result;

    int rowSize = this->lavaMap[0].size();
    int cols = this->lavaMap.size();

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            int location = this->lavaMap[i][j];
            bool lowest = true;
            // Check north
            if (i > 0 && this->lavaMap[i - 1][j] <= location)
            {
                lowest = false;
            }

            if (i < cols - 1 && this->lavaMap[i + 1][j] <= location)
            {
                lowest = false;
            }

            // Check east
            if (j < rowSize - 1 && this->lavaMap[i][j + 1] <= location)
            {
                lowest = false;
            }

            if (j > 0 && this->lavaMap[i][j - 1] <= location)
            {
                lowest = false;
            }

            if (lowest)
            {
                result.emplace_back(i, j);
            }
        }
    }

    return result;
}