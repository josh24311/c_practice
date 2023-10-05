/*
swap half digits of unsigned long 
ex: 12345678 -> 56781234
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
unsigned long swapHalf(unsigned long a){//12345678
  unsigned long h,l;
  int tbit = 0;
  unsigned long tmp = a;
  while(tmp > 0){
    tmp/=10;
    tbit++;
  }
  tbit/=2;
  int exp = 1;
  while(tbit > 0){
    exp*=10;
    tbit--;
  }
  
  printf("exp = %d\n",exp);
  unsigned long upper = a / (unsigned long)exp;
  unsigned long lower = a % (unsigned long)exp;
  printf("upper = %lu\n",upper);
  printf("lower = %lu\n",lower);
  
  return lower*(unsigned long)exp + upper;
}
/***************************************************************************/
int main() {
  unsigned long a = 1123456788;
  printf("\n\n%lu",swapHalf(a));


  
  return 0;
}