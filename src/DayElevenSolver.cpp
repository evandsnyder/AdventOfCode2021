#include "DayElevenSolver.hpp"

DayElevenSolver::DayElevenSolver(std::string fileName) : fileName(fileName) {}

void DayElevenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayElevenSolver::readFile()
{
    std::ifstream infile(this->fileName);
    std::string line;
    while (infile >> line)
    {
        std::vector<int> row;
        for (char &c : line)
        {
            row.push_back(c - '0');
        }
        this->grid.push_back(row);
    }
}

void DayElevenSolver::partOne()
{
    int flashes = 0;
    for (int i = 0; i < 100; i++)
    {
        flashes += step();
    }

    std::cout << "Part One Solution: " << flashes << std::endl;
}

/**
 * @brief This function executes one step of flashing. Every octopus charges 1
 * Then any flashing octopi are evaluated and their neighbors are checked
 * 
 * @return int the number of flashes that occur during this step
 */
int DayElevenSolver::step()
{
    std::set<std::pair<int, int>> tens;
    for (int i = 0; i < this->grid.size(); i++)
    {
        for (int j = 0; j < this->grid[0].size(); j++)
        {
            this->grid[i][j]++;
            if (this->grid[i][j] > 9)
            {
                tens.insert(std::make_pair(i, j));
            }
        }
    }

    std::set<std::pair<int, int>> reset;

    while (tens.size() > 0)
    {
        auto it = tens.begin();
        while (it != tens.end())
        {
            auto &p = *it;
            // This point needs to go into reset
            reset.insert(p);

            // We need to increment all 8 neighbors!
            for (int i = p.first - 1; i < p.first + 2; i++)
            {
                for (int j = p.second - 1; j < p.second + 2; j++)
                {
                    if (i == p.first && j == p.second)
                        continue;
                    if (incrementNeighbor(i, j, &reset))
                    {
                        tens.insert(std::make_pair(i, j));
                    }
                }
            }
            it = tens.erase(it);
        }
    }

    int flashes = reset.size();

    for (auto &p : reset)
    {
        this->grid[p.first][p.second] = 0;
    }

    return flashes;
}

/**
 * @brief This function evaluates a single cell in the grid and should
 * be used to check all 8 neighbors of a given flashing target
 * 
 * @param i y coordinate in the grid
 * @param j x coordinate in the grid
 * @param reset set of coordinate that have already been visited
 * @return true if this new value should be flashed during this step
 * @return false if this value should not be flashed during this step
 */
bool DayElevenSolver::incrementNeighbor(int i, int j, std::set<std::pair<int, int>> *reset)
{
    if (i < 0 || j < 0 || i >= this->grid.size() || j >= this->grid[0].size())
        return false;
    this->grid[i][j]++;

    // If greater than 9 and we haven't seen it,
    if (this->grid[i][j] > 9 && reset->find(std::make_pair(i, j)) == reset->end())
    {
        return true;
    }
    return false;
}

void DayElevenSolver::partTwo()
{
    // We can start at 101, because we've already done 101 steps..
    int flashes, counter = 101;
    while ((flashes = step()) != 100)
    {
        counter++;
    }

    std::cout << "Part Two Solution: " << counter << std::endl;
}