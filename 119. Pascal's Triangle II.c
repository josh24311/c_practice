/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
Constraints:

0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/

int* getRow(int rowIndex, int* returnSize){
/*                       rowIndex   returnSize  fuc in for
          1              0          1            0
        1   1            1          2            0
      1   2   1          2          3            1
    1   3   3   1        3          4            2
  1   4   6   4   1      4          5            3
1   5   10  10  5   1    5          6            4        
*/
  int *cur = NULL;
  *(returnSize) = rowIndex+1;
  cur = realloc(cur, sizeof(int)*(*returnSize));
  memset(cur,0,sizeof(int)*(*returnSize));
  cur[0] = 1;
  for(int i = 1; i < (*returnSize); i++){
    for(int j = i ; j > 0; j--){//greedy 由後往前改值，就不怕覆蓋到了
      cur[j] = cur[j] + cur[j-1]; 
      /*
      i = 3
      cur[3] = cur[3] + cur[2] = 0 + 1 = 1
      cur[2] = cur[2] + cur[1] = 1 + 2 = 3
      cur[1] = cur[1] + cur[0] = 1 + 2 = 3
      */
    }
  }
  

  return cur;
}
/****************************************************************************************/
int main() {
  int a = 0;
  int *returnSize = &a;
  
  int *ans = getRow(3, returnSize);
  for(int i = 0; i < *(returnSize); i++){
    printf("%d ",ans[i]);
  }
  
  return 0;
}