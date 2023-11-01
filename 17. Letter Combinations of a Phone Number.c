/*
#DFS
#recursive
#important
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
2 : a b c
3 : d e f 
4 : g h i
5 : j k l 
6 : m n o
7 : p q r s
8 : t u v
9 : w x y z

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
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
char* phoneMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void backtrack(char* digits, int index, char* combination, char** result, int* returnSize){
  if(index == strlen(digits)){
    // 如果當前組合已經包含了所有數字，將其添加到結果中
    //printf("index full \n\n");
    result[*returnSize] = strdup(combination);
    (*returnSize)++;
    return;
  }
  char* letters = phoneMap[digits[index] - '0'];// digits = "23"
  for(int i = 0; i < strlen(letters); i++){
    //printf("i = %d, index = %d, ",i,index);
    combination[index] = letters[i];// combination[0] = 'a' , combination[1] = 'd'/'e'/'f'
    //printf("combination[%d] = %c\n",index,combination[index]);
    backtrack(digits, index+1, combination, result, returnSize);
  }
}
char ** letterCombinations(char * digits, int* returnSize){
/*
  2 : a b c
  3 : d e f 
  4 : g h i
  5 : j k l 
  6 : m n o
  7 : p q r s
  8 : t u v
  9 : w x y z
*/
  if(digits == NULL || strlen(digits) == 0){
    *returnSize = 0;
    return NULL;
  }
  int totalCombinations = 1;
  for(int i = 0; i < strlen(digits); i++){
    totalCombinations *= strlen(phoneMap[digits[i] - '0']);
  }
  char** result = (char**)malloc(sizeof(char*) * totalCombinations);
  for(int i = 0; i < totalCombinations; i++){
    result[i] = (char*)malloc(sizeof(char)* (strlen(digits) + 1));
    result[i][strlen(digits)] = '\0';
  }

  *returnSize = 0;
  char combination[strlen(digits) + 1];
  combination[strlen(digits)] = '\0';
  backtrack(digits, 0, combination, result, returnSize);
  return result;
}
/***************************************************************/

int main() {
  char* digits1 = "23";
  char* digits2 = "";
  char* digits3 = "2";
  int rets = 0;
  char** ans1 = letterCombinations(digits1, &rets);
  for(int i = 0; i < rets; i++){
    printf("%s\n", ans1[i]);
  }
  
  
  return 0;
}