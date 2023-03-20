#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func( int * , double );

int main( void ){

	int A[3] ;
	int B[3] ;

	printf("Enter the coefficients of first polynomial :: ");
	for( int i = 0 ; i < 3 ; i++ ){
		scanf("%d",&A[i]);
	}

	printf("Enter the coefficients of second polynomial :: ");
        for( int i = 0 ; i < 3 ; i++ ){
                scanf("%d",&B[i]);
        }

	int C[3] ;
	for( int i = 0 ; i < 3 ; i++ ){
		C[i] = A[i] - B[i] ;
	}

	int a = C[2] , b = C[1] , c = C[0] ;

	double d = (b*b) - (4*a*c) ;
	
	if( d < 0 ){
		printf("No Intersection");
	} else if( d == 0 ){
		printf("Polynomials touch at below point :: \n");
		double x = (-1*b)/(2*a) ;
		double y = func(A,x) ;
		printf(" x = %.2lf , y = %.2lf \n", x,y);
	} else{
	
		printf("Polynomials intersect at below two points :: \n" ) ;

		double d1 = sqrt(d) ;

		double x1 = ((-1*b)-d1)/(2*a) ;
	 	double x2 = ((-1*b)+d1)/(2*a) ;
		
		double y1 = func(A,x1) ;
		double y2 = func(A,x2) ;

		printf(" x1 = %.2lf , y1 = %.2lf \n", x1,y1);
		printf(" x2 = %.2lf , y2 = %.2lf \n", x2,y2);

	}

	return 0 ;

}

double func( int *C , double x ){

	double y = 0.0 ;

//	printf("%lf ",x) ;
	for( int i = 0 ; i < 3 ; i++ ){
		double a = C[i] ;
//		printf("%lf ",a) ;
		double b = pow(x,i) ;
//		printf("%lf \n",b);
		y = y + (a*b) ;
	}

//	printf("%lf\n",y);

	return y ;

}
