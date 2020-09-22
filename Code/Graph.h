#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
using namespace std;

class Graph
{
    public:
        Graph(string, string, string);
        virtual ~Graph();
        vector<vector<int>>* getPositions();
        vector<vector<int>>* getWeights();
    private:
        vector<vector<int>>* fileToVector(string);
        vector<vector<int>>* positions;
        vector<vector<int>>* weights;
};
#endif