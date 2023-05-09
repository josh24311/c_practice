/******************************************************************************

Leetcode April 3 : Maximum Subarray
Given an integer array nums, find the contiguous subarray 
(containing at least one number) 
which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*******************************************************************************/
//暴力破解
#include <stdio.h>
#include <limits.h>
int maxSubArray(int*, int);
int main()
{
    
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int len = sizeof(a) / sizeof(int);
    int res = maxSubArray(a,len);
    printf("result = %d",res);
    return 0;
}
int maxSubArray(int* nums, int numSize){
    int tmps = INT_MIN;
    int tmpi,tmpj;
    for(int i = 0; i < numSize; i++){//選擇起點
        int sum = 0;
        for(int j = i; j < numSize; j++){//選擇終點
            
            
            sum += nums[j];
            if(sum > tmps){
                tmps = sum;
            }
        }
    }
    /*printf("maxSubArray is : ");
    for(int i = tmpi; i <= tmpj; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");*/
    return tmps;
}
