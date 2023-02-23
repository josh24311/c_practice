/*C language practice in L71,L72 , enter ints until 0 ,  sum all inputs and count average*/
#include<stdio.h>

int main(){
	int input,sum = 0, count = 0, fstNz = 0;
	printf("Please enter input integer, enter 0 is for end: \n");
	while(1){
		scanf("%d",&input);
		count = count + 1;
		if(input == 0)	{
			if(sum == 0)	fstNz = 1;
			break;
		}
		else{
			sum = sum + input;

		}
	}
	count = count - 1;
	if(fstNz){
		printf("sum is %d\n, average is N/A\n",sum);
	}
	else{
		printf("sum is %d\n, average is %f\n",sum, (float)sum / count );
	}
	return 0;
}
