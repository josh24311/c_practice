/*
70. Climbing Stairs


You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
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
int climbStairsSub(int n, int* cache){
  for(int i = 3; i <= n; i++){
    cache[i] = cache[i-1]+cache[i-2];
  }
  return cache[n];
}
int climbStairs(int n){
  
  if(n == 1 || n == 2) return n;
  int* cache = malloc(sizeof(int)*(n+1));
  cache[0] = -1;
  cache[1] = 1;
  cache[2] = 2;
  int ans =  climbStairsSub(n, cache);
  free(cache);
  return ans;

}
/****************************************************************************************/
int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  printf("ans 1: %d \n",climbStairs(2));
  printf("ans 2: %d \n",climbStairs(3));
  
  
  
  return 0;
}