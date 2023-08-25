/*
LC29_Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000


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
  struct TreeNode* left;
  struct TreeNode* right;
}Tree;

Tree *createTree(int val){
  Tree* root = malloc(sizeof(Tree)*1);
  root->val = val;
  root->left = NULL;
  root->right = NULL;

  return root;
}
void insertLeft(Tree* root, int val){
  root->left = createTree(val);
  
}

void insertRight(Tree* root, int val){
  root->right = createTree(val);
  
}

// 回傳只能從root開始到任意終點的最大路徑和(可以不選，都不選為0)
int maxPathSumRoot(struct TreeNode* root){
  if(root == NULL) return 0;
  // 有選 root
  // case 1 選左
  int left = maxPathSumRoot(root->left) + root->val;
  // case 2 選右
  int right = maxPathSumRoot(root->right) + root->val;
  
  //沒選 root
  int result = 0;
  return max3(left, right, 0);
  
}

// 回傳任意起點走到任意終點的最大路徑和(不能不選，至少選一個節點)
int maxPathSum(struct TreeNode* root){
  if(root == NULL) return INT_MIN;
  
  // 經過中間 root 的最大路徑和
  int middle = root->val + maxPathSumRoot(root->left) + maxPathSumRoot(root->right);
  

  // 不經過中間root的最大路徑和
  //case 1 最大路徑發生在左子樹
  //因至少要有一個節點(不能為空)，所以若該子樹為空，使其回傳一個極小的值INT_MIN
  int left = maxPathSum(root->left);

  //case 2 最大路徑發生在右子樹
  int right = maxPathSum(root->right);
  
  
  return max3(left, right, middle);
}
int main() {
  Tree* rootA = createTree(1);
  insertLeft(rootA,  2);
  insertRight(rootA, 3);
  
  Tree* rootB = createTree(-10);
  insertLeft(rootB, 9);
  insertRight(rootB, 20);
  insertLeft(rootB->right, 15);
  insertRight(rootB->right, 7);
  
  
  
  
  printf("A max path sum is %d\n",maxPathSum(rootA));
  printf("B max path sum is %d\n",maxPathSum(rootB));
  free(rootA);
  free(rootB);
  return 0;
}