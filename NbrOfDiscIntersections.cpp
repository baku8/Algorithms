// 
// We draw N discs on a plane.The discs are numbered from 0 to N − 1. A zero - indexed array A of N non - negative integers, 
// specifying the radiuses of the discs, is given.The J - th disc is drawn with its center at(J, 0) and radius A[J].

// We say that the J - th disc and K - th disc intersect if J ≠ K and the J - th and K - th discs have at least one common point.

// The figure below shows discs drawn for N = 6 and A as follows :A[0] = 1, A[1] = 5, A[2] = 2, A[3] = 1, A[4] = 4, A[5] = 0

//There are eleven(unordered) pairs of discs that intersect, namely:
// - discs 1 and 4 intersect, and both intersect with all the other discs;
// - disc 2 also intersects with discs 0 and 3.
// Write a function : int solution(vector<int> &A);
// The function should return −1 if the number of intersecting pairs exceeds 10, 000, 000.
// Given array A shown above, the function should return 11, as explained above.

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int x = 0; // counter of unordered pairs
	for (unsigned int i = 0; i < A.size(); i++) {
		for (unsigned int j = 0; j < A.size(); j++){
			if (i != j && (j - A[j]) <= (i + A[i]) && (i - A[i]) <= (j + A[j])) {
				x++;
				if (x/2 > 10000000) return -1; // if exceeds 10 000 000
			}
		}
	}
	// value should be devided to remove double score
	cout << "Number of discs which has at least one common point = " << x / 2 << endl;
	return x/2;
}

int main()
{ 
	vector <int> A;
	// vector for testing with result x=11
	A.push_back(1);
	A.push_back(5);
	A.push_back(2);
	A.push_back(1);
	A.push_back(4);
	A.push_back(0);

	solution(A);

    return 0;
}

