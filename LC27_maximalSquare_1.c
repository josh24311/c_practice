/*
LC26_Longest Common Subsequence

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
 Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0
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
bool noZero(char** matrix, int row, int col, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(matrix[row+i][col+j] == '0') return false;
      // 若矩陣中有任何一個0，則false
    }
  }
  return true;
}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
  // 1 0 1 0 0
  // 1 0 1 1 1
  // 1 1 1 1 1
  // 1 0 0 1 0
  // Method 1 暴力解
  if(matrixSize == 0) return 0;
  int rows = matrixSize;
  int cols = matrixColSize[0];

  int maxSize = 0;
  for(int row = 0; row < rows; row++){
    // 決定起始點(row,col)
    for(int col = 0; col < cols; col++){
      // 矩陣邊長size -> 取決於長、寬 二者較小者
      for(int size = 1; size <= min(rows-row, cols-col); size++){
        // 判斷矩陣內是否都為1大小及其大小size
        if(noZero(matrix, row, col, size) && size > maxSize){
          // if以(row,col) 為起點 邊長為size的矩陣內,全部為1
          maxSize = size;
        }
      }
    }
  }
  return maxSize*maxSize;
}


int main() {
  char** a = malloc(sizeof(char*)*4);
  for(int i = 0; i < 4; i++){
    a[i] = malloc(sizeof(char)*5);
  }
  a[0][0] = '1';
  a[0][1] = '0';
  a[0][2] = '1';
  a[0][3] = '0';
  a[0][4] = '0';
  a[1][0] = '1';
  a[1][1] = '0';
  a[1][2] = '1';
  a[1][3] = '1';
  a[1][4] = '1';
  a[2][0] = '1';
  a[2][1] = '1';
  a[2][2] = '1';
  a[2][3] = '1';
  a[2][4] = '1';
  a[3][0] = '1';
  a[3][1] = '0';
  a[3][2] = '0';
  a[3][3] = '1';
  a[3][4] = '0';

  char** b = malloc(sizeof(char*)*2);
  for(int i = 0; i < 2; i++){
    b[i] = malloc(sizeof(char)*2);
  }
  b[0][0] = '0';
  b[0][1] = '1';
  b[1][0] = '1';
  b[1][1] = '0';

  char** c = malloc(sizeof(char*)*1);
  for(int i = 0; i < 1; i++){
    c[i] = malloc(sizeof(char)*1);
  }
  c[0][0] = '0';
  int ca[4] = {5,5,5,5};
  int cb[2] = {2};
  int cc[1] = {1};
  
  printf("answer 1 is %d\n",maximalSquare(a,4,ca));
  printf("answer 2 is %d\n",maximalSquare(b,2,cb));
  printf("answer 3 is %d\n",maximalSquare(c,1,cc));
  

  
  for(int i = 0; i < 4; i++){
    free(a[i]);
  }
  free(a);
  
  for(int i = 0; i < 2; i++){
    free(b[i]);
  }
  free(b);
  for(int i = 0; i < 1; i++){
    free(c[i]);
  }
  free(c);
  
  
  return 0;
}