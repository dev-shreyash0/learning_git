#include <stdio.h>

int main( void ){

	FILE *fp = fopen("222123048.dat","r") ;

	int charCount = 0 , wordCount = 0 ;

	char ch ;

	fscanf(fp,"%c",&ch) ;

//	if( !feof(fp) ){
//		printf("Number of characters in file are :: %d.\n",charCount) ;
//		printf("Number of words in file are :: %d.\n",wordCount) ;
//		return 0 ;
//	}
	
	while( !feof(fp) ){

		charCount++ ;
		if( ch == ' ' ) wordCount++ ;
		fscanf(fp,"%c",&ch) ;	

	}

	if( charCount != 0 ) wordCount++ ;

       	printf("Number of characters in file are :: %d.\n",charCount) ;
        printf("Number of words in file are :: %d.\n",wordCount) ;
   
   	return 0 ;
	
}
