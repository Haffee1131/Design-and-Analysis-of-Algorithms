// Closest Pair Algorithm using BruteForce Method

#include <stdio.h>
#include <math.h>

struct point{
	int x;
	int y;
};

void ClosestPair(struct point p[], int noOfPoints){
	
	//Closest Pair Algo
	int distance, minDistance = 9999;
	int point1, point2; // To store Closest pair indexes
	for(int i=0; i<noOfPoints-1; i++){
		for(int j=i+1; j<noOfPoints; j++){
			distance = (pow((p[j].x - p[i].x), 2) + pow((p[j].y - p[i].y), 2)); // d = (x2-x1)^2 + (y2-y1)^2
		
			if(distance < minDistance){
				minDistance = distance;
				point1 = i;
				point2 = j;
			}
			
		}
	}
	printf("Closest Pair: ( %d, %d ) -- ( %d, %d )\n", p[point1].x, p[point1].y, p[point2].x, p[point2].y);
	printf("Closest Pair Distance: %.2f", pow(minDistance, 0.5));
}

int main(){
	
	// Number of Points
	int noOfPoints;
	printf("Number of points: ");
	scanf("%d", &noOfPoints);
	
	struct point p[noOfPoints];
	
	// Read Points
	for(int i=0; i<noOfPoints; i++){
		printf("Enter point %d : (x,y)\n", i);
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	
	ClosestPair(p, noOfPoints);
	
	return 0;
}