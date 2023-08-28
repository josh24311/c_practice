/*
21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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

struct ListNode{
  int val;
  struct ListNode *next; 
} ;



//
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
  // L1 : 1 -> 2 -> 4
  // L2 : 1 -> 3 -> 4
  struct ListNode* head = malloc(sizeof(struct ListNode));
  struct ListNode* current = head; // 
  while(list1 && list2){
    if(list1->val < list2->val){
      current->next = list1;
      list1 = list1->next;
    }
    else{
      current->next = list2;
      list2 = list2->next;
    }
    current = current->next;
  }
  // list1 or list2 or both none, 將 current->next指向 list1/list2中 非空者
  current->next = list1?list1:list2;

  return head->next;
}

int main() {
  struct ListNode* nodeS1 =  malloc(sizeof(struct ListNode));
  nodeS1->val = 1;
  struct ListNode* na =  malloc(sizeof(struct ListNode));
  nodeS1->next = na;
  na->val = 2;
  struct ListNode* nb =  malloc(sizeof(struct ListNode));
  na->next = nb;
  nb->val = 4;

  struct ListNode* nodeS2 =  malloc(sizeof(struct ListNode));
  nodeS2->val = 1;
  struct ListNode* nc =  malloc(sizeof(struct ListNode));
  nodeS2->next = nc;
  nc->val = 3;
  struct ListNode* nd =  malloc(sizeof(struct ListNode));
  nc->next = nd;
  nd->val = 4;
  
  struct ListNode* nodeC =  mergeTwoLists(nodeS1, nodeS2);
  printf("%d %d %d %d %d %d\n",nodeC->val, nodeC->next->val, nodeC->next->next->val, nodeC->next->next->next->val, nodeC->next->next->next->next->val, nodeC->next->next->next->next->next->val);
  
  
  return 0;
}