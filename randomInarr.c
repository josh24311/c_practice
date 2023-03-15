/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    //printf("Hello World\n");
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int now,tmp,i;
    for(i=0;i<10;++i){ 
        now = rand() % (10-i) + i ;
        tmp = a[i];
        a[i] = a[now];
    	a[now] = tmp;
    }
    for(i=0;i<10;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
