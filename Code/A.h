#ifndef A_H
#define A_H

#include "Graph.h"
#include <queue>

using namespace std;

static double* tempWeights;
static double* tempDists;
struct LessThanByCostAndHueristic
{
  bool operator()(const int& l, const int& r) const
  {
    return tempWeights[l-1] + tempDists[l-1] > tempWeights[r-1] + tempDists[r-1];
  }
};

class A{
    public:
        static vector<int>* a(Graph*, int, int, bool);
    private:
        static double getCost(vector<vector<double>>*, vector<vector<int>>*, int, int, int);
        static double getWeight(vector<vector<double>>*, int, int);
        static double getDistance(vector<vector<int>>*, int, int);
};

#endif