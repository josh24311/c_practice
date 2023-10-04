/*
222. Count Complete Tree Nodes
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
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

//method 1 : 遞迴直接數
/*
void helper(struct TreeNode* root , int* nodeNum){
  if(root == NULL )return;
  (*nodeNum)++;
  helper(root->left, nodeNum);
  helper(root->right, nodeNum);
}
int countNodes(struct TreeNode* root){
  if(root == NULL )return 0;
  //int h = treeHeight(root);
  int nodeNum = 0;
  helper(root, &nodeNum);
  return nodeNum;
}
*/
//method2 高度套公式+遞迴，只看最左下和最右下節點
int countNodes(struct TreeNode* root)
{
    struct TreeNode *l = root, *r = root;
    int h_left = 0, h_right = 0;    
    // go to left-most child
    while (l) {
        l=l->left;
        h_left++;
    }
    // go to right-most child
    while (r) {
        r=r->right;
        h_right++;
    }
    // Full binary tree, skip recursive countNodes
    if (h_left == h_right)
        return (0x1 << h_left) - 1;    

    return countNodes(root->left) + countNodes(root->right) + 1; 
}

/***************************************************************************/
int main() {
  struct TreeNode* a = malloc(sizeof(struct TreeNode));
  struct TreeNode* b = malloc(sizeof(struct TreeNode));
  struct TreeNode* c = malloc(sizeof(struct TreeNode));
  struct TreeNode* d = malloc(sizeof(struct TreeNode));
  struct TreeNode* e = malloc(sizeof(struct TreeNode));
  struct TreeNode* f = malloc(sizeof(struct TreeNode));
  a->val = 1;
  b->val = 2;
  c->val = 3;
  d->val = 4;
  e->val = 5;
  f->val = 6;
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  printf("ans1 = %d\n",countNodes(a));
  
  
  struct TreeNode* h = malloc(sizeof(struct TreeNode));
  h->val = 1;
  printf("ans3 = %d\n",countNodes(h));
  
  struct TreeNode *g ;
  printf("ans2 = %d\n",countNodes(g));
  return 0;
}