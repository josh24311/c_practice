/*
LC26_Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int max(int a, int b){
  if(a>=b) return a;
  else return b;
}

int lcs(char * text1, char * text2, int m , int n, int** cache){
  //text1 : a b c d (e) 
  //text2 : a   c   (e)
  // 對 text1 最後一個字元來說有兩種可能
  //  1. 屬於 LCS
  //  2. 不屬於 LCS
  // 對 text2 最後一個字元來說有兩種可能
  //  1. 屬於 LCS
  //  2. 不屬於 LCS
  if(m == 0 || n == 0) return 0;
  if(cache[m][n] != -1){
    // 該組m,n 曾經算過 LCS長度  使用cache加速
    return cache[m][n];
  }

  int result;
  if(text1[m-1] == text2[n-1]) {
    // 若兩字串最後一個字元相同
    result =  lcs(text1,text2,m-1,n-1,cache) + 1;
  }
  else{
    // 兩字串最後一個字元不同，此時以下兩種找較大者
    // lcs(text1, text2-1) , lcs(text1-1, text2)
    int d1 = lcs(text1,text2,m,n-1,cache);
    int d2 = lcs(text1,text2,m-1,n,cache);
    if(d1 >= d2){
      result = d1;
    }
    else{
      result = d2;
    }  
  }

  cache[m][n] = result;
  return result;
  
}

int longestCommonSubsequence(char * text1, char * text2){
  int len1 = strlen(text1);
  int len2 = strlen(text2);
  int** cache = malloc(sizeof(int*)*(len1+1));
  for(int i = 0; i <= len1; i++){
    cache[i] = malloc(sizeof(int)*(len2+1));
  }
  for(int i = 0; i <= len1; i++){
    for(int j = 0; j <= len2; j++){
      cache[i][j] = -1;
    }
  }
  
  int result = lcs(text1,text2,len1,len2,cache);
  for(int i = 0; i <= len1; i++){
    free(cache[i]);
  }
  free(cache);
  return result;

}


int main() {
  char* a1 = malloc(sizeof(char)*5);
  a1[0] = 'a';
  a1[1] = 'b';
  a1[2] = 'c';
  a1[3] = 'd';
  a1[4] = 'e';

  char*a2 = malloc(sizeof(char)*3);
  a2[0] = 'a';
  a2[1] = 'c';
  a2[2] = 'e';

  char*b1 = malloc(sizeof(char)*3);
  b1[0] = 'a';
  b1[1] = 'b';
  b1[2] = 'c';

  char*b2 = malloc(sizeof(char)*3);
  b2[0] = 'a';
  b2[1] = 'b';
  b2[2] = 'c';

  char*c1 = malloc(sizeof(char)*3);
  c1[0] = 'a';
  c1[1] = 'b';
  c1[2] = 'c';

  char*c2 = malloc(sizeof(char)*3);
  c2[0] = 'd';
  c2[1] = 'e';
  c2[2] = 'f';

  printf("answer 1 is %d\n",longestCommonSubsequence(a1,a2));
  printf("answer 2 is %d\n",longestCommonSubsequence(b1,b2));
  printf("answer 3 is %d\n",longestCommonSubsequence(c1,c2));
  

  
  
  free(a1);
  free(a2);
  free(b1);
  free(b2);
  free(c1);
  free(c2);
  
  
  return 0;
}