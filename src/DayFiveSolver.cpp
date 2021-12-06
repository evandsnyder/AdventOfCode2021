#include "DayFiveSolver.hpp"

DayFiveSolver::DayFiveSolver(std::string fileName) : fileName(fileName) {}
Line::Line(int startX, int startY, int endX, int endY)
    : startX(startX), startY(startY), endX(endX), endY(endY) {}

void DayFiveSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayFiveSolver::readFile()
{
    FILE *file;
    file = fopen(this->fileName.c_str(), "r");
    int sX, sY, eX, eY;
    while ((fscanf(file, "%d,%d -> %d,%d", &sX, &sY, &eX, &eY)) != EOF)
    {
        this->lines.emplace_back(sX, sY, eX, eY);
    }
    fclose(file);
}

void DayFiveSolver::partOne()
{
    // [x],[y],[crossed]
    std::unordered_map<int, std::unordered_map<int, int>> grid;
    for (auto &line : this->lines)
    {
        // Okay, how do we actually find all the points on a line...
        if (isDiagonal(line))
        {
            continue;
        }

        // std::cout << "Evaluating: " << printLine(line) << std::endl;

        int start, end, step;
        if (line.startX == line.endX)
        {
            // Only the Y values change
            step = line.startY > line.endY ? -1 : 1;
            int x = line.startX;
            end = line.endY + step;
            // check if x exists in map
            if (grid.find(x) == grid.end())
            {
                grid[x] = std::unordered_map<int, int>();
            }

            for (int y = line.startY; y != end; y += step)
            {
                // std::cout << "point: (" << x << "," << y << ")\n";
                if (grid[x].find(y) == grid[x].end())
                {
                    grid[x][y] = 0;
                }
                grid[x][y] += 1;
            }
        }
        else
        {
            // Only the x values change
            step = line.startX > line.endX ? -1 : 1;
            int y = line.startY;
            end = line.endX + step;

            for (int x = line.startX; x != end; x += step)
            {
                if (grid.find(x) == grid.end())
                {
                    grid[x] = std::unordered_map<int, int>();
                    grid[x][y] = 0;
                }
                grid[x][y] += 1;
            }
        }
    }

    int total = 0;
    for (auto &[key, value] : grid)
    {
        for (auto &[k, v] : value)
        {
            if (v > 1)
                total++;
        }
    }

    std::cout << "Part One Solution: " << total << std::endl;
}

bool DayFiveSolver::isDiagonal(Line line)
{
    return !(line.startX == line.endX || line.startY == line.endY);
}

void DayFiveSolver::partTwo()
{
    // [x],[y],[crossed]
    std::unordered_map<int, std::unordered_map<int, int>> grid;
    for (auto &line : this->lines)
    {
        // Okay, how do we actually find all the points on a line...
        if (isDiagonal(line))
        {
            // Get diagonal points...
            auto points = getDiagonalPoints(line);
            for (auto &point : points)
            {
                int x = point.first;
                int y = point.second;
                if (grid.find(x) == grid.end())
                {
                    grid[x] = std::unordered_map<int, int>();
                }
                if (grid[x].find(y) == grid[x].end())
                {
                    grid[x][y] = 0;
                }
                grid[x][y] += 1;
            }
            continue;
        }

        // std::cout << "Evaluating: " << printLine(line) << std::endl;

        int start, end, step;
        if (line.startX == line.endX)
        {
            // Only the Y values change
            step = line.startY > line.endY ? -1 : 1;
            int x = line.startX;
            end = line.endY + step;
            // check if x exists in map
            if (grid.find(x) == grid.end())
            {
                grid[x] = std::unordered_map<int, int>();
            }

            for (int y = line.startY; y != end; y += step)
            {
                // std::cout << "point: (" << x << "," << y << ")\n";
                if (grid[x].find(y) == grid[x].end())
                {
                    grid[x][y] = 0;
                }
                grid[x][y] += 1;
            }
        }
        else
        {
            // Only the x values change
            step = line.startX > line.endX ? -1 : 1;
            int y = line.startY;
            end = line.endX + step;

            for (int x = line.startX; x != end; x += step)
            {
                if (grid.find(x) == grid.end())
                {
                    grid[x] = std::unordered_map<int, int>();
                    grid[x][y] = 0;
                }
                grid[x][y] += 1;
            }
        }
    }

    int total = 0;
    for (auto &[key, value] : grid)
    {
        for (auto &[k, v] : value)
        {
            if (v > 1)
                total++;
        }
    }

    std::cout << "Part Two Solution: " << total << std::endl;
}

std::string DayFiveSolver::printLine(Line line)
{
    std::stringstream ss;
    ss << "(" << line.startX << "," << line.startY << ") -> (" << line.endX << "," << line.endY << ")";
    return ss.str();
}

std::vector<std::pair<int, int>> DayFiveSolver::getDiagonalPoints(Line line)
{

    std::vector<std::pair<int, int>> points;
    int slope = (line.endY - line.startY) / (line.endX - line.startX);

    int slopeX = (line.startX > line.endX) ? -1 : 1;
    int slopeY = (line.startY > line.endY) ? -1 : 1;
    for (int x = line.startX, y = line.startY; x != line.endX + slopeX; x += slopeX, y += slopeY)
    {
        points.emplace_back(x, y);
    }

    return points;
}