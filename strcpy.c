/*
1.8  寫出一個字串拷貝程式： void StrCpy(char* dst , char* src) ;
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
/***************************************************************************/
void StrCpy(char* dst , char* src){
  /*
  int i = 0;
  while(src[i] != '\0'){
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  */
  while(*src){
    *dst++ = *src++;
  }
  *dst = '\0';
}
/***************************************************************************/
int main() {
  
  char *b = "hello you";
  int len = strlen(b);
  char *a = malloc(sizeof(char)*(len));
  StrCpy(a, b);
  printf("a = %s\n",a);
  printf("b = %s\n",b);
  
  return 0;
}