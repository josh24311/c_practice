/*
98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true
Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <climits>    
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
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
        5
     4    6
         3  7 
*/
/*
判斷每個子節點都在最小值和最大值中間
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if(root == NULL){
        return true;
      }
      return helper(root->left, LONG_MIN, root->val) & helper(root->right, root->val, LONG_MAX);
      
    }
private:
    bool helper(TreeNode* root, long min, long max){
      if(root == NULL){
        return true;
      }
      if(root->val <= min || root->val >= max){
        return false;
      }
      return helper(root->left, min, root->val) & helper(root->right, root->val, max);
    }
};

// ---------------------------------------
int main() {
  Solution s;
  struct TreeNode* a = new TreeNode(2);
  struct TreeNode* b = new TreeNode(1);
  struct TreeNode* c = new TreeNode(3);
  a->left = b;
  a->right = c;
  struct TreeNode* d = new TreeNode(5);
  struct TreeNode* e = new TreeNode(4);
  struct TreeNode* f = new TreeNode(6);
  struct TreeNode* g = new TreeNode(3);
  struct TreeNode* h = new TreeNode(7);
  d->left = e;
  d->right = f;
  f->left = g;
  f->right = h;
  cout <<" ans1 tree a " << boolalpha << s.isValidBST(a) << endl;
  cout <<" ans2 tree d " << boolalpha << s.isValidBST(d) << endl;
  delete(a);
  delete(b);
  delete(c);
  delete(d);
  delete(e);
  delete(f);
  delete(g);
  delete(h);
  return 0;
  
  
}