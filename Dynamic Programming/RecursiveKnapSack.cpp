// KnapSack Algorithm Using Recursion

#include <stdio.h>
#include <math.h>

int max(int a, int b){
	if(a>=b)
		return a;
	return b;
}

int KnapSack(int weights[], int values[], int n, int maxWeight){
	if(n == 0 || maxWeight == 0) // Base Condition
		return 0;
		
	if(weights[n-1] <= maxWeight)
		return max(values[n-1]+KnapSack(weights, values, n-1, maxWeight-weights[n-1]), //
				KnapSack(weights, values, n-1, maxWeight)); // Recursive Logic(consider, don't consider)
	
	else
		return KnapSack(weights, values, n-1, maxWeight); // if current weight is greater than max weight => don't consider
		
}


int main(){

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

	int maxProfit = KnapSack(weights, values, noOfItems, maxWeight);
	printf("%d", maxProfit);
	
	return 0;
}