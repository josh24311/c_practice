/*
#matrix
#54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

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
#include <unordered_set>
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

1  2  3  4   5
6  7  8  9   10
11 12 13 14  15
16 17 18 19  20

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      if(matrix.size() == 0)return ans;
      int rowBegin = 0;
      int rowEnd = matrix.size() - 1;
      int colBegin = 0;
      int colEnd = matrix[0].size() - 1;
      while(rowBegin <= rowEnd && colBegin <= colEnd){
        //go right
        for(int j = colBegin; j <= colEnd; j++){
          ans.push_back(matrix[rowBegin][j]);
        }
        rowBegin++;
        //go down
        for(int i = rowBegin; i <= rowEnd; i++){
          ans.push_back(matrix[i][colEnd]);
        }
        colEnd--;
        //go left, 因上方有動到rowBegin 此處需判斷是否還有row可以走
        if(rowBegin <= rowEnd){
          for(int j = colEnd; j >= colBegin; j--){
            ans.push_back(matrix[rowEnd][j]); 
          }
          rowEnd--;
        }
        
        //go up, 因上方有動到colEnd 此處需判斷是否還有col可以走
        if(colBegin <= colEnd){
          for(int i = rowEnd; i >= rowBegin; i--){
            ans.push_back(matrix[i][colBegin]);
          }
          colBegin++;
        }

      }
      return ans;
    }
};


// ---------------------------------------
int main() {
  Solution s;
  vector<vector<int>> v1 = {{1,2,3}, {4,5,6}, {7,8,9}};
  vector<vector<int>> v2 = {{1,2,3,4}, {5,6,7,8}, {7,8,9,10}, {11,12,13,14}};
  vector<int> ans1 = s.spiralOrder(v1);
  vector<int> ans2 = s.spiralOrder(v2);
  for(auto x: ans1){
    cout<<x<<" ";
  }
  cout << endl;
  for(auto x: ans2){
    cout<<x<<" ";
  }
  cout << endl;
  return 0;
  
  
}