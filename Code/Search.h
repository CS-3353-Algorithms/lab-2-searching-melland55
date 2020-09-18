#ifndef SEARCH_H
#define SEARCH_H

#include "Algorithm.h"
#include <string>
#include <vector>
using namespace std;

class Search : public Algorithm
{
    public:
        Search();
        Search(int, int);
        ~Search();
        void load(string, string, string);
        void execute();
        void display();
        void stats(string);
        void select(int);
        void save(string);
        void configure();

    private:
		int source;
		int destination;
        string currentAlgo;

    	//Pointer that can point to any of the searching functions
        vector<int>* (*searchAlgoFuncPointer)(int, int);
};
#endif