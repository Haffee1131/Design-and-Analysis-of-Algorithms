// KnapSack Algorithm Using Tabulation Technique

#include <stdio.h>

// Finding max value
int max(int a, int b) {
	if(a>=b)
		return a;
	return b;
}

int main() {

	// Read number of Items
	int noOfItems;
	printf("Number of Items: ");
	scanf("%d", &noOfItems);

	// Declaring Weight Array and Value Array
	int weights[noOfItems], values[noOfItems];

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

	int tabArray[noOfItems+1][maxWeight+1]; // Tabulation Array

	
	for(int i=0; i<=noOfItems; i++) {
		// Updating Tabulation Array 0th column with zero's
		tabArray[i][0] = 0;
		for(int j=0; j<=maxWeight; j++) {
			// Updating Tabulation Array 0th row with zero's
			tabArray[0][j] = 0;
			
			// Tabulation Logic
			if(i!=0 || j!=0) {
				if(weights[i-1] <= j)
					tabArray[i][j] = max(values[i-1] + tabArray[i-1][j-weights[i-1]], tabArray[i-1][j]); // Consider Condition
				else
					tabArray[i][j] = tabArray[i-1][j]; // Don't Consider Condition
			}
		}
	}
	
	int maxProfit = tabArray[noOfItems][maxWeight];
	printf("\n%d\n", maxProfit);
	
	// Tabulation Table
	printf("-----  TABLE  ------\n\n");
	for(int i=0; i<=noOfItems; i++) {
		for(int j=0; j<=maxWeight; j++) {
			printf("%d  ", tabArray[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//4
//1 5
//4 2
//2 7
//3 3
//6