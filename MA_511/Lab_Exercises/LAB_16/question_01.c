#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void ){

	int m , n ;

	printf("Enter the value of m :: ") ;
	scanf("%d",&m) ;
	printf("Enter the value of n :: ") ;
	scanf("%d",&n) ;

	srand( time(0) ) ;

	FILE *fp1 = fopen("file1.dat","w") ;

	double r ;
	int k ;

	printf("Contents of file1 :: ") ;

	for( int i = 0 ; i < m ; i++ ){
		
		r = ( rand() * 1.0 )/((long)RAND_MAX + 1 ) ;
		
		k = 1 + (int)(r*10) ;
		printf("%d ",k) ;
		fprintf(fp1,"%d\n",k) ;
		if( i == m-1 ) break ;

	}
	
	fclose(fp1) ;

	printf("\n") ;
	printf("Contents of file2 :: ") ;

	FILE *fp2 = fopen("file2.dat","w") ;

	if( fp2 == NULL ){
	       	printf("Error") ;
		return 0 ;
	}	
	int l ;

        for( int i = 0 ; i < n ; i++ ){

                r = ( rand() * 1.0 )/((long)RAND_MAX + 1 ) ;

                l = 5 + (int)(r*5) ;
		printf("%d ",l) ;
                fprintf(fp2,"%d\n",l) ;


        }

	fclose(fp2) ;

	int *N = (int *)malloc(151*sizeof(int)) ;

	for( int i = 0 ; i < 151 ; i++ ) N[i] = 0 ;

	fp1 = fopen("file1.dat","r+") ;
	fp2 = fopen("file2.dat","r+") ;
	
	int h ;

	for( int i = 0 ; i < m ; i++ ){
		
		fscanf(fp1,"%d",&h) ;
		N[h] = 1 ;

	}

	for( int i = 0 ; i < n ; i++ ){

                fscanf(fp2,"%d",&h) ;
                N[h] = 1 ;

        }

	int count = 0 ;

	printf("\n") ;
        printf("Contents of file3 :: ") ;

	FILE *fp3 = fopen("file3.dat","w") ;

	for( int i = 0 ; i < 151 ; i++ ){
		
		if( N[i] == 1 ){
			fprintf(fp3,"%d\n",i) ;
			count++ ;
			printf("%d ",i) ;
		}

	}

	fclose(fp1) ;
	fclose(fp2) ;
	fclose(fp3) ;

	printf("\n") ;

	printf("Count :: %d.\n",count) ;

	return 0 ;

}
