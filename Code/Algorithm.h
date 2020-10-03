#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Graph.h"
#include <string>
using namespace std;

class Algorithm
{
    public:
    	//Creates an enum with every type of search
        enum SearchingAlgo{
            BFS_ITERATIVE = 0,
            BFS_RECURSIVE,
            DFS_ITERATIVE,
            DFS_RECURSIVE,
            DIJKSTRA,
            A,
            END
        };
    	
    	//Defines each function that will be overloaded in the Search class
        virtual void load(Graph) = 0;
        virtual void execute() = 0;
        virtual void display() = 0;
        virtual void stats(string) = 0;
        virtual void select(int) = 0;
        virtual void save(string) = 0;
        virtual void configure() = 0;
};
#endif