/*
66. Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits. 

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
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




int* plusOne(int* digits, int digitsSize, int* returnSize){
  int i = 0, j = 0;
  int* result;
  for(i = digitsSize-1; i >=0; i--){
    if(digits[i] != 9){
      break;
    }
  }
  if(i == -1){
    // 全為 9 將會進一位
    result = malloc(sizeof(int)*(digitsSize+1));
    // 
    memset(result,0,sizeof(int)*(digitsSize+1));
    result[0] = 1;
    
    (*returnSize) = digitsSize+1;
  }
  else{
    // 有任一數不為9 bit數不會增加
    // 為9的bit改0
    for(j = digitsSize-1; j > i; j--){
      digits[j] = 0;
    }
    // 第一個不為9 的bit 為 i, 該位的值+1, 其餘不變
    digits[i]++;
    *returnSize = digitsSize;
    result = digits;
  }
  
  return result;
}

int main() {
  int* ar1 = malloc(sizeof(int)*3);
  ar1[0] = 1;
  ar1[1] = 0;
  ar1[2] = 9;
  
  int* rt1 = malloc(sizeof(int)*3);
  rt1[0] = 3;
  rt1[1] = 3;
  rt1[2] = 3;

  int* rs1 = plusOne(ar1, 3, rt1);
  for(int i = 0; i < 3; i++){
    printf(" %d ",rs1[i]);
  }
  
  
  
  return 0;
}