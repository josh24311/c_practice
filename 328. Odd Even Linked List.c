/*
328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
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
//       1  2  3  4  5  6  7
//oddH   ^
//oddT   ^
//eveH      ^
//eveT      ^
//curr         ^
// 1 3 5 7 2 4 6
struct ListNode* oddEvenList(struct ListNode* head){
  if(head == NULL || head->next == NULL || head->next->next == NULL)return head;
  /*
  struct ListNode* oddHead = head;
  struct ListNode* oddTail = head;
  struct ListNode* evenHead = head->next;
  struct ListNode* evenTail = head->next;
  struct ListNode* curr = evenTail->next;

  while(curr!=NULL){
    oddTail->next = curr;
    evenTail->next = curr->next;
    curr->next = evenHead;

    oddTail = curr;
    evenTail = evenTail->next;
    if(evenTail == NULL)break;

    curr = evenTail->next;
  }
  return head;
  */
  struct ListNode* odd = head;
  struct ListNode* even = head->next;
  struct ListNode* evenHead = head->next;
  while(even != NULL && even->next != NULL){
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
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
  struct ListNode* cur = malloc(sizeof(struct ListNode));
  cur = oddEvenList(a);
  for(int i = 0; i < 5; i++){
    printf("%d ",cur->val);
    cur = cur->next;
  }
  struct ListNode* f = malloc(sizeof(struct ListNode));
  struct ListNode* g = malloc(sizeof(struct ListNode));
  struct ListNode* h = malloc(sizeof(struct ListNode));
  struct ListNode* i = malloc(sizeof(struct ListNode));
  struct ListNode* j = malloc(sizeof(struct ListNode));
  struct ListNode* k = malloc(sizeof(struct ListNode));
  struct ListNode* l = malloc(sizeof(struct ListNode));

  f->val = 2;
  g->val = 1;
  h->val = 3;
  i->val = 5;
  j->val = 6;
  k->val = 4;
  l->val = 7;
  f->next = g;
  g->next = h;
  h->next = i;
  i->next = j;
  j->next = k;
  k->next = l;
  cur = oddEvenList(f);
  printf("\n");
  for(int i = 0; i < 7; i++){
    printf("%d ",cur->val);
    cur = cur->next;
  }
  
  return 0;
}