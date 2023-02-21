/*C language practice in L56, sort 3 int number from  std input and store back to initial variables */
#include<stdio.h>

int main(){
	int a,b,c,t;
	printf("Please enter three number(a,b,c) as input : \n");
	scanf("%d%d%d",&a,&b,&c);
	printf("Variables now :\ta = %d, b = %d, c = %d\n",a,b,c);
	if( a > b ){
		t = a; a = b; b = t;
	}
	if( a > c ){
		t = c; c = a; a = t;
	}
	// after above a is mim
	if( b > c ){
		t = b; b = c; c = t;
	}
	
		
	printf("After sort :\ta = %d, b = %d, c = %d\n",a,b,c);

	return 0;
}
