/*
#doublepointers
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
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
// T:O(nlogn + n^2) = O(n^2) , S:O(n)

class Solution {    
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());// -4 -1 -1 0 1 2
      //cout << "nums.size = " << nums.size() << endl;
      int numsSize = nums.size();
      vector<vector<int>> ans;
      
      for(int i = 0; i < numsSize-2; i++){
        if(i != 0 && nums[i] == nums[i-1]){
          continue;
        }
        int left = i + 1;
        int right = nums.size() -1;
        while(left < right){
          int sum = nums[i] + nums[left] + nums[right];
          if( sum == 0){
            ans.push_back({nums[i], nums[left], nums[right]});
            
            while(left < right && nums[left] == nums[left+1]){// to find unique left
              left++;
            }
            left++;
            while(left < right && nums[right] == nums[right-1]){// to find unique right
              right--;
            }
            right--;
          }
          else if (sum > 0){
            right--;
          }
          else if (sum < 0){
            left++;
          }
        }
        
      }
      return ans;
      
    }
};
// ---------------------------------------
int main() {
  Solution s;
  vector<int> ar1 = {
  -1, 0, 1, 2, -1, -4
  };
  vector<vector<int>> ans1 = s.threeSum(ar1);
  cout << "ans1: " << endl;
  for (auto& ar : ans1) {
    cout << "[";
    cout << ar[0];
    cout << ",";
    cout << ar[1];
    cout << ",";
    cout << ar[2];
    cout << "]";
    cout << endl;
  }
  cout << endl;
  vector<int> ar2 = {
  0, 1, 1
  };
  vector<vector<int>> ans2 = s.threeSum(ar2);
  cout << "ans2: " << endl;
  for (auto& ar : ans2) {
    cout << "[";
    cout << ar[0];
    cout << ",";
    cout << ar[1];
    cout << ",";
    cout << ar[2];
    cout << "]";
    cout << endl;
  }
  
  return 0;
}