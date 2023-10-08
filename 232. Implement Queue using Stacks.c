/*
#stack
#queue
#linked list
#use linked list to construct stack, then implement queue using two stacks
232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
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
struct sNode {
    int data;
    struct sNode* next;
};
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);

void push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list of the new node */
    new_node->next = (*top_ref);
    
 
    /* move the head to point to the new node */
    (*top_ref) = new_node;
}
bool stkEmpty(struct sNode* stk){
  if(stk == NULL){
    return true;
  }
  return false;
}
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode* top;
 
    /*If stack is empty then error */
    if (stkEmpty(*top_ref)) {
        printf("This Stack is empty!\n");
        return -1;
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
int top(struct sNode** top_ref){
  int res;
  /*If stack is empty then error */
  if (stkEmpty(*top_ref)) {
    printf("This Stack is empty!\n");
    return -1;
  }else{
    res = (*top_ref)->data;//取得該stack最top元素的值
  }
  return res;
}
void printStack(struct sNode* stk){
  struct sNode *tmp = stk;
  while(tmp != NULL){
    printf("%d->",tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");
}

typedef struct {
  struct sNode* stk1;
  struct sNode* stk2;
} MyQueue;


MyQueue* myQueueCreate() {
  MyQueue* obj = malloc(sizeof(MyQueue));
  obj->stk1 = NULL;
  obj->stk2 = NULL;
  return obj;
}

void myQueuePush(MyQueue* obj, int x) {
  push(&obj->stk1, x);//傳入obj->stk1 的記憶體位置 讓push()對stack1 進行操作
}
bool myQueueEmpty(MyQueue* obj) {
  if(stkEmpty(obj->stk1) && stkEmpty(obj->stk2)){
    return true;
  }
  else{
    return false;
  }
}
int myQueuePop(MyQueue* obj) {
  int res;
  if(myQueueEmpty(obj)){
    printf("stk1 and stk2 are all NULL\n");
    return -1;
  }
  if(stkEmpty(obj->stk2)){
    while(!stkEmpty(obj->stk1)){
      int x = pop(&obj->stk1);
      push(&obj->stk2, x);
    }
  }
  res = pop(&obj->stk2);
  return res;
}

int myQueuePeek(MyQueue* obj) {
  int res;
  if(myQueueEmpty(obj)){
    printf("stk1 and stk2 are all NULL\n");
    return -1;
  }
  if(stkEmpty(obj->stk2)){//從stk1 pop 出後 push到stk2
    while(!stkEmpty(obj->stk1)){
      int x = pop(&obj->stk1);
      push(&obj->stk2, x);
    }
  }
  res = top(&obj->stk2);//取得 top的data
  if(stkEmpty(obj->stk1)){//從stk2 pop 出後 push到stk1
    while(!stkEmpty(obj->stk2)){
      int x = pop(&obj->stk2);
      push(&obj->stk1, x);
    }
  }
  return res;
}

void myQueuePrint(MyQueue* obj){
  if(myQueueEmpty(obj)){
    printf("stk1 and stk2 are all NULL\n");
    return;
  }
  printf("F _ ");
  if(stkEmpty(obj->stk2)){//從stk1 pop 出後 push到stk2
    while(!stkEmpty(obj->stk1)){
      int x = pop(&obj->stk1);
      push(&obj->stk2, x);
    }
  }
  if(stkEmpty(obj->stk1)){//從stk2 pop 出後 push到stk1
    while(!stkEmpty(obj->stk2)){
      int x = pop(&obj->stk2);
      printf("%d _ ",x);
      push(&obj->stk1, x);
    }
  }
  printf("R\n");
}

void myQueueFree(MyQueue* obj) {
  free(obj->stk1);
  free(obj->stk2);
  free(obj);
}

/***************************************************************/
int main() {
  
  MyQueue *qq = myQueueCreate();
  myQueuePrint(qq);
  
  printf("Do push 1\n");
  myQueuePush(qq, 1);
  myQueuePrint(qq);
  printf("Do push 2\n");
  myQueuePush(qq, 2);
  myQueuePrint(qq);
  printf("Do push 3\n");
  myQueuePush(qq, 3);
  myQueuePrint(qq);
  
  printf("peek queue front = %d\n",myQueuePeek(qq));
  printf("Do push 4\n");
  myQueuePush(qq, 4);
  myQueuePrint(qq);
  printf("pop queue front %d\n",myQueuePop(qq));
  myQueuePrint(qq);
  printf("peek queue front = %d\n",myQueuePeek(qq));
  printf("Is queue now empty? %s\n",myQueueEmpty(qq)?"True":"False");
  printf("pop queue front %d\n",myQueuePop(qq));
  myQueuePrint(qq);
  printf("Is queue now empty? %s\n",myQueueEmpty(qq)?"True":"False");
  printf("pop queue front %d\n",myQueuePop(qq));
  myQueuePrint(qq);
  printf("Is queue now empty? %s\n",myQueueEmpty(qq)?"True":"False");
  printf("pop queue front %d\n",myQueuePop(qq));
  myQueuePrint(qq);
  printf("Is queue now empty? %s\n",myQueueEmpty(qq)?"True":"False");
  
  return 0;
}