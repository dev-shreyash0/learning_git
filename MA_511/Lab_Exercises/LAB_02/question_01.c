#include <stdio.h>
#include <stdlib.h>

int main(void){

	int n ;
	printf("Enter the value of 'n' :: ");
	scanf("%d",&n);

	int seed ;
	printf("Enter the value of 'seed' :: ");
	scanf("%d",&seed);

	double * A = ( double * )malloc( n * sizeof(double) );

	srand(seed);

	for( int i = 0 ; i  < n ; i++ ){
	
		*(A+i) = rand()*0.001 ;
	
	}

	for( int i = 0 ; i < n ; i++ ){
	
		printf("%lf ",A[i]);
	
	}

	double max = A[0] ;
	int index = 0 ;

	for( int i = 1 ; i < n ; i++ ){
	
		if( A[i] > max ){
		max = A[i] ;
		index = i ;
		}
	
	}

        double max2 ;

	if( index == n ){
		max2 = A[index-1] ;
	} else{
		max2 = A[index+1] ;
	}

	for( int i = 0 ; i < n ; i++ ){
	
		if( A[i] != max && A[i] > max2 ){
		
			max2 = A[i] ;
		
		}
	
	}

	printf("\n");
	printf("Second largest number in randomly generated numbers is :: %lf.\n",max2);

	free(A);

	return 0 ;

}
