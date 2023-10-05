/*
#tree
#binaryTree
#recursive
226. Invert Binary Tree
Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
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
struct TreeNode* invertTree(struct TreeNode* root){
  if(root==NULL) return NULL;
  struct TreeNode* res = malloc(sizeof(struct TreeNode));
  res->val = root->val;//copy value
  res->left = invertTree(root->right);
  res->right = invertTree(root->left);
  return res;
  
}
void printTree(struct TreeNode* root){
  if(root!=NULL){
    printf("%d ",root->val);
  }
  else{
    return;
  }
  printTree(root->left);
  printTree(root->right);
  
}

/***************************************************************/
int main() {
  struct TreeNode* a = malloc(sizeof(struct TreeNode));
  struct TreeNode* b = malloc(sizeof(struct TreeNode));
  struct TreeNode* c = malloc(sizeof(struct TreeNode));
  struct TreeNode* d = malloc(sizeof(struct TreeNode));
  struct TreeNode* e = malloc(sizeof(struct TreeNode));
  struct TreeNode* f = malloc(sizeof(struct TreeNode));
  struct TreeNode* g = malloc(sizeof(struct TreeNode));
  struct TreeNode* ans = malloc(sizeof(struct TreeNode));
  a->val = 4;
  b->val = 2;
  c->val = 7;
  d->val = 1;
  e->val = 3;
  f->val = 6;
  g->val = 9;
  a->left = b;
  a->right = c;
  b->left= d;
  b->right = e;
  c->left = f;
  c->right = g;
  //printTree(a); // 4 2 1 3 7 6 9
  ans = invertTree(a);
  printTree(ans); // 4 7 9 6 2 3 1
  
  return 0;
}