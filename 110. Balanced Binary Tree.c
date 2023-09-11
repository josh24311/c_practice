/*
110. Balanced Binary Tree

Given a binary tree, determine if it is 
height-balanced

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
int findHeight(struct TreeNode* root){
  if(root == NULL)return 0;
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);
  return lh>rh?lh+1:rh+1;
  
}
bool isBalanced(struct TreeNode* root){
  if(root == NULL)return true;
  int h1 = findHeight(root->left);
  int h2 = findHeight(root->right);
  //printf("h1 = %d\n",h1);
  //printf("h2 = %d\n",h2);
  int diff = (h1>=h2)?(h1-h2):(h2-h1);
  if(diff <= 1){//若該樹為平衡樹，則繼續判斷子樹是否仍為平衡樹
    return isBalanced(root->left)  && isBalanced(root->right);
  }
  else{
    return false;
  }
  
}

/****************************************************************************************/
int main() {

  struct TreeNode* t1 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t2 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t3 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t4 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t5 = malloc(sizeof(struct TreeNode));

  t1->val = 3;
  t2->val = 9;
  t3->val = 20;
  t4->val = 15;
  t5->val = 7;
  t1->left = t2;
  t1->right = t3;
  t3->left = t4;
  t3->right = t5;
  t2->left = NULL;
  t2->right = NULL;

  printf("is t1 balanced? %s\n",isBalanced(t1)?"True":"False");
  struct TreeNode* t6 = malloc(sizeof(struct TreeNode));
  struct TreeNode* t7 = malloc(sizeof(struct TreeNode));
  t1->val = 1;
  t2->val = 2;
  t3->val = 2;
  t4->val = 3;
  t5->val = 3;
  t6->val = 4;
  t7->val = 4;
  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t2->right = t5;
  t4->left = t6;
  t4->right = t7;
  t3->left = NULL;
  t3->right = NULL;
  printf("is t1 balanced? %s\n",isBalanced(t1)?"True":"False");
  

  
  
  return 0;
}