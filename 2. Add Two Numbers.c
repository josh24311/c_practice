/*
#linkedList
#notice line 94  curr->next = NULL
#
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //struct ListNode head  = { .next = NULL }, *curr = &head;
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *curr = head;
  
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry) {
        int num1 = 0, num2 = 0;
        if(l1) {
            num1 = l1->val;
            l1 = l1->next;
        }
        if(l2) {
            num2 = l2->val;
            l2 = l2->next;
        }
        int answer = num1 + num2 + carry;//if l1,l2 == NULL , carry != 0, ans = 0 + 0 +1
        carry = answer > 9;//num1 and num2 are one digit.
        curr = curr->next = malloc(sizeof(struct ListNode));
        curr->val = answer % 10;
        curr->next = NULL;// curr next 指定為NULL
    }
    return head->next;
}
/***************************************************************************/
int main() {
  struct ListNode* ans = malloc(sizeof(struct ListNode));
  struct ListNode* a = malloc(sizeof(struct ListNode));
  struct ListNode* b = malloc(sizeof(struct ListNode));
  struct ListNode* c = malloc(sizeof(struct ListNode));
  struct ListNode* d = malloc(sizeof(struct ListNode));
  struct ListNode* e = malloc(sizeof(struct ListNode));
  struct ListNode* f = malloc(sizeof(struct ListNode));
  a->val = 2;
  b->val = 4;
  c->val = 3;
  d->val = 5;
  e->val = 6;
  f->val = 4;
  a->next = b;
  b->next = c;
  d->next = e;
  e->next = f;
  ans = addTwoNumbers(a, d);
  while(ans!=NULL){
    printf("%d",ans->val);
    ans = ans->next;
  }
  printf("\n");
  
  struct ListNode* g = malloc(sizeof(struct ListNode));
  struct ListNode* h = malloc(sizeof(struct ListNode));
  g->val = 0;
  h->val = 0;
  ans = addTwoNumbers(g, h);
  while(ans){
    printf("%d",ans->val);
    ans = ans->next;
  }
  printf("\n");
  struct ListNode* i = malloc(sizeof(struct ListNode));
  struct ListNode* j = malloc(sizeof(struct ListNode));
  struct ListNode* k = malloc(sizeof(struct ListNode));
  struct ListNode* l = malloc(sizeof(struct ListNode));
  
  struct ListNode* m = malloc(sizeof(struct ListNode));
  struct ListNode* n = malloc(sizeof(struct ListNode));
  struct ListNode* o = malloc(sizeof(struct ListNode));
  struct ListNode* p = malloc(sizeof(struct ListNode));
  struct ListNode* q = malloc(sizeof(struct ListNode));
  struct ListNode* r = malloc(sizeof(struct ListNode));
  struct ListNode* s = malloc(sizeof(struct ListNode));

  i->val = 9;
  j->val = 9;
  k->val = 9;
  l->val = 9;
  
  m->val = 9;
  n->val = 9;
  o->val = 9;
  p->val = 9;
  q->val = 9;
  r->val = 9;
  s->val = 9;
  i->next = j;
  j->next = k;
  k->next = l;
  m->next = n;
  n->next = o;
  o->next = p;
  p->next = q;
  q->next = r;
  r->next = s;
  ans = addTwoNumbers(i, m);
  while(ans){
    printf("%d",ans->val);
    ans = ans->next;
  }
  printf("\n");
  
  return 0;
}