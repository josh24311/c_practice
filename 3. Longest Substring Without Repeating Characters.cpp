/*
#slidingWindow
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
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
/* tmmxyut */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.length() == 0 || s.length() == 1){
        return s.length();
      }
      int n = s.length();
      unordered_map<char, int> m;
      int left = 0;
      int maxLen = 0;
      for(int i = 0; i < n; i++){
        if(m.find(s[i]) != m.end()){//s[i] 已出現在map內
            left = fmax(left, m[s[i]] + 1);
        }
        m[s[i]] = i; // 更新map
        maxLen = fmax(maxLen, i - left + 1);
        
      }
      return maxLen;
    }
};

// ---------------------------------------
int main() {
  Solution s;
  string s1 = "abcabcbb";
  string s2 = "bbbbb";
  string s3 = "pwwkew";
  cout << "ans1 = " << s.lengthOfLongestSubstring(s1) << endl;
  cout << "ans2 = " << s.lengthOfLongestSubstring(s2) << endl;
  cout << "ans3 = " << s.lengthOfLongestSubstring(s3) << endl;
  return 0;
}