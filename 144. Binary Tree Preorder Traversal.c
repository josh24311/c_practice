/*
144. Binary Tree Preorder Traversal
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 
Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
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
void preorderTraversalSub(struct TreeNode* root, int* returnSize, int* result){
  if(root == NULL)return ;
 
  result[*returnSize] = root->val;
  (*returnSize)++;
  preorderTraversalSub(root->left, returnSize, result);
  preorderTraversalSub(root->right, returnSize, result);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
  // recursive
  /*
  int* result = malloc(sizeof(int)*1024);
  *(returnSize) = 0;
  if(root == NULL)return NULL;
  preorderTraversalSub(root, returnSize,result);
  return result;
  */
  //Iteratively
  // stack     
  // buffer    1
  if(root == NULL){
    *(returnSize) = 0;
    return NULL;
  }
  struct TreeNode* stack[100];
  struct TreeNode* buffer[100];
  stack[0] = root;
  int stackSize = 1;
  int bufferSize = 0;
  
  while(stackSize ){
    struct TreeNode* curr = stack[stackSize-1];
    stack[stackSize-1] = NULL;
    stackSize--;
    buffer[bufferSize] = curr;
    bufferSize++;
    if(curr->right){
      stack[stackSize] = curr->right;
      stackSize++;
    }
    if(curr->left){
      stack[stackSize] = curr->left;
      stackSize++;
    }
  }
  int* result = malloc(sizeof(struct TreeNode)*bufferSize);
  for(int i = 0; i < bufferSize; i++){
    result[i] = buffer[i]->val;
  }
  (*returnSize) = bufferSize;
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
  int *ans = preorderTraversal(a, p);
  for(int i = 0; i < *(p); i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
  t = 1;
  p = &t;
  d->val = 1;
  int *ans2 = preorderTraversal(d, p);
  printf("%d ",ans[0]);
  
  
  return 0;
}