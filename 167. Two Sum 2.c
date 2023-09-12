/*
167. Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
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
struct hasht{
  int index;
  int val;
};
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
  // 2 7 11 15 -> target 9 => return [1,2]

  // -1 1 6 7 10  
  int* rst = malloc(sizeof(int)*2);
  (*returnSize) = 2;
  int i = 0, j = numbersSize-1;
  while(i < j){
    if(numbers[i]+ numbers[j] == target){
      rst[0] = i+1;
      rst[1] = j+1;
      return rst;
    }
    else if (numbers[i]+numbers[j] < target){
      i++;
    }
    else{
      j--;
    }
  }

    
  return rst;
  
}
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

  int* c = malloc(sizeof(int)*4);
  c[0] = 2;
  c[1] = 7;
  c[2] = 11;
  c[3] = 15;
  
  int rst = 0;
  int *returnSize = &rst;

  int* ans = malloc(sizeof(int*));
  ans = twoSum(c, 4, 9, returnSize);
  printf("returnSize now is %d\n",*(returnSize));
  printf("[ ");
  for(int i = 0; i < (*returnSize) ; i++){
    //printf("i = %d\n",i);
    printf("%d ",ans[i]);
  }
  printf("]\n");
  return 0;
}