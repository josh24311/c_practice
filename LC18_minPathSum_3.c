/*
LC18_Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
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

void drawGrid(int** grid,int NUMBER_OF_ROWS,int NUMBER_OF_COLUMNS){
  for(int i = 0; i < NUMBER_OF_ROWS; i++){
    for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
      printf("%d",grid[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
}


int minPathSum(int** grid, int gridSize, int* gridColSize){
  //順向DP，得知前一個cache後，後面的cache就可以利用到
  /*
  1 3 1
  1 5 1
  4 2 1
  ---------
  1 2 3
  4 5 6
  */
  int M = gridSize;
  int N = gridColSize[0];
  
  int **cache = malloc(sizeof(int*)*M);
  for(int i = 0 ; i < M; i++){
    cache[i] = calloc(N,sizeof(int));
  }
  for(int row = 0; row < M ; row++){
    for(int col = 0; col < N; col++){
      if(row == 0 && col == 0){
        cache[row][col] = grid[0][0];
        continue;
      }

      int min = INT_MAX;
      if(row >= 1){
        int upMin = cache[row-1][col];
        if(upMin < min){
          min = upMin;
        }
      }

      if(col >= 1){
        int leftMin = cache[row][col-1];
        if(leftMin < min){
          min = leftMin;
        }
      }      
      cache[row][col] = min + grid[row][col];  
    }
  }
  

  int result = cache[M-1][N-1];
  for(int i = 0 ; i < M; i++){
    free(cache[i]);
  }
  free(cache);
  return result;
}

int main() {
  int** gd1 = malloc(sizeof(int*)*3);
  gd1[0] = malloc(sizeof(int)*3);
  gd1[1] = malloc(sizeof(int)*3);
  gd1[2] = malloc(sizeof(int)*3);
  gd1[0][0] = 1;
  gd1[0][1] = 3;
  gd1[0][2] = 1;
  gd1[1][0] = 1;
  gd1[1][1] = 5;
  gd1[1][2] = 1;
  gd1[2][0] = 4;
  gd1[2][1] = 2;
  gd1[2][2] = 1;
  

  int** gd2 = malloc(sizeof(int*)*2);
  gd2[0] = malloc(sizeof(int)*3);
  gd2[1] = malloc(sizeof(int)*3);
  
  gd2[0][0] = 1;
  gd2[0][1] = 2;
  gd2[0][2] = 3;
  gd2[1][0] = 4;
  gd2[1][1] = 5;
  gd2[1][2] = 6;
    

  int colsize1[3] = {3,3,3};
  int colsize2[2] = {3,3};
  drawGrid(gd1,3,3);
  drawGrid(gd2,2,3);
  printf("min path sum in grid1 : %d\n\n",minPathSum(gd1,3,colsize1));
  
  printf("min path sum in grid2 : %d\n\n",minPathSum(gd2,2,colsize2));

  free(gd1[0]);
  free(gd1[1]);
  free(gd1[2]);
  free(gd1);
 
  free(gd2[0]);
  free(gd2[1]);
  free(gd2);
  return 0;
}