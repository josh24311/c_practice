/*
LC30_Check If a String Is a Valid Sequence from Root to Leaves Path


*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
Tree* createTree(int val){
  Tree* root = malloc(sizeof(Tree));
  root->val = val;
  root->left = NULL;
  root->right = NULL;
  return root;
}
void insertLeft(struct TreeNode* root, int val){
  root->left = createTree(val);
}
void insertRight(struct TreeNode* root, int val){
  root->right = createTree(val);
}





  

bool isValidSequence(struct TreeNode* root, int* arr, int arrSize){
  if(arrSize == 0 
    || root == NULL ) return false;
  
  
  int * subarr = calloc(arrSize-1, sizeof(int));
  for(int i = 0; i < arrSize-1; i++){
    subarr[i] = arr[i+1];
  }
  if(root->val == arr[0] && arrSize != 1){
    return isValidSequence(root->left, subarr, arrSize-1) || isValidSequence(root->right, subarr, arrSize-1);
    
  }
  else if (root->val == arr[0] && arrSize == 1 && root->left == NULL && root->right == NULL){
    //判斷到arr最後一個值，且該root Node已經是樹葉
    return true;
  }
  else{
    return false;
  }


  
  return false;
}
int main() {
  Tree* a = createTree(0);
  insertLeft(a, 1);
  insertRight(a, 0);
  insertLeft(a->left, 0);
  insertRight(a->left, 1);
  insertLeft(a->right, 0);
  insertRight(a->left->left, 1);
  insertLeft(a->left->right, 0);
  insertRight(a->left->right, 0);

  int* arr1 = malloc(sizeof(int)*4);
  arr1[0] = 0;
  arr1[1] = 1;
  arr1[2] = 0;
  arr1[3] = 1;
  
  int* arr2 = malloc(sizeof(int)*3);
  arr2[0] = 0;
  arr2[1] = 0;
  arr2[2] = 1;

  printf("If arr1 is valid path? %s\n", isValidSequence(a, arr1, 4) == 1?"True":"false");
  printf("If arr2 is valid path? %s\n", isValidSequence(a, arr2, 3) == 1?"True":"false");
  
  free(a);
  free(arr1);
  free(arr2);
  return 0;
}