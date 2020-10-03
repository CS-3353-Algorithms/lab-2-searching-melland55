#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include "LinkedList.cpp"
#include <string>
#include <vector>
using namespace std;

class Graph
{
    public:
        Graph(string, string, string);
        ~Graph();
        LinkedList<LinkedList<int>>* getAdjacencyList();
        vector<vector<int>>* getPositions();
        vector<vector<double>>* getWeights();
    private:
        bool** adjacencyMatrix;
		LinkedList<LinkedList<int>>* adjacencyList;
        vector<vector<int>>* positions;
        vector<vector<double>>* weights;
};
#endif