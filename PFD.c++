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

// note: our data structure / priority queue should be delcared in the header file?
//use adjacency list-> list of unordered lsit



// ---------------------
// Function Declarations
// ---------------------


// ----
// pfd_read
// ----


// ---------
// pfd_print
// ---------
template<typename T> void pfd_print(T& q){
	
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}

	//cout << endl;
}



// ---------
// pfd_solve
// ---------
void pfd_solve(istream& in, ostream& out){

	//tasks and rules
	int num_tasks;
	int num_rules;

	in >> num_tasks;
	assert(num_tasks > 0);

	in >> num_rules;
	assert(num_rules > 0);

	//cout << "This is the number of tasks and the rules: " << num_tasks << num_rules << endl;

	vector<vector<int>> amatrix(num_tasks, vector<int>(num_tasks)); 
	priority_queue <int, vector<int>, greater<int>> pq;


	//fill the matrix with 0's
	for(int a = 0; a < num_tasks; ++a){
		for(int b = 0; b < num_tasks; ++b){
			amatrix[a][b] = 0;
		}
	}

	/** THIS BLOCK SETS THE 1'S IN MATRIX **/
	for(int i = 0; i < num_rules; ++i){
		
		int task_name;
		in >> task_name;
		assert(task_name > 0);

		int num_pred;
		in >> num_pred;
		assert(num_pred > 0);

		for(int j = 0; j < num_pred; ++j){

			int temp_pred;
			in >> temp_pred;

			amatrix[task_name-1][temp_pred-1] = 1;
		}
	}
	


	int dummy = num_tasks;

	while(dummy > 0){

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

		int size_of_pq = pq.size();

		//CLEAR and POP and PRINT
		for(int pq_size = 0; pq_size < size_of_pq; ++pq_size){

			for(int i = 0; i < num_tasks; ++i){

				int top_element = pq.top();		//grabs top element

				top_element = top_element - 1;	//subtract 1 to make sure its looking at right column

				amatrix[i][top_element] = 0;	//set that whole column to 0
			}

			int replace = pq.top() - 1;
			cout << pq.top() << " ";
			pq.pop();

			//cout << "This is now the size of the pq: " << pq.size() << endl;

			for(int j = 0; j < num_tasks; ++j){

				amatrix[replace][j] = 5;
			}

			dummy--;
		}

		//cout << endl;
	}



	//print matrix
	//when you are reading the matrix, dont froget to add one to the interation to get the correct task_name, i.e. int i = 0 is actually the task 0 + 1 = 1
	/*
	for(int c = 0; c < num_tasks; ++c){

		for(int d = 0; d < num_tasks; ++d){

			cout << '(' << amatrix[c][d] << ")";

		}
		cout<< endl;
	}
	*/
	

}


