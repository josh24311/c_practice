/*
#explore quiz
1672. Richest Customer Wealth
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i th  customer has in the jth bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.



Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
Example 3:

Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17


Constraints:

m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100
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
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
  if(accounts == NULL || accountsSize == 0)return 0;
  int res = INT_MIN;
  for(int i = 0; i < accountsSize; i++){
    int total = 0;
    for(int j = 0; j < *accountsColSize; j++){
      total += accounts[i][j];
    }
    if(total > res){
      res = total;
    }
  }
  return res;
}
/***************************************************************/

int main() {
  int** accounts1 = (int**)malloc(sizeof(int*)*2);
  for(int i = 0; i < 2; i++){
    accounts1[i] = malloc(sizeof(int)*3);
  }
  accounts1[0][0] = 1;
  accounts1[0][1] = 2;
  accounts1[0][2] = 3;
  accounts1[1][0] = 3;
  accounts1[1][1] = 2;
  accounts1[1][1] = 1;

  int** accounts2 = (int**)malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++){
    accounts2[i] = malloc(sizeof(int)*2);
  }
  accounts2[0][0] = 1;
  accounts2[0][1] = 5;
  accounts2[1][0] = 7;
  accounts2[1][1] = 3;
  accounts2[2][0] = 3;
  accounts2[2][1] = 5;
  int size1 = 3;
  int size2 = 2;
  printf("ans1 = %d\n",maximumWealth(accounts1,2,&size1));
  printf("ans2 = %d\n",maximumWealth(accounts2,3,&size2));
  return 0;
}