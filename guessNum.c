/*C language practice in L61, L69, L70 */
#include<stdio.h>

int main(){
	int input,ans = 5, count = 0;//set answer as 5
	printf("Please enter a integer number:\n");
	fflush(stdout);
	//L61 if_else
	/*
	fflush(stdout);
	scanf("%d",&input);
	if(input > ans)	printf("Too large!\n");
	else{
		if(input < ans)	printf("Too small\n");
		else	printf("Correct answer!\n");
	} */
	//L69 while
	while(1){
		scanf("%d",&input);
		count = count +1;
		if(input > ans)	printf("Too large\n");
		else if(input < ans)	printf("Too small\n");
		else break;
	}
	printf("Correct answer in %d guesses!\n",count);
	

	return 0;
}
