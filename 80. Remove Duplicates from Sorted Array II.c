/*
80. Remove Duplicates from Sorted Array II
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/
int removeDuplicates(int* nums, int numsSize){
  
  // index     0 1 2 3 4 5 6 7 8 9  // numsize = 10
  // nums      1 1 2 3 3
  // i                 ^
  // p                 ^

  int p = 2;

  if(numsSize <= 2)return numsSize;
  
  for(int i = 2; i < numsSize; i++){
    if(nums[i] != nums[p-2]){
      nums[p++] = nums[i];
    }
  }

  return p;
  
}
/****************************************************************************************/
int main() {
  int* a = malloc(sizeof(int)*6);
  a[0] = 1;
  a[1] = 1;
  a[2] = 1;
  a[3] = 2;
  a[4] = 2;
  a[5] = 3;

  int ans1 = removeDuplicates(a, 6);
  printf("after remove has %d elements\n",ans1);

  int *b = malloc(sizeof(int)*9);
  b[0] = 0;
  b[1] = 0;
  b[2] = 1;
  b[3] = 1;
  b[4] = 1;
  b[5] = 1;
  b[6] = 2;
  b[7] = 3;
  b[8] = 3;

  int ans2 = removeDuplicates(b, 9);
  printf("after remove has %d elements\n",ans2);

  int *c = malloc(sizeof(int)*10);
  c[0] = 0;
  c[1] = 1;
  c[2] = 1;
  c[3] = 2;
  c[4] = 2;
  c[5] = 2;
  c[6] = 3;
  c[7] = 3;
  c[8] = 3;
  c[9] = 3;

  int ans3 = removeDuplicates(c, 10);
  printf("after remove has %d elements\n",ans3);
  return 0;
}