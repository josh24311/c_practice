/*
122. Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 10^4
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
        //想法一: tmp 紀錄當前區間最大收益 , 當出現prices[i] 不能使tmp更大時, 將 prices[i] 設定為下一次買點, 持續累計maxp 時間 O(n)、空間 O(1)
        /*
        int minv = prices[0], maxp = 0, tmp = 0;
        for(int i = 1; i < prices.size(); i++) {
            if ((prices[i] - minv) > tmp) {
                tmp = (prices[i] - minv);
            } else {
                maxp += tmp;
                tmp = 0;
                minv = prices[i];
            }
        }
        return maxp+tmp;
        */
        //想法二 greedy , 因為可以當天買當天賣, 只要持續累積相鄰兩天正差值即可 時間 O(n)，空間 O(1)
        int maxp = 0, dif = 0;
        for(int i = 1; i < prices.size(); i++) {
            dif = prices[i] - prices[i-1];
            if (dif > 0) {
                maxp += dif;
            }
        }
        return maxp;
    }
};

int main() 
{
    Solution s;
    vector<int> a = {1,2,1,2,0,2};// 1,2,1,2,0,2     7,1,5,3,6,4
    int r = 0;
    r = s.maxProfit(a);
    cout << "r = " << r << endl;
    for(int element:a){
        cout<<element<<" ";
    }
    return 0;
}
