#include "DayThirteenSolver.hpp"

DayThirteenSolver::DayThirteenSolver(std::string fileName) : fileName(fileName) {}

void DayThirteenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayThirteenSolver::readFile()
{
    std::ifstream infile(this->fileName);
    // Need to parse pairs and folds first...
    std::string line;
    this->maxX = 0;
    this->maxY = 0;

    std::vector<std::pair<int, int>> coords;
    while (std::getline(infile, line))
    {
        if (line.find("fold") != std::string::npos)
        {
            this->instructions.push_back(line);
            continue;
        }
        if (line.empty())
        {
            continue;
        }

        // Parse a coord, pair here...
        auto seperator = line.find(",");
        auto x = std::stoi(line.substr(0, seperator));
        auto y = std::stoi(line.substr(seperator + 1));
        this->maxX = (x > this->maxX) ? x : this->maxX;
        this->maxY = (y > this->maxY) ? y : this->maxY;
        // How should I store this..?
        coords.emplace_back(x, y);

        // I feel like I should tuck it into a grid...
        // If I want to keep it as just points, how do I
        //  safely iterate and shrink the map..
        // Keeping a list of points won't make it easy to safely iterate
    }
    this->maxX++;
    this->maxY++;

    // create a grid...
    std::vector<bool> t(this->maxX, false);
    this->grid = std::vector<std::vector<bool>>(this->maxY, t);
    for (auto &p : coords)
    {
        this->grid[p.second][p.first] = true;
    }
}

void DayThirteenSolver::partOne()
{
    auto inst = this->instructions[0];
    auto v = std::stoi(inst.substr(13));
    auto grid(this->grid);

    if (inst[11] == 'x')
    {
        // Fold vertically
        for (int leftIndex = v - 1, rightIndex = v + 1;
             leftIndex > -1 && rightIndex < this->maxX;
             leftIndex--, rightIndex++)
        {
            for (int yIndex = 0; yIndex < this->maxY; yIndex++)
            {
                grid[yIndex][leftIndex] = grid[yIndex][leftIndex] || grid[yIndex][rightIndex];
            }
        }

        // Resize the array
        for (auto &r : grid)
        {
            r = std::vector<bool>(r.begin(), r.begin() + v);
        }
    }
    else
    {
        // Fold horizontally...
        for (int topIndex = v - 1, bottomIndex = v + 1;
             topIndex > -1 && bottomIndex < this->maxY;
             topIndex--, bottomIndex++)
        {
            for (int xIndex = 0; xIndex < this->maxX; xIndex++)
            {
                grid[topIndex][xIndex] = grid[topIndex][xIndex] || grid[bottomIndex][xIndex];
            }
        }

        // Need to trim the vector now...
        grid = std::vector<std::vector<bool>>(grid.begin(), grid.begin() + v);
    }

    int count = 0;
    for (auto &r : grid)
    {
        for (auto v : r)
        {
            if (v)
                count++;
        }
    }

    std::cout << "Part One Solution: " << count << std::endl;
}

void DayThirteenSolver::partTwo()
{
    auto grid(this->grid);
    for (std::string &inst : this->instructions)
    {
        int v = std::stoi(inst.substr(13));
        if (inst[11] == 'x')
        {
            // Fold vertically
            for (int leftIndex = v - 1, rightIndex = v + 1;
                 leftIndex > -1 && rightIndex < this->maxX;
                 leftIndex--, rightIndex++)
            {
                for (int yIndex = 0; yIndex < this->maxY; yIndex++)
                {
                    grid[yIndex][leftIndex] = grid[yIndex][leftIndex] || grid[yIndex][rightIndex];
                }
            }

            // Resize the array
            for (auto &r : grid)
            {
                r = std::vector<bool>(r.begin(), r.begin() + v);
            }

            this->maxX = grid[0].size();
        }
        else
        {
            // Fold horizontally...
            for (int topIndex = v - 1, bottomIndex = v + 1;
                 topIndex > -1 && bottomIndex < this->maxY;
                 topIndex--, bottomIndex++)
            {
                for (int xIndex = 0; xIndex < this->maxX; xIndex++)
                {
                    grid[topIndex][xIndex] = grid[topIndex][xIndex] || grid[bottomIndex][xIndex];
                }
            }

            // Need to trim the vector now...
            grid = std::vector<std::vector<bool>>(grid.begin(), grid.begin() + v);
        }

        this->maxY = grid.size();
    }

    for(auto &r : grid){
        for(auto c : r){
            if(c){
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Part Two Solution: " << 0 << std::endl;
}