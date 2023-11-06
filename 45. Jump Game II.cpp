/*
#greedy
#important
45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
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
    int jump(vector<int>& nums) {
      int numsSize = nums.size();
      //greedy1
      
      int curMax = 0; // 當前可到達的最遠位置
      int nextMax = 0; // 以i到 curMax 中間以其中一步為跳板，下一步可到達的最遠位置
      int jumps = 0;
      for(int i = 0; i < numsSize - 1; i++){// 注意只需判斷到 i = numsSize - 2即可
        nextMax = fmax(nextMax, (i + nums[i]));// 下一步可到達最遠處 ， 以i為跳板若nextMax變大則表示下一步挑此i 可達最遠
        if(i == curMax){
          jumps++;
          curMax = nextMax; // 更新curMax為 nextMax也表示 這一步中最優解的那個i為那個使nextMax變大的那個i
        }
      }
      return jumps ;
      
      //greedy2
      /*
      int jumps = 0;
      int left = 0;
      int right = 0;
      while(right < numsSize -1){
        int farthest = 0;
        for(int i = left; i <= right; i++){ // 更新 此 jump時的可到達最遠的位置
          farthest = fmax(farthest, i + nums[i]);
        }
        left = right + 1;
        right = farthest;
        jumps++;
      }
      return jumps;
      */
    }
};
// ---------------------------------------
int main() {
  Solution s;
  vector<int> ar1 = {2,3,1,1,4};
  int ans1 = s.jump(ar1);
  vector<int> ar2 = {2,3,0,1,4};
  int ans2 = s.jump(ar2);
  cout << "ans1 = " << ans1 << "\tans2 = " << ans2 <<endl;
  return 0;
}