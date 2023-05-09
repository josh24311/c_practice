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
//DP 動態規劃
/*
Kadane's algorithm
走訪整個陣列，每經過一個陣列元素，可以決定出"以該筆資料為 subarray 結尾"的 maximum subarray sum ，
這樣的 maximum subarray 有以下兩種可能 :
前一個陣列元素做為 subarray 結尾的 maximum subarray sum 再加上當前陣列元素
當前陣列元素
有了以各個陣列元素為結尾的 mamimum subarray sum 後，
從中挑出最大值，就是 input array 中的 maximum subarray sum 。

動態規劃的第一步即定義出陣列元素:
dp[i] 定義為包含 data[i] 的最大 subarray sum 。
接著定義出遞迴關係式:
dp[i] = max (dp[i-1] + data[i] , data[i]);
*/
#include <stdio.h>
#include <limits.h>
int max(int,int);
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
    int dp[numSize];
    int tmax = INT_MIN;
    dp[0] = nums[0];
    for(int i = 1; i < numSize; i++){//選擇起點
        dp[i] = max(nums[i], dp[i-1] + nums[i]);
        //dp[1] = max(nums[1], dp[0] + nums[1]);
        //      = max(1, -2+1) = 1
        //dp[2] = max(nums[2], dp[1] + nums[2]);
        //      = max(-3, -3+1) = -2
        if(dp[i] > tmax){
            tmax = dp[i];
        }
    }
    
    
    return tmax;
}
int max(int a, int b){
    return a > b ? a : b;
}