/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Input: head = [1,1,2]
Output: [1,2]
Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
struct ListNode* deleteDuplicates(struct ListNode* head){
// 1 1 2
  /*
  The number of nodes in the list is in the range [0, 300].
  -100 <= Node.val <= 100
  */
  if(head == NULL || head->next == NULL) return head;
  struct ListNode* current = head;
  
  
  while(current && current->next){
    if(current->next->val == current->val){ // found duplicate
      current->next = current->next->next;
    }
    else{
      current = current->next;  
    }
    
  }
  return head;
}
/****************************************************************************************/
int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  
  struct ListNode * list1 = (struct ListNode * ) malloc(sizeof(struct ListNode));
  struct ListNode * list2 = (struct ListNode * ) malloc(sizeof(struct ListNode));
  struct ListNode * list3 = (struct ListNode * ) malloc(sizeof(struct ListNode));
  struct ListNode * list4 = (struct ListNode * ) malloc(sizeof(struct ListNode));
  struct ListNode * list5 = (struct ListNode * ) malloc(sizeof(struct ListNode));
  list1 -> val = 1;
  list1 -> next = list2;
  list2 -> val = 1;
  list2 -> next = list3;
  list3 -> val = 2;
  list3 -> next = list4;
  list4 -> val = 3;
  list4 -> next = list5;
  list5 -> val = 3;
  list5 -> next = NULL;
  struct ListNode * head = deleteDuplicates(list1);
  while (head != NULL) {
    printf("%d->", head ->val);
    head = head -> next;
  }
  
  
  
  return 0;
}