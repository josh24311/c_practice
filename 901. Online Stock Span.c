/*
901. Online Stock Span
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

int MAXSIZE;
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/*******************************************************************************/

typedef struct {
  int prices[10000];
  int end;
  int dp[10000];
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    return calloc(1,sizeof(StockSpanner));
}
// DP method
/*
    idx            0   1  2  3  4  5  6
    obj->prices    100 80 60 70 60 75 85
    obj->dp        1   1  1  2  1  4  6
    obj->end                             ^
    tmp            ^
    count          1
*/
int stockSpannerNext(StockSpanner* obj, int price) {
  obj->prices[obj->end] = price;
  obj->dp[obj->end] = 1;
  if(obj->end == 0){
    obj->end++;
    return obj->dp[obj->end-1];
  }
  int tmp = obj->end-1;
  while(tmp >= 0 && obj->prices[obj->end] >= obj->prices[tmp]){
    obj->dp[obj->end] += obj->dp[tmp];
    tmp-=obj->dp[tmp]; 
  }
  obj->end++;
  return obj->dp[obj->end-1];
}
// BF method
/* 
int stockSpannerNext(StockSpanner* obj, int price) {
  obj->prices[obj->end] = price;
  obj->end++;
  int curr = obj->end-1;// last day
  while(curr >= 0 && obj->prices[curr] <= price){
    curr--;
  }
  if(curr < 0){
    return obj->end;
  }
  return obj->end-1-curr;
}
*/
void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/****************************************************************************************/
int main() {
  StockSpanner* spanner = stockSpannerCreate();
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 100));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 80));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 60));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 70));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 60));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 75));
  printf("\n===> %d\n\n",stockSpannerNext(spanner, 85));
  
  




  stockSpannerFree(spanner);
  return 0;
}