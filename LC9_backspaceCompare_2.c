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
#include <string.h>

bool backspaceCompare(char*, char*);
char* process(char*);
int main() {
  bool ans = false;
  //char* A = "ab#c";
  //char* B = "ad#c";
  char A[5] = {'a','b','#','c'};
  char B[5] = {'a','d','#','c'};
  /*
  //指標指向雙引號字串，沒辦法修改單一元素
  //陣列指向雙引號字串，可以修改單一元素
  char* G = "b";// G[0] = 'a' , 會FAIL
  char* H = "z";// H[0] = 'a' , 會FAIL
  
  */
  char G[2] = {'b'};
  char H[2] = {'z'};
  
  ans = backspaceCompare(G,H);
  printf("answer is %s\n",ans == 1?"true":"false");
  return 0;
}
char* process(char* str)
{
    // O(1): 不另外使用記憶體存陣列
    int len_str = strlen(str);
    int j = 0;
    for(int i = 0 ; i < len_str; i++){
        if(str[i] != '#'){
            str[j] = str[i];
            j++;
        }
        else{
            if(j > 0){
                j--;
            }
        }
    }
    str[j] = '\0';
    return str;
}    
bool backspaceCompare(char * s, char * t){
    return strcmp(process(s), process(t)) ==0;
}
