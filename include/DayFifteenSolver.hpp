#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>

#include "Solver.hpp"

struct Node
{
    std::pair<int, int> vertex;
    int weight;
    Node *next;

    Node(int x, int y, int w)
    {
        vertex = std::make_pair(x, y);
        weight = w;
        next = nullptr;
    }
};

class DayFifteenSolver : public Solver
{
private:
    std::string fileName;
    Node *startNode;
    Node *endNode;
    std::unordered_map<Node*, std::set<Node*>> adj;
    std::vector<std::vector<int>> baseGrid;
    std::vector<std::vector<Node *>> baseNodeGrid;

public:
    DayFifteenSolver(std::string fileName);
    void solve() override;

protected:
    void readFile() override;
    void partOne() override;
    void partTwo() override;

    void addEdge(std::unordered_map<Node*, std::set<Node*>> *adjacencyGraph, Node *start, Node *end);

    Node* minDistance(std::unordered_map<Node *, int> *distances, std::unordered_map<Node *, bool> *shortestPathSet);
    int applyDijkstra(std::vector<std::vector<Node *>> graph);
};