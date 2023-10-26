/*
#LC_17
#graph
#recursive
#DFS
200. Number of Islands
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
const char WATER = '0';
const char LAND = '1';
const char NEW = 'X';
const char USED = 'O';

void floodFill(char** grid, int numOfRows, int numOfCols, int i, int j){
  if(i < 0 || j < 0 || i >= numOfRows || j >= numOfCols || grid[i][j] != LAND){
    return;
  }
  grid[i][j] = NEW;// find uncheck point
  floodFill(grid, numOfRows, numOfCols, i+1, j);
  floodFill(grid, numOfRows, numOfCols, i-1, j);
  floodFill(grid, numOfRows, numOfCols, i, j+1);
  floodFill(grid, numOfRows, numOfCols, i, j-1);
  
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
  int m = gridSize;
  int n = gridColSize[0];

  int numberOfRegions = 0;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == LAND){
        floodFill(grid, m, n, i, j);
        numberOfRegions++;

        for(int y = 0; y < m ; y++){
          for(int x = 0; x < n; x++){
            if(grid[y][x] == NEW){
              grid[y][x] = USED;
            }
          }
        }
        
      }
    }
  }
  return numberOfRegions;
}
/***************************************************************/

int main() {
  char** map1 = malloc(sizeof(char*)*4);
  for(int i = 0; i < 5; i++){
    map1[i] = malloc(sizeof(char));
  }
  map1[0][0] = '1';
  map1[0][1] = '1';
  map1[0][2] = '1';
  map1[0][3] = '1';
  map1[0][4] = '0';

  map1[1][0] = '1';
  map1[1][1] = '1';
  map1[1][2] = '0';
  map1[1][3] = '1';
  map1[1][4] = '0';

  map1[2][0] = '1';
  map1[2][1] = '1';
  map1[2][2] = '0';
  map1[2][3] = '0';
  map1[2][4] = '0';

  map1[3][0] = '0';
  map1[3][1] = '0';
  map1[3][2] = '0';
  map1[3][3] = '0';
  map1[3][4] = '0';
  int a = 5;
  int* p = &a;
  printf("num of island %d \n",numIslands(map1, 4, p));
  
  return 0;
}