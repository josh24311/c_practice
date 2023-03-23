//L156 swap two int with function using pointer concept
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{

    int *countAddr;
    int a = 3,b = 5;
    printf("a= %d\n",a);
    printf("b= %d\n",b);
    swap(&a,&b);
    printf("a now = %d\n",a);
    printf("b now = %d\n",b);
    return 0;
}
