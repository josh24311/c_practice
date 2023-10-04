/*
#tree
#binarySearchTree
#traversal
#recursive

1008. Construct Binary Search Tree from Preorder Traversal
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 1000
All the values of preorder are unique.
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
/***************************************************************************/
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
  // [8,5,1,7,10,12]
  //           ^
  if(preorderSize==0)return NULL;//邊界條件
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = preorder[0];
  int mid=  1;
  while(mid < preorderSize && preorder[mid] < root->val){
    mid++;
  }
  
  root->left = bstFromPreorder(&preorder[1], mid-1);
  root->right = bstFromPreorder(&preorder[mid], preorderSize-mid);
  return root;
}
void printTree(struct TreeNode* root){
  if(root==NULL)return;
  printf("%d\n",root->val);
  printTree(root->left);
  printTree(root->right);
}
/***************************************************************************/
int main() {
  int* a = malloc(sizeof(int)*6);
  
  a[0] = 8;
  a[1] = 5;
  a[2] = 10;
  a[3] = 1;
  a[4] = 7;
  a[5] = 12;
  struct TreeNode *t = bstFromPreorder(a, 6);
  printTree(t);
  
  
  return 0;
}