#include "Graph.h"
#include <fstream>
#include <sstream>

using namespace std;

Graph::Graph(string graphFile, string positionFile, string weightFile){
    positions = fileToVector(positionFile);
    weights = fileToVector(weightFile);
}

vector<vector<int>>* Graph::getPositions(){
    return positions;
}

vector<vector<int>>* Graph::getWeights(){
    return weights;
}

vector<vector<int>>* Graph::fileToVector(string fileName){
    vector<vector<int>>* finalVector = new vector<vector<int>>();
    ifstream ifs;
	ifs.open(fileName);
	//Loops through file and adds all rows and colums to finalVector
	while(!(ifs.eof())){
        int temp;
		string line;
		ifs >> line;
        stringstream ss(line);
        vector<int> vect;
        while (getline(ss, temp, ', ')) { 
            vect.push_back(temp);
        }
        finalVector.push_back(vect);
	}
	ifs.close();
    return finalVector;
}