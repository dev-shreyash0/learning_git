#include <stdio.h>
#include<math.h>


int main(void){
         // take integer -- a -- as input
	 int aDecimal ;
	 printf("Enter the decimal a : ");
	 scanf("%d",&aDecimal) ;

	 // code for converting -- a -- into binary
	 
	 int aBinary = 0 ;

	 int i = 0 ;

	 while( aDecimal != 0 ){
	       int rem = aDecimal % 2 ;
	       aBinary += rem * pow(10,i) ;
	       aDecimal /= 2 ;
	       i++ ;
	 }

	 printf("Binary of a is %d",aBinary);

	 printf("\n");

	 // take integer -- b -- as input 
	 int bDecimal ;
	 printf("Enter the decimal b : ");
	 scanf("%d",&bDecimal);

                                    
	 //code for converting -- b -- into binary 
	 
	 int bBinary = 0 ;

	 int j = 0 ;

	 while( bDecimal != 0 ){
	       int rem = bDecimal % 2 ;
	       bBinary += rem * pow(10,j) ;
	       bDecimal /= 2 ;
	       j++ ;   
	 }

	 printf("Binary of b is %d", bBinary);
         
	 printf("\n");


}
