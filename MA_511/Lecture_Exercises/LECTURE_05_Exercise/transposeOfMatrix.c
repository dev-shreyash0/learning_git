#include <stdio.h>

int main(void){

	int N ;
	printf("Enter the order of square matrix :: ");
	scanf("%d",&N);

	double A[N][N] ;

	printf("Enter the entries of matrix A row wise with spaces between them :: ");

	for( int i = 0 ; i < N ; i++ ){
		for( int j = 0 ; j < N ; j++ ){
			scanf("%lf",&A[i][j]);
		}
	}

	double B[N][N] ;

	for( int i = 0 ; i < N ; i++ ){
                for( int j = 0 ; j < N ; j++ ){
                        B[i][j] = A[j][i] ;
                }
        }

	for( int i = 0 ; i < N ; i++ ){
                for( int j = 0 ; j < N ; j++ ){
                        printf("%lf ",B[i][j]);
                }
		printf("\n");
        }

	return 0 ;

}
