/*
169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <iostream>
#include <vector>
#include <cstdlib>
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
    int majorityElement(vector<int>& nums) {
        //Majority Element 勢必出現超過n/2 次
        //想法一, 排序後nums[2/n] 為解, S: O(1) , T: O(nlogn)
        /*
        if (nums.size() <= 2) {
            return nums[0];
        }
        int n = nums.size();
        qsort(nums.data(), n, sizeof(int), cmp);        
        return nums[n/2];
        */
        //想法二, Boyer-Moore 投票演算法 把 majority element 想成「正票」、其他所有元素都是「反票」。
        //每次遇到一個反票，就和一張正票互相抵銷。因為 majority 的數量超過一半，就算所有其他元素都用來抵銷它，最後仍然會剩下至少一張，所以最後的 candidate 必定是 majority。
        int candidate = 0, count = 0;
        for(int x: nums) {
            if (count == 0) candidate = x; // count == 0: 初始化或是 前綴的票已全部兩兩抵銷，從當前 x 重新計票
            count += (x == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {2,2,1,1,1,2,2};//2,2,1,1,1,2,2    3,2,3
    int r;
    r = s.majorityElement(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
