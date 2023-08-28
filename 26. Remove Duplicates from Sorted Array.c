/*
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

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

int removeDuplicates(int* nums, int numsSize){
  // [1,1,2]
  // [0,0,1,1,1,2,2,3,3,4]
  // 題目要求in-place replace, 即 不另分配記憶體空間
  if(numsSize <= 1) return numsSize;

  int now = 0;
  for(int i = 1; i < numsSize; i++){
    if(nums[i] != nums[now]){
      now++;
      nums[now] = nums[i];
    }
        
  }
  return now+1;
}

int main() {
  int* arr1 = malloc(sizeof(int)*3);
  arr1[0] = 1;
  arr1[1] = 1;
  arr1[2] = 2;

  int* arr2 = malloc(sizeof(int)*10);
  arr2[0] = 0;
  arr2[1] = 0;
  arr2[2] = 1;
  arr2[3] = 1;
  arr2[4] = 1;
  arr2[5] = 2;
  arr2[6] = 2;
  arr2[7] = 3;
  arr2[8] = 3;
  arr2[9] = 4;

  printf("arr1 Unique numsSize : %d\n",removeDuplicates(arr1, 3));
  printf("arr2 Unique numsSize : %d\n",removeDuplicates(arr2, 10));
  return 0;
}