#include "DaySeventeenSolver.hpp"

DaySeventeenSolver::DaySeventeenSolver(std::string fileName) : fileName(fileName) {}

void DaySeventeenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DaySeventeenSolver::readFile()
{
}

void DaySeventeenSolver::partOne()
{

    // Some quick physiqs
    int n = -this->maximumYTarget - 1;

    std::cout << "Part One Solution: " << n * (n + 1) / 2 << std::endl;
}

void DaySeventeenSolver::partTwo()
{
    int validTrajectories = 0;
    for (int x = 0; x <= this->maximumXTarget; x++)
    {
        for (int y = this->maximumYTarget; y <= 6903; y++) // Cheating with hardcoded val
        {
            this->currentXVelocity = x;
            this->currentYVelocity = y;
            if (simulate())
                validTrajectories++;
            reset();
        }
    }

    std::cout << "Part Two Solution: " << validTrajectories << std::endl;
}

void DaySeventeenSolver::reset()
{
    this->currentXPosition = 0;
    this->currentYPosition = 0;

    this->currentXVelocity = 0;
    this->currentYVelocity = 0;
}

void DaySeventeenSolver::step()
{
    this->currentXPosition += this->currentXVelocity;
    // Move closer to 0!
    if (this->currentXVelocity != 0)
    {
        this->currentXVelocity -= (this->currentXVelocity > 0) ? 1 : -1;
    }

    this->currentYPosition += this->currentYVelocity;
    this->currentYVelocity--;
}

// Returns true if a trajectory is valid
bool DaySeventeenSolver::simulate()
{
    // Given an initial trajectory, start stepping!

    while (this->currentXPosition <= this->maximumXTarget &&
           this->currentYPosition >= this->maximumYTarget)
    {
        if (this->currentXPosition >= this->minimumXTarget &&
            this->currentXPosition <= this->maximumXTarget &&
            this->currentYPosition <= this->minimumYTarget &&
            this->currentYPosition >= this->maximumYTarget)
        {
            return true;
        }
        step();
    }

    return false;
}