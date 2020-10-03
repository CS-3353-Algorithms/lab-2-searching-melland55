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
    adjacencyList = new LinkedList<LinkedList<int>>();
    adjacencyMatrix = new bool*[positions->size()];
    for(int i = 0; i < positions->size(); i++){
        adjacencyMatrix[i] = new bool[positions->size()]{0};
    }
	//Loops through file and adds all rows and colums to both the adjacency matrix and adjacency list
	while(!(ifs.eof())){
        LinkedList<int> list;
        string temp;
		string line;
		ifs >> line;
        stringstream ss(line);
        bool dec = true;
        int origin;
        while(getline(ss, temp, ',')){
            list.append(stoi(temp));
            if(dec){
                dec = false;
                origin = stoi(temp);
            }else{
                adjacencyMatrix[origin - 1][stoi(temp) - 1] = true;
            }
        }
        adjacencyList->append(list);
	}
	ifs.close();
    for(int i = 0; i < positions->size(); i++){
        for(int j = 0; j < positions->size(); j++){
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

Graph::~Graph(){
    delete positions;
    delete weights;
}


LinkedList<LinkedList<int>>* Graph::getAdjacencyList(){
    return adjacencyList;
}

vector<vector<int>>* Graph::getPositions(){
    return positions;
}

vector<vector<double>>* Graph::getWeights(){
    return weights;
}