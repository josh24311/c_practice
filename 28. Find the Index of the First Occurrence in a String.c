/*
28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

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

int strStr(char * haystack, char * needle){
  // m i s s i s s i p p i
  // i s s i p

  // l e e t c o d e
  // l e e t o
  
  int len1 = strlen(haystack);//11
  int len2 = strlen(needle);//5
  int count = 0;
  if(len2 > len1) return -1;
  
  for(int i = 0; i < len1; i++){
    for(int j = 0; j < len2; j++){
      if(i+count < len1 && needle[j] == haystack[i+count]){
        count++;
        if(j == len2-1){
          return i;
        }
        else{
          continue;
        }
      }
      else{
        count = 0;
        break;
      }
    }
  }
  return -1;
}

int main() {
  char* str1 = malloc(sizeof(char)*9);
  str1[0] = 's';
  str1[1] = 'a';
  str1[2] = 'd';
  str1[3] = 'b';
  str1[4] = 'u';
  str1[5] = 't';
  str1[6] = 's';
  str1[7] = 'a';
  str1[8] = 'd';

  char* str2 = malloc(sizeof(char)*3);
  str2[0] = 's';
  str2[1] = 'a';
  str2[2] = 'd';

  char* str3 = malloc(sizeof(char)*8);
  str3[0] = 'l';
  str3[1] = 'e';
  str3[2] = 'e';
  str3[3] = 't';
  str3[4] = 'c';
  str3[5] = 'o';
  str3[6] = 'd';
  str3[7] = 'e';

  char* str4 = malloc(sizeof(char)*5);
  str4[0] = 'l';
  str4[1] = 'e';
  str4[2] = 'e';
  str4[3] = 't';
  str4[4] = 'o';

  char* str5 = malloc(sizeof(char)*11);
  str5[0] = 'm';
  str5[1] = 'i';
  str5[2] = 's';
  str5[3] = 's';
  str5[4] = 'i';
  str5[5] = 's';
  str5[6] = 's';
  str5[7] = 'i';
  str5[8] = 'p';
  str5[9] = 'p';
  str5[10] = 'i';

  char* str6 = malloc(sizeof(char)*5);
  str6[0] = 'i';
  str6[1] = 's';
  str6[2] = 's';
  str6[3] = 'i';
  str6[4] = 'p';

  printf("1st same char of 1,2 : %d\n",strStr(str1, str2));
  printf("1st same char of 3,4 : %d\n",strStr(str3, str4));
  printf("1st same char of 5,6 : %d\n",strStr(str5, str6));
  
  
  return 0;
}