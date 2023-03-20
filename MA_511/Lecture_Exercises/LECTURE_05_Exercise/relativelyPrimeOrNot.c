#include <stdio.h>

int main(void){

	// Program to check whether given two positive integers are relatively prime or not.
	
	int A,B ;
	
	printf("Enter the value of integer 'A' :: ");
	scanf("%d",&A);
	printf("Enter the value of integer 'B' :: ");
	scanf("%d",&B);

	// Use Euclidean Algorithm to find the GCD of given numbers
	
	int dividend , divisor , remainder ;

	if( A > B ){
	
		dividend = A ;
		divisor = B ;
	 
	} else{
	
		divisor = A ;
		dividend = B ;

	}

	while( divisor != 0 ){

		remainder = dividend % divisor ;
	
		dividend = divisor ;
		divisor = remainder ;
	
	}

	int gcd = dividend ;

	if( gcd == 1 ){
	
		printf("Given integers %d and %d are relatively prime.\n",A,B);
	
	} else{
	
		 printf("Given integers %d and %d are not relatively prime.\n",A,B);

	}

	return 0 ;

}
