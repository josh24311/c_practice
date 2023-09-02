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

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int min(int a, int b){
  if(a < b) return a;
  else return b;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min3(int a, int b, int c){
  return min(min(a, b), c);
}
int max3(int a, int b, int c){
  return max(max(a, b), c);
}
typedef struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;

} Tree;
struct ListNode{
  int val;
  struct ListNode *next; 
} ;

/****************************************************************************************/
int maxProfit(int* prices, int pricesSize){
    //          7   1   5   3   6   4
    //max          -1   4   4   5   5
    //minval        1   1   1   1   1
    int minVal = prices[0];
    int max = -1;
    for(int i = 1; i < pricesSize; i++){
      //由小到大依序更新第n天最大收益
        if(prices[i] > minVal){
            max = (prices[i]-minVal) > max?(prices[i]-minVal):max;// -1
        }
        else{
          //更新最小買價
            minVal = prices[i] < minVal?prices[i]:minVal;// 1
        }
    }
    return max==-1?0:max;
}

/****************************************************************************************/
int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  int* ar1 = malloc(sizeof(int)*6);
  ar1[0] = 7;
  ar1[1] = 1;
  ar1[2] = 5;
  ar1[3] = 3;
  ar1[4] = 6;
  ar1[5] = 4;
  
  printf("max profit: %d\n",maxProfit(ar1,6));
  int* ar2 = malloc(sizeof(int)*5);
  ar1[0] = 7;
  ar1[1] = 6;
  ar1[2] = 4;
  ar1[3] = 3;
  ar1[4] = 1;
  printf("max profit: %d\n",maxProfit(ar2,5));
  
  
  
  return 0;
}