/*

#BST 性質
#traversal

530. Minimum Absolute Difference in BST
Easy
Topics
Companies
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 10^4].
0 <= Node.val <= 10^5
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
/*
思路: BST內以inorderTraversal 會得到一個val小到大的array
以prev 紀錄 前一個node 的 val

*/

void helper(struct TreeNode* root, int* diff, int* prev){
  if(root == NULL)return;
  helper(root->left, diff, prev);
  if(*prev != -1){
    *diff = min(*diff, abs(root->val - *prev));
  }
  *prev = root->val;
  helper(root->right, diff, prev);
}
int getMinimumDifference(struct TreeNode* root){
  if(root == NULL){
    return -1;
  }
  int diff = INT_MAX;
  int prev = -1;
  helper(root, &diff, &prev);
  return diff;
}

/***************************************************************/

int main() {
  struct TreeNode* a = malloc(sizeof(struct TreeNode));
  struct TreeNode* b = malloc(sizeof(struct TreeNode));
  struct TreeNode* c = malloc(sizeof(struct TreeNode));
  struct TreeNode* d = malloc(sizeof(struct TreeNode));
  struct TreeNode* e = malloc(sizeof(struct TreeNode));
  struct TreeNode* f = malloc(sizeof(struct TreeNode));
  a->val = 1;
  b->val = 5;
  c->val = 3;
  
  a->left = NULL;
  a->right = b;
  b->left = c;
 
  printf("ans1 = %d\n",getMinimumDifference(a));
 
  return 0;
}