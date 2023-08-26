/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

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

char * longestCommonPrefix(char ** strs, int strsSize){
  /*
  Input: strs = ["flower","flight","flow"]
  Output: "fl"
  
  Input: strs = ["dog","racecar","car"]
  Output: ""
  */
  if(strsSize == 0) return "";
  
  int i,j;
  char* temp = strs[0];
  
  for(i = 1; i < strsSize; i++){
    j = 0;
    while(temp[j] && strs[i][j] && temp[j] == strs[i][j]){
      j++;
      
    }
    temp[j] = '\0';
    
    //1 round : f l \0 w e r
    //2 round : f l \0 w \0 r 
    
  }
  

  return temp;
}
int main() {
  char** str1 = malloc(sizeof(char*)*3);
  str1[0] = malloc(sizeof(char)*6);
  str1[1] = malloc(sizeof(char)*6);
  str1[2] = malloc(sizeof(char)*4);
  str1[0][0] = 'f';
  str1[0][1] = 'l';
  str1[0][2] = 'o';
  str1[0][3] = 'w';
  str1[0][4] = 'e';
  str1[0][5] = 'r';

  str1[2][0] = 'f';
  str1[2][1] = 'l';
  str1[2][2] = 'o';
  str1[2][3] = 'w';
  
  str1[1][0] = 'f';
  str1[1][1] = 'l';
  str1[1][2] = 'i';
  str1[1][3] = 'g';
  str1[1][4] = 'h';
  str1[1][5] = 't';

  char** str2 = malloc(sizeof(char*)*3);
  str2[0] = malloc(sizeof(char)*3);
  str2[1] = malloc(sizeof(char)*7);
  str2[2] = malloc(sizeof(char)*3);
  str2[0][0] = 'd';
  str2[0][1] = 'o';
  str2[0][2] = 'g';

  str2[1][0] = 'r';
  str2[1][1] = 'a';
  str2[1][2] = 'c';
  str2[1][3] = 'e';
  str2[1][4] = 'c';
  str2[1][5] = 'a';
  str2[1][6] = 'r';

  str2[2][0] = 'c';
  str2[2][1] = 'a';
  str2[2][2] = 'r';

  printf("Longest common prefix of str1 : %s\n",longestCommonPrefix(str1,3));
  printf("Longest common prefix of str2 : %s\n",longestCommonPrefix(str2,3));
  
  return 0;
}