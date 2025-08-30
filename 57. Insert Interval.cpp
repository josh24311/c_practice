/*
57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        // 階段一：添加所有在 newInterval 之前且不重疊的區間
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // 階段二：合併所有重疊的區間
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // 將合併後的 newInterval 添加到結果中
        result.push_back(newInterval);
        
        // 階段三：添加所有在 newInterval 之後且不重疊的區間
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
int main() 
{
    Solution s;
    vector<vector<int>> result;
    vector<vector<int>> a = {{1,3},{6,9}};
    vector<int> i1 = {2,5};
    vector<vector<int>> b = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> i2 = {4,8};

    result = s.insert(a,i1);
    cout << "Result1:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    
    cout << endl;
    result = s.insert(b,i2);
    cout << "Result2:" << endl;
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;
}






