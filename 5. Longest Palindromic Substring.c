/*
#DP

5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
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

char* longestPalindrome(char* s) {
  /* 
   i/j  
        0 1 2 3 4
        b a b a d
   0 b  T F ?
   1 a    T
   2 b      T
   3 a        T
   4 d          T
   (1) 斜對角都為單一char 回文定義必為 T
   (2) 開始填其他 i 開頭 j 結尾的 arr element
       2.1 例如 i = 0(對應b), j = 1(對應a), 此兩char不等, 則此格填F
       2.2 例如 i = 0(對應b), j = 2(對應b), 此兩char相等, 此時則判斷arr[i+1][j-1] 是否為T, 是的話arr[i][j] 才填T
   (3) 若有新格子被填T，更新result長度

  */
  if(s == NULL || strlen(s) == 1)return s;  
  int len = strlen(s);
  bool dp[len][len];
  // 初始化动态规划表
  for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
          dp[i][j] = false;
      }
  }

  // 单字符都是回文
  for (int i = 0; i < len; i++) {
      dp[i][i] = true;
  }
  
  int curMax = 1;
  int head = 0;
  // 填表順序 例如i = 0, j = 3 兩者char相等，此時需判斷 i = 1 , j = 2 是否為T，先決條件是arr[1][2] 已經被決定
  // j = 0, i = 0
  // j = 1, i = 0, 1
  // j = 2, i = 0, 1, 2
  for(int j = 1; j < len; j++){
    for(int i = 0; i < j; i++){
      if(s[i] == s[j]){
        if((j - i <= 2) || dp[i+1][j-1]){// j - i <= 2 時 子字串必為回文
          dp[i][j] = true;
          if((j - i + 1) > curMax){
            curMax = j - i + 1;
            head = i;
          }
        }
      }
    }
  }
  char* result = malloc(sizeof(char)*(curMax+1));
  for(int i = 0; i < curMax; i++){
    result[i] = s[head + i];
  }
  result[curMax] = '\0';

  return result;
  
}

/***************************************************************/

int main() {
  char arr1[] = "babad";
  char arr2[] = "cbbe";
  char arr3[] = "bcbca";
  char* ans1 = longestPalindrome(arr1);
  for(int i = 0; ans1[i] != '\0'; i++){
    printf("%c",ans1[i]);
  }
  printf("\n\n");
  char* ans2 = longestPalindrome(arr2);
  for(int i = 0; ans2[i] != '\0'; i++){
    printf("%c",ans2[i]);
  }
  printf("\n\n");
  char* ans3 = longestPalindrome(arr3);
  for(int i = 0; ans3[i] != '\0'; i++){
    printf("%c",ans3[i]);
  }
  return 0;
}