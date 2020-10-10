#include "BFS.h"

using namespace std;
vector<int>* BFS::bfsIterative(Graph* graph, int src, int dest, bool isMatrix){
    int numNodes = graph->getPositions()->size();
    int numVisited = 0;
    vector<int>* path = new vector<int>();
    queue<int> queue;
    int* origins = new int[numNodes]{-1};
    bool* visited = new bool[numNodes]{false};
    bool** adjacencyMatrix = graph->getAdjacencyMatrix();
    LinkedList<int>* adjacencyList = graph->getAdjacencyList();
    queue.push(src);
    visited[src - 1] = true;
    numVisited++;
    while(!queue.empty()){
        int node = queue.front();
        queue.pop();
        if(node == dest){
            double cost = 0;
            for(int i = node; i != src || i == -1; i = origins[i - 1]){
                path->insert(path->begin(), i);
                cost += getWeight(graph->getWeights(), origins[i - 1], i);
            }
            path->insert(path->begin(), src);
            path->push_back(numVisited);
            path->push_back(cost * 1000);
            delete[] origins;
            delete[] visited;
            return path;
        }
        if(isMatrix){
            for(int i = 0; i < numNodes; i++){
                if(adjacencyMatrix[node - 1][i] && !visited[i]){
                    queue.push(i + 1);
                    visited[i] = true;
                    numVisited++;
                    origins[i] = node;
                }
            }
        }else{
            Node<int>* temp = adjacencyList[node - 1].head->next;
            while(temp != nullptr){
                if(!visited[temp->data - 1]){
                    queue.push(temp->data);
                    visited[temp->data - 1] = true;
                    numVisited++;
                    origins[temp->data - 1] = node;
                }
                temp = temp->next;
            }
        }
    }
    return nullptr;
}

vector<int>* BFS::bfsRecursive(Graph* graph, int src, int dest, bool isMatrix){
    int numNodes = graph->getPositions()->size();
    int numVisited = 0;
    vector<int>* path = new vector<int>();
    queue<int>* queue = new std::queue<int>();
    int* origins = new int[numNodes]{-1};
    bool* visited = new bool[numNodes]{false};
    bool** adjacencyMatrix = graph->getAdjacencyMatrix();
    LinkedList<int>* adjacencyList = graph->getAdjacencyList();
    queue->push(src);
    visited[src - 1] = true;
    numVisited++;
    if(isMatrix){
        matrixRecursion(adjacencyMatrix, src, dest, numNodes, &numVisited, queue, visited, origins);
    }else{
        listRecursion(adjacencyList, src, dest, numNodes, &numVisited, queue, visited, origins);
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
    return path;
}

void BFS::matrixRecursion(bool** adjacencyMatrix, int src, int dest, int numNodes, int* numVisited, queue<int>* queue, bool* visited, int* origins){
    int node = queue->front();
    queue->pop();
    if(node == dest){
        return;
    }
    for(int i = 0; i < numNodes; i++){
        if(adjacencyMatrix[node - 1][i] && !visited[i]){
            queue->push(i + 1);
            visited[i] = true;
            *numVisited = *numVisited + 1;
            origins[i] = node;
        }
    }
    matrixRecursion(adjacencyMatrix, src, dest, numNodes, numVisited, queue, visited, origins);
}

void BFS::listRecursion(LinkedList<int>* adjacencyList, int src, int dest, int numNodes, int* numVisited, queue<int>* queue, bool* visited, int* origins){
    int node = queue->front();
    queue->pop();
    if(node == dest){
        return;
    }
    Node<int>* temp = adjacencyList[node - 1].head->next;
    while(temp != nullptr){
        if(!visited[temp->data - 1]){
            queue->push(temp->data);
            visited[temp->data - 1] = true;
            *numVisited = *numVisited + 1;
            origins[temp->data - 1] = node;
        }
        temp = temp->next;
    }
    listRecursion(adjacencyList, src, dest, numNodes, numVisited, queue, visited, origins);
}

double BFS::getWeight(vector<vector<double>>* weights, int origin, int dest){
    for(int i = 0; i < weights->size(); i++){
        for(int j = 0; j < weights->at(i).size() - 1; j++){
            if(weights->at(i).at(0) == origin && weights->at(i).at(j) == dest){
                return weights->at(i).at(weights->at(i).size() - 1);
            }
        }
    }
}