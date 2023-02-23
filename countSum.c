/*C language practice in L71 , enter ints until 0 ,  sum all inputs*/
#include<stdio.h>

int main(){
	int input,sum = 0;
	printf("Please enter input integer, enter 0 is for end: \n");
	while(1){
		scanf("%d",&input);
		if(input == 0)	break;
		else{
			sum = sum + input;

		}
	}
	printf("sum is %d\n",sum);
	return 0;
}
