#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926536

int main(void){

        // Program to print sum of terms in series expansion of sin(x) till the next term is smaller than 10^(-5)

        double x ;
        printf("Enter the value of 'x' :: ");
        scanf("%lf",&x);

        double sum = 0 ;

       	x = (PI*x)/180 ;

        int n = 1 ;
        double term = x ;
	int i = 1 ;

        while( fabs(term) >= 0.00005 ){
		
		sum += term ;
                term *= (pow((-1),i)*(pow(x,2)))/((n+1)*(n+2));
                n += 2;
		i++ ;

	}	

        printf("Sum of series expansion of sin(%lf) till next term is smaller than 10^(-5) is :: %lf.\n",x,sum);

        return 0 ;

}

