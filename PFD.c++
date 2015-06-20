// ------------------
// cs378-pfd/PFD.c++
// Copyright (C) 2015
// David Peter Ko
// ------------------

// -------
// Defines
// -------

// --------
// Includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include "PFD.h"

using namespace std;

// note: our data structure / priority queue should be delcared in the header file?

// ---------------------
// Function Declarations
// ---------------------

// ----
// pfd_read
// ----

void pfd_read(istream& input, vector<node>& nodes){

	//replace vector with our data structure?
	
	int tasks, rules, edges;
	input >> tasks;
	input >> rules;

	assert(tasks > 0);

	//Here we should have the 2 tasks and rules already put into our variables
	
	for(int i = 0; i < rules; i++){

		//iterate through the rules and put the rules into our data structure
		//the first input >> from this next line should be the identity of the task, then the next input >> should be the number of preceeding identities (which should be the number of edges)	

	}

	//Here the rules should be put into the data structure

}


// ---------
// pfd_print
// ---------

void pfd_print(ostream& output, priority_queue<node> nodes){
	assert(nodes.size() > 0);
	int front;

	//iterate through the nodes and output
	while(!nodes.empty()){
		//pop off the PQ and output

	}
	
	output << endl;
}



