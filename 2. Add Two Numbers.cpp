/*
#LinkedList
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
// T:O(max(m,n))  , S:O(max(m,n))
// 2 -> 4 -> 3 
// 5 -> 6 -> 4
// 7 -> 0 -> 8
class Solution {
public:
    ListNode*  addTwoNumbers(ListNode* l1, ListNode* l2){
      ListNode* head = new ListNode(-1);
      ListNode* cur = head;
      int carry = 0;
      while(l1 || l2 || carry ){
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        sum %= 10;
        cur->next = new ListNode(sum);
        cur = cur->next;
        if(l1){
          l1 = l1->next;
        }
        if(l2){
          l2 = l2->next;
        }
      }
      return head->next;
    }
};

// ---------------------------------------
int main() {
  Solution s;
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  ListNode* ans = s.addTwoNumbers(l1, l2);
  while(ans != nullptr){
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
  
  return 0;
}