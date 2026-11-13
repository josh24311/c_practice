/*
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/
#include <iostream>
#include <vector>
using namespace std;

int cmp(const void* pa, const void* pb )
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
    int removeDuplicates(vector<int>& nums) {
        //想法一: 利用原陣列非遞減特性, 紀錄當前cur_num, 若重複則跳過，若未重複則更新, s: O(1), T: O(n)
        /*
        int cur_num = -101 , r = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != cur_num) {
                cur_num = nums[i];
                nums[r] = cur_num;
                r++;
            }
        }
        nums.resize(r);
        return r;
        */
        //想法二, 邏輯同一只是不依賴硬性邊界
        if(nums.empty()) {//檢查為空
            return 0;
        }
        int r = 1;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[r-1]) {
                nums[r++] = nums[i];
            }
        }
        return r;
    }
};

int main() 
{
    Solution s;
    int r = 0;
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    r = s.removeDuplicates(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
