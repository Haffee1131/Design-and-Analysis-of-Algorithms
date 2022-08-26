// Travelling Salesman Problem using Exhaustive Search Method

#include <stdio.h>

// Swap Function
void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int minDistance = 9999;
int minDistanceArray[20]; // Array to store min Assignment

void minDistancePath(int cities[], int end, int distance) {

	// Finding Minimum Distance Path
	if(distance<minDistance) {
		minDistance = distance;


		// Storing Min Distance Path
		minDistanceArray[0] = cities[end]; // first city => starting city
		for(int j=0; j<=end; j++) {
			minDistanceArray[j+1] = cities[j]; // updates from second city
		}
	//	minDistanceArray[end+1] = cities[end]; // updating last city i.e starting city
	}
}

void CalculateDistance(int cities[], int end, int distanceMatrix[][10]) {

	int distance = distanceMatrix[cities[end]][cities[0]]; // distance = startingCity -> cities[0]
	for(int i=0; i<end; i++) {
		distance += distanceMatrix[cities[i]][cities[i+1]];
	}
//	distance += distanceMatrix[cities[end-1]][cities[end]]; // distance = cities[end-1] -> startingCity

	minDistancePath(cities, end, distance);
}

void Permute(int cities[10], int start, int end, int distanceMatrix[][10]) {
	if(start == end) {
		CalculateDistance(cities, end, distanceMatrix);
	} else {
		for(int i=start; i<end; i++) {
			Swap(&cities[start], &cities[i]);
			Permute(cities, start+1, end, distanceMatrix);
			Swap(&cities[start], &cities[i]);
		}
	}
}


int main() {

	// Read Number of Cities
	int noOfCities;
	printf("Number of Cities: ");
	scanf("%d", &noOfCities);

	int cities[noOfCities];
	int distanceMatrix[10][10];

	// Read distanceMatrix
	int d;
	cities[0] = 0;
	for(int i=0; i<noOfCities-1; i++) {
		for(int j=i+1; j<noOfCities; j++) {
			cities[j] = j;
			printf("Distance Between city %d and city %d\n", i, j);
			scanf("%d", &d);
			distanceMatrix[i][j] = d;
			distanceMatrix[j][i] = d;
		}
	}

	// Read Starting City
	int startingCity;
	printf("Starting City: ");
	scanf("%d", &startingCity);
	printf("\n\n");

	// moving startingCity to end of array

	Swap(&cities[startingCity], &cities[noOfCities-1]);

	Permute(cities, 0, noOfCities-1, distanceMatrix);

	printf("---  PATH  ---\n");
	for(int j=0; j<noOfCities+1; j++) {
		printf("%d -> ", minDistanceArray[j]);
	}
	printf("\nMinimum Distance: %d", minDistance);

	return 0;
}

//4
//1 6 4 2 5 3
//0
