/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
bool isHappy(int n);
int sqr(int n);
int main()
{
    int n;
    //printf("Hello World");
    n = 28;
    printf("n is HappyNum or not ? %d",isHappy(n));
    
    return 0;
}
bool isHappy(int n){
    int mnum = 0;
    int been[10];
    int i;
    for(i = 0;i<10;i++){
        been[i] = 0;
    }
    mnum = sqr(n);
    while(mnum != 1){
        for(i = 0; i < 10 ;i++){
            if(mnum == i && been[i] != 0){
                printf("Has repeat\n");
                return false;
            }
            else if(mnum == i && been[i] == 0){
                been[i] = 1;
                continue;
            }
        }
        mnum = sqr(mnum);
    }
    printf("FIND 1\n");
    return true;
    
    
}
int sqr(int m){
    int tmp;
    int a = 0;
    while(1){
        if(m >= 10){
            printf("m larger than 10 = %d\n",m);
            tmp = m % 10;
            printf("tmp = %d\n",tmp);
            a += tmp*tmp;
            printf("a = %d\n",a);
            m /= 10;
        }
        else{
            printf("m less = %d\n",m);
            a += m*m;
            printf("a = %d\n",a);
            if(a < 10){
                return a;
            }
            else{
                return sqr(a);
            }
            
        }
    }
    //printf("sqr = %d\n",sqr);
}