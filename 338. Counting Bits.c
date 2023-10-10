/*
#bitOP
#DP

338. Counting Bits
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 
Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

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
/***************************************************************/
int* countBits(int n, int* returnSize){
  /*
  0 = 00000000 00000000 00000000 00000000 has 0
  1 = 00000000 00000000 00000000 00000001 has 1
  2 = 00000000 00000000 00000000 00000010 has 1
  3 = 00000000 00000000 00000000 00000011 has 2
  4 = 00000000 00000000 00000000 00000100 has 1
  5 = 00000000 00000000 00000000 00000101 has 2
  
  */
  (*returnSize) = n+1;
  int* ans = (int*)malloc(sizeof(int)*(*returnSize));

  ans[0] = 0;// 初始化當i = 0
  for(int i = 1; i <= n; i++){
    /*
    i/2 = 00XXXXXX XXXXXXXX XXXXXXXX XXXXXXXX
    i   = 0XXXXXXX XXXXXXXX XXXXXXXX XXXXXXXO
    i的二進制bit 30~ bit 1 的值等於i/2的二進制的值
    */
    
    ans[i] = ans[i/2] + ( (i&1) > 0);
  }
  return ans;
}

/***************************************************************/
int main() {
  int a = 2, b = 5;
  int* p = &a;
  int* ac = malloc(sizeof(int)*(a+1));
  ac = countBits(a, p);
  for(int i = 0; i < (*p); i++){
    printf("%d ",ac[i]);
  }
  printf("\n");
  p = &b;
  int* bc = malloc(sizeof(int)*(b+1));
  bc = countBits(b, p);
  for(int i = 0; i < (*p); i++){
    printf("%d ",bc[i]);
  }
  
  return 0;
}