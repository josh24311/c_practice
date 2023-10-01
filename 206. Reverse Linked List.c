/*
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 
Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
// Iteration
/*
struct ListNode* reverseList(struct ListNode* head){
  //        1 2 3 4 5 
  //head    ^
  //temp      ^
  //prev  ^
  if(head == NULL) return head;
  struct ListNode* prev = NULL;
  struct ListNode* temp = NULL;
  while(head!=NULL){
    temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
  
}
*/
//recursive
struct ListNode* reverseList(struct ListNode* head){
  if(head == NULL || head->next == NULL)return head;//head->next == NULL 表示head此時為最後一個節點
  struct ListNode* newHead = NULL;
  newHead = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return newHead;//newHead為原list最後一個節點，不再變動一路回傳
  
  
}

/****************************************************************************************/
int main() {
  struct ListNode* a = malloc(sizeof(struct ListNode));
  struct ListNode* b = malloc(sizeof(struct ListNode));
  struct ListNode* c = malloc(sizeof(struct ListNode));
  struct ListNode* d = malloc(sizeof(struct ListNode));
  struct ListNode* e = malloc(sizeof(struct ListNode));
  a->val = 1;
  b->val = 2;
  c->val = 3;
  d->val = 4;
  e->val = 5;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  int i = 0;
  struct ListNode* curr = malloc(sizeof(struct ListNode));
  curr = reverseList(a);
  while(i < 5){
    printf("%d ",curr->val);
    curr = curr->next;
    i++;
  }
  
  printf("\n");
  i = 0;
  struct ListNode* f = malloc(sizeof(struct ListNode));
  struct ListNode* g = malloc(sizeof(struct ListNode));
  f->val = 1;
  g->val = 2;
  f->next = g;
  curr = reverseList(f);
  while(i < 2){
    printf("%d ",curr->val);
    curr = curr->next;
    i++;
  }
  
  return 0;
}