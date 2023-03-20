#include <stdio.h>
#include <stdlib.h>

int main( void ){

	int row , col ;

	printf("Enter the number of rows :: ");
	scanf("%d",&row);
	printf("Enter the number of cols :: ");
        scanf("%d",&col);

	int **M = ( int **)malloc(row*sizeof(int *)) ;
	
	printf("Enter the array row-wise :: \n");

	for( int i = 0 ; i  < row ; i++ ){
		M[i] = (int *)malloc(col*sizeof(int)) ;
		for( int j = 0 ; j < col ; j++ ){
			scanf("%d",&M[i][j]);
		}
	}

	printf("Input array is ::\n");

	for( int i = 0 ; i < row ; i++ ){
		for( int j = 0 ; j < col ; j++ ){
			printf("%d ",M[i][j]) ;
		}
		printf("\n") ;
	}

	int r ;
	printf("Enter the row you want to replace(<%d) :: ",row);
	scanf("%d",&r);
	printf("Enter the new elements of the row :: ");
	for( int i = 0 ; i < col ; i++ ){
		scanf("%d",&M[r-1][i]) ;
	}

	printf("The Modified array is :: \n");

	for( int i = 0 ; i < row ; i++ ){
                for( int j = 0 ; j < col ; j++ ){
                        printf("%d ",M[i][j]) ;
                }
                printf("\n") ;
        }

	return 0 ;


}
