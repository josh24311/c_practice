/*
230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
//1. Count leftSize
/* 
int getSize(struct TreeNode* root){
  if(root==NULL) return 0;
  return getSize(root->left) + 1 + getSize(root->right);
}
int kthSmallest(struct TreeNode* root, int k){
  if(root == NULL) return 0;
  int leftSize = getSize(root->left);
  if(k < leftSize+1){
    return kthSmallest(root->left, k);
  }
  else if (k == leftSize+1){
    return root->val;  
  }
  return kthSmallest(root->right, k-(leftSize+1));
}
*/
//2. Inorder traversal 
/*
void inorderTraversal(struct TreeNode* root, int* path, int* size){
  if(root == NULL)return ;
  inorderTraversal(root->left, path, size);
  path = realloc(path, sizeof(int)*(*size+1));
  path[*size] = root->val;
  (*size)++;
  inorderTraversal(root->right, path, size);
}
int kthSmallest(struct TreeNode* root, int k){
  int* path = malloc(sizeof(int));
  int pathSize = 0;
  
  inorderTraversal(root,path,&pathSize);
  return path[k-1];
}
*/
void helper(struct TreeNode* root, int* count, int* ans, int k){
  if(root == NULL) return;
  helper(root->left, count, ans, k);
  (*count)++;
  if((*count) == k){
    (*ans) = root->val;
    return;
  }
  helper(root->right, count, ans, k);
}
int kthSmallest(struct TreeNode* root, int k){
  int ans = 0;
  int count = 0;
  helper(root, &count, &ans, k);
  return ans;
}

/****************************************************************************************/
int main() {
  struct TreeNode* a = malloc(sizeof(struct TreeNode));
  struct TreeNode* b = malloc(sizeof(struct TreeNode));
  struct TreeNode* c = malloc(sizeof(struct TreeNode));
  struct TreeNode* d = malloc(sizeof(struct TreeNode));
  a->val = 3;
  b->val = 1;
  c->val = 4;
  d->val = 2;
  a->left = b;
  a->right = c;
  b->right = d;
  printf("%d's small is %d\n",1,kthSmallest(a, 1));
  struct TreeNode* e = malloc(sizeof(struct TreeNode));
  struct TreeNode* f = malloc(sizeof(struct TreeNode));
  struct TreeNode* g = malloc(sizeof(struct TreeNode));
  struct TreeNode* h = malloc(sizeof(struct TreeNode));
  struct TreeNode* i = malloc(sizeof(struct TreeNode));
  struct TreeNode* j = malloc(sizeof(struct TreeNode));
  e->val = 5;
  f->val = 3;
  g->val = 6;
  h->val = 2;
  i->val = 4;
  j->val = 1;
  e->left = f;
  e->right = g;
  f->left = h;
  f->right = i;
  h->left = j;
  printf("%d's small is %d\n",3,kthSmallest(e, 3));

  
  return 0;
}