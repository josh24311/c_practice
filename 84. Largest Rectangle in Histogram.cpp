/*
#Stack
84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
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
T:O(n), S:O(n)

0 1 2 3 4 5 6
2 1 5 6 2 3 0

i = 0:
  h = 2
  stk {0}
i = 1:
  1 < heights[0] = 2 , 
  height = 2, do pop => stk {1},
  area = 1 * 2 = 2
  
i = 2:
  push 5
  stk{1,2}
i = 3:
  push 6
  stk{1,2,3}

i = 4:
  2 < heights[3] = 6 , do pop
  height = 6, do pop => stk{1,2}
  start = 2, area = (4-2-1)*6 = 6
  2 < heights[2] = 5, do pop
  height = 5, do pop => stk{1}
  start = 1, area = (4-3-1)*5 = 10
  push 2
  stk{1,4}

i = 5:
  push 3
  stk{1,4,5}
i = 6:
  pop 
  pop
  pop

*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      if(heights.size() == 0 ){
        return 0;
      }
      stack<int> stk1 ;
      int res = 0;
      for(int i = 0; i <= heights.size(); i++){
        int h = i == heights.size()?0:heights[i];
        while(!stk1.empty() && h < heights[stk1.top()]){
          int height = heights[stk1.top()];
          stk1.pop();
          int start = stk1.empty()?-1:stk1.top();
          int area = (i - start - 1) * height;
          res = fmax(res, area);
        }
        stk1.push(i);
        
      }
      return res;
    }
};

// ---------------------------------------
int main() {
  Solution s;
  vector<int> a1 = {2,1,5,6,2,3};
  vector<int> a2 = {0,9};
  cout << s.largestRectangleArea(a1) << endl;
  cout << s.largestRectangleArea(a2) << endl;
  return 0;
}