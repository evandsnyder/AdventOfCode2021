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

std::vector<std::string> DayEightSolver::parseEntry(std::string data)
{
    std::istringstream ss(data);
    std::string e;
    std::vector<std::string> result;
    while (ss >> e)
    {
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
    for (auto &pair : this->data)
    {
        auto output = parseEntry(pair.second);

        // If there is a string of length 2, it must be 1
        // If there is a string of length 3, it must be 7
        // if there is a string of length 4, it must be 4
        // if there is a string of length 7, it must be 8

        // Find count of output values where length is 2,3,4, or 7
        for (auto &e : output)
        {
            switch (e.length())
            {
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
    int sumOfParts = 0;
    std::string allCharacters = "abcdefg";

    std::unordered_map<int, std::vector<int>> channelMap;
    channelMap[1] = {2, 5};
    channelMap[2] = {0, 2, 3, 4, 6};
    channelMap[3] = {0, 2, 3, 5, 6};
    channelMap[4] = {1, 2, 3, 5};
    channelMap[5] = {0, 1, 3, 5, 6};
    channelMap[6] = {0, 1, 3, 4, 5, 6};
    channelMap[7] = {0, 2, 5};
    channelMap[8] = {0, 1, 2, 3, 4, 5, 6};
    channelMap[9] = {0, 1, 2, 3, 5, 6};
    channelMap[0] = {0, 1, 2, 4, 5, 6};

    for (auto &pair : this->data)
    {
        auto uniqueNumbers = parseEntry(pair.first);
        auto output = parseEntry(pair.second);

        // start figuring all these suckers out!
        // We have line segments a-g
        char map[7] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};

        // Maybe iterating while there exists undetermined values is the incorrect approach..
        // Start with
        auto one = *(std::find_if(
            uniqueNumbers.begin(), uniqueNumbers.end(), [](std::string word)
            { return word.length() == 2; }));
        auto seven = *(std::find_if(
            uniqueNumbers.begin(), uniqueNumbers.end(), [](std::string word)
            { return word.length() == 3; }));
        auto four = *(std::find_if(
            uniqueNumbers.begin(), uniqueNumbers.end(), [](std::string word)
            { return word.length() == 4; }));
        auto eight = *(std::find_if(
            uniqueNumbers.begin(), uniqueNumbers.end(), [](std::string word)
            { return word.length() == 7; }));

        // starting with 1, find 6
        auto six = std::find_if(uniqueNumbers.begin(), uniqueNumbers.end(), [&](std::string arg)
                                { return arg.length() == 6 && arg.find(one[0]) == std::string::npos; });
        if (six == uniqueNumbers.end())
        {
            map[2] = one[1];
            map[5] = one[0];
            six = std::find_if(uniqueNumbers.begin(), uniqueNumbers.end(), [&](std::string arg)
                               { return arg.length() == 6 && arg.find(one[1]) == std::string::npos; });
        }
        else
        {
            map[5] = one[1];
            map[2] = one[0];
        }

        // Find the char unique to seven
        auto a = *(std::find_if(seven.begin(), seven.end(), [&](char arg)
                                { return one.find(arg) == std::string::npos; }));
        map[0] = a;

        // Find 2!
        // two will be the only word without map[5] in it
        auto two = *(std::find_if(uniqueNumbers.begin(), uniqueNumbers.end(), [&](std::string arg)
                                  { return arg.find(map[5]) == std::string::npos; }));
        // we can use that to find map[1]
        std::string fullTwo(two);
        fullTwo.push_back(map[5]);
        map[1] = *(std::find_if(allCharacters.begin(), allCharacters.end(), [&](char arg)
                                { return fullTwo.find(arg) == std::string::npos; }));

        // using 4, we can now figure out what map[3] is...
        // just need to cross reference four with map and find indepdenet values...
        // Find the only letter in four that is not already in map..
        map[3] = *(std::find_if(four.begin(), four.end(), [&](char c)
                                {
                                    // if letter is in four but not in map..

            for(int i =0 ; i < 7; i++){
                if(map[i] == c){
                    // c is already in map!
                    return false;
                };
            }
            return true; }));

        // Zero will be the only one missing the middle after 1 and 7 are removed...

        // Still need 0, 3, 5, 9
        // need map[4] and map[6]
        // we can find 0 by selecting strings of length 6 and
        auto zero = *(std::find_if(uniqueNumbers.begin(), uniqueNumbers.end(), [&](std::string arg)
                                   { return arg.length() == 6 && arg.find(map[3]) == std::string::npos; }));

        auto nine = *(std::find_if(uniqueNumbers.begin(), uniqueNumbers.end(), [&](std::string arg)
                                   { return arg.length() == 6 && arg.compare(zero) != 0 && arg.compare(*six) != 0; }));

        // unique character between eight and nine is map[4]
        map[4] = *(std::find_if(eight.begin(), eight.end(), [&](char c)
                                { return nine.find(c) == std::string::npos; }));
        // remaining character is map[6]
        map[6] = *(std::find_if(allCharacters.begin(), allCharacters.end(), [&](char c)
                                {
            // if letter is in allCharacters but not in map...
            for(int i =0; i < 7; i++){
                if(map[i] == c) return false;
            }
            return true; }));

        // for simplicity, we're going to reverse our map array here
        std::unordered_map<char, int> reversedMap;
        for (int i = 0; i < 7; i++)
        {
            reversedMap[map[i]] = i;
        }

        // Holy hell we made it! time to just.. convert the output values to a number ??
        std::string numberValue = "";
        for (auto &value : output)
        {
            // How do we map which channels to which number???
            // build channel analysis for each value...
            std::vector<int> activeChannels;
            for (auto &c : value)
            {
                // find channel number with a reverse lookup...
                activeChannels.push_back(reversedMap[c]);
            }

            std::sort(activeChannels.begin(), activeChannels.end());

            for (auto &[k, v] : channelMap)
            {
                if (activeChannels == v)
                {
                    // WE HAVE k
                    numberValue.append(std::to_string(k));
                }
            }
        }

        sumOfParts += stoi(numberValue);
    }
    std::cout << "Part Two Solution: " << sumOfParts << std::endl;
}