/*
#hastMap
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
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
T:O(nlogn) , S:O(n) 

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> map;
      vector<int> res;
      for(int i = 0; i < nums.size(); i++){
        int num = nums[i];
        int diff = target - num;
        if(map.find(diff) != map.end()){
          res.push_back(map[diff]);
          res.push_back(i);
          return res;
        }
        map[num] = i;
      }
      return res;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<int> v1 = {2,7,11,15};
  vector<int> v2 = {3,2,4};
  vector<int> v3 = {3,3};
  vector<int> ans1 = s.twoSum(v1, 9);
  vector<int> ans2 = s.twoSum(v2, 6);
  vector<int> ans3 = s.twoSum(v3, 6);
  for(auto x: ans1){
    cout << x << " ";
  }
  cout << endl;
  for(auto x: ans2){
    cout << x << " ";
  }
  cout << endl;
  for(auto x: ans3){
    cout << x << " ";
  }
  cout << endl;
  
  
  
  return 0;
  
}