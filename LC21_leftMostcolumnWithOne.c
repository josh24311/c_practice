/*
LC21_Leftmost Column with at Least a One
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn’t exist, return -1.

You can’t access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you’re given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

Constraints:

1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a<b) return a;
  else return b;
}
struct BinaryMatrix{
  int(*get)(struct BinaryMatrix*,int, int);
  int*(*dimensions)(struct BinaryMatrix*);
};

int leftMostcolumnWithOne(struct BinaryMatrix* matrix){
  // 找索引[3,4]的方式
  // matrix->get(matrix,3,4);
  // 未實做struct 所以理解演算法就好
  int n = matrix->dimensions(matrix)[0];
  int m = matrix->dimensions(matrix)[1];
  int leftMostCol = m;
  for(int row = 0; row < n; row++){
    while(matrix->get(matrix,row, leftMostCol-1) == 1){
      leftMostCol--;
      if(leftMostCol == 0){
        return 0;
      }
    }
  }
  if(leftMostCol == m) return  -1;
  return leftMostCol;
}


int main() {
  int **mat1 = malloc(sizeof(int*)*2);
  mat1[0] = malloc(sizeof(int)*2);
  mat1[1] = malloc(sizeof(int)*2);
  mat1[0][0] = 0;
  mat1[0][1] = 0;
  mat1[1][0] = 1;
  mat1[1][1] = 1;

  int **mat2 = malloc(sizeof(int*)*2);
  mat2[0] = malloc(sizeof(int)*2);
  mat2[1] = malloc(sizeof(int)*2);
  mat2[0][0] = 0;
  mat2[0][1] = 0;
  mat2[1][0] = 0;
  mat2[1][1] = 1;

  int **mat3 = malloc(sizeof(int*)*2);
  mat3[0] = malloc(sizeof(int)*2);
  mat3[1] = malloc(sizeof(int)*2);
  mat3[0][0] = 0;
  mat3[0][1] = 0;
  mat3[1][0] = 0;
  mat3[1][1] = 0;


  

  free(mat1[0]);
  free(mat1[1]);
  free(mat1);
  free(mat2[0]);
  free(mat2[1]);
  free(mat2);
  free(mat3[0]);
  free(mat3[1]);
  free(mat3);
  
  return 0;
}