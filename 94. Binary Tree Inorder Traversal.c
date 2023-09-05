/*
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
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
void goTra(struct TreeNode*root, int* returnSize, int* res){
  if(root == NULL) return;
  goTra(root->left, returnSize, res);
  res[(*returnSize)] = root->val;
  (*returnSize)+=1;
  goTra(root->right, returnSize, res);

}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
  if(root == NULL){
    int* nn = malloc(sizeof(int)*0);
    *returnSize = 0;
    return nn;
  }
  int* res = malloc(sizeof(int)*101);
  *returnSize = 0;
  goTra(root, returnSize, res);
  return res;
  
}
/****************************************************************************************/
int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  Tree* root = malloc(sizeof(Tree));
  root->val = 1;
  Tree* b = malloc(sizeof(Tree));
  b->val = 2;
  root->left = b ;
  Tree* c = malloc(sizeof(Tree));
  c->val = 3;
  root->right = c;
  Tree* d = malloc(sizeof(Tree));
  d->val = 4;
  b->left = d;
  Tree* e = malloc(sizeof(Tree));
  e->val = 5;
  e->left = NULL;
  e->right = NULL;
  b->right = e;
  Tree* f = malloc(sizeof(Tree));
  f->val = 6;
  c->right = f;
  c->left = NULL;
  Tree* g = malloc(sizeof(Tree));
  g->val = 7;
  g->left = NULL;
  g->right = NULL;
  d->left = g;
  Tree* h = malloc(sizeof(Tree));
  h->val = 8;
  h->left = NULL;
  h->right = NULL;
  d->right = h;
  Tree* i = malloc(sizeof(Tree));
  i->val = 9;
  i->left = NULL;
  i->right = NULL;
  f->left = i;
  Tree* j = malloc(sizeof(Tree));
  j->val = 10;
  f->right = j;
  int* returnSize = malloc(sizeof(int)*10);
  int id;
  for(id = 0; id < 10; id++){
    returnSize[id] = 10;
  }
  int* ans = inorderTraversal(root, returnSize);
  id = 0;
  
  while(id<10){
    printf("%d ",ans[id++]);
  }


  

  return 0;
}