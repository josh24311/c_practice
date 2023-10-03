/*
228. Summary Ranges
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
Example 2:

Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
 

Constraints:

0 <= nums.length <= 20
-231 <= nums[i] <= 231 - 1
All the values of nums are unique.
nums is sorted in ascending order.
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
// 0 1 2 4 5 7
// 0,1,2 為連續分為同一組 ; 4,5為連續 分為同一組 ; 7單獨一組
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
//    0 1 2 4 5 7
  (*returnSize) = 0;
  char** res = NULL;
  int i = 0;
  int low = 0;
  int high = 0;
  while(i < numsSize){
    low = i;
    i++;
    while(i < numsSize && nums[i] == nums[i-1]+1){
      i++;
    }
    high = i-1;

    res = realloc(res, sizeof(char*)*((*returnSize)+1));
    res[(*returnSize)] = malloc(sizeof(char)*25);
    snprintf(res[(*returnSize)],25,"%d",nums[low]);
    //printf("res[(*returnSize)][0] = %c\n",res[(*returnSize)][0]);
    if(low < high){
      snprintf(res[(*returnSize)],25,"%d->%d",nums[low],nums[high]);
    }
    (*returnSize)++;
  }
  return res;
}


/***************************************************************************/
int main() {
  int* a = malloc(sizeof(int)*6);
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 4;
  a[4] = 5;
  a[5] = 7;
  char** ans1 = malloc(sizeof(char*)*3);
  ans1[0] = malloc(sizeof(char)*4);
  ans1[1] = malloc(sizeof(char)*4);
  ans1[2] = malloc(sizeof(char)*1);
  int z = 0;
  int* p = &z;
  ans1 = summaryRanges(a, 6, p);
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < strlen(ans1[i]); j++){
      printf("%c",ans1[i][j]);
    }
    printf(",");
  }
  int* b = malloc(sizeof(int)*7);
  b[0] = 0;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  b[4] = 6;
  b[5] = 8;
  b[6] = 9;

  return 0;
}