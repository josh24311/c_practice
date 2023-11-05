/*
#DFS
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
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
// T:O(m*n) , S:O(1)
class Solution {
private:
void floodFill(vector<vector<char>>& grid, int i, int j, int maxRow, int maxCol){
  if(i < 0 || j < 0 || i >= maxRow || j >= maxCol || grid[i][j] == '0'){
    return;
  }
  grid[i][j] = '0';// has explored mark as 0
  floodFill(grid, i+1, j, maxRow, maxCol);
  floodFill(grid, i-1, j, maxRow, maxCol);
  floodFill(grid, i, j+1, maxRow, maxCol);
  floodFill(grid, i, j-1, maxRow, maxCol);
}
public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int result = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(grid[i][j] == '1'){
            floodFill(grid, i, j, m, n);
            result += 1;

            
          }
        }
      }
      return result;
    }

};
// ---------------------------------------
int main() {
  Solution s;
  vector<vector<char>> ar1 = {
  {'1', '1', '1', '1', '0'},
  {'1', '1', '0', '1', '0'},
  {'1', '1', '0', '0', '0'},
  {'0' ,'0' ,'0' ,'0' ,'0'}
  };
  cout << "an1 = " << s.numIslands(ar1);
  cout << endl;
  vector<vector<char>> ar2 = {
  {'1', '1', '0', '0', '0'},
  {'1', '1', '0', '0', '0'},
  {'0', '0', '1', '0', '0'},
  {'0' ,'0' ,'0' ,'1' ,'1'}
  };
  cout << "an2 = " << s.numIslands(ar2);


  
  return 0;
}