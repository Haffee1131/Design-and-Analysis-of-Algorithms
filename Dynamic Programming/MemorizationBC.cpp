//Binomial Coefficient using Memorization Technique
// nCk = (n-1)C(k-1) + nC(k-1)

#include <stdio.h>
#include <math.h>

// memorization table
int memoTable[20][20];

// Binomial coefficient
int BC(int n, int k) {

	if(n==k || k==0){
		memoTable[n][k] = 1;
		return memoTable[n][k];
	}
	
	if(memoTable[n][k] != -1)
		return memoTable[n][k];

	else {
		memoTable[n][k] = BC(n-1, k-1) + BC(n-1, k);
		return memoTable[n][k];
	}
}

int main() {
	printf("N choose K (nCk) \n");
	
	// Read n value
	int n;
	printf("N value: ");
	scanf("%d", &n);

	// Read k value
	int k;
	printf("K value: ");
	scanf("%d", &k);

	// initialising memorization table values with -1
	for(int i=0; i<n+1; i++) {
		for(int j=0; j<k+1; j++) {
				memoTable[i][j] = -1;
		}
	}

	int result = BC(n, k);
	printf("%dC%d = %d\n", n, k, result);

	return 0;
}
