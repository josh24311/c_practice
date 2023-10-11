/*
#binaryTree
#recursive
#important
257. Binary Tree Paths
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
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
#define MAX_PATH_STR_SIZE   5000

bool binaryTreePathsHelper(struct TreeNode* root, char *str, int strIdx, char ***ret, int* returnSize)
{
  if (NULL == root)
  {
      return true;
  }
    
  char buf[12] = {0};
  
  sprintf(buf, "->%d", root->val);
  int len = strlen(buf);       
  memcpy(&(str[strIdx]), buf, sizeof(char)*len);
  strIdx += len;
  
  bool retLeft = binaryTreePathsHelper(root->left, str, strIdx, ret, returnSize);
  bool retRight = binaryTreePathsHelper(root->right, str, strIdx, ret, returnSize);        
  // Lead Node
  if (retLeft && retRight)
  {
      str[strIdx] = 0;
      *ret = realloc(*ret, sizeof(char *)*(*returnSize+1));
      (*ret)[*returnSize] = calloc(MAX_PATH_STR_SIZE, sizeof(char));
      strcpy((*ret)[*returnSize], &str[2]);
      *returnSize += 1;        
  }
  
  return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char **ret = malloc(sizeof(char*));
    char *path = calloc(MAX_PATH_STR_SIZE, sizeof(char));
    *returnSize = 0;
    binaryTreePathsHelper(root, path, 0, &ret, returnSize);
    
    free(path);
    return ret;
}

/***************************************************************/

int main() {
    // Create a sample binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = root->right->right = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 5;
    root->left->right->left = root->left->right->right = NULL;

    int returnSize;
    char** result = binaryTreePaths(root, &returnSize);

    printf("Binary Tree Paths:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // Free memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}