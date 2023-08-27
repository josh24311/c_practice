/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false

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
Tree* createTree(int val){
  Tree* root = malloc(sizeof(Tree));
  root->val = val;
  root->left = NULL;
  root->right = NULL;
  return root;
}
void insertLeft(struct TreeNode* root, int val){
  root->left = createTree(val);
}
void insertRight(struct TreeNode* root, int val){
  root->right = createTree(val);
}



// {[]}
// (){}
// ([)]
// [({])}
// [()][[
// (()(
// (])                           0         3

bool isValid(char * s){
  char tmp[1000000];
  int flag = -1;
  
  while(*s){
    if(*s == ')'){
      if(flag >= 0 && tmp[flag] == '('){
        flag--;
      }
      else return false;
    }
    else if (*s == ']'){
      if(flag >= 0 && tmp[flag] == '['){
        flag--;
      }
      else return false;
    }
    else if (*s == '}'){
      if(flag >= 0 && tmp[flag] == '{'){
        flag--;
      }
      else return false;
    }
    else{
      tmp[++flag] = *s;
    }
  s++;  
  }
  
  return flag == -1;
}


  


int main() {
  char* s1 = malloc(sizeof(char)*2);
  char* s2 = malloc(sizeof(char)*6);
  char* s3 = malloc(sizeof(char)*2);
  char* s4 = malloc(sizeof(char)*4);
  char* s5 = malloc(sizeof(char)*4);
  char* s6 = malloc(sizeof(char)*6);
  char* s7 = malloc(sizeof(char)*1);
  s1[0] = '(';
  s1[1] = ')';
  
  s2[0] = '(';
  s2[1] = ')';
  s2[2] = '[';
  s2[3] = ']';
  s2[4] = '{';
  s2[5] = '}';

  s3[0] = '(';
  s3[1] = ']';

  s4[0] = '(';
  s4[1] = '[';
  s4[2] = ')';
  s4[3] = ']';
  
  s5[0] = '{';
  s5[1] = '[';
  s5[2] = ']';
  s5[3] = '}';
//  [({])}
  s6[0] = '[';
  s6[1] = '(';
  s6[2] = '{';
  s6[3] = ']';
  s6[4] = ')';
  s6[5] = '}';

  s7[0] = ']';

  
  
  printf("s1 is valid? %s\n",isValid(s1) == 1?"true":"false");
  printf("s2 is valid? %s\n",isValid(s2) == 1?"true":"false");
  printf("s3 is valid? %s\n",isValid(s3) == 
1?"true":"false");
  printf("s4 is valid? %s\n",isValid(s4) == 1?"true":"false");
  printf("s5 is valid? %s\n",isValid(s5) == 1?"true":"false");
  printf("s6 is valid? %s\n",isValid(s6) == 1?"true":"false");
  printf("s7 is valid? %s\n",isValid(s7) == 1?"true":"false");
  
  return 0;
}