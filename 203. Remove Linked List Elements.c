/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
struct ListNode* removeElements(struct ListNode* head, int val){
  /*
  1 2 6 3 4 5 6 -> 6
  1 2 3 4 5
  */
  if(head==NULL)return head;
  struct ListNode* preNode = malloc(sizeof(struct ListNode));
  struct ListNode* curr = malloc(sizeof(struct ListNode));
  preNode->next = head;
  curr = preNode;
  while(curr->next!=NULL){
    if(curr->next->val == val){
      curr->next = curr->next->next;
    }
    else{
      curr = curr->next; 
    }
  }
  return preNode->next;
}


/****************************************************************************************/
int main() {
  struct ListNode* a = malloc(sizeof(struct ListNode));
  struct ListNode* b = malloc(sizeof(struct ListNode));
  struct ListNode* c = malloc(sizeof(struct ListNode));
  struct ListNode* d = malloc(sizeof(struct ListNode));
  struct ListNode* e = malloc(sizeof(struct ListNode));
  struct ListNode* f = malloc(sizeof(struct ListNode));
  struct ListNode* g = malloc(sizeof(struct ListNode));
  struct ListNode* ans1 = malloc(sizeof(struct ListNode));
  a->val = 1;
  b->val = 2;
  c->val = 6;
  d->val = 3;
  e->val = 4;
  f->val = 5;
  g->val = 6;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  ans1 = removeElements(a, 6);
  for(int i = 0; i < 5; i++){
    printf("%d ",ans1->val);
    ans1 = ans1->next;
  }
  printf("\n");
  struct ListNode* h = malloc(sizeof(struct ListNode));
  struct ListNode* i = malloc(sizeof(struct ListNode));
  struct ListNode* j = malloc(sizeof(struct ListNode));
  struct ListNode* k = malloc(sizeof(struct ListNode));
  h->val = 7;
  i->val = 7;
  j->val = 7;
  k->val = 7;
  h->next = i;
  i->next = j;
  j->next = k;
  ans1 = removeElements(h, 7);
 
  printf("%d ",ans1->val);
    



  
  return 0;
}