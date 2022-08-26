//Optimal Merge Algorithm

#include <stdio.h>
#include <math.h>

int mergeSum = 0;
void Merge(int lensArray[], int n) {
	if(n == 1) // if only 1 length is present => it is the total sum
		return ;

	// initialising to find min values and indexes
	int min1 = 999, min2 = 999;
	int index1 = -1, index2 = -1;

	for(int i=0; i<n; i++) {
		// if current element < min1 => update min1 and min2
		if(lensArray[i] < min1) {
			// storing min1 into min2
			min2 = min1;
			index2 = index1;

			// updating min1
			min1 = lensArray[i];
			index1 = i;
		}
		// if current element < min2 => update min2 only
		else if(lensArray[i] < min2) {
			min2 = lensArray[i];
			index2 = i;
		}
	}
	int sum = lensArray[index1] + lensArray[index2];
	mergeSum += sum;

	lensArray[index1] = sum; // storing sum in first min value's place
	lensArray[index2] = lensArray[n-1]; // Replacing min2 value with last element and recursive call with n--;
	
	// Printing modified array
	for(int i=0; i<n-1; i++) {
		printf("%d, ", lensArray[i]);
	}
	printf(" ==> %d", sum);
	printf("\n");

	
	Merge(lensArray, n-1);

}

int main() {

	// Read Number of Arrays = (n)
	int n;
	printf("Number of Arrays: ");
	scanf("%d", &n);

	int lensArray[n]; // array of array Lengths

	// Read Array Lengths
	for(int i=0; i<n; i++) {
		printf("Array %d Length: ", i);
		scanf("%d", &lensArray[i]);
	}

	Merge(lensArray, n);
	printf("\nTotal Merge Sum: %d\n", mergeSum);

	return 0;
}

//6
//10 8 5 6 4 3