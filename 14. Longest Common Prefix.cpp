/*
#string
#min_element , max_element
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
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
T:O(nlogn) , S:O(1)

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      /*
      string ans = "";
      sort(strs.begin(), strs.end());
      int n = strs.size();
      string s1 = strs[0];
      string s2 = strs[n-1];
      int i = 0;
      while(i < fmin(s1.size(), s2.size())){
        if(s1[i] != s2[i]){
          return ans;
        }
        ans += s1[i];
        i++;
      }
      return ans;
      */
      //method 2
      if (strs.empty()) {
        return "";
      }

      // 找到最短的字符串和最长的字符串
      std::string shortest = *min_element(strs.begin(), strs.end());
      std::string longest = *max_element(strs.begin(), strs.end());

      // 比较最短和最长字符串的字符
      int i = 0;
      while (i < shortest.size() && shortest[i] == longest[i]) {
        i++;
      }

      return shortest.substr(0, i);
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<string> str1 = {"flower","flow","flight"};
  vector<string> str2 = {"dog","racecar","car"};
  string ans1 = s.longestCommonPrefix(str1);
  string ans2 = s.longestCommonPrefix(str2);
  cout << ans1 << endl;
  cout << ans2 << endl;
  
  
  
  
  return 0;
  
}