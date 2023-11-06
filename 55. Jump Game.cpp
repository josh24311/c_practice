/*
#greedy
55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <climits>    
#include <string>
#include <algorithm>

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
// T:O(n)  , S:O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int maxReach = 0;//當前可以走的最遠的點
      for(int i = 0; i < n; i++){
        if(i > maxReach){//若檢查到i比當前可以走的位置還要遠的點
          return false;
        }
        maxReach = fmax(maxReach, i + nums[i]);
      }
      return true;
      
    }
};
// ---------------------------------------
int main() {
  Solution s;
  vector<int> ar1 = {2,3,1,1,4};
  bool ans1 = s.canJump(ar1);
  vector<int> ar2 = {3,2,1,0,4};
  bool ans2 = s.canJump(ar2);
  cout << "ans1 = " << ans1 << "\tans2 = " << ans2 <<endl;
  return 0;
}