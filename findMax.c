//L48~49 find max num of 2 or 3 integer numbers
#include<stdio.h>

int main(){
	int a,b,c,max;
	/*two num find max*/
	/*
	printf("Please enter two integers: \n");
	scanf("%d",&a);
	scanf("%d",&b);
	max = a;
	if(b > a)	max = b;
	printf("Maximum is %d\n",max);
	*/

	//*********************************
	/*Three num find max*/
	printf("Please enter three integers: \n");
        scanf("%d%d%d",&a, &b, &c);
	max = a;
	if(b > max){
		max = b;
	}
	if(c > max){
		max = c;	
	}
	printf("Maximum is %d\n",max);


	return 0;
}
