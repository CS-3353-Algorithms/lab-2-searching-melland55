#include "Search.h"
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	string graph = "graph.txt";
	string positions = "positions.txt";
	string weights = "weights.txt";
    Algorithm *search;
	
	//Loads command line arguments and creates Algorithm type Search
	if(argc > 1){
        search = new Search(stoi(argv[1]), stoi(argv[2]));
	} else {
        search = new Search(0, 0);
	}
	
	search->load(graph, positions, weights);
	search->display();

	for(int k = Algorithm::BFS_ITERATIVE; k < Algorithm::END; k++){
		search->select(k);
		search->execute();
		//search->stats();
		//searcher->save();
	}
    return 0;
}
