/*
45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

int cmp(const void* pa, const void* pb )// need include cstdlib
{
    const int *a = (int*)pa;
    const int *b = (int*)pb;
    if (*a > *b) 
        return 1;
    else if (*a < *b)
        return -1;

    return 0;
}

class Solution {
public:
    int jump(vector<int>& nums) {
        //想法一, 維護一個 array , 紀錄跳到當前index所需最短步數 時間 O(n × max(nums))、空間 O(n)
        /*
        int l = nums.size();
        int i, r = INT_MAX;
        vector<int> step(l, INT_MAX);
        step[0] = 0;
        /*
        //對於每個可達index依序更新step
    
        for(i = 0; i < l-1; i++) {
            int e = nums[i];//可以走的最大步數
            while(e > 0) {
                if (i+e < l) {
                    step[i+e] = min(step[i]+1, step[i+e]);
                }
                e--;
            }
        }
        return step[l-1];
        */
        //想法二 , BFS 記錄當前這一跳的邊界end  Greedy（O(n) / O(1)）
        int end = 0, far = 0, jump = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            far = max(far, i+nums[i]);
            if (i == end) {// 走到當前這一跳的邊界, 必須再跳一次
                jump++;
                end = far;// 下一跳的邊界 = 目前能到的最遠處
            }
        }
        return jump;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {2,3,1,1,4};
    int r = 0;
    r = s.jump(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
