/*
#backtracking
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Constraints:

1 <= n <= 8
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
T:O(2^(2n)) , S:O(n)

*/
/*
["((()))","(()())","(())()","()(())","()()()"]
lllrrr 
llrlrr
llrrlr
lrllrr
lrlrlr
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      helper("", n , n, res);
      return res;
    }
private:
    void helper(string curr, int left, int right, vector<string> & res){
      cout << "left = " << left << " right = " << right << endl;
      if(left == 0 && right == 0){
        cout << "do push" << endl;
        res.push_back(curr);
        return;
      }
      if(left > 0){//還有左括弧可以放
        
        helper(curr+"(", left - 1, right, res);
      }
      if(right > left){//合法放法
        
        helper(curr+")", left, right - 1, res);
      }
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<string> ans1 = s.generateParenthesis(3);
  for(auto x: ans1) {
    cout << x << endl;
  }
  cout << endl;
  vector<string> ans2 = s.generateParenthesis(1);
  for(auto x: ans2) {
    cout << x << endl;
  }
  

  return 0;
  
}