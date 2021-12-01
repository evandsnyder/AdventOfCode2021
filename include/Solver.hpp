#pragma once

class Solver{
public:
    virtual void solve() = 0;

protected:
    virtual void readFile() = 0;
    virtual void partOne() = 0;
    virtual void partTwo() = 0;
};