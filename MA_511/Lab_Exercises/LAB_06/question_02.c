#include <stdio.h>

int linear_independent( int * , int * , int ) ;

int main(void){

	int N ;
	printf("Enter the size of the vectors :: ");
	scanf("%d",&N);

	int A[N] , B[N] ;

	printf("Enter the first vector :: ");
	for( int i = 0 ; i < N ; i++ ){
		scanf("%d",A+i);
	}
	
	printf("Enter the second vector :: ");
        for( int i = 0 ; i < N ; i++ ){
                scanf("%d",B+i);
        }

	if( linear_independent(A,B,N) ){
		printf("The vectors are linearly independent.\n");
	} else{
		printf("The vectors are linearly dependent.\n");
	}

	return 0 ;

}

int linear_independent( int * A , int * B , int N ){

	int z = 0 ;	
	for( int i = 0 ; i <= N-1 ; i++ ){
                if( B[i] == 0 ){
                        z++ ;
                }
        }
        if( z == N ){
                return 0 ;
        }
        for( int i = 0 ; i <= N-2 ; i++ ){
                double a = -1 , b = -1 ;
                if( B[i] != 0 && B[i+1] != 0 ){
                         a = ((*(A+i))*1.0)/(*(B+i)) ;
                         b = ((*(A+i+1))*1.0)/(*(B+i+1)) ;
                }
                if( a != b ){
                return 1 ;
                }
        }

	return 0 ;

}
