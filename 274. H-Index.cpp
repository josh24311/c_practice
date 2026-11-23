/*
274. H-Index
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: 
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:
4個值大於等於1
3個值大於等於2
3個值大於等於3

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
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
    int hIndex(vector<int>& citations) {
        //想法一 , 已知總共有幾篇, 從該數字開始往下確認 T: O(n²) , S: O(1)
        /*
        int n = citations.size();
        int r = n, count = 0;
        for(int i = n; i > 0; i--) {
            for(int j = 0; j < n; j++) {
                if (citations[j] >= i) {
                    count++;
                }
            }
            if (count >= i) {
                return i;
            }
            count = 0;
        }
        return 0;
        
        //想法二 , 先排序  T: O(nlogn) , S: O(1)
        int n = citations.size();
        sort(citations.begin(), citations.end());// 0 1 3 5 6
        for(int i = 0; i < n; i++) {
            int h = n-i;
            if (citations[i] >= h) {
                return h;
            }
        }
        return 0;
        */
        //想法三 關鍵觀察：h 不可能超過 n，所以引用數大於 n 的論文，都可以當成引用數 n。 T: O(n) , S: O(n)
        int n = citations.size();//紀錄引用數0~n的文章各自有幾篇
        vector<int> cnt(n+1, 0);//宣告長度n+1
        // 以  3,0,6,1,5 為例 -> cnt[0] = 1 , cnt[1] = 1, cnt[2] = 0, cnt[3] = 1, cnt[4] = 0, cnt[5] = 2
        for(int i = 0; i < n; i++) {
            cnt[min(citations[i], n)]++;
        }
        int papers = 0;
        for(int h = n; h >= 0; h--) {
            papers += cnt[h];
            if (papers >= h) {
                return h;
            }
        }
        return 0;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {3,0,6,1,5};//  1,3,1  3,0,6,1,5 0,0,2
    int r = 0;
    r = s.hIndex(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
