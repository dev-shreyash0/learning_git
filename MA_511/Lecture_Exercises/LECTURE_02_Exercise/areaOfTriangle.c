#include <stdio.h>
#include <math.h>

int main(void){
	
	// Program to print the area of triangle of given side lengths A,B,C 
	

	double A,B,C ;
	
	printf("Enter the value of side 'A' of tringle :: ");
	scanf("%lf",&A);

	printf("Enter the value of side 'B' of tringle :: ");
	scanf("%lf",&B);

	printf("Enter the value of side 'C' of tringle :: ");
	scanf("%lf",&C);

	double s = (A+B+C)/2 ;

	double area = sqrt(s*(s-A)*(s-B)*(s-C)); // Heron's formula

	printf("Area of given triangle is :: %lf.\n",area);

	return 0 ;


} 

