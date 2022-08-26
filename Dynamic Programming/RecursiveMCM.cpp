//Matrix Chain Multiplication Algorithm

#include <stdio.h>
#include <math.h>

int Mcm(int array[], int start, int end) {
	if(start >= end)
		return 0;

	int minMultis = 999999, multis;
	for(int k=start; k<end; k++) {
		// Divide at index k and adding two resultant matrices cost
		multis = Mcm(array, start, k) + Mcm(array, k+1, end) + (array[start-1] * array[k] * array[end]);
		
		if(multis < minMultis)
			minMultis = multis;
	}
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
	
	// from 1 to noOfMatrices
	int TotalMinMultis = Mcm(array, 1, n);
	printf("\nMinimum Multiplications: %d", TotalMinMultis);

	return 0;
}

//4
//1 2 3 4 3

// Minimum Multiplications: 30