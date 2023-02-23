/*C language practice in L61, L69 */
#include<stdio.h>

int main(){
	int input,ans = 5;//set answer as 5
	printf("Please enter a integer number:\n");
	//L61 if_else
	/*
	scanf("%d",&input);
	if(input > ans)	printf("Too large!\n");
	else{
		if(input < ans)	printf("Too small\n");
		else	printf("Correct answer!\n");
	} */
	//L69 while
	while(1){
		scanf("%d",&input);
		if(input > ans)	printf("Too large\n");
		else if(input < ans)	printf("Too small\n");
	}
	printf("Correct answer!\n");

	return 0;
}
