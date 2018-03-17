// SocksLaundering.cpp:
// Bob has exactly N clean and M dirty socks, which are described in arrays C and D, respectively. 
// The colors of the socks are represented as integers (equal numbers representing identical colors).
// given an integer K(the number of socks that the washing machine can clean), 
// two arrays C and D(containing the color representations of N clean and M dirty socks respectively), 
// returns the maximum number of pairs of socks that Bob can take on the trip.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int K, vector<int> &C, vector<int> &D) {
	int p = 0; // nbr of clean pairs
	int w = 0; // nbr of washed single dirty sock to achieve pair with clean sock
	int dp = 0; // nbr of dirty pairs
	int kk = K; // nbr of remained slots in the washer

	// sorting by color (number)
	sort(C.begin(), C.begin() + C.size());
	sort(D.begin(), D.begin() + D.size());

	// remove clear pairs from 'C' Clean vector
	for (unsigned int i = 0; i < (C.size() - 1); i++) {
		if (C[i] == C[i + 1]) {
			C.erase(C.begin() + i+1);
			C.erase(C.begin() + i);
			i--;
			p++;
		}
	}

	// when the washing machine can't clean (K=0)
	if (K == 0) {
		return p;
	}

	// searching single dirty sock for single clean sock and check free slot in the washer
	for (unsigned int i = 0; i < C.size(); i++){
		if (kk != 0) {
			for (unsigned int j = 0; j < D.size(); j++) {
				if (C[i] == D[j]) {
					w++;
					kk--; // decrease nbr of free slot in the washer
					D.erase(D.begin() + j);
					j = D.size(); // set 'j' to the end of loop
				}
			}
		}
	}

	// changing 'kk' to the even -> next, will search for pairs (2 socks) in dirty vector
	if (kk % 2 != 0)kk--;

	// searching for the dirty pairs to wash and checking free slots (kk) in the washer at the same time
	if (kk != 0) {
		// checking nbr of dirty pairs
		for (unsigned int i = 0; i < (D.size() - 1); i++) {
			if (D[i] == D[i + 1]) {
				dp++; // increase nbr of dirty pairs
				i++;
			}
		}
		// allocation dirty pairs to free place in the washer 
		while (kk!=0 && dp !=0) {
			w++;
			dp--; 
			kk-=2; // pair = 2 socks
		}
	}
		// add washed pairs to stock
	p += w;
	cout << "the maximum number of pairs of socks that Bob can take on the trip =  " << p << endl;
	return p;
}

int main()
{
	int K1 = 15;
	int K2 = 2;
	
	vector <int> C1 {1,1,1,4,5,7,2,4,7,44,22,11,49,11,2,44,1};
	vector <int> D1 {5,7,3,8,38,46,22,48,31,29,2,1};
	solution(K1, C1, D1);
	/*
	vector <int> C2 {3,2,2};
	vector <int> D2 {1,2,3};

	solution(K2, C2, D2);
	*/

    return 0;
}

