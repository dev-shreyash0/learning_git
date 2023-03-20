#include <stdio.h>

int main(void){
	
	// Program to find largest integer from given set.

	int N ;

	printf("Enter the cardinality of set from which largest integer is to be found :: ");
	scanf("%d",&N);

	int max ;

	printf("Enter the 1th number in set :: ");
	scanf("%d",&max);

	int i ;

	for( i = 2 ; i <= N ; i++ ){
	
		printf("Enter the %dth number in set :: ",i);
		int n ;
		scanf("%d",&n);

		if( n > max ){
		
			max = n ;

		}

	}

	printf("Largest integer of given set is :: %d.\n",max);

	return 0 ;

}
