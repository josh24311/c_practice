/******************************************************************************
Leetcode April 1 : Single number
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*******************************************************************************/

#include <stdio.h>
int singleNumber(int*, int);
int main()
{
    int na,num;
	int a[3] = {2,2,1};     // num = 3
	int b[5] = {4,1,2,1,2}; // num = 5
	int c[1] = {1};         // num = 1
	
    printf("Single number is : %d",singleNumber(b,5));

    return 0;
}
int singleNumber(int* nums, int numSize){
    int n = nums[0];
    for(int i = 1; i < numSize; i++){
        n ^= nums[i];
    }
    return n;
}
