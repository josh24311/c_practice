/*
113. Path Sum II
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/
void DFS(struct TreeNode* root, int targetSum, int sumNow, int pIndex, int* rIndex, int* path, int** rst){
  if(root == NULL){
    printf("NULL point\n");
    return; 
  }

  path[pIndex] = root->val;
  pIndex++;
  printf("root %d, current path: ",root->val);
  for(int i = 0; i < pIndex; i++){
    printf("%d ",path[i]);
  }
  printf("\n");
  sumNow+=root->val;
  printf("rIndex now: %d\n",*rIndex);
  if(root->left == NULL && root->right == NULL){
    printf("~~~leaf node %d~~~\n",root->val);
    if(sumNow == targetSum){
      for(int i = 0; i < pIndex; i++){
        rst[*rIndex][i] = path[i];
      }
      printf("rst now : ");
      for(int i = 0; i <= (*rIndex); i++){
        printf("[");
        for(int j = 0; j < pIndex; j++){
          printf("%d ",rst[i][j]);
        }
        printf("]  ");
      }
      printf("\n");
      (*rIndex)++;
      
    }
    
    
  }
  DFS(root->left, targetSum, sumNow, pIndex, rIndex, path, rst);
  DFS(root->right, targetSum, sumNow, pIndex, rIndex, path, rst);

}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
  int bSize = 8;
  int** rst = malloc(sizeof(int*)*bSize);
  for(int i = 0; i < bSize; i++){
    rst[i] = malloc(sizeof(int)*bSize);
  }
  int heightMax = treeHeight(root);
  int* path = malloc(sizeof(int)*bSize);
  int r = 0;
  int* rIndex = &r;
  memset(path, 0, sizeof(int)*bSize);
  *returnColumnSizes = (int*)malloc(sizeof(int)*heightMax);
  DFS(root,targetSum,0,0,rIndex,path,rst);
  return rst;
  
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
  Tree* t10 = malloc(sizeof(Tree));
  t1->val = 5;
  t2->val = 4;
  t3->val = 8;
  t4->val = 11;
  t5->val = 13;
  t6->val = 4;
  t7->val = 7;
  t8->val = 2;
  t9->val = 5;
  t10->val = 1;
  t1->left = t2;
  t1->right = t3;
  t2->left = t4;
  t3->left = t5;
  t3->right = t6;
  t4->left = t7;
  t4->right = t8;
  t6->left = t9;
  t6->right = t10;
  int a = 0;
  int* returnSize = &a;
  int** rs = malloc(sizeof(int*)*2);
  int** returnColumnSizes = malloc(sizeof(int*));
  
  rs[0] = malloc(sizeof(int)*4);
  rs[1] = malloc(sizeof(int)*4);
  
  rs = pathSum(t1, 22, returnSize, returnColumnSizes);
  printf("=============================\n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 4; j++){
      printf("%d ",rs[i][j]);
    }
    printf("\n");
  }



  
  return 0;
}