/*
#linkedList
#double pointer
#19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <climits>    
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// ---------------------------------------
/*
T:O(n) , S:O(1)

*/
/*
1-> 2 -> 3 -> (4) -> 5 , n = 2

*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* cur = new ListNode(-1);
      cur->next = head;
      ListNode* first = cur;
      ListNode* second = cur;
      for(int i = 0; i <= n; i++){
        first = first->next;//first 和 second 距離相當於創造長條型
      }
      while(first){//長條型移動
        first = first->next;
        second = second->next;
      }
      second->next = second->next->next;
      return cur->next;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  ListNode* a = new ListNode(1);
  ListNode* b = new ListNode(2);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  ListNode* e = new ListNode(5);
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  ListNode* ans1 = s.removeNthFromEnd(a, 2);
  while(ans1){
    cout << ans1->val << " ";
    ans1 = ans1->next;
  }
  cout << endl;
  ListNode* f = new ListNode(1);
  ListNode* g = new ListNode(2);
  f->next = g;
  ListNode* ans2 = s.removeNthFromEnd(f, 1);
  while(ans2){
    cout << ans2->val << " ";
    ans2 = ans2->next;
  }
  
  return 0;
  
}