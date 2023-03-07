/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<time.h>
#include<stdlib.h>
#include <stdio.h>

int main()
{
    srand(time(0));
    //printf("Hello World");
    int tr = 100000;
    int a,b;
    int n[11] = {0};
    for(int i =1; i <= tr; i++){
        a = rand() % 6 +1;
        b = rand() % 6 +1;
        n[a+b-2]++;
    }
    for(int i = 2;i <= 12;i++){
        printf("%d has %d\n",i,n[i-2]);
    }
    return 0;
}
