#include "Search.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	vector<vector<string>> graphs;
	vector<string> temp;
	temp.push_back("../Data/SampleGraph/graph.txt");
	temp.push_back("../Data/SampleGraph/positions.txt");
	temp.push_back("../Data/SampleGraph/weights.txt");
	graphs.push_back(temp);
	temp.clear();
	temp.push_back("../Data/Large50/largeGraph.txt");
	temp.push_back("../Data/Large50/largePositions.txt");
	temp.push_back("../Data/Large50/largeWeights.txt");
	graphs.push_back(temp);
	temp.clear();
	temp.push_back("../Data/Large100/largeGraph.txt");
	temp.push_back("../Data/Large100/largePositions.txt");
	temp.push_back("../Data/Large100/largeWeights.txt");
	graphs.push_back(temp);
	vector<string> outputFiles;
	outputFiles.push_back("../Data/outputSample.csv");
	outputFiles.push_back("../Data/outputLarge50.csv");
	outputFiles.push_back("../Data/outputLarge100.csv");
	Algorithm* search;
    srand (time(0));
	if(argc > 1){
        search = new Search(stoi(argv[1]), stoi(argv[2]));
	} else {
        search = new Search(1, 2);
		for(int k = 2; k < graphs.size(); k++){
			ifstream tempFile(graphs.at(k).at(1));
			int numNodes = 0;
			if(tempFile.is_open()){
				string temp;
				while(!tempFile.eof()){
					getline(tempFile,temp);
					numNodes++;
				}
				tempFile.close();
			}
			search->load(graphs.at(k).at(0), graphs.at(k).at(1), graphs.at(k).at(2));
			for(int i = 0; i < 100; i++){
				search->configure(rand() % numNodes + 1, rand() % numNodes + 1);
				for(int j = Algorithm::BFS_ITERATIVE; j < Algorithm::END; j++){
					search->select(j);
					search->execute();
					//search->stats();
					search->save(outputFiles.at(k));
				}
			}
		}
	}
    while(true){
	}
    return 0;
}
