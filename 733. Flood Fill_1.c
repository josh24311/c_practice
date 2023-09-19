/*
733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n
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
int** floodFill(int** image, 
                int imageSize, 
                int* imageColSize,
                int sr,
                int sc,
                int color,
                int* returnSize,
                int** returnColumnSizes){
  // [[1,1,1],
  //  [1,1,0],
  //  [1,0,1]]
  // sr = 1, sc = 1 , newColor = 2 : sr,sc 處填上 newColor顏色
  
  const int nRows = imageSize;
  const int nCols = imageColSize[0];
  int** result = malloc(sizeof(int*)*nRows);
  for(int i = 0; i < nRows; i++){
    result[i] = malloc(sizeof(int)*nCols);
  }
  for(int i = 0 ; i < nRows; i++){
    for(int j = 0; j < nCols; j++){
      result[i][j] = image[i][j];
    }
  }
  int targetColor = result[sr][sc];
  bool isDirty = true;
  result[sr][sc] = -1;
  while(isDirty){
    isDirty = false;
    for(int row = 0; row < nRows; row++){
      for(int col = 0; col < nCols; col++){
        if(result[row][col] == -1){
          if(row-1 >= 0){
            if(result[row-1][col] == targetColor){
              result[row-1][col] = -1;
              isDirty = true;  
            }
          }
          if(row+1 < nRows){
            if(result[row+1][col] == targetColor){
              result[row+1][col] = -1;
              isDirty = true;  
            }
          }
          if(col-1 >= 0){
            if(result[row][col-1] == targetColor){
              result[row][col-1] = -1;
              isDirty = true;  
            }
          }
          if(col+1 < nCols){
            if(result[row][col+1] == targetColor){
              result[row][col+1] = -1;
              isDirty = true;  
            }
          }
        }    
      }
    }
  }
  for(int row = 0; row < nRows; row++){
    for(int col = 0; col < nCols; col++){
      if(result[row][col] == -1){
        result[row][col] = color;
      }
    }
  }
  
  (*returnSize) = imageSize;
  *returnColumnSizes = malloc(sizeof(int)*nRows);
  for(int i = 0; i < nRows; i++){
    (*returnColumnSizes)[i] = nCols;
  }
  return result;
}

/****************************************************************************************/
int main() {
  int** im = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    im[i] = malloc(sizeof(int)*3);
  }
  im[0][0] = 1;
  im[0][1] = 1;
  im[0][2] = 1;
  im[1][0] = 1;
  im[1][1] = 1;
  im[1][2] = 0;
  im[2][0] = 1;
  im[2][1] = 0;
  im[2][2] = 1;

  int* imageColSize = malloc(sizeof(int)*3);
  imageColSize[0] = 3;
  imageColSize[1] = 3;
  imageColSize[2] = 3;
  int a = 3;
  int* returnSize = &a;
  int** returnColumnSizes;
  im = floodFill(im, 3, imageColSize, 1, 1, 2, returnSize, returnColumnSizes);

  return 0;
}