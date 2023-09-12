/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
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

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  // nums = [-1,0,1,2,-1,-4]
  // nums = [-4,-1,-1,0,1,2]
  int rstSize = 0;
  int first,second,third,sum;
  int bSize = 8;
  int** rst = malloc(sizeof(int*)*bSize);
   *returnColumnSizes = (int *)malloc(sizeof(int) * bSize);
  qsort(nums, numsSize, sizeof(int), cmp);
  for(first = 0; first < numsSize-2; first++){
    if(first > 0 && nums[first] == nums[first-1]){
      // if nums[first] duplicate
      continue;
    }
    second = first+1;
    third = numsSize-1;
    while(second < third){
      if(nums[second] == nums[second-1] && second != first+1){//  second != first +1 非第一輪
        second++;
        continue;
      }
      sum = nums[first]+nums[second]+nums[third];
      if(sum == 0){
        // found 
        rst[rstSize] = (int *)malloc(sizeof(int) * 3);
        (*returnColumnSizes)[rstSize] = 3;
        rst[rstSize][0] = nums[first];
        rst[rstSize][1] = nums[second];
        rst[rstSize][2] = nums[third];
        rstSize++;
        second++;// find next with same i
        third--;//find next with same i
        if(rstSize == bSize){
          // expand array size
          bSize*=2;
          rst = (int**)realloc(rst, sizeof(int*)*bSize);
          (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), sizeof(int)*bSize);
        }
      }
      else if (sum < 0){
        //sum is too small
        second++;
      }
      else{
        //sum is too large
        third--;
      }
    }
  }
  

  *(returnSize) = rstSize;
  return rst;
}

/****************************************************************************************/
int main() {

  int* c = malloc(sizeof(int)*6);
  c[0] = -1;
  c[1] = 0;
  c[2] = 1;
  c[3] = 2;
  c[4] = -1;
  c[5] = -4;
  int rst = 0;
  int *returnSize = &rst;
  
  int **returnColumnSizes = malloc(sizeof(int*));
  returnColumnSizes[0] = malloc(sizeof(int)*3);
  returnColumnSizes[0][0] = 3;
  returnColumnSizes[0][1] = 3;
  returnColumnSizes[0][2] = 3;
  int** ans = malloc(sizeof(int*)*2);
  ans = threeSum(c, 6, returnSize, returnColumnSizes);
  printf("returnSize now is %d\n",*(returnSize));
  for(int i = 0; i < *returnSize ; i++){
    for(int j = 0; j < 3; j++){
      printf("%d ",ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}