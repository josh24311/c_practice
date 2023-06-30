/*
LC17_Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }


void drawGrid(char** grid,int NUMBER_OF_ROWS,int NUMBER_OF_COLUMNS){
  for(int i = 0; i < NUMBER_OF_ROWS; i++){
    for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
      printf("%c",grid[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
}
int numIslands(char** grid, int gridSize, int* gridColSize){
  if(gridSize == 0) return 0;
  int NUMBER_OF_ROWS = gridSize;
  int NUMBER_OF_COLUMNS = gridColSize[0];
  drawGrid(grid, NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
  int numberOfRegions = 0;
  const char WATER = '0';
  const char LAND = '1';
  const char NEW = 'X';
  /*
  11110
  11010
  11000
  00000
  --
  11000
  11000
  00100
  00011
  */
  for(int i = 0; i < NUMBER_OF_ROWS; i++){
    for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
      if(grid[i][j] == '1'){
        grid[i][j] = NEW;
        
        //drawGrid(grid, NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
        bool hasNew;
        do{
          hasNew = false;
          for(int y = 0; y < NUMBER_OF_ROWS; y++){
            for(int x = 0; x < NUMBER_OF_COLUMNS; x++){
              if(grid[y][x] == LAND){
                int upX = x;
                int upY = y-1;
                if(upY >= 0 && grid[upY][upX] == NEW){
                  grid[y][x] = NEW;
                  hasNew = true;
                }
                int downX = x;
                int downY = y+1;
                if(downY < NUMBER_OF_ROWS && grid[downY][downX] == NEW){
                  grid[y][x] = NEW;
                  hasNew = true;
                }
                int leftX = x-1;
                int leftY = y;
                if(leftX >= 0 && grid[leftY][leftX] == NEW){
                  grid[y][x] = NEW;
                  hasNew = true;
                }
                int rightX = x+1;
                int rightY = y;
                if(rightX < NUMBER_OF_COLUMNS && grid[rightY][rightX] == NEW){
                  grid[y][x] = NEW;
                  hasNew = true;
              }        
            }
          }
        }
        }while(hasNew == true);
        
        //drawGrid(grid, NUMBER_OF_ROWS, NUMBER_OF_COLUMNS);
        numberOfRegions++;
        
      }
    }
  }

  
  return numberOfRegions;
}


int main() {
  char** gd1 = malloc(sizeof(char*)*4);
  gd1[0] = malloc(sizeof(char)*5);
  gd1[1] = malloc(sizeof(char)*5);
  gd1[2] = malloc(sizeof(char)*5);
  gd1[3] = malloc(sizeof(char)*5);
  gd1[0][0] = '1';
  gd1[0][1] = '1';
  gd1[0][2] = '1';
  gd1[0][3] = '1';
  gd1[0][4] = '0';
  gd1[1][0] = '1';
  gd1[1][1] = '1';
  gd1[1][2] = '0';
  gd1[1][3] = '1';
  gd1[1][4] = '0';
  gd1[2][0] = '1';
  gd1[2][1] = '1';
  gd1[2][2] = '0';
  gd1[2][3] = '0';
  gd1[2][4] = '0';
  gd1[3][0] = '0';
  gd1[3][1] = '0';
  gd1[3][2] = '0';
  gd1[3][3] = '0';
  gd1[3][4] = '0';

  char** gd2 = malloc(sizeof(char*)*4);
  gd2[0] = malloc(sizeof(char)*5);
  gd2[1] = malloc(sizeof(char)*5);
  gd2[2] = malloc(sizeof(char)*5);
  gd2[3] = malloc(sizeof(char)*5);
  gd2[0][0] = '1';
  gd2[0][1] = '1';
  gd2[0][2] = '0';
  gd2[0][3] = '0';
  gd2[0][4] = '0';
  gd2[1][0] = '1';
  gd2[1][1] = '1';
  gd2[1][2] = '0';
  gd2[1][3] = '0';
  gd2[1][4] = '0';
  gd2[2][0] = '0';
  gd2[2][1] = '0';
  gd2[2][2] = '1';
  gd2[2][3] = '0';
  gd2[2][4] = '0';
  gd2[3][0] = '0';
  gd2[3][1] = '0';
  gd2[3][2] = '0';
  gd2[3][3] = '1';
  gd2[3][4] = '1';
    

  int colsize[4] = {5,5,5,5};
  printf("number of island in grid1 : %d\n\n",numIslands(gd1,4,colsize));
  
  //printf("number of island in grid2 : %d\n\n",numIslands(gd2,4,colsize));

  free(gd1[0]);
  free(gd1[1]);
  free(gd1[2]);
  free(gd1[3]);
  free(gd1);
  free(gd2[0]);
  free(gd2[1]);
  free(gd2[2]);
  free(gd2[3]);
  free(gd2);
  return 0;
}