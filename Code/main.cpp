#include "Search.h"
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    string path = "../Data/SampleGraph/";
	string graph = "graph.txt";
	string positions = "positions.txt";
	string weights = "weights.txt";
    Algorithm *search;
    Graph data(path+graph, path+positions, path+weights);
    /*vector<vector<double>>* temp = data.getWeights();
    for(int i = 0; i < temp->size(); i++){
        for(int j = 0; j < temp->at(i).size() - 1; j++){
            cout << temp->at(i).at(j) << ", ";
        }
        cout << temp->at(i).at(temp->at(i).size() - 1) << endl;
    }*/
    LinkedList<int>* list = new LinkedList<int>();
    list->prepend(10);
    cout << list->getSize() << endl;
    list->prepend(9);
    cout << list->getSize() << endl;
    list->prepend(8);
    cout << list->getSize() << endl;
    cout << list->head->data << list->head->next->data << list->tail->data << endl;
    cout << list->pop();
    cout << list->pop();
    cout << list->pop();
	/*
	//Loads command line arguments and creates Algorithm type Search
	if(argc > 1){
        search = new Search(stoi(argv[1]), stoi(argv[2]));
	} else {
        search = new Search(0, 0);
	}
	
	//search->load();
	search->display();

	for(int k = Algorithm::BFS_ITERATIVE; k < Algorithm::END; k++){
		search->select(k);
		search->execute();
		//search->stats();
		//searcher->save();
	}*/
    while(true){

    }
    return 0;
}
