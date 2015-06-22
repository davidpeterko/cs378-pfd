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

#include <iostream> 	// istream, ostream
#include <string>   	// string
#include <utility>  	// pair
#include <vector>		// std:: vector
#include <queue>		// std:: priority_queue
#include <functional> 	// std:: greater

using namespace std;

// ---------------------
// Function Declarations
// ---------------------

vector<vector<int> > matrix_fill_zero(int numoftasks, vector<vector<int> > matrix);
void print_matrix(ostream& w, vector<vector<int> > matrix);
void print_queue(ostream& w, priority_queue<int, vector<int>, greater<int> > pq);
void pfd_solve(istream& in, ostream& out);