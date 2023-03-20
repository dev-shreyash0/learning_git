#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f( double ) ;

int main(void){

	double a = 0.0 ;
	double b = 5.0 ;
	double pricision = 0.000001 ;

	if( f(a) * f(b) > 0 ){
		printf("Not valid guess!"); 
	} else if( f(a) * f(b) == 0 ){
		if( f(a) == 0 ){
			printf("%lf is the root.\n",a) ;
		}else{
			printf("%lf is the root.\n",b) ;
		}
	} else{

		double mid = (a+b)/2 ;
		double lp = a , rp = b ;

		while( fabs(f(mid)) >= pricision ){

			if( f(lp)*f(mid) < 0 ){
				rp = mid ;
			} else{
				lp = mid ;
			}

			mid = (lp+rp)/2 ;

		}

		printf("%lf is the root.\n",mid) ;

	}

	return 0 ;

}

double f( double x ){

	return (pow(x,5)+(3*pow(x,2))-10) ;

}

