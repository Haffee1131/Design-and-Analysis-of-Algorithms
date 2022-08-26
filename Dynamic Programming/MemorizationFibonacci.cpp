// Memorization Fibonacci Algorithm

#include <stdio.h>

// Array to store fib values
int fibArray[50];

int fib(int n) {
	
	if(n==0 || n==1){
		
		fibArray[n] = n;
		return fibArray[n];
	}
	
	if(fibArray[n] != -1)// If values already present -> no need to recur...
		return fibArray[n];

	fibArray[n] = fib(n-1) + fib(n-2); // Storing in fibArray
	
	return fibArray[n];
}

int main() {

	// Read n value
	int n;
	printf("N value: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++) // initialising fibArray with -1's
		fibArray[i] = -1;
		
	int result = fib(n-1);
//	printf("%d\n", result);

	// printing fibArray values
	for(int i=0; i<n; i++) {
		printf("%d, ", fibArray[i]);
	}

	return 0;
}
