/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
    

    return 0;
}
void movezeros(int* nums, int numsSize){
    
    while(1){
        int count = 0;
        for(int i = 1; i <= numsSize; i++){
            if(nums[i-1] == 0 && nums[i] != 0){
                //not finish yet
                count++;
                int t = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = t;
                break;
            }
        }
        if(count == 0) break;
    }
}