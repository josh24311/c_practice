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
int max(int a, int b){
  if(a >= b) return a;
  else return b;
}
int min3(int a, int b, int c){
  int m = a;
  if(b < m){
    m = b;
  }
  if(c < m){
    m = c;
  }
  return m;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
  if(matrixSize == 0) return 0;
  int** msBottomRight = malloc(sizeof(int*)*(matrixSize+1));
  for(int row = 0; row <= matrixSize; row++){
    msBottomRight[row] = calloc(matrixColSize[0]+1, sizeof(int));
  }
  int answer = 0;
  for(int rows = 1; rows <= matrixSize; rows++){
    for(int cols = 1; cols <= matrixColSize[0]; cols++){
      if(matrix[rows-1][cols-1] == '1'){
        msBottomRight[rows][cols] = 
          min3(
            msBottomRight[rows-1][cols],
            msBottomRight[rows][cols-1],
            msBottomRight[rows-1][cols-1]) + 1;
      }
      answer = max(answer, msBottomRight[rows][cols]);
    }
  }

  for(int row = 0; row < matrixSize; row++){
    free(msBottomRight[row]);
  }
  free(msBottomRight);
  return answer*answer;
  
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