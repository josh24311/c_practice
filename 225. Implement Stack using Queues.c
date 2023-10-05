/*
#stack
#dataStructure
#implement
225. Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 
Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?
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

typedef struct {
  int val[100];//suitable size
  int top;
} MyStack;


MyStack* myStackCreate() {
  MyStack *obj = malloc(sizeof(MyStack));
  obj->top = -1;//initial top
  memset(obj->val, 0, sizeof(int)*100);
  return obj;
}

void myStackPush(MyStack* obj, int x) {
  obj->top++;
  obj->val[obj->top] = x;
}

int myStackPop(MyStack* obj) {
  int res = obj->val[obj->top];
  obj->val[obj->top] = 0;
  obj->top--;//move top back
  return res;
}

int myStackTop(MyStack* obj) {
  int res = obj->val[obj->top];
  return res;
}

bool myStackEmpty(MyStack* obj) {
  return obj->top==-1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/***************************************************************/
int main() {
  MyStack* stk = myStackCreate();
  myStackPush(stk, 1);
  printf("1st push\n");
  for(int i = 0; i < 4; i++){
    printf("val[%d] = %d\n",i,stk->val[i]);
  }
  
  myStackPush(stk, 2);
  printf("\n2nd push\n");
  for(int i = 0; i < 4; i++){
    printf("val[%d] = %d\n",i,stk->val[i]);
  }
  
  printf("show top is %d\n",myStackTop(stk));
  for(int i = 0; i < 4; i++){
    printf("val[%d] = %d\n",i,stk->val[i]);
  }
  
  int t1 = myStackPop(stk);
  printf("pop value %d\n",t1);
  printf("after pop\n");
  for(int i = 0; i < 4; i++){
    printf("val[%d] = %d\n",i,stk->val[i]);
  }
  free(stk);
  return 0;
}