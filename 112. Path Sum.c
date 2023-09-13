/*
112. Path Sum
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
bool hasPathSum(struct TreeNode* root, int targetSum){
  if(root == NULL)return false;
  if(root->left == NULL && root->right == NULL){
    return root->val == targetSum;
  }
  return (hasPathSum(root->left, targetSum-root->val) || (hasPathSum(root->right, targetSum-root->val)));
}

/****************************************************************************************/
int main() {

  Tree* t1 = malloc(sizeof(Tree));
  Tree* t2 = malloc(sizeof(Tree));
  Tree* t3 = malloc(sizeof(Tree));
  Tree* t4 = malloc(sizeof(Tree));
  Tree* t5 = malloc(sizeof(Tree));
  Tree* t6 = malloc(sizeof(Tree));
  Tree* t7 = malloc(sizeof(Tree));
  Tree* t8 = malloc(sizeof(Tree));
  Tree* t9 = malloc(sizeof(Tree));
  t1->val = 5;
  t2->val = 4;
  t3->val = 8;
  t4->val = 11;
  t5->val = 13;
  t6->val = 4;
  t7->val = 7;
  t8->val = 2;
  t9->val = 1;
  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t3->left = t5;
  t3->right = t6;
  t4->left = t7;
  t4->right = t8;
  t6->right = t9;
  printf("has pathSum? %s\n",hasPathSum(t1, 22)?"True":"False");
  return 0;
}