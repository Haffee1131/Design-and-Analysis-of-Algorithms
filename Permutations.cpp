// Permutations Algorithm

#include <stdio.h>
#include <string.h>

// Swap Function
void Swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

//// Print Function
//void Print(char str[]){
//	int i=0;
//	while(str[i]!='\0'){
//		printf("%c", str[i]);
//		i++;
//	}
//	printf("\n");
//}

// Permutation Algo
void Permute(char str[], int start, int end){
	if(start == end)
		printf("%s\n", str);
	else{
		for(int i=start; i<end; i++){	
			Swap(&str[start], &str[i]);
			Permute(str, start+1, end);
			Swap(&str[start], &str[i]);
		}
	}
}

int main(){
	
	// Read string
	char str[20];
		
	printf("Enter string: ");
	scanf("%s", str);
	
	// Length of String
	int len = strlen(str);
	
	// Permutation Function call
	Permute(str, 0, len);
	
	return 0;
}