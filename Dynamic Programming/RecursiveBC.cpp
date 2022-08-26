//Binomial Coefficient using Recursion
// nCk = (n-1)C(k-1) + nC(k-1)

#include <stdio.h>
#include <math.h>

// Binomial coefficient
int BC(int n, int k) {
	if(n==k || k==0)
		return 1;
	return BC(n-1, k-1) + BC(n-1, k);
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

	int result = BC(n,k);
	printf("%dC%d = %d\n", n, k, result);

	return 0;
}
