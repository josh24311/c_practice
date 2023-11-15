/*
#matrix
48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
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
1 2 3     [7] 8  9    7 4 1
4 5 6  =>  4 [5] 6 => 8 5 2
7 8 9      1  2 [3]   9 6 3
                      (0,1) = (1,0)
                      (0,2) = (2,0)
                      (1,2) = (2,1)

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int top = 0;
      int down = matrix.size() - 1;
      while(top < down){
        swap(matrix[top], matrix[down]);
        top++;
        down--;
      }
      for(int i = 0; i < matrix.size(); i++){
        for(int j = i + 1; j < matrix[0].size(); j++){
          swap(matrix[i][j], matrix[j][i]);
        }
      }
      
    }
};

// ---------------------------------------
int main() {
  Solution s;
  vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  s.rotate(matrix);
  for(auto row : matrix){
    cout << "[";
    cout << row[0];
    cout << ", ";
    cout << row[1];
    cout << ", ";
    cout << row[2];
    cout << ", ";
    cout << row[3];
    cout << "]";
    cout << endl;
  }
  return 0;
}