/*
#array
#同LC13
525. Contiguous Array
子陣列中使0和1一樣多的陣列長度最長為何?
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
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

int findMaxLength(int* nums, int numsSize){
  int *arr = malloc(sizeof(int)*(numsSize*2+1));  
  // arr[sum+numsSize] 存 第一次出現 sum 時的index
  // arr[-1+9] = arr[8] 存 第一次出現 -1 時的 index 即是 0
  for (int i = 0; i < numsSize*2+1; i++){
      arr[i] = -2;
  }
    // numsSize = 9
    /*    0  1  2  3  4  5  6  7  8  9   10 11 12 13 14 15 16 17 18
    nums  0  0  1  1  0  1  0  0  1
    arr  -2 -2 -2 -2 -2 -2 -2  1  0 [-1] -2 -2 -2 -2 -2 -2 -2 -2 -2
    sum  -1 -2 -1  0 -1  0 -1 -2 -1                                     
    */
  arr[numsSize] = -1;//每次遇到 arr[0 + numsSize] 更新 maxLen 為 i-(-1) = i+1
  int sum = 0;
  int maxLen = 0;
  for(int i = 0; i < numsSize; i++){
    sum+= (nums[i] == 0?-1:1);
    if(arr[sum+numsSize] >= -1){//出現此sum的i已被記錄過，即比對現i與初次紀錄的index差
      maxLen = max(maxLen, i - arr[sum+numsSize] );
    }
    else{//出現此sum的i未被記錄
      arr[sum+numsSize] = i;
    }
  }

  free(arr);
  return maxLen;
}
/***************************************************************/
int main() {
  
  int a[] = {0,1};
  printf("ans1  = %d\n",findMaxLength(a, 2));
  
  int b[] = {0,0,1,1,0,1,0,0,1};
  printf("ans2  = %d\n",findMaxLength(b, 9));
  return 0;
}