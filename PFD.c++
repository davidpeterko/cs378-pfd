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
#include <algorithm> 

#include "PFD.h"

using namespace std;

// ---------------------
// Function Declarations
// ---------------------

// ----------------
// matrix_fill_zero
// ----------------
void matrix_fill_zero(int numoftasks, vector<vector<int> > matrix){
	for(int a = 0; a < numoftasks; ++a){
		for(int b = 0; b < numoftasks; ++b){
			matrix[a][b] = 0;
		}
	}
}

// ------------
// print matrix
// ------------
void print_matrix(vector<vector<int> > matrix){
	for(unsigned int i = 0; i < matrix.size(); ++i){

		for(unsigned int j = 0; j < matrix[i].size(); ++j){

			cout << '(' << matrix[i][j] << ")";

		}
		cout<< endl;
	}
}


// ---------
// pfd_solve
// ---------
void pfd_solve(istream& in, ostream& out){

	int num_tasks;
	int num_rules;

	in >> num_tasks;
	assert(num_tasks > 0);
	assert(num_tasks <= 100);											// N <= 100

	in >> num_rules;
	assert(num_rules > 0);
	assert(num_rules <= 100);	
	assert(num_rules < num_tasks);										// M <= 100

	/* Data Structures */
	vector<vector<int> > amatrix(num_tasks, vector<int>(num_tasks)); 
	vector<int> check;

	for(int i = 0; i < num_rules; ++i){
		int task_name;
		in >> task_name;
		assert(task_name <= num_tasks);	

		/** check for no duplicate tasks **/
		assert(find(check.begin(), check.end(), task_name) == check.end());
		check.push_back(task_name);

		int num_pred;
		in >> num_pred;
		assert(num_pred < num_tasks);

		for(int j = 0; j < num_pred; ++j){
			int temp_pred;
			in >> temp_pred;

			amatrix[task_name-1][temp_pred-1] = 1;
		}
	}

	int dummy = num_tasks;

	while(dummy > 0){

		priority_queue<int, vector<int>, greater<int> > pq;

		//SCANNING for which ROWS are full 0s, 
		for(int row = 0; row < num_tasks; ++row){
			bool flag = false;											//flag set to false if it hits a 1, then true

			for(int column = 0; column < num_tasks; ++column){
				if(amatrix[row][column] == 1 || amatrix[row][column] == 5){
					flag = true;
				}
			}

			if(flag == false){
				int value = row + 1;
				pq.push(value);
			}
		}

		//CLEAR and POP and PRINT
		//for(unsigned int pq_size = 0; pq_size < pq.size(); ++pq_size){

			for(int i = 0; i < num_tasks; ++i){
				int top_element = pq.top();		//grabs top element
				top_element = top_element - 1;	//subtract 1 to make sure its looking at right column
				amatrix[i][top_element] = 0;	//set that whole column to 0
			}

			int replace = pq.top() - 1;

			if(dummy == 1){
				cout << pq.top();
			} 
			else{
				cout << pq.top() << " ";
			}	

			pq.pop();

			amatrix[replace][0] = 5;
			//cout << endl;
			//print_matrix(amatrix);
			
			//for(unsigned int i =0; i < pq.size(); ++i){
			//		pq.pop();
			//}
			dummy--;


		}



	//} print clear bracket

	//print_matrix(amatrix);
}