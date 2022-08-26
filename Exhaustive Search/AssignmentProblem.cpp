// Assignment Algorithm Using Exhaustive Search Method

#include <stdio.h>
#include <math.h>

// Swap Function
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int minCost = 9999;
int minCostArray[20]; // Array to store min Assignment

void minCostAssignment(int jobs[], int end, int cost) {

	// Finding Minimum cost Assignment
	if(cost<minCost) {
		minCost = cost;

		// Storing Min Assignment 
		for(int j=0; j<end; j++) {
			minCostArray[j] = jobs[j];
		}
	}
}

void CalculateCost(int jobs[], int end, int jobsCostMatrix[][10]) {

	int cost=0;
	for(int i=0; i<end; i++) {
		cost += jobsCostMatrix[i][jobs[i]];
	}
	minCostAssignment(jobs, end, cost);
}

void Assignment(int jobs[], int start, int end, int jobsCostMatrix[][10]) {
	if(start == end) {
		CalculateCost(jobs, end, jobsCostMatrix);
	} else {
		for(int i=start; i<end; i++) {
			Swap(&jobs[start], &jobs[i]);
			Assignment(jobs, start+1, end, jobsCostMatrix);
			Swap(&jobs[start], &jobs[i]);
		}
	}
}

int main() {

	// Read Number of Persons
	int n;
	printf("Number of Persons: ");
	scanf("%d", &n);

	int jobs[n];
	int jobsCostMatrix[10][10];

	// Read jobs cost Matrix
	printf("Jobs Cost Matrix: \n");
	for(int i=0; i<n; i++) {
		jobs[i] = i;
		for(int j=0; j<n; j++) {
			printf("Person %d Job %d Cost: ", i, j);
			scanf("%d", &jobsCostMatrix[i][j]);
		}
	}

	Assignment(jobs, 0, n, jobsCostMatrix);

	// Printing min cost
	printf("\n\nMinimum Cost: %d\n", minCost);
	
	//Printing Min Cost Assignment
	printf("\n---  Assignment  ---\n");
	for(int j=0; j<n; j++) {
		printf("person %d => job %d\n", j, minCostArray[j]);
	}

	return 0;
}

//4 
//5 2 4 8 6 4 3 5 5 8 1 8 3 3 9 7
