/*
#LinkedList
206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
//ite
//       1   ->   2   ->   3   ->   4   ->   5   ->   NULL
//prev
//     head
//               curr

//rec
//       1   ->   2   ->   3   ->   4   ->   5   ->   NULL
//
//                                          head
//                                          newHead

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      //iteratively , T:O(n) , S:O(1)
      /*
      if(head == nullptr || head->next == nullptr) return head;
      ListNode* prev = nullptr;
      ListNode* curr = nullptr;
      while(head != nullptr){
        curr = head->next;//用curr記住head->next
        head->next = prev;//更新new list
        prev = head;//更新下一輪的prev
        head = curr;//更新下一輪的head
      }
      return prev;
      */
      
      //recursively, T:O(n) , S:O(1)
      if(head == nullptr || head->next == nullptr) return head;//到達初始list的尾巴後開始回傳,使得新list的頭節點為舊list的尾節點
      ListNode* newHead = reverseList(head->next);//遞迴呼叫
      head->next->next = head;//將當前head的下一個指向自己
      head->next = nullptr;
      return newHead;//最後一次recursive結束後回傳newHead
    }
};

// ---------------------------------------
int main() {
  Solution s;
  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(3);
  l1->next->next->next = new ListNode(4);
  l1->next->next->next->next = new ListNode(5);
  
  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(2);
  
  ListNode* ans1 = s.reverseList(l1);
  while(ans1 != nullptr){
    cout << ans1->val << " ";
    ans1 = ans1->next;
  }
  cout << endl;
  ListNode* ans2 = s.reverseList(l2);
  while(ans2 != nullptr){
    cout << ans2->val << " ";
    ans2 = ans2->next;
  }
  cout << endl;
  
  return 0;
}