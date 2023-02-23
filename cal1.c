/*C language practice in L62 */
#include<stdio.h>

int main(){
	int a,b;
	char op;
	float ans;
	scanf("%d%c%d",&a ,&op, &b);
	if(op == '+'){
		ans = a + b;
	}
	else if(op=='-'){
		ans = a - b;
	}
	else if(op=='*'){
		ans = a * b;
	}
	else if(op=='/'){
		ans = (float)a / b;
	}

	printf("Answer : %f\n",ans);
	return 0;
}
