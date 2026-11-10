/*
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //想法一: 將b依序擺到a的尾端之後用qsort重新排序
        /*
        int i = m, j = 0;
        while(i != m+n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        qsort(nums1.data(), m+n, sizeof(int), cmp);// O((m+n) * log(m+n))
        */
        //想法二, 利用原陣列非遞減特性, 由後往前排序 s: O(1) , T: O(m+n)
        int i = m-1;
        int j = n-1;//nums2 正在存取的index , 目標要把此index放到0為止
        int k = m+n-1;//nums1 最尾端index
        while(j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() 
{
    Solution s;
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    int m = 3, n = 3;
    s.merge(a,m,b,3);
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
