/*
202. Happy Number
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

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
/*******************************************************************************/
int calSum(n){
  int r;
  int sum = 0;
  while(n > 0){
    r = n %10;
    sum+=r*r;
    n/=10;
  }
  return sum;
}
bool isHappy(int n){
  /*
  1**2 + 9**2 = 82
  8**2 + 2**2 = 68
  6**2 + 8**2 = 100
  1**2 + 0 + 0 = 1 END
  ---
  2**2 = 4
  4**2 = 16
  1**2 + 6**2 = 37
  3**2 + 7**2 = 58
  5**2 + 8**2 = 89
  8**2 + 9**2 = 145
  1**2 + 4**2 + 5**2 = 42
  4**2 + 2**2 = 20
  2**2 = 4
  */
  int fast,slow;
  slow = calSum(n);
  fast = calSum(calSum(n));
  //printf("slow = %d, fast = %d\n",slow,fast);
  while(fast!=slow){
    slow = calSum(slow);
    fast = calSum(calSum(fast));
  }
  return slow==1;
}


/****************************************************************************************/
int main() {
  
  printf("%d is happy? %s\n",19,isHappy(19)?"True":"False");
  printf("%d is happy? %s\n",2,isHappy(2)?"True":"False");




  
  return 0;
}