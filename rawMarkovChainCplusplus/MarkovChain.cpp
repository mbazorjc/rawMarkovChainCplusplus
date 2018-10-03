#include "MarkovChain.h"



MarkovChain::MarkovChain() // contructor
{
}


MarkovChain::~MarkovChain() // destructor
{
}

#include <iostream>

#include <stdio.h>		// for printf() 

#include <vector>  // for the vector class

using namespace std;




#define	N_STATES	2	// number of states 
#define N_STEPS		20	// number of steps

typedef double Vector[N_STATES];
typedef double Matrix[N_STATES][N_STATES]; // this is just a kind of alias

Vector initial = { .99, .01 }; // prior
Matrix transition = { .9, .1, .4, .6 }; //transition matrix

int main(int argc, char **argv)
{
	// display the transition matrix

	cout << "\n The Markov Chain Transition Matrix: " << endl;

	for (int i = 0; i < N_STATES; i++)
	{
		cout << "\n         " << endl;
		for (int j = 0; j < N_STATES; j++)
			cout << " %1.4f " << transition[i][j] << endl;
	}
	cout << ("\n\n");

	// display the sequence of state vectors
	Vector	current; // same size as the initial vector
	memcpy(current, initial, sizeof(current));
	for (int step = 0; step < N_STEPS; step++)
	{
		// display the current state vector
		cout << " State Vector %-4d " << step << endl;
		for (int j = 0; j < N_STATES; j++)
			cout << " %1.4f " << current[j] << endl;
		cout << ("\n\n");
		// compute the next state vector
		Vector	product; // the vector that contains the trantion matrix computation
		for (int j = 0; j < N_STATES; j++)
		{
			double	sum = 0.0;
			for (int k = 0; k < N_STATES; k++)
				sum += current[k] * transition[k][j]; // this performs a kind of bayes' update
			product[j] = sum;
		}
		memcpy(current, product, sizeof(current));

	}
	cin.get();
	return 0;
}
