#include "DayTenSolver.hpp"

DayTenSolver::DayTenSolver(std::string fileName) : fileName(fileName) {}

void DayTenSolver::solve()
{
    readFile();
    // useSample();
    partOne();
    partTwo();
}

void DayTenSolver::readFile()
{
    std::ifstream infile(this->fileName);
    std::string line;

    while (infile >> line)
    {
        this->input.push_back(line);
    }
}

void DayTenSolver::useSample()
{
    this->input.push_back("[({(<(())[]>[[{[]{<()<>>");
    this->input.push_back("[(()[<>])]({[<{<<[]>>(");
    this->input.push_back("{([(<{}[<>[]}>{[]{[(<()>");
    this->input.push_back("(((({<>}<{<{<>}{[]{[]{}");
    this->input.push_back("[[<[([]))<([[{}[[()]]]");
    this->input.push_back("[{[{({}]{}}([{[{{{}}([]");
    this->input.push_back("{<[[]]>}<{[{[{[]{()[[[]");
    this->input.push_back("[<(<(<(<{}))><([]([]()");
    this->input.push_back("<{([([[(<>()){}]>(<<{{");
    this->input.push_back("<{([{{}}[<[[[<>{}]]]>[]]");
}

void DayTenSolver::partOne()
{
    int result = 0;
    for (auto &entry : this->input)
    {
        std::stack<char> entryStack;
        for (char &c : entry)
        {
            switch (c)
            {
            case '[':
            case '(':
            case '{':
            case '<':
                entryStack.push(c);
                break;
            default:
                // Its a closing one!
                // if top is corresponing, keep going else, break
                if (c - 1 == entryStack.top() || c - 2 == entryStack.top())
                {
                    entryStack.pop();
                }
                else
                {
                    // INVALID
                    switch (c)
                    {
                    case '}':
                        result += 1197;
                        break;
                    case ']':
                        result += 57;
                        break;
                    case '>':
                        result += 25137;
                        break;
                    case ')':
                        result += 3;
                        break;
                    default:
                        break;
                    }
                    goto early_terminate;
                }
                break;
            }
        }

        if (!entryStack.empty())
        {
            this->incompleteStrings.push_back(entryStack);
        }

    early_terminate:
        continue;
    }

    std::cout << "Part One Solution: " << result << std::endl;
}

void DayTenSolver::partTwo()
{
    std::vector<long> allResults;
    for (auto &stack : this->incompleteStrings)
    {
        long tempResult = 0;
        while (!stack.empty())
        {
            tempResult *= 5;
            switch (stack.top())
            {
            case '(':
                tempResult += 1;
                break;
            case '[':
                tempResult += 2;
                break;
            case '{':
                tempResult += 3;
                break;
            case '<':
                tempResult += 4;
                break;
            default:
                break;
            }
            stack.pop();
        }
        allResults.push_back(tempResult);
    }

    std::sort(allResults.begin(), allResults.end());
    int winnerIndex = (allResults.size() / 2); 

    std::cout << "Part Two Solution: " << allResults[winnerIndex] << std::endl;
}