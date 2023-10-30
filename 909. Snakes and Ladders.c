/*
#graph BFS
909. Snakes and Ladders
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.



Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1


Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n^2].
The squares labeled 1 and n^2 do not have any ladders or snakes.
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
//define queue
#define MAX_N 30

// 定义队列数据结构
typedef struct {
    int data[MAX_N * MAX_N];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int val) {
    q->data[q->rear] = val;
    q->rear++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front++;
    return val;
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

/***************************************************************/
int snakesAndLadders(int** board, int boardSize, int* boardColSize){
/*
    c 0  1  2  3  4  5
r
0    -1 -1 -1 -1 -1 -1 
1    -1 -1 -1 -1 -1 -1 
2    -1 -1 -1 -1 -1 -1 
3    -1 35 -1 -1 13 -1 
4    -1 -1 -1 -1 -1 -1 
5    -1 15 -1 -1 -1 -1 


index of num : (row, col)   num = 9, row =4, col = 3
  (row) : 
    n - (num-1)/n - 1
  (col) = 
    if(n-row)%2 == 0{ <--
      col = n - (num-1)%n - 1
    }
    else{ -->
      col = (num-1)%n
    }
    
*/
  int n = boardSize;
  int target = n * n;


  // 初始化队列
  Queue q;
  initQueue(&q);

  // 初始状态，位置为1，步数为0
  enqueue(&q, 1);
  int steps = 0;
  int visited[target + 1];
  for (int i = 0; i <= target; i++) {
      visited[i] = 0;
  }

  while (!isQueueEmpty(&q)) {
      int size = q.rear - q.front;
      for (int i = 0; i < size; i++) {
          int position = dequeue(&q);
          if (position == target) {
              return steps;
          }
          for (int dice = 1; dice <= 6; dice++) {
              int next_position = position + dice;
              if (next_position <= target) {
                int x = n - (next_position-1)/n - 1;
                int y = ((n-x)%2 == 0)? n - (next_position-1)%n - 1 : (next_position-1)%n;
                next_position = board[x][y] == -1 ? next_position : board[x][y];
                  // 如果有梯子或蛇，移动到对应的位置
                  //next_position = (flat_board[next_position - 1] != -1) ? flat_board[next_position - 1] : next_position;
                  if (!visited[next_position]) {
                      enqueue(&q, next_position);
                      visited[next_position] = 1;
                  }
              }
          }
      }
      steps++;
  }

  return -1; // 如果无法到达目标位置，返回-1
  
}
/***************************************************************/

int main() {
  int** arr = malloc(sizeof(int*)*6);
  for(int i = 0; i < 6; i++){
    arr[i] = malloc(sizeof(int)*6);
  }
  arr[0][0] = -1;
  arr[0][1] = -1;
  arr[0][2] = -1;
  arr[0][3] = -1;
  arr[0][4] = -1;
  arr[0][5] = -1;
  arr[1][0] = -1;
  arr[1][1] = -1;
  arr[1][2] = -1;
  arr[1][3] = -1;
  arr[1][4] = -1;
  arr[1][5] = -1;
  arr[2][0] = -1;
  arr[2][1] = -1;
  arr[2][2] = -1;
  arr[2][3] = -1;
  arr[2][4] = -1;
  arr[2][5] = -1;
  arr[3][0] = -1;
  arr[3][1] = 35;
  arr[3][2] = -1;
  arr[3][3] = -1;
  arr[3][4] = 13;
  arr[3][5] = -1;
  arr[4][0] = -1;
  arr[4][1] = -1;
  arr[4][2] = -1;
  arr[4][3] = -1;
  arr[4][4] = -1;
  arr[4][5] = -1;
  arr[5][0] = -1;
  arr[5][1] = 15;
  arr[5][2] = -1;
  arr[5][3] = -1;
  arr[5][4] = -1;
  arr[5][5] = -1;
  int size = 6;
  int* p = &size;
  printf("ans %d\n",snakesAndLadders(arr, 6, p));

  int** arr2 = malloc(sizeof(int*)*2);
  for(int i = 0; i < 2; i++){
    arr[i] = malloc(sizeof(int)*2);
  }
  arr2[0][0] = -1;
  arr2[0][1] = -1;
  arr2[0][2] = -1;
  arr2[0][3] = 3;
  size = 2;
  p = &size;
  printf("ans %d\n",snakesAndLadders(arr2, 2, p));
  return 0;
}