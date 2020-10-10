#include "Dijkstra.h"
#include <math.h>
#include <time.h>

using namespace std;

vector<int>* Dijkstra::dijkstra(Graph* graph, int src, int dest, bool isMatrix){
    int numNodes = graph->getPositions()->size();
    int numVisited = 0;
    vector<int>* path = new vector<int>();
    priority_queue<int, vector<int>, LessThanByCost> queue;
    int* origins = new int[numNodes]{-1};
    bool* visited = new bool[numNodes]{false};
    double* costs = new double[numNodes];
    tempCosts = costs;
    fill_n(costs, numNodes, INFINITY);
    bool** adjacencyMatrix = graph->getAdjacencyMatrix();
    LinkedList<int>* adjacencyList = graph->getAdjacencyList();
    vector<vector<double>>* weights = graph->getWeights();
    queue.push(src);
    visited[src - 1] = true;
    costs[src - 1] = 0;
    numVisited++;
    while(!queue.empty()){
        int node = queue.top();
        queue.pop();
        if(node != dest){
            if(isMatrix){
                for(int i = 0; i < numNodes; i++){
                    if(adjacencyMatrix[node - 1][i]){
                        double temp = getCost(weights, node, i + 1);
                        if((costs[node - 1] + temp < costs[dest - 1] || costs[dest - 1] == INFINITY) && (!visited[i] || costs[node - 1] + temp < costs[i])){
                            costs[i] = costs[node - 1] + temp;
                            queue.push(i + 1);
                            visited[i] = true;
                            numVisited++;
                            origins[i] = node;
                        }
                    }
                }
            }else{
                Node<int>* temp = adjacencyList[node - 1].head->next;
                while(temp != nullptr){
                    double tempCost = getCost(weights, node, temp->data);
                    if((!visited[temp->data - 1] || costs[node - 1] + tempCost < costs[temp->data - 1]) && (costs[node - 1] + tempCost < costs[dest - 1] || costs[dest - 1] == INFINITY)){
                        costs[temp->data - 1] = costs[node - 1] + tempCost;
                        queue.push(temp->data);
                        visited[temp->data - 1] = true;
                        numVisited++;
                        origins[temp->data - 1] = node;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    double cost = 0;
    for(int i = dest; i != src || i == -1; i = origins[i - 1]){
        path->insert(path->begin(), i);
        cost += getCost(graph->getWeights(), origins[i - 1], i);
    }
    path->insert(path->begin(), src);
    path->push_back(numVisited);
    path->push_back(cost * 1000);
    delete[] origins;
    delete[] visited;
    delete[] costs;
    return path;
}

double Dijkstra::getCost(vector<vector<double>>* weights, int origin, int dest){
    for(int i = 0; i < weights->size(); i++){
        for(int j = 0; j < weights->at(i).size() - 1; j++){
            if(weights->at(i).at(0) == origin && weights->at(i).at(j) == dest){
                return weights->at(i).at(weights->at(i).size() - 1);
            }
        } 
    }
}