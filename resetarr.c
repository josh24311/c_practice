// L165
#include <stdio.h>

int maxv(int[], int);
int main(){
	int n = 4;//total nums
	int v[] = {3,9,7,11};
	/*
	int *p = v; // int *p = &v[0]	
	printf("v0 = %d\n",v[0]);
	printf("p = %p\n",p);
	printf("*p = %d\n",*p);
	printf("increase p\n");
	//printf("p now = %p\n",p++);
	p++;
	printf("p now = %p\n",p);	
	printf("*p = %d\n",*p);
	*/

	//find max using pointer
	printf("Max is : %d\n",maxv(v,n));//equal to maxv(&v[0]);

	
	return 0;
}

int maxv(int *v, int n){
	int max = v[0],i;//max = *(v + 0)
	for(i=1; i<n ; i++){
		if(*(v+i) > max)	max = *(v+i);
	}		 
	return max;

}
