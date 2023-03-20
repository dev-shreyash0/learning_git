#include <stdio.h>
#include <math.h>

int main(void){

	// Program prints the roots of quadratic equation Ax^2 + Bx + C = 0 
	
	double A,B,C ;
	printf("Enter the value of coefficient of x^2 :: ");
	scanf("%lf",&A);
	printf("Enter the value of coefficient of x^1 :: ");
	scanf("%lf",&B);
	printf("Enter the value of coefficient of x^0 :: ");
	scanf("%lf",&C);

	double D = (B*B) - (4*A*C) ;

	if( D < 0 ){
	
		printf("No real roots exist for given equation.\n");
		
	}else if( D == 0 ){
	
		printf("Real and equal roots exist for given equation.\n");

		double root = ((-1)*B)/(2*A) ;

		printf("Roots of equation are %lf and %lf.\n",root,root);

	}else{
	
		printf("Real and distinct roots exist for given equation.\n");

		double sqD = sqrt(D);

		double root1 = (((-1)*B) - sqD)/(2*A) ;
		double root2 = (((-1)*B) + sqD)/(2*A) ;

		printf("Roots of equation are %lf and %lf.\n",root1,root2);
	
	}

	return 0 ;


}
