/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that 
cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Input: intervals = [[2,3],[1,5],[4,8]]   -> [1,5] [2,3] [4,8]
Output: [[1,8]]
Input: intervals = [[8,9],[1,3], [4,5]]  -> [1,3] [4,5] [8,9]
Output: [[1,3], [4,5], [8,9]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int m = intervals.size();
      vector<vector<int>> result;
      if (m == 1) {
        result.push_back(intervals[0]);
        return result;
      }
      //第一個元素照升序排列
      sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
      });
      int lMin, lMax;
      lMin = intervals[0][0];
      lMax = intervals[0][1];
      for (int i = 1; i < m; i++) {
        if (intervals[i][0] >= lMin && intervals[i][0] <= lMax) {
          lMax = intervals[i][1] >= lMax ? intervals[i][1]: lMax;
        } else if (intervals[i][0] > lMax) {
          result.push_back({lMin, lMax});
          lMin = intervals[i][0];
          lMax = intervals[i][1];
        }
        if (i == m-1) {
          result.push_back({lMin, lMax});
        }        
      }
      return result;
    }
};
int main() 
{
    Solution s;
    vector<vector<int>> matrix1 = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> matrix2 = {{1,4}, {4,5}};
    vector<vector<int>> matrix3 = {{2,3}, {1,5}, {4,8}};
    vector<vector<int>> matrix4 = {{1,3}};
    vector<vector<int>> result1 = s.merge(matrix1);
    vector<vector<int>> result2 = s.merge(matrix2);
    vector<vector<int>> result3 = s.merge(matrix3);
    vector<vector<int>> result4 = s.merge(matrix4);
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    for (const auto& interval : result3) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    for (const auto& interval : result4) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}