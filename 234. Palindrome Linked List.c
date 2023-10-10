/*
#fastslowpointer
#linkedlist
#reverse linkedlist
#important
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
 Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
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
/***************************************************************/
struct ListNode* getMidList(struct ListNode* head){
  struct ListNode* dummy = malloc(sizeof(struct ListNode));
  dummy->next = head;
  struct ListNode* slow = dummy;
  struct ListNode* fast = dummy;
  /*
    f
  dummy -> head -> ... -> NULL
    s
  */
  while(fast!=NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  /*
       H              f
  d -> 1 -> 2 -> 3 -> 4 -> NULL
            s
       H                         f
  d -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
                 s
  */
  return slow;
}
struct ListNode* reverseList(struct ListNode* head){
  /*
  1.
      H
      1->2->3->N
         t
  2.
      H
 N <- 1  2->3->N  
 p       t
  3.
      H
 N <- 1  2->3->N
      p  t  
  4.     
         H
 N <- 1  2->3->N
      p  t
  */
  struct ListNode* prev = NULL;
  while(head!=NULL){
    struct ListNode* tmp = head->next;
    head->next = prev;
    prev = head;
    head = tmp;
  }
  return prev;
}
bool isPalindrome(struct ListNode* head){
  // 1 2 2 1
  // 1 2 2 3 2 2 1
  //method1 : T: O(n) , S: O(n) , n = numbers of nodes
  /*
  int arr[100000] = {-1};
  int size = 0;
  int i,j;
  struct ListNode* tmp = head;
  while(tmp!=NULL){
    arr[size++] = tmp->val;
    tmp = tmp->next;
  }
  i = 0;
  j = size-1;
  
  while(i < j){
    if(arr[i] != arr[j]){
      return false;
    }
    else{
      i++;
      j--;
    }
  }

  free(tmp);
  
  return true;
  */
  //method2 找中點+翻轉
  struct ListNode* mid = getMidList(head);
  struct ListNode* midNext = reverseList(mid->next);
  while(midNext != NULL){
    if(head->val == midNext->val){
      head = head->next;
      midNext = midNext->next;
    }
    else{
      return false;
    }
  }
  
  return true;
  
}

/***************************************************************/
int main() {
  struct ListNode* a = malloc(sizeof(struct ListNode));
  struct ListNode* b = malloc(sizeof(struct ListNode));
  struct ListNode* c = malloc(sizeof(struct ListNode));
  struct ListNode* d = malloc(sizeof(struct ListNode));
  struct ListNode* e = malloc(sizeof(struct ListNode));
  struct ListNode* f = malloc(sizeof(struct ListNode));
  struct ListNode* g = malloc(sizeof(struct ListNode));
  
  a->val = 1;
  b->val = 2;
  c->val = 2;
  d->val = 3;
  e->val = 2;
  f->val = 2;
  g->val = 1;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  printf("ans1 : %s\n",isPalindrome(a)?"True":"False");
  struct ListNode* h = malloc(sizeof(struct ListNode));
  struct ListNode* i = malloc(sizeof(struct ListNode));
  h->val = 1;
  i->val = 2;
  h->next = i;
  printf("ans2 : %s\n",isPalindrome(h)?"True":"False");
  
  return 0;
}