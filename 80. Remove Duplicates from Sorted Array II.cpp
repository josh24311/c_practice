/*
80. Remove Duplicates from Sorted Array II
You are given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
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
        //想法一 更新時機: 重複第一次，或是不重複的第一次
        /*
        int k = 1, same = 0;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                if (same == 0) {
                    nums[k] = nums[i];
                    k++;
                    same++;
                }
            } else {
                nums[k] = nums[i];
                k++;
                if (same) {   
                    same = 0;
                }
            }
        }
        return k;
        */
        //想法二，同題目26，只是將允許重複的寬度變為2
        if (nums.size() <= 2) {
            return nums.size();
        }
        int k = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k-2]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main() 
{
    Solution s;
    int r = 0;
    vector<int> a = {1,1,1,2,2,3}; // {1,2,3,4,5}  {0,0,1,1,1,1,2,3,3} {1,1,1,2,2,3}
    r = s.removeDuplicates(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
