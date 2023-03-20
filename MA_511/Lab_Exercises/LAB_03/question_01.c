#include <stdio.h>

void swap( int * , int * , int * ) ;

int main(void){

	int X[3] , Y[3] , Z[3] ;

	for( int i = 1 ; i <= 3 ; i++ ){
	
		printf("Enter the co-ordinates of %dth 3-d point :: ",i);
		scanf("%d",&X[i-1]);
		scanf("%d",&Y[i-1]);
		scanf("%d",&Z[i-1]);
	
	}

	printf("Before swapping the middle coordinates---------\n");

	for( int i = 0 ; i < 3 ; i++ ){
		printf("%d %d %d\n",X[i],Y[i],Z[i]);
	}

	swap(&Y[0],&Y[1],&Y[2]);

	printf("After swapping the middle coordinates---------\n");

	for( int i = 0 ; i < 3 ; i++ ){
                printf("%d %d %d\n",X[i],Y[i],Z[i]);
        }

	return 0 ;

}

void swap( int * a , int * b , int * c ){

	int temp = *c ;

	*c = *b ;
	*b = *a ;
	*a = temp ;

	return ;

}
