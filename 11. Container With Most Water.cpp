/*
#twoPointer
11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

Constraints:

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
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
T:O(n), S:O(1)

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0,right = height.size()-1;
      int res = 0;
      while(left < right){
        int waterNow = fmin(height[left], height[right])*(right - left);
        res = max(res,waterNow);
        if(height[left] > height[right]){//保留較高者
          right--;
        }
        else{
          left++;
        }
      }
      return res;
    }
};

// ---------------------------------------
int main() {
  Solution s;
  vector<int> a1 = {1,8,6,2,5,4,8,3,7};
  vector<int> a2 = {1,1};
  cout << s.maxArea(a1) << endl;
  cout << s.maxArea(a2) << endl;
  return 0;
}