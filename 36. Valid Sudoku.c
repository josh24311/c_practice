/*
36. Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
   int i = 0, j = 0, k = 0, temp = 0;
    bool flag[10] = { 0 };
    for(i = 0; i < 9; i++) {
        memset(flag, 0, sizeof(bool) * 10);
        for(j = 0; j < 9; j++) {
            temp = board[i][j] - '0';
            if(temp >= 0) {
                if(flag[temp])
                    return false;
                else
                    flag[temp] = true;
            }
        }
    }
    for(i = 0; i < 9; i++) {
        memset(flag, 0, sizeof(bool) * 10);
        for(j = 0; j < 9; j++) {
            temp = board[j][i] - '0';
            if(temp >= 0) {
                if(flag[temp])
                    return false;
                else
                    flag[temp] = true;
            }
        }
    }
  /*
  k = 
  0 1 2
  3 4 5
  6 7 8
  k = 7 對應board
  (6,3) (6,4) (6,5)                (0,0) (0,1) (0,2) 
  (7,3) (7,4) (7,5) ==>(i,j)       (1,0) (1,1) (1,2) 
  (8,3) (8,4) (8,5)                (2,0) (2,1) (2,2) 
  */
    for(k = 0; k < 9; k++) {
        memset(flag, 0, sizeof(bool) * 10);
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                temp = board[i + k / 3 * 3][j + k % 3 * 3] - '0';
                if(temp >= 0) {
                    if(flag[temp])
                        return false;
                    else
                        flag[temp] = true;
                }
            }
        }
    }
    return true; 
}

/****************************************************************************************/
int main() {
  char** sud = malloc(sizeof(char*)*9);
  for(int i = 0; i < 9; i++){
    sud[i] = malloc(sizeof(char)*9);
  }
  sud[0][0] = '5';
  sud[0][1] = '3';
  sud[0][2] = '.';
  sud[0][3] = '.';
  sud[0][4] = '7';
  sud[0][5] = '.';
  sud[0][6] = '.';
  sud[0][7] = '.';
  sud[0][8] = '.';
  sud[1][0] = '6';
  sud[1][1] = '.';
  sud[1][2] = '.';
  sud[1][3] = '1';
  sud[1][4] = '9';
  sud[1][5] = '5';
  sud[1][6] = '.';
  sud[1][7] = '.';
  sud[1][8] = '.';
  sud[2][0] = '.';
  sud[2][1] = '9';
  sud[2][2] = '8';
  sud[2][3] = '.';
  sud[2][4] = '.';
  sud[2][5] = '.';
  sud[2][6] = '.';
  sud[2][7] = '6';
  sud[2][8] = '.';
  sud[3][0] = '8';
  sud[3][1] = '.';
  sud[3][2] = '.';
  sud[3][3] = '.';
  sud[3][4] = '6';
  sud[3][5] = '.';
  sud[3][6] = '.';
  sud[3][7] = '.';
  sud[3][8] = '3';
  sud[4][0] = '4';
  sud[4][1] = '.';
  sud[4][2] = '.';
  sud[4][3] = '8';
  sud[4][4] = '.';
  sud[4][5] = '3';
  sud[4][6] = '.';
  sud[4][7] = '.';
  sud[4][8] = '1';
  sud[5][0] = '7';
  sud[5][1] = '.';
  sud[5][2] = '.';
  sud[5][3] = '.';
  sud[5][4] = '2';
  sud[5][5] = '.';
  sud[5][6] = '.';
  sud[5][7] = '.';
  sud[5][8] = '6';
  sud[6][0] = '.';
  sud[6][1] = '6';
  sud[6][2] = '.';
  sud[6][3] = '.';
  sud[6][4] = '.';
  sud[6][5] = '.';
  sud[6][6] = '2';
  sud[6][7] = '8';
  sud[6][8] = '.';
  sud[7][0] = '.';
  sud[7][1] = '.';
  sud[7][2] = '.';
  sud[7][3] = '4';
  sud[7][4] = '1';
  sud[7][5] = '9';
  sud[7][6] = '.';
  sud[7][7] = '.';
  sud[7][8] = '5';
  sud[8][0] = '.';
  sud[8][1] = '.';
  sud[8][2] = '.';
  sud[8][3] = '.';
  sud[8][4] = '8';
  sud[8][5] = '.';
  sud[8][6] = '.';
  sud[8][7] = '7';
  sud[8][8] = '9';
  int a = 9;
  int* boardColSize = &a;
  printf("Is valid ? %s\n",isValidSudoku(sud, 9, boardColSize)?"True":"False");

  return 0;
}