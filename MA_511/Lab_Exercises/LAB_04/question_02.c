#include <stdio.h>

int calculateOddSum( int ) ;

int main(void){

	int n ;
	printf("Enter the natural number :: ");
	scanf("%d",&n);
	
	if( n%2 == 0 ){
		n-- ;
	}
	int oddSum = calculateOddSum(n);

	printf("Odd Sum is :: %d\n",oddSum);
	
	return 0 ;
}

int calculateOddSum( int n ){

	if( n == 1 ){
		return 1 ;
	}

	return n+calculateOddSum(n-2) ;

}


