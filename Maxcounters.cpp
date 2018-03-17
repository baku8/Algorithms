// You are given N counters, initially set to 0, and you have two possible operations on them :
// - increase(X) − counter X is increased by 1,
// - max counter − all counters are set to the maximum value of any counter.
// A non - empty zero - indexed array A of M integers is given.This array represents consecutive operations :
// if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
// if A[K] = N + 1 then operation K is max counter.
// N and M are integers within the range [1..100,000];
// each element of array A is an integer within the range[1..N + 1].
// example A[0] =  3 -> means that you should increase counter '3'; A[1] = 1 -> increase counter '1'

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> &A) {

	vector <int> C;
	int max = 0; // max value of counters
	int *wsk;
	wsk = new int[N];
	memset(wsk, 0, N * sizeof(int)); // set all values to '0' (initializing)

	for (unsigned int i = 0; i < A.size(); i++) {
		if (A[i] < (N + 1) && A[i] > 0) {
			wsk[(A[i] - 1)]++;
		// set 'max' value of counters
		if (max < wsk[(A[i] - 1)]) max = wsk[(A[i] - 1)];
		}
		// set to the maximum value of any counter
		if (A[i] == (N + 1)) {
			for (int j = 0; j < N; j++) {
				wsk[j] = max;
			}
		}
	}
	// write array to vector
	for (int j = 0; j < N; j++) {
		cout << wsk[j] << " ";
		C.push_back(wsk[j]);
	}
	return C;
}

int main()
{
	int N = 5; //  nbr of counters
	vector <int > A{ 3,4,4,6,1,4,4 };

	solution(N, A);
		
	return 0;
}

