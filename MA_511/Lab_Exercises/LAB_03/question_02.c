#include <stdio.h>
#include <stdlib.h>

int main(void){

	int n ;
	printf("Enter the value of 'n' :: ");
	scanf("%d",&n);

	char ch[2] ;
        printf("Enter the value of alphabet :: ");
        scanf("%s",ch);

	int seed ;
	printf("Enter the value of seed :: ");
	scanf("%d",&seed);

	printf("\n");

	srand(seed);

	int A[n][n] , B[n][n] ;

	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			A[i][j] = 0 ;
			B[i][j] = 0 ;
		}
	}

	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
			while( A[i][j] <= 10 || B[i][j] <= 10 ){
				A[i][j] = rand();
				B[i][j] = rand();
			}
                }
        }

	printf("Randomly generated matrix A is :: \n");
	printf("\n");

	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                	printf("%d ",A[i][j]);
                }
		printf("\n");
        }
	
	printf("\n");

	printf("Randomly generated matrix B is :: \n");

	printf("\n");

        for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                        printf("%d ",B[i][j]);
                }
                printf("\n");
        }

	printf("\n");

        if( ch[0] != 'a' && ch[0] != 's' ){
   
   		printf("Error\n");
   
        } else if( ch[0] == 'a' ){

		printf("Addition of A and B is :: \n");

		printf("\n");
	
		for( int i = 0 ; i < n ; i++ ){
                	for( int j = 0 ; j < n ; j++ ){
                        	printf("%ld ",(long)A[i][j]+(long)B[i][j]);
                	}
                	printf("\n");
        	}

	} else{
	
		printf("Subtraction of A and B is :: \n");

		printf("\n");

                for( int i = 0 ; i < n ; i++ ){
                        for( int j = 0 ; j < n ; j++ ){
                                printf("%ld ",(long)A[i][j]-(long)B[i][j]);
                        }
                        printf("\n");
                }

	}

	return 0 ;

}
