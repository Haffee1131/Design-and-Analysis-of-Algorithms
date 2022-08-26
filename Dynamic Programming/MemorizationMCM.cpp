//Matrix Chain Multiplication Algorithm Using Memorization Technique

#include <stdio.h>
#include <cstring>

int memoArray[20][20]; // Memorization Table

int Mcm(int array[], int start, int end) {
	if(start >= end) // base case
		return 0;
	
	if(memoArray[start][end] != -1) // if value already memorized => can use it
		return memoArray[start][end];

	int minMultis = 999999, multis;
	for(int k=start; k<end; k++) {
		// Divide at index k and adding two resultant matrices cost
		multis = Mcm(array, start, k) + Mcm(array, k+1, end) + (array[start-1] * array[k] * array[end]);
		if(multis < minMultis)
			minMultis = multis;
	}
	memoArray[start][end] = minMultis;
	return minMultis;
}

int main() {

	// Read number of Matrices = n
	int n;
	printf("Number of Matrices: ");
	scanf("%d", &n);

	// Array to store p x q 's
	int array[n+1];

	// Read matrices lens
	printf("Enter Matrices p x q 's: ");
	for(int i=0; i<n+1; i++) {
		scanf("%d", &array[i]);
	}
	
	// initialising memoArray with -1's
	memset(memoArray, -1, sizeof(memoArray));
	
	// from 1 to noOfMatrices
	int TotalMinMultis = Mcm(array, 1, n);
	printf("\nMinimum Multiplications: %d", TotalMinMultis);

	return 0;
}

//4
//1 2 3 4 3

// Minimum Multiplications: 30