/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int anum =5;
int main()
{
    
    int i,l=-1,r=-1;
    int arr[5] = {0};
    printf("Enter %d int :\n",anum);
    for(i=0;i<anum;i++){
        printf("%d: ",i+1);
        scanf("%d",&arr[i]);
    }
    while(!( r ==0)){
        int tmax=-1;
        int ab = -1;// for min abs
        int ind;
        printf("R :");
        scanf("%d",&r);
        printf("ANS: ");
        ab = r;
        for(i=0;i<anum;i++){
            
            if(abs(arr[i] - r) < ab ){
                ab = abs(arr[i] - r);
                ind = i;
            }
        }
        printf("%d\n",arr[ind]);
        
        

        printf("\n");
    }
    printf("=== END ===\n");
    
    
    return 0;
}
