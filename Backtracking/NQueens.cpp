//N-Queens using Backtracking

#include <stdio.h>
#include <stdbool.h>

int n;

bool isSafe(int board[10][10], int row, int col){
	
	// checking specificied row on left side
	for(int i=0; i<col; i++){
		if(board[row][i] == 1)	// if already has queen
			return false;		// not safe => return false
	}
	
	// checking if upper diagonal left side is safe
	for(int i=row, j=col;  i>=0 && j>=0;  i--, j--){
		if(board[i][j] == 1)
			return false;
	}
	
	// checking if lower diagonal left side is safe
	for(int i=row, j=col;  i<n && j>=0;  i++, j--){
		if(board[i][j] == 1)
			return false;
	}
	
	return true; // if all conditions fail then it is safe to place at board[row][col]

}



bool solve(int board[10][10], int col){
	
	if(col >= n)	// all queens are placed -- base condition
		return true;
		
	for(int i=0; i<n; i++){ // checking rows i.e i for constant column
		
		if(isSafe(board, i, col) == true){
			board[i][col] = 1; // if safe => queen os placed
			
			if(solve(board, col+1) == true) // checking for placing rest of queens
				return true;
			else				// if we can't place next queen then previous queen is removed and recurred...
				board[i][col] = 0;
		}
		
	}
	
	return false; // if queen cannot be placed in any row in this column return false
		
		
		
}




int main() {

	// Read  n value
	printf("N cross board: ");
	scanf("%d", &n);

	int board[10][10];

	// Initialising board with 0's
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			board[i][j] = 0;
		}
	}

	bool res;
	res = solve(board, 0);
	if(res == false)
		printf("Solution doesn't exist.");
	else {
		// Printing Board
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%d  ", board[i][j]);
			}
			printf("\n");
		}
	}
	
	
	return 0;
}
