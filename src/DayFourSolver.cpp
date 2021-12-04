#include "DayFourSolver.hpp"

DayFourSolver::DayFourSolver(std::string fileName) : fileName(fileName) {}

void DayFourSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayFourSolver::readFile()
{
    // First line is the numbers being read
    std::string numbers_string;

    // Skip line
    // Read 5 lines...

    std::ifstream infile(this->fileName);
    std::string action;

    infile >> numbers_string;
    size_t pos = 0;
    std::string token;
    std::string delim = ",";
    while ((pos = numbers_string.find(delim)) != std::string::npos)
    {
        token = numbers_string.substr(0, pos);
        this->numbers.push_back(std::stoi(token));
        numbers_string.erase(0, pos + 1);
    }
    this->numbers.push_back(std::stoi(numbers_string));

    int t;

    std::vector<int> all_numbers;

    while (infile >> t)
    {
        all_numbers.push_back(t);
    }
    infile.close();

    // a grid is 5x5..
    // there are 100 of them..
    // Each grid is 5x5...
    
    for (std::vector<int>::iterator it = all_numbers.begin(); it != all_numbers.end(); it += 25)
    {
        std::vector<int> t(it, it + 25);
        auto r = createBoard(t);
        this->boards.push_back(r);
    }
}

Board DayFourSolver::createBoard(std::vector<int> values)
{
    Board board;
    // There are 5 sets of 5 here...
    for (int i = 0; i < values.size(); i += 5)
    {
        std::vector<std::pair<int, bool>> row;

        row.emplace_back(values[i], false);
        row.emplace_back(values[i + 1], false);
        row.emplace_back(values[i + 2], false);
        row.emplace_back(values[i + 3], false);
        row.emplace_back(values[i + 4], false);

        board.push_back(row);
    }
    return board;
}

void DayFourSolver::printBoard(Board board)
{
    for (auto &v : board)
    {
        for (auto &p : v)
        {
            std::cout << p.first << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool DayFourSolver::isBoardSolved(Board board)
{
    // Must check all rows...
    // Must check all columns...
    bool solved;
    for(int i  = 0; i < 5; i++){
        solved = board[i][0].second &
                 board[i][1].second &
                 board[i][2].second &
                 board[i][3].second &
                 board[i][4].second;
        if (solved)
            return true;
    }
    // Got to check columns...
    for (int i = 0; i < 5; i++)
    {
        solved = board[0][i].second &
                 board[1][i].second &
                 board[2][i].second &
                 board[3][i].second &
                 board[4][i].second;
        if (solved)
            return true;
    }

    return false;
}

void DayFourSolver::partOne()
{
    // For each number... iterate over every board.. if the value is in the board, flag it..
    // After the fifth, start checking for solves...

    for(auto& drawn : this->numbers){
        for(Board &board : this->boards){
            for(auto &row: board){
                for(auto &elem : row){
                    if(elem.first == drawn){
                        elem.second = true;
                    }
                }
            }

            // Check for success!
            if(isBoardSolved(board)){
                std::cout << "Part One Solution: " << drawn * findSumOfBoard(board) << std::endl;
                return;
            }
        }
    }
}

void DayFourSolver::partTwo()
{

    // Need to find the last solved one...
    // So remove the solved one
    std::vector<Board> boards(this->boards);
    for(auto& drawn : this->numbers){
        for(std::vector<Board>::iterator it = boards.begin(); it != boards.end(); it++){
        // for(Board &board : this->boards){
            for(auto &row: *it){
                for(auto &elem : row){
                    if(elem.first == drawn){
                        elem.second = true;
                    }
                }
            }

            // Check for success!
            if(isBoardSolved(*it)){
                //if its the last one solved! else remove it
                if(boards.size() == 1){
                    std::cout << "Part Two Solution: " << drawn * findSumOfBoard(*it) << std::endl;
                    return;
                } else {
                    it = boards.erase(it);
                    it--;
                }
            }
        }
    }

    std::cout << "Part Two Solution: " << 0 << std::endl;
}

int DayFourSolver::findSumOfBoard(Board board){
    int sum = 0;
    for(auto &row : board){
        for(auto &elem : row){
            if(!elem.second) sum += elem.first;
        }
    }

    return sum;
}