/*
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
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
    int maxProfit(vector<int>& prices) {
        //想法一 , 由後往前一一比對, 紀錄當前最高收益 S:O(1) , T:O(n^2) : Time Limit Exceeded
        /*
        int i,j, max = 0, l = prices.size();
        for(i = l-1; i > 0; i--) {
            for (j = i-1; j >= 0; j--) {
                if ((prices[i] - prices[j]) > max) {
                    max = (prices[i] - prices[j]);
                }
            }
        }
        return max;
        */
        // 想法二 , 動態維護目前為止的最低價 minv , 持續更新maxp S:O(1) , T:O(n)
        int maxp = 0, minv = prices[0];

        for(int i = 1; i < prices.size() ; i++) {
            if (prices[i] > minv) {
                maxp = max((prices[i]-minv) , maxp);
            } else { //若當前值小於當前最小值, 則更新最小值index
                minv = prices[i];
            }
        }
        return maxp;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {7,1,5,3,6,4}; // 2,1,2,1,0,1,2
    int r = 0;
    r = s.maxProfit(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
