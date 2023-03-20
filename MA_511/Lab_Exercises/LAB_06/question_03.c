#include <stdio.h>

char * linear_independent( int * , int * ) ;

int main(void){

        int N ;
        printf("Enter the size of the vectors :: ");
        scanf("%d",&N);

        int A[2*N] ;

        printf("Enter the first vector :: ");
        for( int i = 0 ; i < N ; i++ ){
                scanf("%d",A+i);
        }

        printf("Enter the second vector :: ");
        for( int i = N ; i < 2*N ; i++ ){
                scanf("%d",A+i);
        }

        printf("%s\n",linear_independent(A,A+N));

        return 0 ;

}

char *  linear_independent( int * A , int * B ){

	static char Y[4] = "YES" ;
	static char N[3] = "NO" ;
	int n = B-A , z = 0 ;
	for( int i = 0 ; i <= n-1 ; i++ ){
		if( B[i] == 0 ){
			z++ ;
		}
	}
	if( z == n ){
		return N ;
	}
        for( int i = 0 ; i <= n-2 ; i++ ){
		double a = -1 , b = -1 ;
		if( B[i] != 0 && B[i+1] != 0 ){
                	 a = ((*(A+i))*1.0)/(*(B+i)) ;
                	 b = ((*(A+i+1))*1.0)/(*(B+i+1)) ;
		}
		if( a != b ){
                return Y ;
                }
        }

        return N ;

}
  
