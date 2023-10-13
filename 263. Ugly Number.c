/*
263. Ugly Number
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.


Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

Constraints:

-2^31 <= n <= 2^31 - 1
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

bool isUgly(int n){
  if(n == 0) return false;
  if(n == 1)return true;
  if(n % 2 == 0){
    return isUgly(n/2);
  }
  if(n % 3 == 0){
    return isUgly(n/3);
  }
  if(n % 5 == 0){
    return isUgly(n/5);
  }
  return false;
}
/***************************************************************/

int main() {
  
  printf("ans1 = %s\n",isUgly(6)? "true" : "false");
  printf("ans2 = %s\n",isUgly(1)? "true" : "false");
  printf("ans3 = %s\n",isUgly(14)? "true" : "false");
    
  
  return 0;
}