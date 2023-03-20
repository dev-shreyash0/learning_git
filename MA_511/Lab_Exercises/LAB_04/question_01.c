#include <stdio.h>

int main(void){

	char ch ;
	printf("Enter the single aphabet :: ");
	scanf("%c",&ch);

	char A[1001] , B[1001] , D[1001] , E[2001] ;

	switch(ch){
	
		case 'c' : printf("Enter the first string :: ");
			   scanf(" %[^\n]",A);
			   printf("Enter the second string :: ");
			   scanf(" %[^\n]",B);

			   int cI = 0 , aI = 0 , bI = 0 ;
				
			   while( A[aI] != '\0' ){
			   	E[cI] = A[aI] ;
				cI++ ;
				aI++ ;
			   }			   
			   while( B[bI] != '\0' ){
			   	E[cI] = B[bI] ;
				cI++ ;
				bI++ ;
			   }
			   
			   E[cI] = '\0' ;

			   printf("Concatenated String is :: ");
			   printf("%s\n",E);
			   return 0 ;
	
		case 'C' : printf("Enter the String :: ");
			   scanf(" %[^\n]",D);

			   int dI = 0 ;

			   while( D[dI] != '\0' ){
			   	if( D[dI] >= 'a' && D[dI] <= 'z' ){
					D[dI] = (char)(D[dI]-'a'+'A') ;
				} else if( D[dI] >= 'A' && D[dI] <= 'Z' ){
					D[dI] = (char)(D[dI]+'a'-'A') ;
				} else{

				}		
				dI++ ;
			   }

			   printf("Resultant String is :: ");
			   printf("%s\n",D);
			   return 0 ;
 		
		default : printf("Invalid Character!\n") ;		   				   
	
	
	
	}


	return 0 ;

}
