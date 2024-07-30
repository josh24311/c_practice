/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {                                          //        f
public:                                                   //   p
    ListNode* sortList(ListNode* head) {                  // 4 2 1 3
      if (head == nullptr || head->next == nullptr) {     //     s
        return head;
      }
      ListNode *prev = nullptr;                           
      ListNode *slow = head;
      ListNode *fast = head;
      while (fast != nullptr && fast->next != nullptr) {
        prev = slow;//prev 恰好將 list 平分
        slow = slow->next;
        fast = fast->next->next;
      }
      prev->next = nullptr;//斷開為2 List
      return merge(sortList(head), sortList(slow));//各自sort  之後再 merge
    }
private:
    ListNode* merge(ListNode *l1, ListNode *l2) {
      /*
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
      } else {
        l2->next = merge(l2->next, l1);
        return l2;
      }*/
      ListNode dummy;
      ListNode* tail = &dummy;
      while (l1 && l2) {
          if (l1->val < l2->val) {
              tail->next = l1;
              l1 = l1->next;
          } else {
              tail->next = l2;
              l2 = l2->next;
          }
          tail = tail->next;
      }
      tail->next = l1 ? l1 : l2;
      return dummy.next;      
    }
};
 
int main() 
{
    Solution s;
    int values[] = {4, 2, 1, 3};
    ListNode *list = new ListNode(values[0]);
    ListNode *cur = list;
    for(int i = 1; i < 4; i++) {
      cur->next = new ListNode(values[i]);
      cur = cur->next;
    }
    cur = s.sortList(list);
    while(cur != nullptr) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
    int values2[] = {-1, 5, 3, 4, 0};
    ListNode *list2 = new ListNode(values2[0]);
    cur = list2;
    for(int i = 1; i < 5; i++) {
      cur->next = new ListNode(values2[i]);
      cur = cur->next;
    }
    cur = s.sortList(list2);
    while(cur != nullptr) {
      cout << cur->val << " ";
      cur = cur->next;
    }    
    return 0;
}