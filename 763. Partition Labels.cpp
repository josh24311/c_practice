/*
#greedy
#hashmap
763. Partition Labels
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
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
T:O(n) , S:O(26)

*/
/*
s = "ababcbaca defegde hijhklij"
     012345678 9
m1[a] = 8
m1[b] = 5
m1[c] = 7


s = "abccdab e m"
     0123456 7 8
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
      int len = s.size();
      map<char,int> m1;
      vector<int> res;
      //更新每個字母最後出現的位置
      for(int i = 0; i < len; i++){
        m1[s[i]] = i;
      }
      
      int start = 0;
      int end = 0;
      for(int i = 0; i < len; i++){
        //更新substring 結尾 index
        end = max(end, m1[s[i]]); 
        if(i == end){//代表此substring內已無任何元素可以使end增加
          res.push_back( end - start + 1);
          start = end + 1;//下一個substring
        }
      }
      return res;
    }
private:
    int findRightMostIndex(const string s, const char c){
      int len = s.size();
      int res = len - 1 ;
      while(res >= 0){
        if(s[res] == c){
          return res;
        }
      }
      return res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  string s1 = "ababcbacadefegdehijhklij";
  vector<int> ans1 = s.partitionLabels(s1);
  for(auto x: ans1)
    cout<<x<<" ";
  cout<<endl;
  string s2 = "eccbbbbdec";
  vector<int> ans2 = s.partitionLabels(s2);
  for(auto x: ans2)
    cout<<x<<" ";
  cout<<endl;
  
  return 0;
  
}