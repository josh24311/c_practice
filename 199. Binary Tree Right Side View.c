/*
#binaryTree
#recursive
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
void helper(struct TreeNode* root, int* arr, int height, int hNow){
  if(root == NULL)return;
  if(hNow < height){
    printf("hNow : %d, root now %d\n",hNow,root->val);
    if(arr[hNow] == 999){
      arr[hNow] = root->val;  
      printf("arr[%d] = %d\n",hNow,arr[hNow]);
    }
    hNow++;
    helper(root->right, arr, height, hNow);
    helper(root->left, arr, height, hNow);
  }
  else{
    return;
  }
}
int* rightSideView(struct TreeNode* root, int* returnSize){
  int h = treeHeight(root);
  (*returnSize) = h;
  if(root == NULL)return NULL;
  printf("%d\n",h);
  int *arr = (int*)malloc(sizeof(int)*h);
  for(int i = 0; i < h; i++){
    arr[i] = 999;
  }
  helper(root,arr, h , 0);
  return arr;
}
/***************************************************************/
int main() {
  struct TreeNode* a = malloc(sizeof(struct ListNode));
  struct TreeNode* b = malloc(sizeof(struct ListNode));
  struct TreeNode* c = malloc(sizeof(struct ListNode));
  struct TreeNode* d = malloc(sizeof(struct ListNode));
  struct TreeNode* e = malloc(sizeof(struct ListNode));
  struct TreeNode* f = malloc(sizeof(struct ListNode));
  a->val = 1;
  b->val = 2;
  c->val = 3;
  d->val = 5;
  e->val = 4;
  f->val = 8;
  a->left = b;
  a->right = c;
  b->right = d;
  c->right = e;
  d->left = f;
  /*
        1
       / \
      2   3
      \    \
       5    4
      /
     8
  */  
  int size = 0;
  int *p = &size;
  int* res = rightSideView(a, p);
  for(int i = 0; i < *p; i++){
    printf("%d ",res[i]);
  }
  printf("\n");
  
  return 0;
}