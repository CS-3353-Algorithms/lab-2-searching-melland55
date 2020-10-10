#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include <stack>

using namespace std;

class DFS{
    public:
        static vector<int>* dfsIterative(Graph*, int, int, bool);
        static vector<int>* dfsRecursive(Graph*, int, int, bool);
    private:
        static void matrixRecursion(bool**, int, int, int, int*, stack<int>*, bool*, int*);
        static void listRecursion(LinkedList<int>*, int, int, int, int*, stack<int>*, bool*, int*);
        static double getWeight(vector<vector<double>>*, int, int);
};
#endif