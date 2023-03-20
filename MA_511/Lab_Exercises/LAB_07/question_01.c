#include <stdio.h>
#include <stdlib.h>

int ** compute( int ** , int * , int ) ;
void scalar_Mult( int ** , int , int** , int ) ;
void scalar_Mult1( int , int** , int ) ;
void multiply( int ** , int , int** , int , int ) ;
void multiply1( int ** , int ** , int ) ;
void printM( int ** , int ) ;
int main( void ){
	
	int n ;
	printf("Enter the degree of the polynomial :: ");
	scanf("%d",&n);

	int *P = (int *)malloc((n+1)*sizeof(int)) ;

	printf("Enter the coefficients starting from a_0 :: ");

	for( int i = 0 ; i < n+1 ; i++ ){
		scanf("%d",P+i);
	}

	int **M = (int **)malloc(n*(sizeof(int *))) ;

	printf("Enter the matrix row-wise :: ");

	for( int i = 0 ; i < n ; i++ ){
		M[i] = (int *)malloc(n*sizeof(int)) ;
		for( int j = 0 ; j < n ; j++ ){
			scanf("%d", &M[i][j] );
		}
	}
	
	int **R ;

	R = compute(M,P,n) ;
	
//	printM(R,n) ;

	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                        if( R[i][j] != 0 ){
				printf("NO\n");
				return 0 ;
			} 
                }
        }

	printf("YES\n") ; 

	return 0 ;

}

int ** compute( int **M , int *P , int n ){

	 int **R = (int **)malloc(n*(sizeof(int *))) ;

	 for( int i = 0 ; i < n ; i++ ){
		R[i] = (int *)malloc(n*sizeof(int)) ; 
                for( int j = 0 ; j < n ; j++ ){
                        R[i][j] = 0 ;
                }
         }

//	 printM(R,n) ;

	 for( int i = 0 ; i <= n ; i++ ){
		 if( i != 0 ){
		 	multiply(M,i,R,n,P[i]) ;
			if( i == 1 ){
				scalar_Mult(M,P[i],R,n) ;
			}
		 } else{
		 	scalar_Mult1(P[i],R,n) ;
		//	printM(R,n);
	         }		
	 }

	 return R ;

}

void scalar_Mult( int **M , int m , int **R , int n  ){

	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			R[i][j] += m*M[i][j] ;
		}
	}

	return ;

}

void multiply( int **M , int m , int **R , int n , int x ){

	if( m == 1 ){
		return ;
	}

	int **temp = (int **)malloc(n*(sizeof(int *))) ;
	
	for( int i = 0 ; i < n ; i++ ){
		temp[i] = (int *)malloc(n*sizeof(int)) ;
                for( int j = 0 ; j < n ; j++ ){
                        temp[i][j] = M[i][j] ;
                }
        }
//	printM(temp,n) ;

	for( int i = 1 ; i < m ; i++ ){
		multiply1(temp,M,n) ;
	}
	
//	printM(temp,n);
//	printM(R,n) ;
	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                        R[i][j] += x*temp[i][j] ;
                }
        }

//	printM(R,n) ;

	free(temp) ;

	return ;

}

void multiply1( int **temp , int **M , int n ){

	int temp1[n][n] ;

	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			temp1[i][j] = 0 ;
			for( int k = 0 ; k < n ; k++ ){
				temp1[i][j] += temp[i][k]*M[k][j] ;
			}
		}
	}

	

	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
		//	printf("%d ",temp1[i][j]);
                        temp[i][j] = temp1[i][j] ;
                }
	//	printf("\n");
        }

	return ;

}

void scalar_Mult1( int m , int **R , int n  ){
	
	for( int i = 0 ; i < n ; i++ ){
		R[i][i] += m ;
	}

	return ;

}

void printM( int **M , int n ){
	
	for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < n ; j++ ){
                        printf("%d ",M[i][j]) ;
                }
                printf("\n");
        }


}
