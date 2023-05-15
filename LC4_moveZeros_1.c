/******************************************************************************
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

*******************************************************************************/
//Method 1 will cause TLE error
#include <stdio.h>
void movezeros(int*, int);
int main()
{
    int numsSize = 5;
    int nums[5] = {1, 0, 3, 0, 12};
    movezeros(nums,numsSize);
    for(int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);    
    }
    printf("\n");

    return 0;
}
void movezeros(int* nums, int numsSize){
    
    while(1){
        int count = 0;
        for(int i = 0; i+1 < numsSize; i++){
            if(nums[i] == 0 && nums[i+1] != 0){
                //not finish yet
                count++;
                int t = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = t;
                break;
            }
        }
        if(count == 0) break;
    }
}
