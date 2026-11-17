/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
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
    void rotate(vector<int>& nums, int k) {
       /*
       1 2 3 4 5 6 7
       7 1 2 3 4 5 6
       6 7 1 2 3 4 5
       5 6 7 1 2 3 4

       */
        //想法一, 額外陣列 S:O(n) , T:O(n)
        /*
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n ; i++) {
            res[(i+k)%n] = nums[i];
        }
        nums = res;
        */
        //想法二：三次反轉 , S:O(1) , T: O(n) 需include algorithm
        //原理 向右旋轉k步等同於將最後k個元素照順序搬到前k個
        int n = nums.size();
        k %= n;//k 有可能大於等於n , 先取餘數
        reverse(nums.begin(), nums.end());//翻轉整體, 使得最後k個元素跑到最前面 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.begin()+k);//翻轉前k個 5 6 7 4 3 2 1
        reverse(nums.begin()+k, nums.end());//翻轉後方n-k個 5 6 7 1 2 3 4
    }
};

int main() 
{
    Solution s;
    vector<int> a = {1,2,3,4,5,6,7};
    int r = 3;
    cout << "r = " << r << endl;
    s.rotate(a, r);
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
