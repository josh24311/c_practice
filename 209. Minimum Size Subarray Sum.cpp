/*
#Sliding Window
209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
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

2,3,1,2,4,3
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int res = INT_MAX;
      int sum = 0;
      int left = 0;
      for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        while(left <= i && sum >= target){
          res = fmin(res, (i - left + 1));
          sum -= nums[left];
          left++;
        } 
      }
      return res == INT_MAX?0:res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<int> v1 = {2,3,1,2,4,3};
  int t1 = 7;
  cout << s.minSubArrayLen(t1,v1) << endl;
  vector<int> v2 = {1,4,4};
  int t2 = 4;
  cout << s.minSubArrayLen(t2,v2) << endl;
  vector<int> v3 = {1,1,1,1,1,1,1,1};
  int t3 = 11;
  cout << s.minSubArrayLen(t3,v3) << endl;
  
  return 0;
  
}