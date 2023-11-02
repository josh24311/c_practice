/*
#DP
#strategy
1025. Divisor Game
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.



Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


Constraints:

1 <= n <= 1000
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

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
//define queue
#define MAX_N 30



/***************************************************************/

bool divisorGame(int n){
  if(n == 1){
    return false;
  }
  if(n == 2){
    return true;
  }
  //DP : T:O(n^2) , S:O(n)
  bool dp[n+1];
  dp[0] = false;
  dp[1] = false;
  dp[2] = true;
  // dp[i] 表示 Alice 拿到 i 這個數時是否可以獲勝
  for(int i = 3; i <= n; i++){
    dp[i] = false;// 先假設Alice拿到i輸
    for(int j = 1; j < i; j++){   
      if((i % j == 0) && (!dp[i-j])){// 若找到一個數j 可以整除 i 且 拿到i-j 這個數的人(Bob)會輸
        dp[i] = true;
        break;// alice 必拿 j -> alice 必勝
      }
    }
  }
  return dp[n];


  
  /*
  // opt ans T:O(1) , S:O(1)
  return (n % 2 == 0) ;
  */
}


/***************************************************************/

int main() {
  printf("ans1 = %s\n",divisorGame(2)?"Alice wins":"Bob wins");
  printf("ans2 = %s\n",divisorGame(3)?"Alice wins":"Bob wins");
  printf("ans3 = %s\n",divisorGame(8)?"Alice wins":"Bob wins");
  return 0;
}