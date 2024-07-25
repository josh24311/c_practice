/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      int i,j;
      int rowZero = 0, colZero = 0;
      //標記第0 row, 0 col 的 element 為 pivot
      //若第0 row, 0 col 的 element 恰好為0, set flag
      for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
          if (matrix[i][j] == 0) {
            if (i == 0) {
              rowZero = 1;
            }
            if (j == 0) {
              colZero = 1;
            }
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }
      //若row pivot / col pivot 任一個為0
      for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }
      //處理第0 row, 0 col
      if (rowZero) {
        for (j = 0; j < n; j++) {
          matrix[0][j] = 0;
        }
      }
      if (colZero) {
        for (i = 0; i < m; i++) {
          matrix[i][0] = 0;
        }
      }
      
      
    }
};

int main() 
{
    Solution s;
    vector<vector<int>> matrix1 = {{1,1,1}, {1,0,1}, {1,1,1}};
    vector<vector<int>> matrix2 = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    s.setZeroes(matrix1);
    cout << "matrix1" <<endl;
    for (const auto& row: matrix1) {
      for (const auto &elem : row) {
        cout << elem << " ";
      }
      cout << endl;
    }
    cout << "matrix2" <<endl;
    s.setZeroes(matrix2);
    for (const auto& row: matrix2) {
      for (const auto &elem : row) {
        cout << elem << " ";
      }
      cout << endl;
    }
    return 0;
}