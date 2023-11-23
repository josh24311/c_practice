/*
#binaryTree
#stack
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?
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
/*
T:O(m) , S:O(1)

*/
/*

*/
//method 1 recursive
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if(root == nullptr){
        return {};
      }
      vector<int> res;
      helper(root, res);
      return res;
    }
private:
    void helper(TreeNode* root, vector<int> & res){
      if(root == nullptr){
        return;
      }
      
      helper(root->left, res);
      res.push_back(root->val);
      helper(root->right, res);
    }
};
*/
//method 2 iterative using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if(root == nullptr){
        return {};
      }
      vector<int> res;
      stack<TreeNode*> stk;
      TreeNode* curr = root;
      while(curr != nullptr || !stk.empty()){
        //push all left node of curr node
        while(curr != nullptr){
          stk.push(curr);
          curr = curr->left;
        }
        curr =  stk.top();
        stk.pop();
        res.push_back(curr->val);
        curr = curr->right;//若此時curr != nullptr 繼續加入其左節點至stack
        
      }
      return res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  TreeNode* a = new TreeNode(1);
  TreeNode* b = new TreeNode(2);
  TreeNode* c = new TreeNode(3);
  a->right = b;
  b->left = c;
  vector<int> ans = s.inorderTraversal(a);
  for(auto x: ans)
    cout<<x<<" ";
  cout<<endl;
  

  return 0;
  
}