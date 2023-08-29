/*
27. Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

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

int removeElement(int* nums, int numsSize, int val){
  if(numsSize == 0) return 0;
  if(numsSize == 1){
    if(nums[0] == val){
      return 0;
      nums = NULL;
    }
    else{
      return 1;
    }
  }

  int i,j = 0;
  for(i = 0; i < numsSize; i++){
    if(nums[i] != val){
      nums[j] = nums[i];
      j++;
    }
  }

  return j;  
}

int main() {
  int* arr1 = malloc(sizeof(int)*4);
  arr1[0] = 3;
  arr1[1] = 2;
  arr1[2] = 2;
  arr1[3] = 3;

  int* arr2 = malloc(sizeof(int)*8);
  arr2[0] = 0;
  arr2[1] = 1;
  arr2[2] = 2;
  arr2[3] = 2;
  arr2[4] = 3;
  arr2[5] = 0;
  arr2[6] = 4;
  arr2[7] = 2;

  int* arr3 = malloc(sizeof(int)*1);
  arr3[0] = 1;

  int* arr4 = malloc(sizeof(int)*2);
  arr4[0] = 3;
  arr4[1] = 3;

  printf("arr1 result : %d\n",removeElement(arr1, 4, 3));
  printf("arr2 result : %d\n",removeElement(arr2, 8, 2));
  printf("arr3 result : %d\n",removeElement(arr3, 1, 1));
  printf("arr4 result : %d\n",removeElement(arr4, 2, 3));
  return 0;
}