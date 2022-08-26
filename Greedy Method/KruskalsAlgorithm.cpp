// Kruskal's Algorithm Using Greedy Method

#include <stdio.h>
#include <math.h>

// To find parent of node
int findParent(int x, int parents[]) {
	// Loop runs until x has no parent(i.e it is the last node)
	while(parents[x] != -1)
		x = parents[x];
	return x;
}

int main() {

	// Read number of nodes
	int noOfNodes;
	printf("Number of Nodes: ");
	scanf("%d", &noOfNodes);

	int parents[noOfNodes];
	int adjMatrix[noOfNodes][noOfNodes];

	// Updating All Declared Arrays and Matrices
	printf("Adjacency Matrix: \n");
	for(int i=0; i<noOfNodes; i++) {
		parents[i] = -1;
		for(int j=i; j<noOfNodes; j++) {
			printf("node %d -> node %d: ", i, j);
			scanf("%d", &adjMatrix[i][j]);
			if(adjMatrix[i][j] == -1)
				adjMatrix[i][j] = 999;
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
	printf("\n");
	
	// Kruskal's Logic
	int u, v; // min cost nodes
	int totalCost = 0; // Total Cost for Spanning
	int edgesSpanned = 0; // Need noOfNodes-1 edges
	int minCost; // To store minCost every time
	
	while(edgesSpanned < (noOfNodes-1)) {
		minCost = 99999;
		// Finding minimum cost nodes = (u, v)
		for(int i=0; i<noOfNodes; i++) {
			for(int j=i; j<noOfNodes; j++) {
				if(adjMatrix[i][j] < minCost) {
					minCost = adjMatrix[i][j];
					u = i;
					v = j;
				}
			}
		}

		int uParent = findParent(u, parents);
		int vParent = findParent(v, parents);

		if(uParent != vParent) {
			parents[vParent] = uParent;
			totalCost += adjMatrix[u][v];
			printf("Edge Considered: %d -- %d  ==> cost: %d\n", u, v, adjMatrix[u][v]);
			edgesSpanned++;
		}
		// making min nodes as maximum(so as not to consider later)
		adjMatrix[u][v] = 999;
		adjMatrix[v][u] = 999;
	}
	printf("\nTotal Cost: %d\n", totalCost);

	return 0;
}
//7
//-1 2 -1 4 -1 5 -1 -1 7 1 3 8 4 -1 -1 10 -1 6 -1 2 -1 -1 -1 -1 -1 -1 1 -1

//Edge Considered: 1 -- 3
//Edge Considered: 5 -- 6
//Edge Considered: 0 -- 1
//Edge Considered: 3 -- 4
//Edge Considered: 1 -- 6
//Edge Considered: 2 -- 6
//
//Total Cost: 16