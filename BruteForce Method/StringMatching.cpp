// String Matching Algorithm Using BruteForce Method

#include <stdio.h>
#include <string.h>

void StringMatch(char str[], char pattern[]){
	
	//Finding Length of String
	int	m = strlen(str);

	//Finding Length of Pattern
	int	n = strlen(pattern);

	//String Matching Algo
	int matchCount = 0;
	for(int i=0; i<=m-n; i++) {
		int flag = 0;
		for(int j=0; j<n; j++) {
			if(str[i+j] != pattern[j]) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			matchCount++;
	}
	printf("Match Count: %d", matchCount);

}

int main() {

	char str[20]; //String
	char pattern[10]; //Pattern

	//Read String
	printf("Enter String: ");
	scanf("%s", str);

	//Read Pattern
	printf("Enter Pattern: ");
	scanf("%s", pattern);

	StringMatch(str, pattern);
	
	return 0;
}