/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

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