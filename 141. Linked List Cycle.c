/*
141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/****************************************************************************************/
bool hasCycle(struct ListNode *head) {
  // a => b => c => d => b
  // 3    2    0    -4   2 
  //           ^           
  //                 ^
  
  struct ListNode* fast = malloc(sizeof(struct ListNode));
  struct ListNode* slow = malloc(sizeof(struct ListNode));
  fast = head;
  slow = head;
  while(fast!= NULL ){// fast 指針先到盡頭
    if(fast->next == NULL) return false;//fast->next 指針先到盡頭
    
    slow = slow->next;
    fast = fast->next->next; // 需要有84行，否則此行 NULL->next 無意義
    if(slow == fast)return true;
  }
  return false;
}
  



/****************************************************************************************/
int main() {
  
  struct ListNode* a = malloc(sizeof(struct ListNode));
  a->val = 3;
  struct ListNode* b = malloc(sizeof(struct ListNode));
  b->val = 2;
  struct ListNode* c = malloc(sizeof(struct ListNode));
  c->val = 0;
  struct ListNode* d = malloc(sizeof(struct ListNode));
  d->val = -4;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = b;
  printf("Has cycle ? %s\n",hasCycle(a)?"True":"False");
  struct ListNode* e = malloc(sizeof(struct ListNode));
  e->val = 1;
  struct ListNode* f = malloc(sizeof(struct ListNode));
  f->val = 2;
  e->next = f;
  f->next = e;
  printf("Has cycle ? %s\n",hasCycle(e)?"True":"False");
  struct ListNode* g = malloc(sizeof(struct ListNode));
  g->val = 1;
  printf("Has cycle ? %s\n",hasCycle(g)?"True":"False");
  
  return 0;
}