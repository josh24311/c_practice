/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//L123 sort 5 int numbers
#include <stdio.h>
int all=5;
int main()
{
    int i, arr[5]={0},j,tmp,fl=0;
    printf("Enter %d number:\n",all);
    fflush(stdout);
    for(i=0;i<all;i++){
        scanf("%d",&arr[i]);
        
    }
    for(i=0;i<all-1;i++){
        for(j=0;j<all-i-1;j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        
    }
    
    printf("After bubble sort\n");
    for(i=0;i<all;i++){
        printf("%d ",arr[i]);
    }
    
   
    
    
    return 0;
}
