#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <queue>

using namespace std;

class BFS{
    public:
        static vector<int>* bfsIterative(Graph*, int, int, bool);
        static vector<int>* bfsRecursive(Graph*, int, int, bool);
    private:
        static void matrixRecursion(bool**, int, int, int, int*, queue<int>*, bool*, int*);
        static void listRecursion(LinkedList<int>*, int, int, int, int*, queue<int>*, bool*, int*);
        static double getWeight(vector<vector<double>>*, int, int);
};
#endif