//Floyed Warshall Algorithm using dynamic programming

#include <stdio.h>
#include <math.h>

void output(int n, int distanceMatrix[20][20]) {

	// Printing Shortest Distances
	printf("\n\nShortest Distances between Pairs\n\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d  ",distanceMatrix[i][j]);
		}
		printf("\n");
	}
}

void floyedWarshall(int n, int graph[20][20]) {
	
	int distanceMatrix[20][20]; // To store final shortest distances between vertex pairs

	// Copying graph into distanceMatrix
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			distanceMatrix[i][j] = graph[i][j];
		}
	}


	// Floyed-Warshall Logic
	
	// i => source vertex
	// j => destinaton vertex
	// k => intermediate vertex
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				
				// if distance through intermediate vertex is less than direct path => update value
				if(distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]) {
					distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
				}
			}
		}
	}

	output(n, distanceMatrix);
}


int main() {

	// Read number of vertices of graph
	int n;
	printf("Number of Vertices: ");
	scanf("%d", &n);

	int graph[20][20];

	// Read Graph values
	// input = 0 if i = j
	// input = 99 if no path exist
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d, %d: ", i, j);
			scanf("%d", &graph[i][j]);
		}
	}

	floyedWarshall(n, graph);

	return 0;
}

//4
//0 5 99 10 99 0 3 99 99 99 0 1 99 99 99 0
