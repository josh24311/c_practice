// L165
#include <stdio.h>

int maxv(int[]);
int main(){
	int v[3] = {3,9,7};
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
	printf("Max is : %d\n",maxv(v));//equal to maxv(&v[0]);

	
	return 0;
}

int maxv(int *v){
	int max = v[0],i;//max = *(v + 0)
	for(i=1; i<3 ; i++){
		if(*(v+i) > max)	max = *(v+i);
	}		 
	return max;

}
