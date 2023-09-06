/*
100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
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
struct ListNode{
  int val;
  struct ListNode *next; 
} ;

/****************************************************************************************/
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
  if(p == NULL && q == NULL){
    printf("Both p q are NULL\n");
    return true;
  } 
  if(p == NULL && q != NULL || p!= NULL && q == NULL || p->val != q->val){
    if(p == NULL && q !=NULL){
     printf("p NULL\n"); 
    }
    else if (p != NULL && q ==NULL){
     printf("q NULL\n"); 
    }
    else if(p->val != q->val){
     printf("p q diff val\n"); 
    }
    return false; 
  }
  bool tmpleft = true;
  bool tmpright = true;
  printf("p = %d, q = %d\n",p->val,q->val);
  //printf("p->left = %d, q->left = %d\n",p->left->val,q->left->val);

  tmpleft = isSameTree(p->left, q->left);
  tmpright = isSameTree(p->right, q->right);
  return tmpleft & tmpright;
}

/****************************************************************************************/
int main() {
  Tree* t1 = malloc(sizeof(Tree));
  t1->val = 1;
  Tree* t1a = malloc(sizeof(Tree));
  t1a->val = 2;
  t1->left = t1a;
  Tree* t1b = malloc(sizeof(Tree));
  t1b->val = 3;
  t1->right = t1b;

  Tree* t2 = malloc(sizeof(Tree));
  t2->val = 1;
  Tree* t2a = malloc(sizeof(Tree));
  t2a->val = 2;
  t2->left = t2a;
  Tree* t2b = malloc(sizeof(Tree));
  t2b->val = 3;
  t2->right = t2b;
/*****/
  Tree* t3 = malloc(sizeof(Tree));
  t3->val = 1;
  Tree* t3a = malloc(sizeof(Tree));
  t3a->val = 2;
  t3->left = t3a;
  t3->right = NULL;
  
  Tree* t4 = malloc(sizeof(Tree));
  t4->val = 1;
  t4->left = NULL;
  
  Tree* t4b = malloc(sizeof(Tree));
  t4b->val = 2;
  t2->right = t4b;
  //printf("t1,t2 :%s\n",isSameTree(t1, t2)?"true":"false");
  printf("t3,t4 :%s\n",isSameTree(t3, t4)?"true":"false");

  return 0;
}