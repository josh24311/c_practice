/*
402. Remove K Digits
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
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
bool isEmpty(int top){
  if(top == -1)return true;
  else return false;
}
bool isfull(int top){
   if(top == MAXSIZE)return true;
   else return false;
}
int peekInt(int* stack, int top){
  return stack[top];
}
char peekChar(char* stack, int top){
  return stack[top];
}
int popInt(int* stack, int* top){
  int data;
  if(!isEmpty(*top)){
    data = stack[*top];
    (*top)--;
    return data;
  }
  else{
    printf("There is nothing to POP in the stack\n");
  }
}
int popChar(char* stack, int* top){
  char data;
  if(!isEmpty(*top)){
    data = stack[*top];
    (*top)--;
    return data;
  }
  else{
    printf("There is nothing to POP in the stack\n");
  }
}
void pushInt(int* stack, int* top, int data){
  (*top)++;
  stack[*top] = data;

}
void pushChar(char* stack, int* top, char data){
  (*top)++;
  stack[*top] = data;
}
/****************************************************************************************/

char * removeKdigits(char* num, int k){
  if(strlen(num) == k)return "0";

  int j = 0;
  int len = strlen(num);
  for(int i = 0; i <= len; i++){
    while(k > 0 && j >0 && num[i] < num[j-1]){
      j--;
      k--;
    }
    num[j] = num[i];
    j++;
  }
  int i = 0;
  while(num[i] == '0'){
    i++;
  }
  if(i == strlen(num)){
    return "0";
  }

  int re = strlen(num);
  for(j =0; j <= re-i; j++){
    num[j] = num[j+i];
  }
  return num;
}

/****************************************************************************************/
int main() {
  //"1432219";
  char* s1 = malloc(sizeof(char)*8);
  s1[0] = 1;
  s1[1] = 4;
  s1[2] = 3;
  s1[3] = 2;
  s1[4] = 2;
  s1[5] = 1;
  s1[6] = 9;

  
  int k = 3;
  char* result1 = removeKdigits(s1, k);
  printf("result1: ");
  for(int i = 0; result1[i] != '\0'; i++){
    printf("%c",result1[i]);
  }
  printf("\n");
  
  return 0;
}