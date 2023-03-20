#include <stdio.h>

int main(void){

	int m,n ;

	printf("Enter the degree if first polynomial :: ");
	scanf("%d",&m);

	printf("Enter the degree if second polynomial :: ");
        scanf("%d",&n);

	int A[m+1] , B[n+1] , C[(m*n)+1] ;

	printf("Enter the coefficients of first polynomial in increasing degree :: ");
	for( int i = 0 ; i < m+1 ; i++ ){
		scanf("%d",&A[i]);
	}

	printf("Enter the coefficients of secand polynomial in increasing degree :: ");
        for( int i = 0 ; i < n+1 ; i++ ){
                scanf("%d",&B[i]);
        }

	for( int i = 0 ; i < (m*n)+1 ; i++ ){
		C[i] = 0 ;
	}

		for( int aI = 0 ; aI <= m ; aI++ ){
			for( int bI = n ; bI >= 0 ; bI-- ){
				if(aI+bI<=m*n){
					C[aI+bI] += A[aI]*B[bI] ;
				}
			}			
		}

	for( int i = 0 ; i < (m*n)+1 ; i++ ){
		printf("%d ",C[i]);
	}

	return 0 ;

}
