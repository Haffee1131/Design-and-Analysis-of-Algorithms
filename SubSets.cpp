// SubSets Algorithm

#include <stdio.h>
#include <math.h>
#include <string.h>

void SubSets(char str[], int len) {

	int subSetSize = pow(2, len); // SubSet Size
	char subSet[len]; // New Array to Store Subsets
	
	// Size Based Subsets
//	int size;
//	printf("Size: ");
//	scanf("%d", &size);
	
	for(int i=1; i<subSetSize; i++) { // i starts from 1 to leave null set
		int k=0;
		for(int j=0; j<len; j++) {
			if(i & (1<<j)) { // Bit Masking Approach
				printf("i: %d, j: %d,  2^%d: %d, i&(1<<j): %d \n\n", i, j, j, 1<<j, i&(1<<j));
				subSet[k] = str[j];
				k++;
			}
		}
		subSet[k] = '\0'; // Assigning Last Element of subset with null char
		
		// Size Based subSets
//		if(k == size)
//			printf("%s\n", subSet);
		printf("%s\n", subSet);
	}
}

int main() {

	// Read string
	char str[20];

	printf("Enter string: ");
	scanf("%s", str);

	// Length of String
	int len = strlen(str);

	// SubSets Function call
	SubSets(str, len);

	return 0;
}
