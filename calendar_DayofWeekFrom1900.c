/*
calendar_DayofWeekFrom1900
寫一個程式，輸入某年某月某日的，然後判斷該日是星期幾 ? ( 需考慮閏年 )
參考 1900年1月1日為星期一

目前使用的格里曆閏年規則如下：
  西元年分除以400可整除，為閏年。2月有29天
  西元年分除以4可整除但除以100不可整除，為閏年。1896是閏年 1900不是閏年
  西元年分除以4不可整除，為平年。
  西元年分除以100可整除但除以400不可整除，為平年 1900不是閏年 2000是閏年
  1901 / 1 / 1 為 星期二 , 365%7 = 1 
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int MAXSIZE;
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
int treeHeight(struct TreeNode* root){
  if(root == NULL) return 0;
  else{
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    return max(lh, rh)+1;
  }
}
/***************************************************************/
bool isLeap(int Y){
  if(Y%400 == 0 || Y%4 == 0 && Y %100 != 0){
    return true;
  }
  else{
    return false;
  }
}
int findDayofMonth(int Y, int M, int D){
  /*
  思路
  1.判斷Y是否為閏年
  2.計算1900年1月1日到Y年1月1日共經過多少天，得知Y年1月1日星期幾
  3.Y年1月1日到Y年M月D日有多少天 ，計算該天為星期幾
  */
  if(Y <1900){
    printf("Please enter year larger or equal to 1900\n");
    return -1;
  }
  if(M <1 || M > 12){
    printf("Please enter month from 1 to 12\n");
    return -1;
  }
  bool currLeap = isLeap(Y);
  int febDay = currLeap?29:28;
  if(D<1||D>31){
    printf("Please enter date from 1 to 31\n");
    return -1;
  }
  else if (M == 4 || M == 6 || M == 9 || M == 11){
    if(D > 30){
      printf("Please enter date from 1 to 30 for this month\n");
      return -1;
    }
  }
  else if(M == 2){
    if(currLeap){
      if(D > 29){
        printf("Please enter date from 1 to 29 for this month\n");
        return -1;  
      }
    }
    else{
      if(D > 28){
        printf("Please enter date from 1 to 28 for this month\n");
        return -1;  
      }
    }
  }
        
      
  int nowYear = 1900;
  int passDay = 0;
  while(nowYear != Y){
    passDay+=(isLeap(nowYear)?366:365);
    nowYear++;
  }
  passDay%=7;//(0~6 , mon ~ sun)
  int allMon[12] = {0};
  allMon[0] = 31;
  allMon[1] = febDay;
  allMon[2] = 31;
  allMon[3] = 30;
  allMon[4] = 31;
  allMon[5] = 30;
  allMon[6] = 31;
  allMon[7] = 31;
  allMon[8] = 30;
  allMon[9] = 31;
  allMon[10] = 30;
  allMon[11] = 31;
  for(int i = 0; i < M-1; i++){
    passDay+=allMon[i];
  }
  passDay+=(D-1);
  passDay%=7;
  return passDay+1;
}
/***************************************************************/
int main() {
  int year;
  int month;
  int date;
  printf("Year: ");
  scanf("%d",&year);
  printf("Month: ");
  scanf("%d",&month);
  printf("Date: ");
  scanf("%d",&date);
  int ans = findDayofMonth(year, month, date);
  char* dd = malloc(sizeof(char)*4);
  dd = "WRN";
  printf("%d/%d/%d is ",year,month,date);
  switch(ans){
    case 1:
      {
        dd = "MON";
        break;
      }
    case 2:
      {
        dd = "TUE";
        break;
      }
    case 3:
      {
        dd = "WED";
        break;
      }
    case 4:
      {
        dd = "THU";
        break;
      }
    case 5:
      {
        dd = "FRI";
        break;
      }
    case 6:
      {
        dd = "SAT";
        break;
      }
    case 7:
      {
        dd = "SUN";
        break;
      }
    default:
      {
        printf("Wrong answer!\n");
      }
  }
  printf("%s day\n",dd);
  free(dd);
  return 0;
}