/*
LC15_Valid Parenthesis String
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

bool checkValidSubString(char * s, int i, int j, int** cache){
  if(i > j ) return true;
  if(cache[i][j] != 0){
    if(cache[i][j] == 1){
      return true;
    }
    else if(cache[i][j] == -1){
      return false;
    }
  }
  if(s[i]==')'){
    //開頭為右括弧
    cache[i][j] = -1;
    return false;
  }
  else if (s[i] == '*'){
    //開頭星號當空字串用
    if(checkValidSubString(s,i+1,j,cache)) {
      cache[i][j] = 1;
      return true;
    }
  }
  
    // s[i+1],...s[j] 找一個對應的 ')'
    // (left)right: 找到一個左小，在其右邊找到一個右小or星號，若left,right 都為valid，則整個string valid
  // 開頭為左括弧，或者開頭為星號但是充當左括弧用
  for(int k = i+1; k <=j; k++){
      if(s[k] == ')' || s[k] == '*'){//找到index k 為右括弧或者星號時配對成功
        //printf("a=%d ",checkValidSubString(s,i+1,k-1));
        //printf("b=%d ",checkValidSubString(s,k+1,j));
        //printf("\n");
        if(checkValidSubString(s,i+1,k-1, cache) && checkValidSubString(s,k+1,j,cache)){
          cache[i][j] = 1;
          return true;
        }
      }
    }  
  cache[i][j] = -1;
  return false;
}
bool checkValidString(char * s){
  int len = strlen(s);
  //int cache[len][len];
  int ** cache = malloc(sizeof(int*)*len);//0 表示還沒算過, 1表示算過且為true, -1 表示算過且為false
  for(int i = 0; i < len; i++){
    cache[i] = calloc(len, sizeof(int));
  }
  //printf("len(s) is %d\n",len);
  // 給入起點和終點
  bool isValid = checkValidSubString(s, 0, len-1, cache);
  for(int i = 0;i < len; i++){
	free(cache[i]);
  }
  free(cache);
  return isValid;
  
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
