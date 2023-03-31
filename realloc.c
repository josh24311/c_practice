/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//L186 realloc memory

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* numbers = 0; // point to NULL
    int length = 0; //number input by far
    while(1){
        int input;
        scanf("%d",&input);
        if(input == 0) break;
        numbers  =realloc(numbers, sizeof(int) * (length + 1));
        numbers[length] = input;
        length++;
    }
    printf("Numbers: ");
    for(int i=0; i< length; i++){
        printf("%d ",numbers[i]);
    }
    printf("\n");
    return 0;
}
