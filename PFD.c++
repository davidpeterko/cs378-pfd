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
#include <functional>
#include <vector>
#include <queue>
#include <sstream>

#include "PFD.h"

using namespace std;

//use adjacency list-> list of unordered lsit


// ---------------------
// Function Declarations
// ---------------------

// --------
// pfd_read
// --------


// ---------
// pfd_print
// ---------
template<typename T> void pfd_print(T& q){
	
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}

	cout << endl;
}



// ---------
// pfd_solve
// ---------
void pfd_solve(istream& in, ostream& out){

	priority_queue <int, vector<int>, greater<int>> pq;

	//tasks and rules
	int num_tasks;
	int num_rules;

	in >> num_tasks;
	assert(num_tasks > 0);

	in >> num_rules;
	assert(num_rules > 0);

	//now we have # of tasks and rules

	//feed in the next lines pfd_read

	for(int i = 0; i < num_rules; ++i){
		
		int task_name;

		in >> task_name;

		assert(task_name > 0);

		int num_pred;

		in >> num_pred;

		assert(num_pred > 0);

		//this for loop iterates through all the predecessors (all numbers after the value 'K')
		for(int j = 0; j < num_pred; ++j){

			//construct graph using these next rules

			//goes through the process of eliminating nodes with no predecessor

			//then one by one construct the output

			//should the output be in a PQ? then call pfd_print?


		}

	}
	
	

	//works
	pfd_print(pq);

}




