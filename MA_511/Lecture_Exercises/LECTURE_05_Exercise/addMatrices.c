#include <stdio.h>

int main(void){

	int M , N ;
	printf("Enter number of rows in matrix :: ");
	scanf("%d",&M);
	printf("Enter number of columns in matrix :: ");
	scanf("%d",&N);

	double A[M][N] , B[M][N] , sum[M][N] ;

	printf("Enter the entries in matrix A (use spaces between two entries and enter row wise) :: ");

	for( int i = 0 ; i < M ; i++ ){
	
		for( int j = 0 ; j < N ; j++ ){
		
			scanf("%lf",&(A[i][j]));
			sum[i][j] = 0 ;
		
		}
	
	}

	printf("Enter the entries in matrix B (use spaces between two entries and enter row wise) :: ");

        for( int i = 0 ; i < M ; i++ ){

                for( int j = 0 ; j < N ; j++ ){

                        scanf("%lf",&(B[i][j]));
			sum[i][j] = A[i][j]+B[i][j] ;

                }

        }
	
	for( int i = 0 ; i < M ; i++ ){

                for( int j = 0 ; j < N ; j++ ){

                        printf("%lf ",sum[i][j]);

                }

		printf("\n");

        }

	return 0 ;

}
