/*
*hash table
12. Integer to Roman
Seven different symbols represent Roman numerals with the following values:
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Constraints:

1 <= num <= 3999
*/
#include <iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
      string res;
#if 0   
        1 <= num <= 3999
        10的次方倍最多連寫三個 - 300(CCC), 30(XXX)
        5開頭的字母不能連寫
        4.9 開頭的要用減法表示法- 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD)  900 (CM)
        Symbol	Value
        I	      1
        V	      5
        X	      10
        L	      50
        C	      100
        D	      500
        M	      1000
#endif
#if 0
        // method 1
        string res;
        int head = 0, i;
        while(num > 0) {
          head = num / 1000;
          if (head > 0) {
            for(i = 0; i < head; i++) {
              res.append("M");
            }
            num = num % 1000;
            continue;
          } else {
            head = num / 100;
            if (head > 0) {
              if (head == 4 || head == 9) {
                if (head == 4) {
                  res.append("CD");
                } else {
                  res.append("CM");
                }
              } else {
                if (head >= 5) {
                  res.append("D");
                  head -= 5;
                }
                for(i = 0; i < head; i++) {
                  res.append("C");
                }
              }
              num = num % 100;
              continue;
            } else {
              head = num / 10;
              if (head > 0) {
                if (head == 4 || head == 9) {
                  if (head == 4) {
                    res.append("XL");
                  } else {
                    res.append("XC");
                  }
                } else {
                  if (head >= 5) {
                    res.append("L");
                    head -= 5;
                  }
                  for(i = 0; i < head; i++) {
                    res.append("X");
                  }
                }
                num = num % 10;
                continue;
              } else {
                head = num % 10;
                if (head == 4) {
                  res.append("IV");
                } else if (head == 9) {
                  res.append("IX");
                } else {
                  if (head >= 5) {
                    res.append("V");
                    head -= 5;
                  }
                  for(i = 0; i < head; i++) {
                    res.append("I");
                  }
                }
                break;
              }
            }
          }          
        }
#else
        // hash table
        int values[] =    {1000, 900, 500, 400, 100,  90,  50,  40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0; i < 13 ; i++) {
          while(num >= values[i]) {
            res += symbols[i];
            num -= values[i];
          }
        }
#endif
        return res;
    }
};
int main() 
{
    Solution s;
    string ans;
    int q[] = {3749, 58, 1994, 3484, 520, 1800, 987, 43};
    for(int i = 0; i < sizeof(q)/sizeof(q[0]); i++) {//sizeof(q)/sizeof(q[0])
      ans = s.intToRoman(q[i]);
      cout << "ex" << (i+1) << ": " << ans << endl;
    }
//"MMMDCCXLIX"
//"LVIII"
//"MCMXCIV"
    
    return 0;
}