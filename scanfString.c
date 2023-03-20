/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void str_read(char[]);

int main()
{
    //printf("Hello World");
    char str[15];
    str_read(str);
    printf("%s\n",str);
    return 0;
}
void str_read(char str[] ){
    int i=0;
    while(1){
        scanf("%c",&str[i]);
        if(str[i] == '\n')
            break;
        i++;
    }
    str[i] = '\0';
    
}