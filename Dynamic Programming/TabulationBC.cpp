//Binomial Coefficient using Tabulation Technique
// nCk = (n-1)C(k-1) + nC(k-1)

#include <stdio.h>
#include <math.h>

// Binomial coefficient
int BC(int n, int k) {

	// Tabulation table
	int tabTable[20][20];

	for(int i=0; i<n+1; i++) {
		for(int j=0; j<k+1; j++) {
			// since, nC0 = 1, nCn = 1
			if(j==0 || i==j)
				tabTable[i][j] = 1;
			else
				tabTable[i][j] = tabTable[i-1][j-1] + tabTable[i-1][j];
		}
	}
	return tabTable[n][k];
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

	int result = BC(n, k);
	printf("%dC%d = %d\n", n, k, result);

	return 0;
}
