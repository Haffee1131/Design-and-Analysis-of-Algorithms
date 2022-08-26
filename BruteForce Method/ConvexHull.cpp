// Convex Hull Algorithm using BruteForce Method

#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

void ConvexHull(struct point p[], int noOfPoints) {

	//Convex Hull Algo

	int a,b,c; // Line Equation Constants
	int left, right; // Flags to check given point side
	for(int i=0; i<noOfPoints-1; i++) {
		for(int j=i+1; j<noOfPoints; j++) {

			// Finding Line Equations Constants
			a = p[j].y - p[i].y; // y2-y1
			b = p[i].x - p[j].x; // x1-x2
			c = (p[i].x * p[j].y) - (p[j].x * p[i].y); // x1y2 - x2y1

			// Finding if all other points are either side of this line
			left = 0;
			right = 0;
			for(int k=0; k<noOfPoints; k++) {
				if(k!=i && k!=j) {
					int d = (a*p[k].x + b*p[k].y); // d = ax+by
					if(d<c)
						left = 1; // Point is left side of line
					if(d>c)
						right = 1; // Point is right side of line
					if(d == c) {
						if((p[i].x<=p[k].x && p[k].x<=p[j].x) || (p[i].y<=p[k].y && p[k].y<=p[j].y)) {

							left =1;
							right =1;
						}

					}
				}
				if(left>0 && right>0)
					break; // i and j points cannot form convex hull
			}
			if(!(left>0 && right>0)) { // All other points are only on either of the side of line
				printf("( %d, %d ) && ", p[i].x, p[i].y);
				printf("( %d, %d )\n", p[j].x, p[j].y);
			}
		}
	}
}

int main() {

	// Number of Points
	int noOfPoints;
	printf("Number of points: ");
	scanf("%d", &noOfPoints);

	struct point p[noOfPoints];

	// Read Points
	for(int i=0; i<noOfPoints; i++) {
		printf("Enter point %d : (x,y)\n", i);
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	// Print Given Points
	printf("\n\n-- Given Points --\n\n");
	for(int i=0; i<noOfPoints; i++) {
		printf("Point %d ==> \n", i);
		printf("( %d, %d )\n", p[i].x, p[i].y);
	}
	printf("\n\n");

	ConvexHull(p, noOfPoints);

	return 0;
}