/*
LC13_Contiguous Array
Given a binary array nums, return the maximum length of a contiguous subarray
with an equal number of 0 and 1. Example 1: Input: nums = [0,1] Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0
and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
number of 0 and 1.

Constraints:
1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
// count0(i,j,nums) nums[i] 到 nums[j] 中有多少個0
// count0(i,j,nums) == count0(0,j,nums) - count0(0,i-1,nums)


int findMaxLength(int *nums, int numsSize) {
  int *sum = malloc(sizeof(int)*(numsSize*2+1));        
    for (int i = 0; i < numsSize*2+1; i++)
    {
        sum[i] = -1;
    }
    
    int *tmp = &(sum[numsSize]);
    int ret = 0;
    int curSum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        curSum = (nums[i] == 0 ? curSum-1 : curSum+1);
        if (tmp[curSum] == -1 && curSum != 0)
        {
            tmp[curSum] = i;
            continue;
        } else
        {
            int diff = i - tmp[curSum];
            ret = ret > diff ? ret : diff;
        }
    }
    
    free(sum);
    return ret;
}

int main() {
  int st[] = {0, 1};
  int rt[] = {0, 1, 0};
  int zt[] = {0, 1, 1, 0, 1, 1, 1, 0};
  int ht[] = {0, 0, 1, 0, 0, 0, 1, 1};
  int size = 8;

  printf("Contiguous Array length is %d\n", findMaxLength(ht, size));
  return 0;
}
