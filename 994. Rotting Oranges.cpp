/*
#queue_pair
#BFS
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
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
T:O(m*n) , S:O(m*n)

*/
/*

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      queue<pair<int,int>> q;
      vector<vector<bool>> visited(m,vector<bool>(n,false));
      
      int res = 0;
      int freshNum = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){ 
          if(grid[i][j] == 1){
            freshNum++;    
          }
          if(grid[i][j] == 2){
            q.push({i,j});
            visited[i][j] = true;
          }
        }
      }
      
      if (freshNum == 0) {
          return 0;  // No fresh oranges to start with.
      }
      
      
      int freshToRot = 0;
      while(!q.empty()){
        int size = q.size();
        bool hasRotten = false;
        while(size--){
          auto top = q.front();
          q.pop();
          int i = top.first;
          int j = top.second;
          if(i - 1 >= 0 && grid[i-1][j] == 1 && !visited[i-1][j]){
            freshToRot++;
            grid[i-1][j] = 2;
            q.push({i-1,j});
            visited[i-1][j] = true;
            hasRotten = true;
          }
          if(i + 1 < m && grid[i+1][j] == 1 && !visited[i+1][j]){
            freshToRot++;
            grid[i+1][j] = 2;
            q.push({i+1,j});
            visited[i+1][j] = true;
            hasRotten = true;
          }
          if(j - 1 >= 0 && grid[i][j-1] == 1 && !visited[i][j-1]){
            freshToRot++;
            grid[i][j-1] = 2;
            q.push({i,j-1});
            visited[i][j-1] = true;
            hasRotten = true;
          }
          if(j + 1 < n && grid[i][j+1] == 1 && !visited[i][j+1]){
            freshToRot++;
            grid[i][j+1] = 2;
            q.push({i,j+1});
            visited[i][j+1] = true;
            hasRotten = true;
          }
        }
        if(hasRotten){
          res++;
        }
      }
      return freshNum == freshToRot ? res : -1;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
  vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
  vector<vector<int>> grid3 = {{0,2}};
  cout << s.orangesRotting(grid1) << endl;
  cout << s.orangesRotting(grid2) << endl;
  cout << s.orangesRotting(grid3) << endl;

  return 0;
  
}