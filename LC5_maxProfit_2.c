/******************************************************************************
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.




*******************************************************************************/

#include <stdio.h>
int maxProfit(int*, int);
int main()
{
    int numsSize = 5;
    int nums[5] = {1, 2, 3, 4, 5};
    
    printf("Best profit is %d\n",maxProfit(nums,numsSize));

    return 0;
}
int maxProfit(int* prices, int pricesSize){
    //method 2 只看相鄰兩天
    int total = 0;
    for(int i = 0; i+1 < pricesSize; i++){
        if(prices[i] < prices[i+1]){
            total += prices[i+1] - prices[i];
        }
    }
    return total;
}
