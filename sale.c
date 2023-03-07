/*C language practice in L76 */
#include<stdio.h>

int main(){
	int num,money=0;
	while(1){
		printf("Please enter item number(1~5): \n");
		scanf("%d",&num);
		if(num == 0)
			break;
		else{
			printf("You bought item number %d\n",num);
			switch(num){
				case 1:
					money += 90;
					break;
				case 2:
					money += 75;
					break;
				case 3:
					money += 83;
					break;
				case 4:
					money += 89;
					break;
				case 5:
					money += 71;
					break;
				default:
					printf("Please enter number between 1 to 5\n");
			}
		}
	}
	printf("Total money is %d\n",money);
	
	return 0;
}
