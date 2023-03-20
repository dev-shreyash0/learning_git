#include <stdio.h>
#include <math.h>

int isPrime( int , int ) ;
int primeSum( int ) ;

int main(void){

	int n ;
	printf("Enter the value of n :: ");
	scanf("%d",&n);


	printf("Prime Sum :: %d ",primeSum(n));

	return 0 ;

}

int isPrime( int n , int d ){

	if( d > sqrt(n) ){
		return 1 ;
	}

	if( n%d == 0 ){
		return 0 ;
	}

	return isPrime(n,d+1) ;

}

int primeSum( int n ){

	if( n == 1 ){
		return 0 ;
	}

	if( isPrime(n,2) ){
		return n+primeSum(n-1) ;
	}else{
		return primeSum(n-1) ;
	}

}
