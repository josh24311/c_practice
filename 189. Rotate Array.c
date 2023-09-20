/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
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
void reverse(int* nums, int start, int end){
  while(start < end){
    //swap two numbers
    nums[start] ^= nums[end];
    nums[end] ^= nums[start];
    nums[start] ^= nums[end];
    
    start++;
    end--;
  }
}
void rotate(int* nums, int numsSize, int k){
  // 0 1 2 3 | 4 5 6
  // 1 2 3   4 5 6 7 => k = 3
  // 7 6 5 | 4 3 2 1
  // 5 6 7 | 1 2 3 4
  
  if(k%numsSize == 0)return;
  k = k % numsSize;
  reverse(nums,0,numsSize-1);
  reverse(nums,0,k-1);
  reverse(nums,k,numsSize-1);
  

}

/****************************************************************************************/
int main() {
  int*a = malloc(sizeof(int)*7);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  a[4] = 5;
  a[5] = 6;
  a[6] = 7;
  rotate(a, 7, 3);
  printf("a:\t");
  for(int i = 0; i < 7; i++){
    printf("%d ",a[i]);  
  }
  printf("\n");
  int* b = malloc(sizeof(int)*4);
  b[0] = -1;
  b[1] = -100;
  b[2] = 3;
  b[3] = 99;
  rotate(b, 4, 2);
  printf("b:\t");
  for(int i = 0; i < 4; i++){
    printf("%d ",b[i]);  
  }
  return 0;
}