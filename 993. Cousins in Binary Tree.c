/*
993. Cousins in Binary Tree

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

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
int getDepth(struct TreeNode* root, int target){
  if(root == NULL) return -1;
  if(root->val == target)return 0;
  int leftDepth = getDepth(root->left, target);
  int rightDepth = getDepth(root->right, target);
  if(leftDepth != -1){
    return leftDepth+1;
  }
  if(rightDepth != -1){
    return rightDepth+1;
  }
  return -1;
}
int getParent(struct TreeNode* root, int target){
  if(root == NULL)return -1;
  if(root->left == NULL && root->right == NULL && root->val != target){
    return -1;
  }
  if(root->left != NULL && root->left->val == target){
    return root->val;
  }
  if(root->right != NULL && root->right->val == target){
    return root->val;
  }
  
  int leftParent = getParent(root->left, target);
  int rightParent = getParent(root->right, target);
  if(leftParent != -1)return leftParent;
  if(rightParent!= -1)return rightParent;
  return -1;
}
bool isCousins(struct TreeNode* root, int x, int y){
  int xDepth = getDepth(root,x);
  int yDepth = getDepth(root,y);
  //printf("xdepth = %d, ydepth = %d\n",xDepth,yDepth);
  int xParent = getParent(root, x);
  int yParent = getParent(root, y);
  return (xDepth == yDepth) && (xParent != yParent);
}

/****************************************************************************************/
int main() {

  struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t5 = malloc(sizeof(struct TreeNode));

  t1->val = 1;
  t2->val = 2;
  t3->val = 3;
  t4->val = 4;
  t1->left= t2;
  t1->right= t3;
  t2->left = t4;

  printf("X = 4,Y = 3 are cousins? %s\n",isCousins(t1, 4, 3)==1?"True":"False");
  t2->left = NULL;
  t5->val = 5;
  t2->right = t4;
  t3->right = t5;
  printf("X = 5,Y = 4 are cousins? %s\n",isCousins(t1, 5, 4)==1?"True":"False");
  printf("X = 2,Y = 3 are cousins? %s\n",isCousins(t1, 2, 3)==1?"True":"False");

  
  
  return 0;
}