/*
LC1_First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:
Input: n = 1, bad = 1
Output: 1
 
Constraints:

1 <= bad <= n <= 231 - 1
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
int firstBadVersion(int n) {
    long long first = 1, last = (long long)n+1;
    while(last > first){
        long long mid = (first + (last - first))/2;
        if(isBadVersion(mid) && !isBadVersion(mid-1)){
            return mid;
        }
        if(!isBadVersion(mid)){
            first = mid +1 ;
        }
        else{
            last = mid;
        }
    }
    return first;

}



int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  
  
  
  
  
  return 0;
}