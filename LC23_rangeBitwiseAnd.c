/*
LC23_Bitwise AND of Numbers Range
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4
Example 2:
Input: left = 0, right = 0
Output: 0
Example 3:
Input: left = 1, right = 2147483647
Output: 0
 

Constraints:
0 <= left <= right <= 2^31 - 1
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


int rangeBitwiseAnd(int m, int n){
  // 5 & 6 & 7
  //     421
  // -------
  // 5 : 101
  //&6 : 110
  // ----------
  //     100
  //&7 : 111
  // ----------
  //     100
  
  /* TLE ver
  int res = m;
  for(int k = m+1; k <n; k++){
    res = res & k;
  }
  if(m != n){
    res = res & n;// in case n = INT_MAX
  }*/

  // Transfer DEC to BIN
  /*
  for(int k = m; k <= n; k++){
    printf("%d: ",k);
    for(int i = 30; i >= 0; i--){
      printf("%d", (k & (1 << i)) != 0);
    }
    printf("\n");
  }
  */
  int res = 0;
  // Thought : 解本身即為 找頭和尾，前面一樣的bit照抄，後面不一樣的bit補0
  
  // Method1 : 左往右數，一樣的bit相加
  /*
  for(int i = 30; i >= 0; i--){
    int dm = m & (1 << i);
    int dn = n & (1 << i);
    if(dm == dn){
      res = res + dm;
    }
    else{
      break;
    }
  }
  */
  // Method2 : 同理， >> 運算子直到2者相同，最後再補0回來
  
  int count = 0;
  while( m != n ){
    m = m >> 1;
    n = n >> 1;
    count++;
  }
  res = m << count;

  
  return res;
}

int main() {
  int left1 = 5, right1 = 7;
  int left2 = 0, right2 = 0;
  int left3 = 1, right3 = 2147483647;
  
  printf("\nLeft1 is %d, Right1 is %d. Answer: %d\n",left1,right1,rangeBitwiseAnd(left1, right1));
  printf("\nLeft2 is %d, Right2 is %d. Answer: %d\n",left2,right2,rangeBitwiseAnd(left2, right2));
  printf("\nLeft3 is %d, Right3 is %d. Answer: %d\n",left3,right3,rangeBitwiseAnd(left3, right3));

  
  
  
  return 0;
}