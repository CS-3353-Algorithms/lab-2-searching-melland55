#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Graph::Graph(string graphFile, string positionFile, string weightFile){
    positions = new vector<vector<int>>;
    ifstream ifs;
	ifs.open(positionFile);
	//Loops through file and adds all rows and colums to positions
	while(!(ifs.eof())){
        string temp;
		string line;
		ifs >> line;
        stringstream ss(line);
        vector<int> vect;
        while(getline(ss, temp, ',')){
            vect.push_back(stoi(temp));
        }
        positions->push_back((vect));
	}
	ifs.close();
    weights = new vector<vector<double>>;
	ifs.open(weightFile);
	//Loops through file and adds all rows and colums to weights
	while(!(ifs.eof())){
        string temp;
		string line;
		ifs >> line;
        stringstream ss(line);
        vector<double> vect;
        while(getline(ss, temp, ',')){
            vect.push_back(stod(temp));
        }
        weights->push_back((vect));
	}
	ifs.close();
	ifs.open(graphFile);
    adjacencyList = new LinkedList<int>[positions->size()];
    adjacencyMatrix = new bool*[positions->size()];
    for(int i = 0; i < positions->size(); i++){
        adjacencyMatrix[i] = new bool[positions->size()]{0};
    }
	//Loops through file and adds all rows and colums to both the adjacency matrix and adjacency list
    int counter = 0;
	while(!(ifs.eof())){
        LinkedList<int> list;
        string temp;
		string line;
		ifs >> line;
        stringstream ss(line);
        int origin;
        bool dec = true;
        while(getline(ss, temp, ',')){
            adjacencyList[counter].append(stoi(temp));
            if(dec){
                dec = false;
                origin = stoi(temp);
            }else{
                adjacencyMatrix[origin - 1][stoi(temp) - 1] = true;
            }
        }
        counter++;
	}
}

Graph::~Graph(){
    delete positions;
    delete weights;
}


LinkedList<int>* Graph::getAdjacencyList(){
    return adjacencyList;
}

bool** Graph::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

vector<vector<int>>* Graph::getPositions(){
    return positions;
}

vector<vector<double>>* Graph::getWeights(){
    return weights;
}