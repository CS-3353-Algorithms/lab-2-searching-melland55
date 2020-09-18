#include "Search.h"
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

void Search::load(string graph, string positions, string weights){
	
}

void Search::execute(){
	
}

void Search::display(){
	
}

void Search::stats(string algo){
	
}

//Selects the specified searching Algorithm
void Search::select(int searchAlgo){
	switch(searchAlgo){
		case BFS_ITERATIVE:
			//searchAlgoFuncPointer = &BFS::bfsIterativeSearch;
			break;
		case BFS_RECURSIVE:
			//searchAlgoFuncPointer = &BFS::bfsRecursiveSearch;
			break;
		case DFS_ITERATIVE:
			//searchAlgoFuncPointer = &DFS::dfsIterativeSearch;
			break;
		case DFS_RECURSIVE:
			//searchAlgoFuncPointer = &DFS::dfsRecursiveSearch;
			break;
		case DIJKSTRA:
			//searchAlgoFuncPointer = &DIJKSTRA::dijkstraSearch;
			break;
		case A:
			//searchAlgoFuncPointer = &A::aSearch;
			break;
	}
}

void Search::save(string filePath){
	
}

void Search::configure(){
	
}