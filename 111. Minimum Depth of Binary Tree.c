/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
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

/****************************************************************************************/

int minDepth(struct TreeNode* root){
  if(root == NULL)return 0;
  if(root->left == NULL && root->right == NULL)return 1;
  else if (root->left == NULL){
    return minDepth(root->right)+1;
  }
  else if(root->right == NULL){
    return minDepth(root->left)+1;
  }
  else{
    int ld = minDepth(root->left);
    int rd = minDepth(root->right);
    return (ld<rd)?ld+1:rd+1;
  }
}

/****************************************************************************************/
int main() {

  struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t5 = malloc(sizeof(struct TreeNode));

  t1->val = 2;
  t2->val = 3;
  t3->val = 4;
  t4->val = 5;
  t5->val = 6;
  t1->left = NULL;
  t1->right = t2;
  t2->left = NULL;
  t2->right = t3;
  t3->left = NULL;
  t3->right = t4;
  t4->left = NULL;
  t4->right = t5;
  
  

  printf("min depth of t is %d\n",minDepth(t1));
  
  

  
  
  return 0;
}