#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793 

int main(void){

	// Program to print sum of first N terms in series expansion of sin(x)

	int N ;
	printf("Enter the value of 'N' :: ");
	scanf("%d",&N);

	double x ;
	printf("Enter the value of 'x'(in degrees) :: ");
	scanf("%lf",&x);

	x = (PI*x)/180 ;
	
	double sum = x ;

	int n = 1 ;
	double term = x ;

	for( int i = 1 ; i < N ; i++ ){

		term *= (pow((-1),i)*(pow(x,2)))/((n+1)*(n+2));
		sum += term ;
		n += 2 ;

	}


	printf("Sum of first %d  terms of series expansion of sin(%lf) is :: %lf.\n",N,x,sum);

	return 0 ;

}
