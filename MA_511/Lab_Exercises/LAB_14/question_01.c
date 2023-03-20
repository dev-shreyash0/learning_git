#include <stdio.h>

int main( void ){

	FILE *fp = fopen("222123048.dat","w") ;

	if( fp == NULL ){
		printf("Error while opening the file.") ;
		return 0 ;
	}

	char s[1000] ;

	scanf("%[^\n]",s) ;

	int i = 0 ;

	while( s[i] != '\0' ){
		fprintf(fp,"%c",s[i]) ;
		i++ ;
	}

	fclose(fp) ;

	return 0 ;

}
