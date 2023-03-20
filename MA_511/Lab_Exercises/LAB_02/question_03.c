#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

	double x , eps ;
	printf("Enter the value of 'x' :: ");
	scanf("%lf",&x);
	printf("Enter the value of epsilon :: ");
	scanf("%lf",&eps);

	if( abs( exp(x) - 1 ) <  eps ){
	
		printf("Value of 'n' is :: %d.\n",(int)0);
		return 0 ;

	}

	double sum = 1 , term = 1 ;
	
	int n = 0 ;

	while( fabs( exp(x) - sum ) >= eps ){
	
		n++ ;
		term *= (x/n) ;
		sum += term ;
	
	}

	printf("Value of 'n' is :: %d.\n",n);
	
	return 0 ;


}	




