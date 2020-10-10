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
        LinkedList<int>* getAdjacencyList();
        bool** getAdjacencyMatrix();
        vector<vector<int>>* getPositions();
        vector<vector<double>>* getWeights();
    private:
        bool** adjacencyMatrix;
		LinkedList<int>* adjacencyList;
        vector<vector<int>>* positions;
        vector<vector<double>>* weights;
};
#endif