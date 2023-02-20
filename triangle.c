//L43~47 triangle type
#include<stdio.h>

int main(){
	int side1,side2,side3,s1q,s2q,s3q;//side length
	printf("Please enter three side lengths of triangle: \n");
	scanf("%d%d%d",&side1, &side2, &side3);
	if( side1*side2*side3  && (side1+side2 > side3) && (side1+side3 > side2) && (side2+side3 > side1) ){
		//all side lengths nonzero and sum of two lengths is greater than the third length.
		s1q = side1 * side1;
		s2q = side2 * side2;
		s3q = side3 * side3;
		if(side1 == side2 || side1 == side3 || side2 == side3){
			printf("The triangle is isosceles trangle.\n");
		}
		if(side1 == side2 && side2 == side3){
			printf("The triangle is regular triangle.\n");
		}
		if(( s1q+s2q == s3q) || (s1q + s3q == s2q) || (s2q + s3q == s1q)){
			printf("The triangle is right triangle.\n");
		}

	}
	return 0;
}
