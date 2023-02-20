/*C language course practice in L41*/
#include<stdio.h>

int main(){
	int setm = 300,dism = 3000,guest;
	double dis = 0.8,pay;
	printf("Please enter how many guests :");
	scanf("%d",&guest);
	pay = guest * setm;
	if( pay >= dism){
		pay = pay * dis; 
	}
	printf("The guest must pay %f dollars\n",pay);

	return 0;
}
