/*
168. Excel Sheet Column Title
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
 

Constraints:

1 <= columnNumber <= 231 - 1
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
char * convertToTitle(int columnNumber){
  char * result = (char * ) calloc(10000, sizeof(char));
  int i = 0;
  while(columnNumber > 0){
    columnNumber--;
    result[i++] =(char)(columnNumber%26+'A');
    columnNumber/=26;
  }
  result[i] = '\0';
  //reverse
  
  for(int j = 0; j < i/2; j++){
    int tmp = result[j];
    result[j] = result[i-j-1];
    result[i-j-1] = tmp;
  }
  return result;
}
/****************************************************************************************/
int main() {
  char* ans = malloc(sizeof(char)*10000);
  ans = convertToTitle(1);
  
  for(int i = 0; ans[i] != '\0'; i++){
    printf("%c",ans[i]);
  }
  printf("\n");
  ans = convertToTitle(28);
  for(int i = 0; ans[i] != '\0'; i++){
    printf("%c",ans[i]);
  }
  printf("\n");
  ans = convertToTitle(701);
  for(int i = 0; ans[i] != '\0'; i++){
    printf("%c",ans[i]);
  }
  printf("\n");

  return 0;
}