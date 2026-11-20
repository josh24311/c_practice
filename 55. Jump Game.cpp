/*
55. Jump Game
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents 
your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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
    bool canJump(vector<int>& nums) {
        // 由左往右判斷, 每前進一個index , greedy紀錄"最遠可達"的變動 時間 O(n)、空間 O(1)
        int far = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (i > far)
                return false;//i 超出目前最遠可達範圍, 表示 i 本身到不了, 後面的位置也都到不了
            far = max(far, nums[i]+i);//從i開始跳 更新最遠可達
            if (far >= n-1)//代表最遠可達已經可以到終點, 後續無須再比較
                return true;
        }
        return true;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {1,0,1,0 }; // 3,2,1,0,4  2,3,2,0,4  2,0,0,1,4  2,3,0,1,4 
    bool r = 0;
    r = s.canJump(a);
    cout << "r = " << r << endl;

    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
