/*
145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
/****************************************************************************************/
void postorderTraversalSub(struct TreeNode* root, int* returnSize,int* result){
  if(root == NULL)return;
  postorderTraversalSub(root->left, returnSize, result);
  postorderTraversalSub(root->right, returnSize, result);
  result[*returnSize] = root->val;
  (*returnSize)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
  (*returnSize) = 0;// 此行需在if(root == NULL) return NULL  之前
  if(root == NULL) return NULL;
  int* result = malloc(sizeof(int)*101);
  memset(result,0, sizeof(int)*101);
  
  postorderTraversalSub(root, returnSize, result);
  return result;
}

/****************************************************************************************/
int main() {
  struct TreeNode* a = malloc(sizeof(struct TreeNode));
  struct TreeNode* b = malloc(sizeof(struct TreeNode));
  struct TreeNode* c = malloc(sizeof(struct TreeNode));
  struct TreeNode* d = malloc(sizeof(struct TreeNode));
  a->val = 1;
  b->val = 2;
  c->val = 3;
  a->right = b;
  b->left = c;
  int t = 3;
  int* p = &t;
  int *ans = postorderTraversal(a, p);
  for(int i = 0; i < *(p); i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
  t = 1;
  p = &t;
  d->val = 1;
  int *ans2 = postorderTraversal(d, p);
  printf("%d ",ans2[0]);
  
  return 0;
}