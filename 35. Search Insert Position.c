/*
35. Search Insert Position


Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

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



int searchInsert(int* nums, int numsSize, int target){
  //O(nlogn)
  // 1 3 5 6
  // 2
  if(target > nums[numsSize-1]) return numsSize;
  else if(target < nums[0]) return 0;
  
  int left = 0;
  int right = numsSize-1;
  int mid;
  while(left <= right){
    mid = (left+right)/2;
    if(target > nums[mid]){
      left = mid+1;
    }
    else if (target < nums[mid]){
      right = mid-1;
    }
    else{
      return mid;
    }
  }
  return left;
}

int main() {
  int* arr1 = malloc(sizeof(int)*4);
  arr1[0] = 1;
  arr1[1] = 3;
  arr1[2] = 5;
  arr1[3] = 6;

  printf("result 1 : %d\n",searchInsert(arr1, 4, 5));
  printf("result 2 : %d\n",searchInsert(arr1, 4, 2));
  printf("result 3 : %d\n",searchInsert(arr1, 4, 7));
  
  
  
  return 0;
}