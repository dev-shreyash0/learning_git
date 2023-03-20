#include <stdio.h>

int main(void){

	int M1 , M2 , N1 , N2 ;

	printf("Enter the number of rows in first matrix :: ");
	scanf("%d",&M1);
	printf("Enter the number of columns in first matrix :: ");
        scanf("%d",&N1);
	printf("Enter the number of rows in second matrix :: ");
        scanf("%d",&M2);
	printf("Enter the number of columns in first matrix :: ");
        scanf("%d",&N2);

	if( N1 != M2 ){
		printf("Matries cannot be multipied.\n");
	}

	double A[M1][N1] , B[M2][N2] , mul[M1][N2] ;

	printf("Enter the entries of matrix A in row wise manner with spaces between each entry :: ");

	for( int i = 0 ; i < M1 ; i++ ){
		for( int j = 0 ; j < N1 ; j++ ){
			scanf("%lf",&A[i][j]);
		}
	}

	printf("Enter the entries of matrix B in row wise manner with spaces between each entry :: ");

        for( int i = 0 ; i < M2 ; i++ ){
                for( int j = 0 ; j < N2 ; j++ ){
                        scanf("%lf",&B[i][j]);
                }
        }

	for( int i = 0 ; i < M1 ; i++ ){
		for( int j = 0 ; j < N2 ; j++ ){
			mul[i][j] = 0 ;
			for( int k = 0 ; k < N1 ; k++ ){
				mul[i][j] += A[i][k]*B[k][j] ; 
			}
		}
	}

        for( int i = 0 ; i < M1 ; i++ ){
                for( int j = 0 ; j < N2 ; j++ ){
                        printf("%lf ",mul[i][j]);
                }
		printf("\n");
        }


	return 0 ;


}
