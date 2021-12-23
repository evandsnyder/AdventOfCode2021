#include "DaySixteenSolver.hpp"

DaySixteenSolver::DaySixteenSolver(std::string fileName) : fileName(fileName), versionNumbers(0) {}

void DaySixteenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DaySixteenSolver::readFile()
{
    std::ifstream infile(this->fileName);
    std::string input;
    infile >> input;
    // Convert whole line to binary?
    std::string binary;
    for (auto &c : input)
    {
        switch (c)
        {
        case '0':
            binary += "0000";
            break;
        case '1':
            binary += "0001";
            break;
        case '2':
            binary += "0010";
            break;
        case '3':
            binary += "0011";
            break;
        case '4':
            binary += "0100";
            break;
        case '5':
            binary += "0101";
            break;
        case '6':
            binary += "0110";
            break;
        case '7':
            binary += "0111";
            break;
        case '8':
            binary += "1000";
            break;
        case '9':
            binary += "1001";
            break;
        case 'A':
            binary += "1010";
            break;
        case 'B':
            binary += "1011";
            break;
        case 'C':
            binary += "1100";
            break;
        case 'D':
            binary += "1101";
            break;
        case 'E':
            binary += "1110";
            break;
        case 'F':
            binary += "1111";
            break;
        }
    }

    this->binary = binary;
}

void DaySixteenSolver::partOne()
{
    auto r = processPacket();

    std::cout << "Part One Solution: " << this->versionNumbers << std::endl;
    std::cout << "Part Two Solution: " << r << std::endl;
}

void DaySixteenSolver::partTwo()
{
}

// returns the number of bytes read and the resultant value
ull DaySixteenSolver::processPacket()
{

    int bytesRead = 6;
    int version = std::stoi(this->binary.substr(0, 3), nullptr, 2);
    int typeID = std::stoi(this->binary.substr(3, 3), nullptr, 2);
    this->versionNumbers += version;

    this->binary.erase(this->binary.begin(), this->binary.begin() + 6);

    if (typeID == ID::LITERAL)
    {
        bool end = false;
        std::string val = "";
        while (!end)
        {
            end = this->binary.front() == '0';
            val.append({this->binary.begin() + 1, this->binary.begin() + 5});
            this->binary.erase(this->binary.begin(), this->binary.begin() + 5);
        }

        return std::stoll(val, nullptr, 2);
    }

    // Evaluate operator packet!
    int lengthTypeID = (this->binary[0] == '1') ? 11 : 15;
    this->binary.erase(this->binary.begin());

    std::vector<ull> values;

    if (lengthTypeID == 11)
    {

        // read 11 bytes to determine how many packets there are
        int packetCount = std::stoi(this->binary.substr(0, 11), nullptr, 2);
        this->binary.erase(this->binary.begin(), this->binary.begin() + 11);

        int packetsRead = 0;
        for (; packetsRead < packetCount; packetsRead++)
        {

            // parse the packet!
            values.push_back(processPacket());
        }
    }
    else
    {
        int bitLength = std::stoi(this->binary.substr(0, 15), nullptr, 2);
        this->binary.erase(this->binary.begin(), this->binary.begin() + 15);

        int curBytes = this->binary.size();
        while (this->binary.size() > curBytes - bitLength)
        {
            values.push_back(processPacket());
        }
    }

    ull result = 0;
    switch (typeID)
    {
    case ID::SUM:
        result = 0;
        for (auto &v : values)
        {
            result += v;
        }
        return result;
    case ID::PRODUCT:
        result = 1;
        for (auto &v : values)
        {
            result *= v;
        }
        return result;
    case ID::MINIMUM:
        return *std::min_element(values.begin(), values.end());
    case ID::MAXIMUM:
        return *std::max_element(values.begin(), values.end());
    case ID::EQUAL_TO:
        return (ull)(values[0] == values[1]);
    case ID::GREATER_THAN:
        return (ull)(values[0] > values[1]);
    case ID::LESS_THAN:
        return (ull)(values[0] < values[1]);
    }

    return result;
}