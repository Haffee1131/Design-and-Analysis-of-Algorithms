//Matrix Chain Multiplication Algorithm Using Memorization Technique

#include <stdio.h>
#include <cstring>

int Mcm(int array[], int n) {

	int tabTable[20][20]; // tabulation Table

	// implementing base case
	for(int i=1; i<n; i++)
		tabTable[i][i] = 0;
	
	int multis;
	// for lengths from 2 to n
	for(int length=2; length<=n; length++){
		// i is from startlength to tolength of considered len length's
		for(int i=1; i<=n-length+1; i++){
			int j = length + (i-1);
			tabTable[i][j] = 9999;
			// k is to point upto where matrices are selected
			for(int k=1; k<=length-1; k++) {
				multis = tabTable[i][k] + tabTable[k+1][j]+ (array[i-1] * array[k] * array[j]);
				if(multis < tabTable[i][j])
					tabTable[i][j] = multis;
			}	
		}
	}
	
	return tabTable[1][n-1];
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
	for(int i=0; i<(n+1); i++) {
		scanf("%d", &array[i]);
	}

	// from 1 to noOfMatrices
	int TotalMinMultis = Mcm(array, n+1);
	printf("\nMinimum Multiplications: %d", TotalMinMultis);

	return 0;
}

//4
//1 2 3 4 3

// Minimum Multiplications: 30