/*
#bitOP
231. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
Example 1:

Input: n = 1
Output: true
Explanation: 2^0 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 2^4 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-2^31 <= n <= 2^31 - 1
 

Follow up: Could you solve it without loops/recursion?
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
bool isPowerOfTwo(int n){
  /*
  // method 1 divede by 2 , and check %2 
  if(n != 1 && n %2 != 0)return false;
  if(n == 1) return true;
  while(n > 2){
    if(n%2!=0)return false;
    
    n = n/2;
  }
  if(n == 2){
    return true;
  }
  else{
    return false;
  }
  return false;
  */
  // method 2 bit operation
  return n > 0 && (n & (n-1))==0;
}
/***************************************************************/
int main() {
  int a = 1;
  printf("%d is power of 2 %s\n",a,isPowerOfTwo(a)?"True":"False");
  a = 16;
  printf("%d is power of 2 %s\n",a,isPowerOfTwo(a)?"True":"False");
  a = 3;
  printf("%d is power of 2 %s\n",a,isPowerOfTwo(a)?"True":"False");
  return 0;
}