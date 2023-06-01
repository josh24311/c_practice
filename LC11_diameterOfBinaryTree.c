/*
LC11_diameterOfBinaryTree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right; 
}Tree;

Tree* new_node(int x){
  Tree* tmp;
  tmp = malloc(sizeof(Tree));
  tmp->val = x;
  tmp->left = NULL;
  tmp->right = NULL;
}
Tree* insert(Tree * root, int x){  
  if (root == NULL)  
    return new_node(x);  
  else if (x > root->val)  
    root->right = insert(root->right, x);  
  else   
    root->left = insert(root->left, x);  
  return root;  
}  
//從樹根走到最遠的樹葉需要經過幾個節點
int maxDepth(Tree* root){
  if(root == NULL) return 0;
  int leftMax   = maxDepth(root->left);
  int rightMax  = maxDepth(root->right);
  return (leftMax > rightMax ? leftMax : rightMax) + 1;
}
int diameterOfBinaryTree(Tree* root){
  if(root == NULL) return 0;
  //最長路徑通過root
  //   起點在左子樹，終點在右子樹，等同求左右子樹的深度和
  int middle  =   maxDepth(root->left) + maxDepth(root->right);
  //最長路徑沒通過root
  //a. 最長路徑在左子樹
  //   等於求diameterOfBinaryTree(root->left)
  int left    =   diameterOfBinaryTree(root->left);
  //b. 最長路徑在右子樹
  //   等於求diameterOfBinaryTree(root->right)
  int right    =  diameterOfBinaryTree(root->right);
  int max = middle;
  if(left > max){
    max = left;
  }
  if(right > max){
    max = right;
  }

  return max;
}
int main() {
  
  Tree* root = new_node(78);
  insert(root,22);
  insert(root,86);
  insert(root,8);
  insert(root,59);
  insert(root,82);
  insert(root,3);
  insert(root,56);
  insert(root,71);
  insert(root,62);
  printf("maxlength is %d\n",diameterOfBinaryTree(root));
 
  free(root);
  return 0;
}

