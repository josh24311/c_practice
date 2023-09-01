/*
67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
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
char * addBinary(char * a, char * b){
  int la = strlen(a);
  int lb = strlen(b);
  int len = la>lb?la:lb;
  char* result = (char*)malloc(len+1);
  result[len] = '\0';
  int carry = 0;
  
  for(int i = 0; i < len; i++){
    if(la > 0){
      carry+=a[--la]-'0';
    }
    if(lb > 0){
      carry+=b[--lb]-'0';
    }
    result[len-1-i] = (carry%2) +'0';
    carry = carry/2;
  }
  if(carry == 1){
    //仍進位
    /*
    0 0 -> 1 0 0
    
    */
    result = (char*)realloc(result, len+2);
    result[len+1] = '\0';
    for(int i = len; i > 0; i-- ){
      result[i] = result[i-1];
    }
    result[0] = '1';
  }

  return result;
}



int main() {
  //char* s1 = malloc(sizeof(char)*2);
  // s1[0] = '';
  //int* ar1 = malloc(sizeof(int)*3);
  // ar1[0] = ;
  //int* rt1 = malloc(sizeof(int)*3);
  // rt1[0] = 3;
  
  
  char* s1 = malloc(sizeof(char)*2);
  s1 = "11";
  

  
  char* s2 = malloc(sizeof(char)*1);
  s2 = "1";

  char* s3 = malloc(sizeof(char)*4);
  s3 = "1010";

  char* s4 = malloc(sizeof(char)*4);
  s4 = "1011";

  char* rs1 = addBinary(s1, s2);
  int lenr = strlen(rs1);
  printf("\nresult: ");
  for(int i = 0; i < lenr; i++){
    printf("%c ",rs1[i]);
  }
  printf("\n");
  char* rs2 = addBinary(s3, s4);
  lenr = strlen(rs2);
  printf("\nresult: ");
  for(int i = 0; i < lenr; i++){
    printf("%c ",rs2[i]);
  }
  
  
  return 0;
}