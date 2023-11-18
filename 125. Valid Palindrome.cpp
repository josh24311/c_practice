/*
#twoPointer
#API : isalnum , tolower
125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
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
T:O(n) , S:O(1)
a. b  ba
a,b=a
*/
class Solution {
public:
    bool isPalindrome(string s) {
      if(s.size() == 0)return true;
      int left = 0;
      int right = s.length()-1;
      while(left < right){
        while(left < right && !isalnum(s[left])){
          ++left;
        }
        while(left < right && !isalnum(s[right])){
          --right;
        }
        if(tolower(s[left]) != tolower(s[right])){
          return false;
        }
        ++left;
        --right;
      }
      return true;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  string s3 = " ";
  cout << s.isPalindrome(s1) << endl;
  cout << s.isPalindrome(s2) << endl;
  cout << s.isPalindrome(s3) << endl;
  return 0;
  
}