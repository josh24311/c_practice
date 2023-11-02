/*
#DP
#KADANE'S ALGORITHM
53. Maximum Subarray
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
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
int maxSubArray(int* nums, int numsSize){
  //[5 , 4 , -1 , 7 , 8]
  //TLE
  /*
  int result = INT_MIN;
  for(int i = 0; i < numsSize; i++){
    int sum = 0;
    for(int j = i; j < numsSize; j++){
      sum += nums[j];
      if(sum > result){
        result = sum;
      }
    }
  }
  return result;
  */
  // DP : T:O(n) , S:O(1)
  // DP : 以index i 為結尾的 maxSubarray和 定義為 
  //若 dp[i-1]為負，則 dp[i] =  nums[i]
  //若 dp[i-1]為正，則 dp[i] = dp[i-1] + nums[i]
  if(numsSize == 0)return 0;
  int curSum = nums[0];
  int maxSum = nums[0];
  for(int i = 1; i < numsSize; i++){
    curSum = (curSum < 0)? nums[i] : curSum + nums[i];
    maxSum = (curSum > maxSum )? curSum : maxSum;
  }
  return maxSum;
}

/***************************************************************/

int main() {
  
  int* arr1 = malloc(sizeof(int)*9);
  arr1[0] = -2;
  arr1[1] = 1;
  arr1[2] = -3;
  arr1[3] = 4;
  arr1[4] = -1;
  arr1[5] = 2;
  arr1[6] = 1;
  arr1[7] = -5;
  arr1[8] = 4;

  int* arr2 = malloc(sizeof(int)*2);
  arr2[0] = -1;
  arr2[1] = -2;

  int* arr3 = malloc(sizeof(int)*5);
  arr3[0] = 5;
  arr3[1] = 4;
  arr3[2] = -1;
  arr3[3] = 7;
  arr3[4] = 8;

  printf("ans1 = %d\n",maxSubArray(arr1, 9));
  printf("ans2 = %d\n",maxSubArray(arr2, 1));
  printf("ans3 = %d\n",maxSubArray(arr3, 5));
  return 0;
}