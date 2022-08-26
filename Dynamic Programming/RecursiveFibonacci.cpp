// Fibonnaci Algorithm

#include <stdio.h>

int fib(int n){
	if(n==0 || n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

int main(){
	
	// Read n value
	int n;
	printf("N value: ");
	scanf("%d", &n);
		
	int result = fib(n-1);
	printf("%d ", result);
	
	return 0;
}
