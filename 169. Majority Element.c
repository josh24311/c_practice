/*
169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
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
/*******************************************************************************/
int majorityElement(int* nums, int numsSize){
  // 2 2 1 1 1 2 2
  // 1 2 2 2 2 1 1
  // 1 1 2 2 2 2 2
  if(numsSize == 1 || numsSize == 2)return nums[0];
  /*
  qsort(nums, numsSize, sizeof(int), cmp);
  return nums[numsSize/2];
  */
  //Boyer–Moore majority vote algorithm
  /*
  候選人:now , 每次nums多一個now ,增一票(count++),
  每次nums少一個now, 減一票(count--)
  若count 恰為0表示當前now已非目前最高票,此時更新當前候選人now 為 nums[i]
  */
  int count = 0;
  int now;
  for(int i = 0; i < numsSize; i++){
    if(count == 0){
      now = nums[i];
    }

    if(nums[i] != now){
      count--;
    }
    else{
      count++;
    }
  }

  return now;
}
/****************************************************************************************/
int main() {
  int* array1 = malloc(sizeof(int)*3);
  int* array2 = malloc(sizeof(int)*7);
  
  array1[0] = 3;
  array1[1] = 2;
  array1[2] = 3;

  printf("ans1 = %d\n",majorityElement(array1, 3));
  array2[0] = 2;
  array2[1] = 2;
  array2[2] = 1;
  array2[3] = 1;
  array2[4] = 1;
  array2[5] = 2;
  array2[6] = 2;
  printf("ans2 = %d\n",majorityElement(array2, 7));
  
  

  return 0;
}