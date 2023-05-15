/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int next_n(int);
bool contains(int*, int, int);
bool isHappy(int);
int main()
{
    int n ;
    printf("Please input n: ");
    fflush(stdin);
    scanf("%d",&n);
    printf("n is a happyNumber ? %s\n",isHappy(n)? "True" : "False");

    return 0;
}
int next_n(int n){
    int r =  0;
    while(n != 0){
        int d = n % 10;
        r += d * d; 
        n /= 10;
    }
    return r;
}
bool contains(int* history, int size, int n){
    for(int i = 0; i < size ; i++){
        if(history[i] == n){
            return true;
        }
    }
    return false;
}
bool isHappy(int n){
    int history[10000];
    int size = 0;
    while(!contains(history, size, n)){
        history[size] = n;
        size++;
        
        n = next_n(n);
    }
    
    return n==1;
}
