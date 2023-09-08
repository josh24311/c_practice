/*
108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:
 Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
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
struct TreeNode* buildSub(int* nums, int start, int end){
  if(start > end)return NULL;
  int mid = start + (end-start)/2;
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = nums[mid];//取中位數當root使其成為平衡樹
  root->left = buildSub(nums, start, mid-1);//遞迴建造左子樹
  root->right = buildSub(nums, mid+1, end);//遞迴建造右子樹
  return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){

  return buildSub(nums, 0, numsSize-1);
}

/****************************************************************************************/
int main() {

  int* s2 = malloc(sizeof(int)*2);


  s2[0] = 1;
  s2[1] = 3;

  Tree* ans2 = sortedArrayToBST(s2, 2);
  printf("\n%d %d ",ans2->val,ans2->right->val);
  return 0;
}