#include "DayFourteenSolver.hpp"

DayFourteenSolver::DayFourteenSolver(std::string fileName) : fileName(fileName) {}

void DayFourteenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayFourteenSolver::readFile()
{
    std::ifstream infile(this->fileName);
    std::string line;
    while (std::getline(infile, line))
    {
        if (line.empty())
            continue;
        if (line.find("->") == std::string::npos)
        {
            this->polymerTemplate = line;
            continue;
        }

        // first two characters are key
        // first two plus last is value
        auto key = line.substr(0, 2);
        // Skip adding last character for now...
        auto value = std::string() + line.back();
        this->rules[key] = value;
        this->pairs.insert(std::make_pair(key, 0l));

        this->count.insert(std::make_pair(line[0], 0l));
        this->count.insert(std::make_pair(line[1], 0l));
        this->count.insert(std::make_pair(line.back(), 0l));
    }

    for (auto it = this->polymerTemplate.begin(); it != this->polymerTemplate.end() - 1; it++)
    {
        auto key = std::string() + *it + *(it + 1);

        this->count[*it]++;

        this->pairs[key]++;
    }

    this->count[this->polymerTemplate.back()]++;
}

void DayFourteenSolver::partOne()
{

    auto r = evaluatePolymer(10);

    std::cout << "Part One Solution: " << r << std::endl;
}

void DayFourteenSolver::partTwo()
{
    auto r = evaluatePolymer(40);

    std::cout << "Part Two Solution: " << r << std::endl;
}

long DayFourteenSolver::evaluatePolymer(int steps)
{
    std::unordered_map<std::string, long> pairs(this->pairs);
    std::unordered_map<char, long> count(this->count);

    for (int i = 0; i < steps; i++)
    {
        auto temp_pairs(pairs);
        for (auto &[k, v] : pairs)
        {
            if (v < 1)
            {
                continue;
            }
            // Generate new keys
            auto r = this->rules[k];
            count[r[0]] += v;
            auto k1 = k.front() + r;
            auto k2 = r + k.back();

            temp_pairs[k1] += v;
            temp_pairs[k2] += v;

            // remove the now accounted for pairs.
            // Setting to 0 would invalidate the generation of other pairs
            // so just remove the ones we generated with this v
            temp_pairs[k] -= v;
        }
        pairs = temp_pairs;
    }

    long largest = 0, smallest = LONG_MAX;
    for (auto &[k, v] : count)
    {
        smallest = v < smallest ? v : smallest;
        largest = v > largest ? v : largest;
    }

    return largest - smallest;
}