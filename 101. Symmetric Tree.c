/*
101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:
 Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 
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
/*
       1
    2     2  
  3  4   4  3
5 6 7 8 8 7 6 5  
*/
bool isSymmetricTree(struct TreeNode* left, struct TreeNode* right){
  if(left == NULL || right == NULL){
   return left==right; 
  }
  else{
    if(left->val != right->val)return false;
    else{
      return isSymmetricTree(left->left, right->right) && isSymmetricTree(left->right, right->left);
    }
  }
}
bool isSymmetric(struct TreeNode* root){
  if(root == NULL) return true;
  return isSymmetricTree(root->left, root->right);
  
}

/****************************************************************************************/
int main() {
  Tree* t = malloc(sizeof(Tree));
  // 1 2 2 3 4 4 3
  Tree* a = malloc(sizeof(Tree));
  Tree* b = malloc(sizeof(Tree));
  Tree* c = malloc(sizeof(Tree));
  Tree* d = malloc(sizeof(Tree));
  Tree* e = malloc(sizeof(Tree));
  Tree* f = malloc(sizeof(Tree));
  
  t->val = 1;
  a->val = 2;
  b->val = 2;
  c->val = 3;
  d->val = 4;
  e->val = 4;
  f->val = 3;
  t->left = a;
  t->right = b;
  a->left = c;
  a->right = d;
  b->left = e;
  b->right = f;

  printf("Tree t\tis sym? %d\n",isSymmetric(t));
  Tree* t2 = malloc(sizeof(Tree));
  Tree* g = malloc(sizeof(Tree));
  Tree* h = malloc(sizeof(Tree));
  Tree* i = malloc(sizeof(Tree));
  Tree* j = malloc(sizeof(Tree));
  t2->val = 1;
  g->val = 2;
  h->val = 2;
  i->val = 3;
  j->val = 3;
  t2->left = g;
  t2->right = h;
  g->right = i;
  h->right = j;
  printf("Tree t2\tis sym? %d\n",isSymmetric(t2));
  

  return 0;
}