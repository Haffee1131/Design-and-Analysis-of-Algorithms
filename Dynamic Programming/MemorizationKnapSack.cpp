// KnapSack Algorithm Using Memorization Technique

#include <stdio.h>
#include <string.h>

int memoArray[30][30];
//memset(memoArray, -1, sizeof(memoArray));

int max(int a, int b) {
	if(a>=b)
		return a;
	return b;
}

int KnapSack(int weights[], int values[], int n, int maxWeight) {
	if(n == 0 || maxWeight == 0){ // Break Condition
		return 0;
	}

	if(memoArray[n][maxWeight]!= -1)
		return memoArray[n][maxWeight];
	else {
		if(weights[n-1] <= maxWeight) {
			memoArray[n][maxWeight] = max(values[n-1]+KnapSack(weights, values, n-1, maxWeight-weights[n-1]), //
			                              KnapSack(weights, values, n-1, maxWeight)); // Recursive Logic(consider, don't consider)
			return memoArray[n][maxWeight];
		}

		else {
			memoArray[n][maxWeight] = KnapSack(weights, values, n-1, maxWeight); // if current weight is greater than max weight => don't consider
			return memoArray[n][maxWeight];
		}

	}
}


int main() {

	// Read number of Items
	int noOfItems;
	printf("Number of Items: ");
	scanf("%d", &noOfItems);

	// Declaring Weight Array and Value Array
	int weights[noOfItems+1], values[noOfItems+1];

	// Reading Weight Array and Value Array Values
	printf("Enter Weight Array and Value Array Values\n");
	for(int i=0; i<noOfItems; i++) {
		printf("Item %d: ", i);
		scanf("%d %d", &weights[i], &values[i]);
	}

	// Read Maximum Weight
	int maxWeight;
	printf("maxWeight: ");
	scanf("%d", &maxWeight);

	for(int i=0; i<=noOfItems; i++) {
		for(int j=0; j<=maxWeight; j++) {
			if(i==0 || j==0)
				memoArray[i][j] = 0;
			else
				memoArray[i][j] = -1;
		}
	}

	for(int i=0; i<=noOfItems; i++) {
		for(int j=0; j<=maxWeight; j++) {
			printf("%d  ", memoArray[i][j]);
		}
		printf("\n\n");
	}

	int maxProfit = KnapSack(weights, values, noOfItems, maxWeight);
	printf("%d\n\n", maxProfit);

	for(int i=0; i<=noOfItems; i++) {
		for(int j=0; j<=maxWeight; j++) {
			printf("%d  ", memoArray[i][j]);
		}
		printf("\n\n");
	}

	return 0;
}

//4
//1 5
//4 2
//2 7
//3 3
//6