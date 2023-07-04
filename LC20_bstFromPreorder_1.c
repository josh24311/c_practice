/*
LC20_Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a<b) return a;
  else return b;
}

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

struct TreeNode* bstFromPreorderRanged(int* preorder, int start, int end ){
  if(start == end) return NULL;
  // [8] 5 1 7  | 10 12
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = preorder[start];
  int i = start+1;
  while( i < end && preorder[i] < root->val ){
    i++;
  }
  // 此時i為 1st 比root大的節點
  // range : [start,end) 包含起點不包含終點
  // left  : preorder[1]~preorder[i]
  // right : preorder[i]~preorder[preorderSize]

  root->left = bstFromPreorderRanged(preorder, start+1, i);
  root->right = bstFromPreorderRanged(preorder, i, end);
  return root;
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
  return bstFromPreorderRanged(preorder, 0,preorderSize);//[0,preorderSize)
  
}

void printTree(struct TreeNode* root, int h)
{
  if(root==NULL){
    printf("NULL ");
    return;
  }
  else{
    printf("%d ",root->val);
    
    
  }
  
  printTree(root->left,h);
  printTree(root->right,h);
}



int main() {
  int* arr1 = malloc(sizeof(int)*6);
  arr1[0] = 8;
  arr1[1] = 5;
  arr1[2] = 1;
  arr1[3] = 7;
  arr1[4] = 10;
  arr1[5] = 12;
  /*
          8
        5   10
      1  7    12

      output = [8,5,10,1,7,null,12]
  */

  int* arr2 = malloc(sizeof(int)*2);
  arr2[0] = 1;
  arr2[1] = 3;
  struct TreeNode* a = malloc(sizeof(struct TreeNode)*1);
  a = bstFromPreorder(arr1, 6);
  printTree(a,3);
  printf("\n");
  struct TreeNode* b = malloc(sizeof(struct TreeNode)*1);
  b = bstFromPreorder(arr2, 2);
  printf("----------\n");
  printTree(b,2);

  
  //printf("output tree for arr1: %d \n\n",0,search(arr1,7,0));
  //printf("output tree for arr2: %d\n\n",3,search(arr2,1,3));
  free(a);
  free(arr1);
  free(arr2);
  return 0;
}