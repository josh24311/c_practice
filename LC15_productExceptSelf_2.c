/*
LC15_Product Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }


int* productExceptSelf(int* nums, int numsSize, int* returnSize){
  *returnSize = numsSize;
  // 1 2 3 4 - > 24 12 8 6
  
  int* t = malloc(sizeof(int)*numsSize);
  //int t[4] = {0,0,0,0};

  int lefts[numsSize];
  lefts[0] = 1;
 
  // left : nums[0]*nums[1]*...*nums[i-1]
  for(int i = 1; i < numsSize; i++){
    int left = 1;
    // lefts[0] = 1
    // lefts[1] = 1 * nums[0]              := lefts[0] * nums[0]
    // lefts[2] = 1 * nums[0] * nums[1]    := lefts[1] * nums[1]
    lefts[i] = lefts[i-1] * nums[i-1];
  }
  // right : nums[i+1]*nums[i+2]*...*nums[numsSize]
  int rights[numsSize];
  rights[numsSize-1] = 1;
  
  for(int i = numsSize-2; i >= 0; i--){
    int right = 1;
    // rights[numsSize-1] = 1;
    // rights[numsSize-2] = 1*nums[numsSize-1]        
    //      := rights[numsSize-1]*nums[numsSize-1]
    // rights[numsSize-3] = 1*nums[numsSize-1]*nums[numsSize-2]
    //      := rights[numsSize-1]*nums[numsSize-1]*nums[numsSize-2] 
    //      := rights[numsSize-2]*nums[numsSize-2]
    // rights[2] = 1                *nums[3]*...*nums[numsSize-1]
    // rights[1] = 1        *nums[2]*nums[3]*...*nums[numsSize-1] := rights[2]*nums[2]
    // rights[0] = 1*nums[1]*nums[2]*nums[3]*...*nums[numsSize-1] := rights[3]*nums[3]
    rights[i] = rights[i+1] * nums[i+1];
    
  }
  
  for(int i = 0; i < numsSize; i++){
    t[i] = lefts[i] * rights[i];
  }
  
  return t;
}

int main() {
  
  int* sa = malloc(sizeof(int)*4);
  sa[0] = 1;
  sa[1] = 2;
  sa[2] = 3;
  sa[3] = 4;
  int* sb = malloc(sizeof(int)*5);
  sb[0] = -1;
  sb[1] = 1;
  sb[2] = 0;
  sb[3] = -3;
  sb[4] = 3;
  int size1 = 4;
  int size2 = 5;
  int sf = 0,sizeNow = 0;
  sa = productExceptSelf(sa,size1,&size1);
  sb = productExceptSelf(sb,size2,&size2);
  printf("Input test case (0 or 1)\n");
  scanf("%d",&sf);
  
  if(sf == 0){
    
    sizeNow = size1;
    printf("testcase is %d,sizeNow is %d \n",sf,sizeNow);
    printf("Answer array : ");
    for(int i = 0; i < sizeNow; i++){
      printf("%d ",sa[i]);
    }
  } 
  else{
    sizeNow = size2;
    printf("testcase is %d,sizeNow is %d \n",sf,sizeNow);
    printf("Answer array : ");
    for(int i = 0; i < sizeNow; i++){
      printf("%d ",sb[i]);
    }
  }
  
  
  
  free(sa);
  free(sb);
  return 0;
}
