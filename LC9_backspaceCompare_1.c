/*
LC9_Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 
Follow up: Can you solve it in O(n) time and O(1) space?
*/
#include <stdio.h>
#include <stdbool.h>
bool backspaceCompare(char*, char*);
char* process(char*, int);
int main() {
  bool ans = false;
  char* A = "ab#c";
  char* B = "ad#c";
  char* C = "ab##";
  char* D = "c#d#";
  char* E = "a##c";
  char* F = "#a#c";
  char* G = "b";
  char* H = "z";
  
  ans = backspaceCompare(A, B);
  printf("answer is %s\n",ans == 1?"true":"false");
  return 0;
}
bool backspaceCompare(char * S , char * T){
  printf("S\t\t\t=\t%s\n",S);
  printf("T\t\t\t=\t%s\n",T);
  int len_S = strlen(S);
  int len_T = strlen(T);
  char* result_S = process((const)S, len_S);
  char* result_T = process((const)T, len_T);
  bool areEqual = strcmp(process((const)S, len_S),process((const)T, len_T)) == 0;
  free(result_S);
  free(result_T);
  
  return areEqual;
}
char* process(char* str, int len_str){
  char* result = malloc(sizeof(char)*(len_str+1));
  int j = 0;
  for(int i = 0 ; i < len_str; i++){
    if(str[i] != '#'){
      result[j] = str[i];
      j++;
    }
    else{
      if(j > 0){
        j--;  
      }
    }
  }
  result[j] = '\0';
  return result;
}
