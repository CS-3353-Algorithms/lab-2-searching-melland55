#include "A.h"
#include <math.h>

using namespace std;
vector<int>* A::a(Graph* graph, int src, int dest, bool isMatrix){
    int numNodes = graph->getPositions()->size();
    int numVisited = 0;
    vector<int>* path = new vector<int>();
    priority_queue<int, vector<int>, LessThanByCostAndHueristic> queue;
    int* origins = new int[numNodes]{-1};
    bool* visited = new bool[numNodes]{false};
    double* costs = new double[numNodes];
    double* dists = new double[numNodes];
    tempWeights = costs;
    tempDists = dists;
    fill_n(costs, numNodes, INFINITY);
    bool** adjacencyMatrix = graph->getAdjacencyMatrix();
    LinkedList<int>* adjacencyList = graph->getAdjacencyList();
    vector<vector<double>>* weights = graph->getWeights();
    vector<vector<int>>* positions = graph->getPositions();
    queue.push(src);
    visited[src - 1] = true;
    costs[src - 1] = getDistance(positions, src, dest);
    numVisited++;
    while(!queue.empty()){
        int node = queue.top();
        queue.pop();
        if(node != dest){
            if(isMatrix){
                for(int i = 0; i < numNodes; i++){
                    if(adjacencyMatrix[node - 1][i] && (costs[node - 1] + getWeight(weights, node, i + 1) < costs[dest - 1] || costs[dest - 1] == INFINITY) && (!visited[i] || costs[node - 1] + getWeight(weights, node, i + 1) < costs[i])){
                        dists[i] = getDistance(positions, i + 1, dest);
                        costs[i] = costs[node - 1] + getWeight(weights, node, i + 1);
                        queue.push(i + 1);
                        visited[i] = true;
                        numVisited++;
                        origins[i] = node;
                    }
                }
            }else{
                Node<int>* temp = adjacencyList[node - 1].head->next;
                while(temp != nullptr){
                    if((!visited[temp->data - 1] || costs[node - 1] + getWeight(weights, node, temp->data) < costs[temp->data - 1]) && (costs[node - 1] + getWeight(weights, node, temp->data) < costs[dest - 1] || costs[dest - 1] == INFINITY)){
                        dists[temp->data - 1] = getDistance(positions, temp->data, dest);
                        costs[temp->data - 1] = costs[node - 1] + getWeight(weights, node, temp->data);
                        queue.push(temp->data);
                        visited[temp->data - 1] = true;
                        numVisited++;
                        origins[temp->data - 1] = node;
                    }
                    temp = temp->next;
                }
            }
        }else{
            break;
        }
    }
    double cost = 0;
    for(int i = dest; i != src || i == -1; i = origins[i - 1]){
        path->insert(path->begin(), i);
        cost += getWeight(graph->getWeights(), origins[i - 1], i);
    }
    path->insert(path->begin(), src);
    path->push_back(numVisited);
    path->push_back(cost * 1000);
    delete[] origins;
    delete[] visited;
    delete[] costs;
    return path;
}

double A::getCost(vector<vector<double>>* weights, vector<vector<int>>* positions, int origin, int dest, int final){
    return getWeight(weights, origin, dest) + getDistance(positions, dest, final);
}

double A::getWeight(vector<vector<double>>* weights, int origin, int dest){
    for(int i = 0; i < weights->size(); i++){
        for(int j = 0; j < weights->at(i).size() - 1; j++){
            if(weights->at(i).at(0) == origin && weights->at(i).at(j) == dest){
                return weights->at(i).at(weights->at(i).size() - 1);
            }
        }
    }
}

double A::getDistance(vector<vector<int>>* positions, int origin, int dest){
    int x = abs(positions->at(origin - 1).at(1) - positions->at(dest - 1).at(1));
    int y = abs(positions->at(origin - 1).at(2) - positions->at(dest - 1).at(2));
    return sqrt(x*x + y*y);
}