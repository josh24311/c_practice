#include <stdio.h>
#include <string.h>

int main(){
	char input[64]="", output[64]="";
	long int slen = 0;
	int i;	
	printf("Please enter uppercase string:\t");
	scanf("%s",input);
	slen = strlen(input);
	for(i = 0; i < slen; i++){
		output[i] = input[i] + ('a' - 'A');
	}
	printf("Lowercase of input string is :\t%s\n",output); 
	
  	return 0;
}
