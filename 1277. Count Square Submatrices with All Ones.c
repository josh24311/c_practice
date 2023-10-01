/*
1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

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
/*******************************************************************************/
/*
//以座標(bottom,right)為右下角可生成的正方形，其最大邊長為何?
int maxSquare(int** matrix, int bottom, int right){
  
  //? ? ?
  //? C A
  //? B D
  //if(D == 1 && maxSquare(A) == 2 && maxSquare(B) == 2 && maxSquare(C) == 2)
  //  -> maxSquare(D) = 3
  //so , maxSquare(D) = min3(maxSquare(A),maxSquare(B),maxSquare(C))+1
  
  
  if(bottom==0 || right == 0)return matrix[bottom][right];
  if(matrix[bottom][right] == 0)return 0;
  return min3(maxSquare(matrix, bottom-1, right),maxSquare(matrix, bottom, right-1),maxSquare(matrix, bottom-1, right-1))+1;
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
  int rows = matrixSize;
  int cols = matrixColSize[0];
  int side,res = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      int size = maxSquare(matrix, i, j);
      res+=size;
    }
  }
  return res;
}
*/

// use cache
int countSquares(int** matrix, int matrixSize, int* matrixColSize){
  int rows = matrixSize;
  int cols = matrixColSize[0];
  int res = 0;
  int cache[rows][cols] ;
  // cache[i][j] : 以 座標 (i,j)為右下角，可生成之正方形其最大邊長值
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      int size  = 0;
      if(i == 0 || j == 0){
        size = matrix[i][j];
      }
      else if (matrix[i][j] == 0){
        size = 0;
      }
      else{
        size = min3(cache[i][j-1],cache[i-1][j],cache[i-1][j-1])+1;
      }
      cache[i][j] = size;
      res += size;
    }
  }
  return res;
}
/****************************************************************************************/
int main() {
  int** m1 = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    m1[i] = malloc(sizeof(int)*4);
  }
  m1[0][0] = 0;
  m1[0][1] = 1;
  m1[0][2] = 1;
  m1[0][3] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m1[1][2] = 1;
  m1[1][3] = 1;
  m1[2][0] = 0;
  m1[2][1] = 1;
  m1[2][2] = 1;
  m1[2][3] = 1;
  int a = 4;
  int* p = &a;
  printf("ans1 = %d\n",countSquares(m1, 3, p));
  int** m2 = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    m2[i] = malloc(sizeof(int)*3);
  }
  m2[0][0] = 1;
  m2[0][1] = 0;
  m2[0][2] = 1;
  m2[1][0] = 1;
  m2[1][1] = 1;
  m2[1][2] = 0;
  m2[2][0] = 1;
  m2[2][1] = 1;
  m2[2][2] = 0;
  a = 3;
  p = &a;
  printf("ans2 = %d\n",countSquares(m2, 3, p));

  return 0;
}