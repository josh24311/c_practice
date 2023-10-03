/*
#hashMap
#qsort
219. Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5

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
/***************************************************************************/
//idx     0 1 2 3 4 5
//val     1 2 3 1 2 3  , k=2
//p      (0,1) (3,1) (1,2) (4,2) (2,3) (5,3) 
//i  
//j      
struct hash{
  int idx;
  int val;
};
int cmp3(const void *a, const void *b){
  if(((const struct hash*)a)->val < ((const struct hash*)b)->val){
    return -1;
  } 
  else if (((const struct hash*)a)->val > ((const struct hash*)b)->val){
    return 1;
  }
  else{
    if(((const struct hash*)a)->idx < ((const struct hash*)b)->idx){
      return -1;
    }
    else{
      return 1;
    }
  }
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
  if(numsSize < 2 || nums == NULL){
    return false;
  }
  //TLE
  /*
  for(int i = 0; i < numsSize; i++){
    for(int j = 1; j <= k && (i+j) < numsSize; j++){
      if(nums[i] == nums[i+j]){
        return true;
      }
    }
  }  
  return false;
  */
  struct hash *p = malloc(sizeof(struct hash)*numsSize);
  for(int i = 0; i < numsSize; i++){
    p[i].val = nums[i];
    p[i].idx = i;
  }
  qsort(p, numsSize, sizeof(struct hash), cmp3);
  //      idx,val
  //p      (0,1) (3,1) (1,2) (4,2) (2,3) (5,3) 
  for(int i = 0; i < numsSize-1; i++){
    if(p[i].val == p[i+1].val){
      if(p[i+1].idx - p[i].idx <= k){
        return true;
      }
    }
  }
  free(p);
  return false;
}


/***************************************************************************/
int main() {
  int* a = malloc(sizeof(int)*4);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 1;
  printf("ans1 = %s\n",containsNearbyDuplicate(a, 4, 3)?"True":"False");
  int* b = malloc(sizeof(int)*4);
  b[0] = 1;
  b[1] = 0;
  b[2] = 1;
  b[3] = 1;
printf("ans2 = %s\n",containsNearbyDuplicate(b, 4, 1)?"True":"False");
  int* c = malloc(sizeof(int)*6);
  c[0] = 1;
  c[1] = 2;
  c[2] = 3;
  c[3] = 1;
  c[4] = 2;
  c[5] = 3;
  printf("ans3 = %s\n",containsNearbyDuplicate(c, 6, 2)?"True":"False");
  int* d = malloc(sizeof(int)*2);
  d[0] = 99;
  d[1] = 99;
  printf("ans4 = %s\n",containsNearbyDuplicate(d, 2, 2)?"True":"False");
  return 0;
}