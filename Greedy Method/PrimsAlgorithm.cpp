// Prim's Algorithm Using Greedy Method

#include <stdio.h>
#include <math.h>

int main() {

	// Read number of nodes
	int noOfNodes;
	printf("Number of Nodes: ");
	scanf("%d", &noOfNodes);

	int parents[noOfNodes], costs[noOfNodes], visited[noOfNodes];
	int adjMatrix[noOfNodes][noOfNodes];

	// Updating All Declared Arrays and Matrices
	printf("Adjacency Matrix: \n");
	for(int i=0; i<noOfNodes; i++) {
		parents[i] = -1;
		costs[i] = 9999;
		visited[i] = 0;
		for(int j=i; j<noOfNodes; j++) {
			printf("node %d -> node %d: ", i, j);
			scanf("%d", &adjMatrix[i][j]);
			adjMatrix[j][i] = adjMatrix[i][j];
		}
	}
	
	// Printing Adjacency Matrix
	printf("\n\n----  Ajacency Matrix  ----\n");
	for(int i=0; i<noOfNodes; i++) {
		for(int j=0; j<noOfNodes; j++) {
			printf("%d\t", adjMatrix[i][j]);
		}
		printf("\n");
	}

	int startNode;
	printf("\nStart Node: ");
	scanf("%d", &startNode);
	printf("\n");

	costs[startNode] = 0; //cost of starting Node to zero(to make it minimum)


	// Prim's Logic
	for(int k=0; k<noOfNodes-1; k++) {
		int minNode;
		int minCost = 9999;
		// Finding minimum node
		for(int i=0; i<noOfNodes; i++) {
			if(visited[i] == 0 && costs[i] < minCost) {
				minCost = costs[i];
				minNode = i;
			}
		}
		visited[minNode] = 1; // making min node as visited
		for(int j=0; j<noOfNodes; j++) {
			//conditions:  1. Non Visited  2. finding its linked nodes  3. adjMatrix cost < cost matrix cost
			if(visited[j] == 0 && adjMatrix[minNode][j] != -1 && adjMatrix[minNode][j] < costs[j]) {
					costs[j] = adjMatrix[minNode][j];
					parents[j] = minNode;
			}
		}
	}

	// printing nodes - parent - cost
	int totalCost = 0;
	printf("Spanning Result: \n");
	for(int i=0; i<noOfNodes; i++) {
		totalCost += adjMatrix[i][parents[i]];
		printf("Node %d : parent %d ==> cost: %d\n", i, parents[i], adjMatrix[i][parents[i]]);
	}
	printf("\nTotal Cost: %d\n", totalCost);

	return 0;
}
//7 
//-1 2 -1 4 -1 5 -1 -1 7 1 3 8 4 -1 -1 10 -1 6 -1 2 -1 -1 -1 -1 -1 -1 1 -1

//Spanning Result:
//Node 0 : parent -1 ==> cost: 0
//Node 1 : parent 0 ==> cost: 2
//Node 2 : parent 6 ==> cost: 6
//Node 3 : parent 1 ==> cost: 1
//Node 4 : parent 3 ==> cost: 2
//Node 5 : parent 6 ==> cost: 1
//Node 6 : parent 1 ==> cost: 4
//
//Total Cost: 16