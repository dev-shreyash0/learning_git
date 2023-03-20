#include <stdio.h>
#include <math.h>

double valueOfPoly( double * , int , double ) ;

int main(void){

	double a , b ;
	printf("Enter the value of 'a' :: ");
	scanf("%lf",&a) ;
	printf("Enter the value of 'b' :: ");
	scanf("%lf",&b) ;

	int n , m ;

	printf("Enter the degree of first polynomial :: ");
	scanf("%d",&n);

	printf("Enter the degree of second polynomial :: ");
	scanf("%d",&m);

	double A[n+1] , B[m+1] ;
	
	printf("Enter the coefficients of the first polynomial in increasing order of degree :: ");

	for( int i = 0 ; i < n+1 ; i++ ){
		scanf("%lf",&A[i]);
	}

	printf("Enter the coefficients of the second polynomial in incresing order of degree :: ");

	for( int i = 0 ; i < m+1 ; i++ ){
		scanf("%lf",&B[i]);
	}

	long intervals ;

	printf("Enter the number of equal intervals in which given interval should be divided :: ");
	scanf("%ld",&intervals);

	int flag = 0 ;

	if( valueOfPoly(A,n+1,a) - valueOfPoly(B,m+1,a) > 0 ){
		flag++ ;
	} else if( valueOfPoly(A,n+1,a) - valueOfPoly(B,m+1,a) < 0 ){
		flag-- ;
	} else{
	
	}
	if( valueOfPoly(A,n+1,b) - valueOfPoly(B,m+1,b) > 0 ){
		flag++ ;
	} else if ( valueOfPoly(A,n+1,b) - valueOfPoly(B,m+1,b) < 0 ){
		flag-- ;
	} else{
	
	}

	for( long i = 1 ;  i < intervals ; i++ ){
	
		if(valueOfPoly(A,n+1,a+(i*((b-a)/intervals))) - valueOfPoly(B,m+1,a+(i*((b-a)/intervals))) > 0){
			flag++ ;
		} else if( valueOfPoly(A,n+1,a+(i*((b-a)/intervals))) - valueOfPoly(B,m+1,a+(i*((b-a)/intervals))) < 0 ){
			flag-- ;
		}
	
	}

	if( flag == intervals+1 ){
		printf(" f > g\n");
	} else if( flag == (-1)*(intervals+1) ){
		printf(" f < g\n");
	} else{
		printf("f and g intersect\n");
	}	

	return 0 ;

}



double valueOfPoly( double * A , int size , double x ){

	double value = 0 ;

	for( int i = 0 ; i < size ; i++ ){
	
		value += A[i]*pow(x,i) ;
	
	}

	return value ;

}
