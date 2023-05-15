//Leetcode practice 1 : singleNumber, input int arrays , return num that is the only one in arrays.
//
#include<stdio.h>

int singleNumber(int*, int);
int main(){
	int a[3] = {1,2,1};
	int b[5] = {4,1,2,1,2};
	printf("%d\n",singleNumber(b,5));
	return 0;
}

int singleNumber(int* nums, int numSize){
	/*int times = 0;
	for(int i = 0; i < numSize; i++){
		for(int j = 0; j < numSize; j++){
			if(nums[j] == nums[i]){
				times++;		
			}	
		}
		if(times == 1){
			return nums[i];
		}
		else{
			times = 0;
		}

	}
	*/
	int n = nums[0];
	for(int i = 1; i < numSize; i++){
		n ^= nums[i];
	}
	return n;
}
