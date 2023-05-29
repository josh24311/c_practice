/*
LC8_middleNode
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/
#include <stdio.h>
#include <stdbool.h>
typedef struct ListNode{
  int val;
  struct ListNode *next;
}node_t;

struct ListNode* middleNode(struct ListNode* head){
  node_t* fast = head;
  node_t* slow = head;

  while(fast != NULL && fast->next != NULL){
    //兔子一次走兩格，烏龜一次走一格
    fast = fast->next->next;
    slow = slow->next;

    
    //兔子會先走到盡頭，此時烏龜剛好走到中間
  }
  return slow;
}
int main() {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 8;
    test_list->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->val = 4;
    test_list->next->next->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->next->next->val = 5;
    test_list->next->next->next->next->next = NULL;
    node_t  * result = middleNode(test_list);
    printf("middle is %d\n",result->val);
  return 0;
}
