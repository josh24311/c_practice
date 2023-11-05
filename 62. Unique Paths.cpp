/*
#DP
62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector> 
#include <numeric>
#include <climits>    
#include <string>

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
/*
0 1 1
1 2 3
1 3 6

*/
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> array (m, vector<int>(n, 0));
      array[0][0] = 1;
      for(int i = 1; i <= n-1; i++){
        array[0][i] = 1;
      }
      for(int i = 1; i <= m-1; i++){
        array[i][0] = 1;
      }
      for(int i = 1; i <= m-1; i++){
        for(int j = 1; j <= n-1; j++){
          array[i][j] = array[i-1][j] + array[i][j-1];
        }
      }
      int res = array[m-1][n-1];
      
      return res;
      
    }
};

// ---------------------------------------
int main() {
  Solution s;
  int ans1 = s.uniquePaths(3, 7);
  cout << ans1 << endl;
  int ans2 = s.uniquePaths(3, 2);
  cout << ans2 << endl;



  
  return 0;
}