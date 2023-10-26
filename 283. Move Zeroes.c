/*
#double pointer
283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

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
/***************************************************************/
void moveZeroes(int* nums, int numsSize){
  // 0 1 0 3 12
  // method 1 全部移後面的數字，在尾端補0
  /*
  int i = 0,j,zeroN = 0;
  int count = 0;
  for(i = 0; i < numsSize; i++){
    if(nums[i] == 0){
      count++;
    }
  }
  i = 0;
  j = numsSize-1;
  while(count > 0){
    if(nums[i] == 0){
      for(int k = i; k < j; k++){
        nums[k] = nums[k+1];
      }
      nums[j] = 0;
      j--;
      count--;
    }
    else{
      i++;
    }
  }
  */
  //method 2 用i紀錄要換的位置，前端先填非0
  // 0 1 0 3 12
  int i = 0;
  int j;
  for(j = 0; j < numsSize; j++){
    if(nums[j] != 0){
      nums[i] = nums[j];
      i++;
    }
  }
  for(j = i; j < numsSize; j++){
    nums[j] = 0;
  }
}
/***************************************************************/

int main() {
  int arr1[] = {0,1,0,3,12};
  
  int arr2[] = {0,0,1};
  moveZeroes(arr1, 5);
  moveZeroes(arr2, 3);
  for(int i = 0; i < 5; i++ ){
    printf("%d ",arr1[i]);
  }
  printf("\n");
  for(int i = 0; i < 3; i++ ){
    printf("%d ",arr2[i]);
  }
  return 0;
}