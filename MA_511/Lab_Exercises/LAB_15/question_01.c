#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ){

	FILE *fp = fopen("test.dat","r+") ;

	char R[1000] ;

	printf("Enter the string to be replaced :: ") ;
	scanf("%[^\n]",R) ;

	char S[1000] ;
	fscanf(fp,"%s",S) ;

	while( !feof(fp) ){
		
		int i = strcmp(S,R) ;

		if( i == 0 ){
			fprintf(fp,"%s","XYZ ") ;
		} else{
			fprintf(fp,"%s",S) ;
		}

		fscanf(fp,"%s",S) ;

	}	

	fclose(fp) ;

	return 0 ;

}
