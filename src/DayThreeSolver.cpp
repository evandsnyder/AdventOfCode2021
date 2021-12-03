#include "DayThreeSolver.hpp"

DayThreeSolver::DayThreeSolver(std::string fileName) : fileName(fileName) {}

void DayThreeSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayThreeSolver::readFile()
{
    std::ifstream infile(this->fileName);
    std::string v;

    while (infile >> v)
    {
        this->values.push_back(v);
    }
    infile.close();
}

void DayThreeSolver::partOne()
{
    int valueSet[12] = {0};
    for (std::string &v : this->values)
    {
        // 111011111011
        for (int i = 0; i < 12; i++)
        {
            if (v[i] == '1')
                valueSet[i] += 1;
        }
    }

    int compSize = this->values.size();
    std::string epsilon = "", gamma = "";

    for (int i = 0; i < 12; i++)
    {
        // Is 1 the majority??
        int target = valueSet[i];
        int actual = compSize - target;

        if (actual > target)
        {
            // Minority?
            // string append 0
            epsilon += "0";
            gamma += "1";
        }
        else
        {
            // string append 1
            epsilon += "1";
            gamma += "0";
        }
    }

    this->gamma = gamma;

    int epsilonResult = BinaryToInt(epsilon);
    int gammaResult = BinaryToInt(gamma);

    std::cout << "Part One Solution: " << gammaResult * epsilonResult << std::endl;
}

void DayThreeSolver::partTwo()
{
    std::vector<std::string> scrubber(this->values), oxygen(this->values);
    std::string t_scrub, t_oxy;
    int i = 0;
    while (oxygen.size() > 1 && i < 12)
    {
        // Given the current set and index, calculate the most common value...
        int ones = 0;
        int zeroes = 0;
        for (auto &v : oxygen)
        {
            if (v[i] == '1')
                ones++;
            else
                zeroes++;
        }

        if (zeroes > ones)
        {
            oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [i](std::string &x)
                                        { return x[i] == '1'; }),
                         oxygen.end());
        }
        else
        {
            oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [i](std::string &x)
                                        { return x[i] == '0'; }),
                         oxygen.end());
        }
        i++;
    }

    if (oxygen.size() == 1)
        t_oxy = oxygen[0];

    i = 0;
    while (scrubber.size() > 1 && i < 12)
    {
        // Given the current set and index, calculate the most common value...
        int ones = 0;
        int zeroes = 0;
        for (auto &v : scrubber)
        {
            if (v[i] == '1')
                ones++;
            else
                zeroes++;
        }

        if (ones < zeroes)
        {
            scrubber.erase(std::remove_if(scrubber.begin(), scrubber.end(), [i](std::string &x)
                                          { return x[i] == '0'; }),
                           scrubber.end());
        }
        else
        {
            scrubber.erase(std::remove_if(scrubber.begin(), scrubber.end(), [i](std::string &x)
                                          { return x[i] == '1'; }),
                           scrubber.end());
        }
        i++;
    }

    if (scrubber.size() == 1)
        t_scrub = scrubber[0];

    std::cout << "Part Two Solution: " << BinaryToInt(t_oxy) * BinaryToInt(t_scrub) << std::endl;
}

int DayThreeSolver::BinaryToInt(std::string binary)
{
    return stoi(binary, 0, 2);
}