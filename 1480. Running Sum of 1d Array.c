/*
#array
1480. Running Sum of 1d Array
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.



Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]


Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
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
int* runningSum(int* nums, int numsSize, int* returnSize){
  if(nums == NULL || numsSize == 0)return NULL;
  int* result = malloc(sizeof(int)*numsSize);
  *returnSize = numsSize;
  
  for(int i = 1; i < numsSize; i++){
    
    nums[i] += nums[i-1];
  }
  return nums;
}
/***************************************************************/

int main() {
  int* arr1 = malloc(sizeof(int)*4);
  arr1[0] = 1;
  arr1[1] = 2;
  arr1[2] = 3;
  arr1[3] = 4;
  int* arr2 = malloc(sizeof(int)*5);
  arr2[0] = 1;
  arr2[1] = 1;
  arr2[2] = 1;
  arr2[3] = 1;
  arr2[4] = 1;
  int* arr3 = malloc(sizeof(int)*5);
  arr3[0] = 3;
  arr3[1] = 1;
  arr3[2] = 2;
  arr3[3] = 10;
  arr3[4] = 1;
  int size = 4;
  
  int* res1 = runningSum(arr1, 4, &size);
  for(int i = 0; i < size; i++){
    printf("res1[%d] = %d\n", i, res1[i]);
  }
  
  size = 5;
  int* res2 = runningSum(arr2, 5, &size);
  for(int i = 0; i < size; i++){
    printf("res2[%d] = %d\n", i, res2[i]);
  }
  size = 5;
  int* res3 = runningSum(arr3, 5, &size);
  for(int i = 0; i < size; i++){
    printf("res3[%d] = %d\n", i, res3[i]);
  }
  
  return 0;
}