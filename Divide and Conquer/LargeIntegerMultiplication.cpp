//Large Integer Multiplication Using Divider and Conquer Method

#include <stdio.h>
#include <math.h>

long long unsigned Multiply(long long unsigned num1, long long unsigned num2){
	if(num1<10 || num2<10)
		return num1*num2;
	int len1 = log10(num1)+1; // num1 length
	int len2 = log10(num2)+1; // num2 length
	
	// Finding maximum of 2 lengths = n
	int n; 
	if(len1 >= len2)
		n = len1;
	else
		n = len2;
		
	// Finding a1a0, b1b0
	long long unsigned a1, a0, b1, b0;
	a1 = num1 / pow(10, n/2);	
	a0 = num1 % (long long unsigned)pow(10, n/2);
	b1 = num2 / pow(10, n/2);
	b0 = num2 % (long long unsigned)pow(10, n/2);
	printf("%llu, %llu, %llu, %llu\n\n", a1, a0, b1, b0);
	
	// Formula Substitution
	int c0 = Multiply(a0, b0); // c0 = a0b0
	int c2 = Multiply(a1, b1); // c2 = a1b1
	int c1 = Multiply((a0 + a1), (b0 + b1)) - c0 - c2; // (a0 + a1) * (b0 + b1)) - c0 - c2
	if(n%2==1) // if n is odd make it even
		n = n-1;
	return(c2*pow(10, n) + c1*pow(10, n/2) + c0);
}



int main(){
	
	// Read First and Second Number
	long long unsigned num1, num2;
	printf("First Number: ");
	scanf("%llu", &num1);
	printf("Second Number: ");
	scanf("%llu", &num2);
	
	long long unsigned result = Multiply(num1, num2);
	printf("Multiplication: %llu * %llu = %llu\n", num1, num2, result);
	printf("Actual Multiplication: %llu", num1*num2);
	
	return 0;
}
