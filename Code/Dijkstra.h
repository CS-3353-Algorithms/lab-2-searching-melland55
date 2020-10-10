#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <queue>

using namespace std;

static double* tempCosts;
struct LessThanByCost
{
  bool operator()(const int& l, const int& r) const
  {
    return tempCosts[l-1] > tempCosts[r-1];
  }
};

class Dijkstra{
    public:
        static vector<int>* dijkstra(Graph*, int, int, bool);
    private:
        static double getCost(vector<vector<double>>*, int, int);
};

#endif