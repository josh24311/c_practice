/*
33. Search in Rotated Sorted Array

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
  if(a < b) return a;
  else return b;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min3(int a, int b, int c){
  return min(min(a, b), c);
}
int max3(int a, int b, int c){
  return max(max(a, b), c);
}
typedef struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;

} Tree;
struct ListNode{
  int val;
  struct ListNode *next; 
} ;

/****************************************************************************************/
/*
  i     0   1 2  3  4 5 6
  ------------------------
  typeA 7 8 1 (2) 3 4 [5]  , pivot 不在 mid end 中間
  pivot     ^
  typeB 4 5 6 (7) 0 1 [2]  ，pivot 在   mid end 中間
  pivot           ^
        3   1
  */

int search(int* nums, int numsSize, int target){
  int left = 0;
  int right = numsSize-1;
  while(left <= right){
    int mid = left + (right-left)/2;
    if(nums[mid] == target) return mid;
    if(nums[mid] < nums[right]){//typeA
      if(nums[mid] < target && nums[right] >= target) left = mid+1;
      else right = mid-1;
    }
    else{//typeB
      if(nums[left] <= target && nums[mid] > target) right = mid-1;
      else left = mid+1;
      
    }
    
  }
  return -1;
}

/****************************************************************************************/
int main() {
  int* ar1 = malloc(sizeof(int)*7);
  ar1[0] = 4;
  ar1[1] = 5;
  ar1[2] = 6;
  ar1[3] = 7;
  ar1[4] = 0;
  ar1[5] = 1;
  ar1[6] = 2;

  int* ar2 = malloc(sizeof(int)*1);
  ar2[0] = 1;
  int* ar3 = malloc(sizeof(int)*2);
  ar3[0] = 3;
  ar3[1] = 1;
  //printf("ans1 in index %d\n",search(ar1, 7, 0));
  //printf("ans2 in index %d\n",search(ar1, 7, 3));
  //printf("ans3 in index %d\n",search(ar2, 1, 0));
  printf("ans4 in index %d\n",search(ar3, 2, 3));
  

  return 0;
}