/*C language practice in L66  */
/*Input ID , output according name*/
#include<stdio.h>

int main(){
	int id;
	printf("Please enter ID : \n");
	fflush(stdout);
	scanf("%d",&id);
	switch(id){
		case 2:
			printf("John\n");
			break;
		case 13:
			printf("Mary\n");
			break;
		case 16:
			printf("Amy\n");
			break;
		default:
			printf("Not found\n");
	}
	return 0;
}
