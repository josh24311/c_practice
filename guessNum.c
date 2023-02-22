/*C language practice in L61 */
#include<stdio.h>

int main(){
	int input,ans = 5;//set answer as 5
	printf("Please enter a integer number:\n");
	scanf("%d",&input);
	if(input > ans)	printf("Too large!\n");
	else{
		if(input < ans)	printf("Too small\n");
		else	printf("Correct answer!\n");
	} 
	return 0;
}
