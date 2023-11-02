/*
#calculate
#recursive
326. Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


Constraints:

-2^31 <= n <= 2^31 - 1


Follow up: Could you solve it without loops/recursion?
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
/* 1 3 9 27 */
bool isPowerOfThree(int n){
  if(n <= 0)return false;
  //method 1 : recursive T:O(logn) , S:O(1)
  /*
  if(n == 1){
    return true;
  }
  else{
    if(n % 3 == 0){
      n /= 3;
      return isPowerOfThree(n);
    }
    else{
      return false;
    }
  }
  return false;
  */
  //method 2 , calculate log T:O(1), S:O(1)
  double logResult = log10(n) / log10(3); // means log3(n) , check if logResult is an integer
  return fabs(round(logResult) - logResult) < 1e-10;
}

/***************************************************************/

int main() {
  printf("%s\n",isPowerOfThree(27)?"True":"False");
  printf("%s\n",isPowerOfThree(0)?"True":"False");
  printf("%s\n",isPowerOfThree(-1)?"True":"False");
  
  return 0;
}