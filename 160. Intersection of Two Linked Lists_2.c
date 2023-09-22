/*
160. Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA < m
0 <= skipB < n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
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
/****************************************************************************************/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //   4 2 
    //       8 3 7
    // 5 6 1
/*
思路-  若兩list相會:A走到NULL再接回B 與 B走到NULL再接回A 兩條路線會重合在IntersectionNode
若兩list不相會:A走到NULL再接回B 與 B走到NULL再接回A 兩條路線會重合在NULL
*/
  if(headA == NULL || headB == NULL)return NULL;
  struct ListNode* currA = malloc(sizeof(struct ListNode));
  struct ListNode* currB = malloc(sizeof(struct ListNode));
  currA = headA;
  currB = headB;
  while(currA!=currB){
    currA = currA == NULL?headB:currA->next;
    currB = currB == NULL?headA:currB->next;
  }
  return currA;
}

/****************************************************************************************/
int main() {
  struct ListNode* a = malloc(sizeof(struct ListNode));
  struct ListNode* b = malloc(sizeof(struct ListNode));
  struct ListNode* c = malloc(sizeof(struct ListNode));
  struct ListNode* d = malloc(sizeof(struct ListNode));
  struct ListNode* e = malloc(sizeof(struct ListNode));
  struct ListNode* f = malloc(sizeof(struct ListNode));
  struct ListNode* g = malloc(sizeof(struct ListNode));
  struct ListNode* h = malloc(sizeof(struct ListNode));

  a->val = 4;
  b->val = 2;
  c->val = 5;
  d->val = 6;
  e->val = 1;
  f->val = 8;
  g->val = 3;
  h->val = 7;
  a->next = b;
  b->next = f;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = g;
  g->next = h;
  struct ListNode *ans1 = malloc(sizeof(struct ListNode));
  ans1 = getIntersectionNode(a, c);
  printf("ans1 val %d\n",ans1->val);
  struct ListNode* i = malloc(sizeof(struct ListNode));
  struct ListNode* j = malloc(sizeof(struct ListNode));
  struct ListNode* k = malloc(sizeof(struct ListNode));
  struct ListNode* l = malloc(sizeof(struct ListNode));
  struct ListNode* m = malloc(sizeof(struct ListNode));
  struct ListNode* n = malloc(sizeof(struct ListNode));
  i->val = 5;
  j->val = 9;
  k->val = 1;
  l->val = 3;
  m->val = 2;
  n->val = 4;
  i->next = j;
  j->next = k;
  l->next = m;
  k->next = m;
  m->next = n;
  struct ListNode *ans2 = malloc(sizeof(struct ListNode));
  ans2 = getIntersectionNode(i, l);
  printf("ans2 val %d\n",ans2->val);
  struct ListNode* o = malloc(sizeof(struct ListNode));
  struct ListNode* p = malloc(sizeof(struct ListNode));
  struct ListNode* q = malloc(sizeof(struct ListNode));
  struct ListNode* r = malloc(sizeof(struct ListNode));
  struct ListNode* s = malloc(sizeof(struct ListNode));

  o->val = 2;
  p->val = 6;
  q->val = 4;
  r->val = 1;
  s->val = 5;
  o->next = p;
  p->next = q;
  r->next = s;
  struct ListNode *ans3 = malloc(sizeof(struct ListNode));
  ans2 = getIntersectionNode(o, r);
  printf("ans3 val %d\n",ans3->val);
  

  return 0;
}