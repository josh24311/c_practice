//L52 find median of 3 integer numbers
#include<stdio.h>

int main(){
	int a,b,c,med;
	/*Three num find medium*/
	printf("Please enter three integers: \n");
	fflush(stdout);
	scanf("%d%d%d",&a, &b, &c);
	/*
	if(a <= b){
		med = b;
		if(b >= c){
			if(a <= c){
				med = c;
			}
			else{
				med = a;
			}
		}
	}
	else{//a > b
		med = a;
		if(c >= b){
			if(a > c){
				med = c;
			}

		}
		else{
			med = b;
		}
	}
	*/

	med = a;
	if( ( (b-a) * (c-a) > 0 )){//a is max or a is min
		
	
		if(b > a){//a is min
			if(b <= c){
				med = b;
			}
			else{
				med = c;
			}	
		}
		else{//a is max
			if(b <= c){
				med = c;
			}
			else{
				med = b;
			}
		}
		
	}

	printf("Median is %d\n",med);

	return 0;
}
