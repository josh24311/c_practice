#include <stdio.h>

int main(){
	char input, output;
	printf("Please enter uppercase alphabat: ");
	scanf("%c",&input);
	output = input + ('a' - 'A');
	printf("Lowercase of input char is : %c\n",output); 
	
  	return 0;
}
