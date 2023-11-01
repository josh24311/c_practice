/*
#linked list mid node
#recursive
#divide and conquer
#important
#merge sort T:O(nlogn) , S:O(logn)
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5


Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
//define queue
#define MAX_N 30

// 定义队列数据结构
typedef struct {
    int data[MAX_N * MAX_N];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int val) {
    q->data[q->rear] = val;
    q->rear++;
}

int dequeue(Queue *q) {
    int val = q->data[q->front];
    q->front++;
    return val;
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

/***************************************************************/

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {//l1比較小, 則l1的後段跟l2去接
        l1->next = merge(l1->next, l2);
        return l1;
    } else {//l2比較小, 則l2的後段跟l1去接
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
struct ListNode* sortList(struct ListNode* head){
  if (!head || !head->next) {
    return head;
  }

  // 使用快慢指针找到链表中点
  struct ListNode *slow = head, *fast = head, *prev = NULL;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  /*      slow
  4   2    1   3
      prev        fast
  */

  // 分割链表成两部分
  prev->next = NULL;//斷成 4->2   1->3
  
  // 递归排序两部分
  struct ListNode* l1 = sortList(head);
  struct ListNode* l2 = sortList(slow);

  // 合并两个有序链表
  return merge(l1, l2);
  
}
/***************************************************************/

int main() {
  struct ListNode* a = malloc(sizeof(struct ListNode));
  a->val = 4;
  struct ListNode* b = malloc(sizeof(struct ListNode));
  b->val = 2;
  struct ListNode* c = malloc(sizeof(struct ListNode));
  c->val = 1;
  struct ListNode* d = malloc(sizeof(struct ListNode));
  d->val = 3;
  a->next = b;
  b->next = c;
  c->next = d;
  struct ListNode* node = sortList(a);
  
  for(;node!=NULL;node = node->next ){
    printf("%d\n", node->val);
  }
  
  return 0;
}