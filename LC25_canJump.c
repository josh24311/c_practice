/*
LC25_Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a<b) return a;
  else return b;
}

bool canJump(int* nums, int numsSize){
  // a = [2, 3, 1, 1, 4]
  // [F, F, F, F, F] -> [T, ?, ?, ?, T]
  //method1 
  /*
  bool* t = malloc(sizeof(int)*numsSize);
  for(int i = 1; i < numsSize; i++){
    t[i] = false;
  }
  t[0] = true;
  
  for(int i = 0; i < numsSize; i++){
    if(t[i] == true)  {
      for(int j = 1; j <= nums[i]; j++){
        if(i+j <= numsSize){
          t[i+j] = true;
        }
      }
    }
  }
  
  return t[numsSize-1];
  */
  // [T, F, F, F, F] 3 2 0 1 4
  int maxCanreach = 0;
  for(int i = 0; i < numsSize; i++){
    if(i <= maxCanreach){
      int canReach = i + nums[i];//該輪最遠可到達處index
      if(canReach > maxCanreach){
        maxCanreach = canReach;
      }
    }
  }

  return maxCanreach >= numsSize -1;
  
  

}


int main() {
  int* a = malloc(sizeof(int)*5);
  a[0] = 2;
  a[1] = 3;
  a[2] = 1;
  a[3] = 1;
  a[4] = 4;

  int*b = malloc(sizeof(int)*5);
  b[0] = 3;
  b[1] = 2;
  b[2] = 1;
  b[3] = 0;
  b[4] = 4;

  printf("a can jump or not ? %s\n",canJump(a, 5)==1?"true":"false");
  printf("b can jump or not ? %s\n",canJump(b, 5)==1?"true":"false");
  
  free(a);
  free(b);
  
  
  return 0;
}