#include <stdio.h>
#include <math.h>
int main(void){

	double sum = 0 ;

	int i ;

	double fact = 1 ;

	for( i = 1 ; i <= 20 ; i++ ){
	    fact = (fact * i) ;
	    if( i % 2 == 0 ){
	       double d = exp(i) ;
	       sum = sum + (fact/d) ;
	    }
	}
         
	printf("Sum of even terms of given sequence %lf", sum );

}
