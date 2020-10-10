#include "Search.h"
#include "BFS.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "A.h"
#include <fstream>

using namespace std;

Search::Search(){
    source = 0;
    destination = 0;
}

Search::Search(int src, int dest){
	source = src;
	destination = dest;
}

Search::~Search(){

}

void Search::load(string graphFile, string positionFile, string weightFile){
	graph = new Graph(graphFile, positionFile, weightFile);
}

void Search::execute(){
	auto start = chrono::high_resolution_clock::now();
	matrixPath = searchPointer(graph, source, destination, true);
	matrixTime = chrono::high_resolution_clock::now() - start;
	start = chrono::high_resolution_clock::now();
	listPath = searchPointer(graph, source, destination, false);
	listTime = chrono::high_resolution_clock::now() - start;
	cost = (double)listPath->back() / 1000;
	listPath->pop_back();
	totalNodesVisited = listPath->back();
	listPath->pop_back();
}

void Search::display(){
	cout << endl << "*************************" << endl;
	cout << currentAlgo << endl;
	cout << endl << "*************************" << endl;
	cout << "Path" << endl;
	for(int i = 0; i < listPath->size(); i++){
		cout << listPath->at(i) << " -> ";
	}
	cout << endl << "*************************" << endl;
}

void Search::stats(){
	cout << endl << "****************************" << endl;
	cout << currentAlgo << " List " << endl << "--------------------------------" << endl;
	for(int i = 0; i < listPath->size(); i++){
		cout << listPath->at(i) << "->" ;
	}
	cout << "--------------------------------" << endl;
	cout << "Number of Path Nodes: " << listPath->size() << endl;
	cout << "Cost of Path: " << cost << endl;
	cout << "Number of Nodes Explored: " << totalNodesVisited << endl;
	cout << "Time to Execute Matrix:   " << matrixTime.count() << " miliseconds" << endl;
	cout << "Time to Execute List:     " << listTime.count() << " miliseconds" << endl;
	cout << endl << "****************************" << endl;
}

void Search::select(int searchAlgo){
	switch(searchAlgo){
		case BFS_ITERATIVE:
			searchPointer = &BFS::bfsIterative;
			currentAlgo = "BFS_Iterative";
			break;
		case BFS_RECURSIVE:
			searchPointer = &BFS::bfsRecursive;
			currentAlgo = "BFS_Recursive";
			break;
		case DFS_ITERATIVE:
			searchPointer = &DFS::dfsIterative;
			currentAlgo = "DFS_Iterative";
			break;
		case DFS_RECURSIVE:
			searchPointer = &DFS::dfsRecursive;
			currentAlgo = "DFS_Recursive";
			break;
		case DIJKSTRA:
			searchPointer = &Dijkstra::dijkstra;
			currentAlgo = "Dijkstra";
			break;
		case A:
			searchPointer = &A::a;
			currentAlgo = "A*";
			break;
	}
}

void Search::save(string fileName){
	ofstream file;
	file.open(fileName, ios::app);
	file << currentAlgo << ", " << listPath->size() << ", " << totalNodesVisited << ", " << matrixTime.count() << ", " << listTime.count() << ", " << cost << endl;
	file.close();
}

void Search::configure(int src, int dest){
	source = src;
	destination = dest;
	cout << src << " " << dest << endl;
}