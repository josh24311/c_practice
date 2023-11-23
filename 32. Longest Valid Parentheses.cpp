/*
#stack
#DP
#hard
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses  substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
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
T:O(n) , S:O(n)

*/
/*
"(()"
")()())"
"(())"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
      int res = 0;
      //method 1 : stack
      /*
      stack<int> stk;
      stk.push(-1); // 最新 "無效位"
      for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
          stk.push(i);
        }
        else{// encounter ')'
          stk.pop();// do pop
          if(stk.empty()){
            stk.push(i);// 更新最新 "無效位"
          }
          else{
            res = fmax(res, i - stk.top());
          }
        }    
      }*/
      // method 2 : DP
      vector<int> dp(s.length(), 0);//dp[i] 表示以第i位當結尾的最長有效子字串長度
      //在遍歷時，只有遇到')' 才更新DP內的值
      for(int i = 1; i < s.length(); i++){
        if(s[i] == ')'){
          if(s[i-1] == '('){
            dp[i] = ((i >= 2)? dp[i-2] : 0) + 2;
          }
          else if(i - dp[i-1] -1 >= 0 && s[i-dp[i-1]-1] == '('){//s[i] == ')' 且在更之前index有可匹配之'('
            // 若 index [i - dp[i-1] - 2]存在，則須考慮dp[i-dp[i-1]-2],即為新找到'('的更之前的dp值
            dp[i] = dp[i-1] + ((i - dp[i-1] -2 >= 0)  ? dp[i - dp[i-1] - 2] : 0) + 2;
          }
          res = fmax(res, dp[i]);
        }
      }
      return res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  string s1 = "(()";
  cout << s.longestValidParentheses(s1) << endl;
  string s2 = ")()())";
  cout << s.longestValidParentheses(s2) << endl;
  string s3 = "()(()";
  cout << s.longestValidParentheses(s3) << endl;
  
  

  return 0;
  
}