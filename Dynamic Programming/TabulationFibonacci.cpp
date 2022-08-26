// Tabulation Fibonacci Algorithm

#include <stdio.h>

int main(){
	
	// Read n value
	int n;
	printf("N value: ");
	scanf("%d", &n);
	
	int fibArray[n];
	
	fibArray[0] = 0; // First value = 0
	fibArray[1] = 1; // Second value = 1
	
	// Updating fibArray
	for(int i=2; i<n; i++){
		fibArray[i] =  fibArray[i-1] + fibArray[i-2];
	}

	// printing fibArray values
	for(int i=0; i<n; i++) {
		printf("%d, ", fibArray[i]);
	}
	
	return 0;
}
