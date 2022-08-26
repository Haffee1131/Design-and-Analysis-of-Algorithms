// Fractional KnapSack Algorithm Using Greedy Method

#include <stdio.h>
#include <math.h>


void GreedyKnapSack(int weights[], int values[], double profits[], int noOfItems, int maxWeight) {

	double maxProfit = 0; // To store Global max Profit
	int maxProfitArray[20]; // To store items
	int maxProfitIndex; // To store max profit index value
	double localMaxProfit; // To find max Profit Every Time

	int k=0;
	for(int i=0; i<noOfItems; i++) {
		localMaxProfit = -1; // For Every Loop local max profit will be resetted to -1
		for(int j=0; j<noOfItems; j++) {

			// Finding local max profit and its index
			if(profits[j] > localMaxProfit) {
				localMaxProfit = profits[j];
				maxProfitIndex = j;
			}
		}
		// assigning local max profit's index value with -1
		profits[maxProfitIndex] = -1;

		if(weights[maxProfitIndex] <= maxWeight) {
			maxProfit += values[maxProfitIndex];
			maxWeight = maxWeight - weights[maxProfitIndex];

			maxProfitArray[k] = maxProfitIndex; // updating max profit array
			k++;
		}
		// Fractional KnapSack Logic
		else{
			maxProfit += maxWeight*((double)values[maxProfitIndex]/weights[maxProfitIndex]);
			maxWeight = 0;
			maxProfitArray[k] = maxProfitIndex; // updating max profit array
			k++;
			break;
		}
	}

	// Max Profit
	printf("\nMaximum Profit: %f\n", maxProfit);

	// Printing Items Consisiting Max Profit
	printf("Maximum Profit Items: ");
	for(int i=0; i<k; i++)
		printf("%d, ", maxProfitArray[i]);
}

int main() {

	// Read number of Items
	int noOfItems;
	printf("Number of Items: ");
	scanf("%d", &noOfItems);

	// Declaring Weight Array and Value Array
	int weights[noOfItems], values[noOfItems];
	double profits[noOfItems];

	// Reading Weight Array and Value Array Values
	printf("Enter Weight Array and Value Array Values\n");
	for(int i=0; i<noOfItems; i++) {
		printf("Item %d: ", i);
		scanf("%d %d", &weights[i], &values[i]);

		profits[i] = (double)values[i]/weights[i]; // Updating profit array
	}

	// Read Maximum Weight
	int maxWeight;
	printf("maxWeight: ");
	scanf("%d", &maxWeight);

	GreedyKnapSack(weights, values, profits, noOfItems, maxWeight);

	return 0;
}
//4
//1 5
//4 2
//2 7
//3 3
//2
