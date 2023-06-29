/*
LC16_Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }


bool checkValidString(char * s){
  int len = strlen(s);
  //考量到星號可詮釋為'(' or ')' or ""，數左括弧時要考量範圍
  int minCount = 0;//最少有幾個左括弧
  int maxCount = 0;//最多有幾個左括弧
  for(int i = 0; i < len; i++){
    if(s[i] == '('){
      minCount++;
      maxCount++;
    }
    else if (s[i] == ')'){//一個右括弧抵銷一個左括弧
      minCount--;
      maxCount--;
    }
    else if (s[i] == '*'){
      minCount--;//星號當右括弧
      maxCount++;//星號當左括弧
    }
    if(maxCount < 0){
      return false;
    }

    if(minCount < 0){
      minCount = 0;// ex: "*"，此時星號不能當右括弧用
    }
  }
  return minCount==0;
}

int main() {
  char sa[] = "()";
  char sb[] = "(*)";
  char sc[] = "(*))";
  char sd[] = "(((*)";
  char se[] = ")*";
  char sf[] = ")";
  printf("sa is valid? %s\n\n",(checkValidString(sa)==1)?"true":"false");
  printf("sb is valid? %s\n\n",(checkValidString(sb)==1)?"true":"false");
  printf("sc is valid? %s\n\n",(checkValidString(sc)==1)?"true":"false");
  printf("sd is valid? %s\n\n",(checkValidString(sd)==1)?"true":"false");
  printf("se is valid? %s\n\n",(checkValidString(se)==1)?"true":"false");
  printf("sf is valid? %s\n\n",(checkValidString(sf)==1)?"true":"false");
 
  return 0;
}
