#ifndef SEARCH_H
#define SEARCH_H

#include "Algorithm.h"
#include "Graph.h"
#include <string>
#include <vector>
#include <chrono>
#include <ratio>

using namespace std;

class Search : public Algorithm
{
    public:
        Search();
        Search(int, int);
        ~Search();
        void load(string, string, string);
        void execute();
        void display();
        void stats();
        void select(int);
        void save(string);
        void configure(int, int);

    private:
        string currentAlgo;
		int source;
		int destination;
        Graph* graph;
        vector<int>* matrixPath;
        vector<int>* listPath;
        chrono::duration<double, milli> matrixTime, listTime;
        int matrixNodesVisited, listNodesVisited, totalNodesVisited;
        double cost;
    	//Pointer that points to any of the search algorithms
        vector<int>* (*searchPointer)(Graph*, int, int, bool);
};
#endif