//KnapSack Algorithm Using Exhaustive Search Method

#include <stdio.h>
#include <math.h>

int maxProfit = -1;

void KnapSack(int weights[], int values[], int noOfItems, int maxWeight) {

	int subSet[noOfItems]; // New Array to Store Subsets
	int subSetSize = pow(2, noOfItems); // SubSet Size
	int bestSubSet[noOfItems]; // To Store Best SubSet
	int bestLen; // Best Subset Length
	
	for(int i=1; i<subSetSize; i++) { // i starts from 1 to leave null set
		int weight = 0, profit = 0, k = 0;
		for(int j=0; j<noOfItems; j++) {
			if(i & (1<<j)) { // Bit Masking Approach
//				printf("i: %d, j: %d,  1<<j: %d, i&(1<<j): %d \n\n", i, j, 1<<j, i&(1<<j));
				if((weight+weights[j]) <= maxWeight){
					weight += weights[j];
					profit += values[j];
					
					subSet[k] = j;
					k++;
				}
			}
		}
		if(profit > maxProfit){
			maxProfit = profit;
			bestLen = k;
			
			// Updating Best SubSet
			for(int m=0; m<bestLen; m++){
				bestSubSet[m] = subSet[m];
			}			
		}
	}
	printf("\nMaximum Profit Items: ");
	for(int m=0; m<bestLen; m++){
		printf("%d, ", bestSubSet[m]);
	}
	printf("\nMaximum Profit: %d", maxProfit);
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

	KnapSack(weights, values, noOfItems, maxWeight);
	
	return 0;
}

//4
//2 20
//5 30
//10 50
//5 10
//16
