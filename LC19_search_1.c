/*
LC19_Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a<b) return a;
  else return b;
}




int search(int* nums, int numsSize, int target){
  /*
  4,5,6,7,0,1,2 find 3

  */
  // O(n)
  for(int i = 0; i < numsSize; i++){
    if(nums[i] == target){
      return i;
    }
  }
  
  
  
  return -1;
}

int main() {
  int* arr1 = malloc(sizeof(int)*7);
  arr1[0] = 4;
  arr1[1] = 5;
  arr1[2] = 6;
  arr1[3] = 7;
  arr1[4] = 0;
  arr1[5] = 1;
  arr1[6] = 2;

  int* arr2 = malloc(sizeof(int)*1);
  arr2[0] = 1;
  

  printf("Target num %d is at position in arr1: %d \n\n",0,search(arr1,7,0));
  
  printf("Target num %d is at position in arr2: %d\n\n",3,search(arr2,1,3));
  printf("Target num %d is at position in arr2: %d\n\n",0,search(arr2,1,0));


  free(arr1);
 
 
  free(arr2);
  return 0;
}