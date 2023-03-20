#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main( void ){

	FILE *fp = fopen("file1.dat","w") ;

	srand(time(0)) ;

	int N ;
	printf("Enter the value of N :: ") ;
	scanf("%d",&N) ;

	int I = 0 , D = 0 ;

	for( int i = 0 ; i < N ; i++ ){
		
		double r = ((double)rand())/(RAND_MAX) ;

		if( r <= 0.8 ){
			fprintf(fp,"%s\n","Insert") ;
			I++ ;
		} else{
			fprintf(fp,"%s\n","Delete") ;
			D++ ;
		}

	}

	double p = ((I*(1.0))/N)*100 ;

	printf("Percentage of Insert is :: %.2lf.\n",p) ;
	printf("Percentage of Delete is :: %.2lf.\n",100-p) ;

	fclose(fp) ;

	return 0 ;

}
