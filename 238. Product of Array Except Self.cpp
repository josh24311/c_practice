/*
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to 
the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

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
/*
for i = 0 , nums[1]*nums[2]*nums[3]
for i = 1 , nums[0]*nums[2]*nums[3]
for i = 2 , nums[0]*nums[1]*nums[3]
for i = 3 , nums[0]*nums[1]*nums[2]
ex: i = 1 , r = 1*3*4 = 12 = (1*2*3*4)/2 , 但題目規定不能用除法

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //想法一 , 兩層 for 但T:O(n^2)
        /*
        int n = nums.size();
        vector<int> r(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (j == i) continue;
                r[i] *= nums[j];
            }
        }
        return r;
        
        //想法二 左邊乘積 × 右邊乘積   answer[i] 就是「i 左邊所有元素的乘積」乘上「i 右邊所有元素的乘積」，不需要除法 , O(n) 時間 / O(n) 額外空間
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i-1];  //最後形成 1 1 2 6
        }
        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1]; //最後形成  24 12 4 1
        }
        for(int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
        */
        //想法三, 參考二 先把 ans 當作 left 用，再從右往左用一個變數 suffix 累乘 , O(n) 時間 / O(1) 額外空間
        int n = nums.size();
        vector<int> ans(n,1);
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1]; //左邊乘積
        }
        int suffix = 1;//累乘用
        for(int i = n-1; i >= 0; i--) {
            ans[i] *= suffix; // 左乘積 * 右乘積
            suffix *= nums[i];//更新當前右乘積
        }
        return ans;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {1,2,3,4};//-1,1,0,-3,3
    //int r = 0;
    //cout << "r = " << r << endl;
    vector<int> r = s.productExceptSelf(a);
    for(int element:r){
        cout<<element<<" ";
    }
    return 0;
}
