/*
209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
/****************************************************************************************/
//       [2 3 1 2] 4 3
// left   ->
int minSubArrayLen(int target, int* nums, int numsSize){
  int left = 0;
  int sum = 0;
  int result = INT_MAX;
  for(int i = 0; i < numsSize; i++){
    sum+=nums[i];
    //找到第一個sum >= target時開始移動left 去減少window
    while(left <= i && sum >= target){
      result = min(result, (i-left+1)); // i-left+1 = 當前window寬
      sum-=nums[left];
      left++;
    }
    
  }
  return result==INT_MAX?0:result;
}



/****************************************************************************************/
int main() {
  int* array1 = malloc(sizeof(int)*5);
  int* array2 = malloc(sizeof(int)*3);
  int* array3 = malloc(sizeof(int)*8);
  array1[0] = 1;
  array1[1] = 2;
  array1[2] = 3;
  array1[3] = 4;
  array1[4] = 5;
  
  printf("ans1 : %d\n",minSubArrayLen(11, array1, 5));
  array2[0] = 1;
  array2[1] = 4;
  array2[2] = 4;
  printf("ans2 : %d\n",minSubArrayLen(4, array2, 3));
  array3[0] = 1;
  array3[1] = 1;
  array3[2] = 1;
  array3[3] = 1;
  array3[4] = 1;
  array3[5] = 1;
  array3[6] = 1;
  array3[7] = 1;
  printf("ans3 : %d\n",minSubArrayLen(11, array3, 8));
  
  

  return 0;
}