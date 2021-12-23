#include "DayFifteenSolver.hpp"

DayFifteenSolver::DayFifteenSolver(std::string fileName) : fileName(fileName)
{
}

void DayFifteenSolver::solve()
{
    readFile();
    partOne();
    partTwo();
}

void DayFifteenSolver::readFile()
{
    // create a grid...
    // Or Create a graph...
    std::ifstream infile(this->fileName);
    std::string line;
    while (infile >> line)
    {
        std::vector<int> row;
        for (auto &c : line)
        {
            row.push_back(c - '0');
        }

        this->baseGrid.push_back(row);
    }

    std::unordered_map<Node *, std::set<Node *>> adj;
    std::vector<std::vector<Node *>> nodeGrid;
    for (int i = 0; i < this->baseGrid.size(); i++)
    {
        nodeGrid.push_back(std::vector<Node *>());
        for (int j = 0; j < this->baseGrid[0].size(); j++)
        {
            Node *node = new Node(j, i, this->baseGrid[i][j]);
            this->adj[node] = std::set<Node *>();
            nodeGrid[i].push_back(node);
        }
    }

    this->startNode = nodeGrid[0][0];
    this->endNode = nodeGrid.back().back();

    this->baseNodeGrid = std::vector<std::vector<Node *>>(nodeGrid);
}

void DayFifteenSolver::partOne()
{
    // HOw can we print the end..
    std::cout << "Part One Solution: " << applyDijkstra(this->baseNodeGrid) << std::endl;
}

void DayFifteenSolver::partTwo()
{

    // Start by rebuilding the grid:
    // iterate 5 times in each direction...
    // We'll have to rebuild all the edges too
    // Create 5x5 larger than base grid...

    std::vector<std::vector<std::vector<int>>> gridOfGrids(9);
    gridOfGrids[0] = std::vector<std::vector<int>>(this->baseGrid);
    // Add base grid
    for (int riskLevel = 1; riskLevel < 9; riskLevel++)
    {
        auto tmpGrid(this->baseGrid);
        for (auto &r : tmpGrid)
        {
            for (auto &v : r)
            {
                // This value calculation doesn't work..
                v += riskLevel;
                if (v > 9)
                {
                    v -= 9;
                }
            }
        }
        gridOfGrids[riskLevel] = std::vector<std::vector<int>>(tmpGrid);
    }

    std::vector<std::vector<int>> pointerGrid;
    for (int i = 0; i < 5; i++)
    {
        pointerGrid.push_back(std::vector<int>(5));
        for (int j = 0; j < 5; j++)
        {
            pointerGrid[i][j] = i + j;
        }
    }
    // Need to translate this into a nodeGrid...
    int size = gridOfGrids[0].size();
    std::vector<std::vector<Node *>> nodeGrid(size * 5, std::vector<Node *>(size * 5, nullptr));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int riskLevel = i + j;
            int startingX = size * j;
            int startingY = size * i;
            for (int m = 0; m < size; m++)
            {
                for (int n = 0; n < size; n++)
                {
                    int x = startingX + n;
                    int y = startingY + m;
                    nodeGrid[y][x] = new Node(x, y, gridOfGrids[riskLevel][m][n]);
                }
            }
        }
    }

    std::cout << "Part Two Solution: " << applyDijkstra(nodeGrid) << std::endl;
}

// Returns distance to last node
int DayFifteenSolver::applyDijkstra(std::vector<std::vector<Node *>> graph)
{

    std::unordered_map<Node *, int> distances;
    std::unordered_map<Node *, bool> visitedSet;
    std::unordered_map<Node *, std::set<Node *>> adjacencyGraph;

    Node *source = graph[0][0];
    Node *destination = graph.back().back();

    // Build the adjacency graph
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            // add edges
            Node *node = graph[i][j];
            // Check their bounds
            // Only need top, bot, left, and right
            if (i - 1 >= 0)
            {
                // Add top
                addEdge(&adjacencyGraph, node, graph[i - 1][j]);
            }

            if (i + 1 < graph.size())
            {
                // add bot
                addEdge(&adjacencyGraph, node, graph[i + 1][j]);
            }

            if (j - 1 >= 0)
            {
                // add left
                addEdge(&adjacencyGraph, node, graph[i][j - 1]);
            }

            if (j + 1 < graph[0].size())
            {
                // Add right
                addEdge(&adjacencyGraph, node, graph[i][j + 1]);
            }
        }
    }

    // For every node
    for (auto &[node, v] : adjacencyGraph)
    {
        distances[node] = INT_MAX;
        visitedSet[node] = false;
    }

    distances[source] = 0;

    for (int i = 0; i < adjacencyGraph.size() - 1; i++)
    {
        auto nearestNode = minDistance(&distances, &visitedSet);
        visitedSet[nearestNode] = true;

        // visit all edges...
        for (auto &k : adjacencyGraph[nearestNode])
        {
            if (!visitedSet[k] && distances[nearestNode] != INT_MAX &&
                distances[nearestNode] + k->weight < distances[k])
            {
                distances[k] = distances[nearestNode] + k->weight;
            }
        }
    }

    return distances[destination];
}

Node *DayFifteenSolver::minDistance(std::unordered_map<Node *, int> *distances,
                                    std::unordered_map<Node *, bool> *visitedSet)
{
    int min = INT_MAX;
    Node *minNode;
    for (auto &[k, v] : *distances)
    {
        if ((*visitedSet)[k] == false &&
            v <= min)
        {
            min = v;
            minNode = k;
        }
    }
    return minNode;
}

void DayFifteenSolver::addEdge(std::unordered_map<Node *, std::set<Node *>> *adjacencyGraph, Node *start, Node *end)
{
    (*adjacencyGraph)[start].insert(end);
    (*adjacencyGraph)[end].insert(start);
}