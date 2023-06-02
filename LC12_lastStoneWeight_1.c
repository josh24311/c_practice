/*
LC12_lastStoneweight
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void * a , const void * b){
  return ( *(int*)a - *(int*)b);
}
int lastStoneWeight(int* stones, int stonesSize){
  // 2,7,4,1,8,1
  int i = 0, j = 0;
  int diff = 0;
  int tmpsize = stonesSize;
  while(tmpsize > 1){
    diff = 0;
    qsort(stones, stonesSize , sizeof(stones[0]), cmp); 
    diff = (stones[tmpsize-1] - stones[tmpsize-2]);
    if(tmpsize == 2){
      return diff;
    }
    else{
      stones[tmpsize - 2] = diff;
      tmpsize--;
    }
  }  
  return stones[0];
}

int main() {
  int st[] = {2,7,4,1,8,1};
  int rt[] = {2,0,0};
  int size = 3;

  printf("\nLastStoneWeight is %d\n",lastStoneWeight(rt, size));
  return 0;
}
