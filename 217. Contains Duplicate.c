/*
217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

int MAXSIZE;
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
/*******************************************************************************/
bool containsDuplicate(int* nums, int numsSize){
// 1 2 3 1 4 -> 1 1 2 3 4
  if(numsSize <=1)return false;
  // LTE
  /*
  for(int i = 0; i < numsSize; i++){
    for(int j = i+1; j < numsSize; j++){
      if(nums[j] == nums[i])return true;
    }
  }
  return false;
  */
  qsort(nums, numsSize, sizeof(int), cmp);
  for(int i = 0 ; i < numsSize-1; i++){
    if(nums[i] == nums[i+1])return true;
  }
  return false;
    
  
  
}
/****************************************************************************************/
int main() {
  int* a = malloc(sizeof(int)*4);
  int* b = malloc(sizeof(int)*4);
  int* c = malloc(sizeof(int)*10);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  
  c[0] = 1;
  c[1] = 1;
  c[2] = 1;
  c[3] = 3;
  c[4] = 3;
  c[5] = 4;
  c[6] = 3;
  c[7] = 2;
  c[8] = 4;
  c[9] = 2;
  printf("a has duplicate ? %s\n",containsDuplicate(a, 4)?"True":"False");
  printf("b has duplicate ? %s\n",containsDuplicate(b, 4)?"True":"False");
  printf("c has duplicate ? %s\n",containsDuplicate(c, 10)?"True":"False");
  return 0;
}