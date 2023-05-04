#include <stdio.h>
#include <stdbool.h>
int next_n(int);
bool contains(int*, int, int);
bool isHappy(int);
int main()
{
    int n;
    printf("Enter n: ");
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
bool isHappy(int n){
    int slow = n;
    int fast = n;
    do{
        slow = next_n(slow);
        fast = next_n(next_n(fast));
    }while(slow != fast);
    
    return slow == 1;
}