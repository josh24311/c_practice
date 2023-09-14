/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
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
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
  int **ans = NULL;
  *returnSize = 0;

  ans = realloc(ans, sizeof(int*)*(numRows));
  (*returnColumnSizes) = (int*)malloc(sizeof(int)*(numRows));
  for(int i = 0; i < numRows; i++){
    ans[i] = malloc(sizeof(int)*(i+1));
    ans[i][0] = 1;
    ans[i][i] = 1;
    for(int j = 1; j < i; j++){
      ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
    }
    (*returnSize)++; 
    // returnColumnSizes
    (*returnColumnSizes)[i] = i+1;
  }

  return ans;
}
/****************************************************************************************/
int main() {

  int input;
  int returnSize;
  int p = 0;
  int *pp = &p;  
  int** returnColumnSizes = &pp;

  
  input = 5;
  int** ans2 = generate(input, &returnSize, returnColumnSizes);
  printf("ans \n");
  printf("{");
  for (int i = 0; i < (returnSize); i++) {
    printf("[");
      for (int j = 0; j < (*returnColumnSizes)[i]; j++){
        printf("%d ", ans2[i][j]);     
      }
    printf("]");
  }
  printf("}");
  printf("\n");
  
  return 0;
}