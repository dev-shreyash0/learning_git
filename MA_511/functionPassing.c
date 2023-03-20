#include <stdio.h>

void add( int , int ) ;
void subtract( int , int ) ;
void performOperations( void(*) (int , int )) ;

int main( void ){

	performOperations(add);
	performOperations(subtract);

	return 0 ;

}

void add( int a , int b ){
	printf("%d + %d = %d\n",a,b,a+b) ;
	return ;
}
void subtract( int a , int b ){
	printf("%d - %d = %d\n",a,b,a-b) ;
	return ;
}
void performOperations( void(*ptr) ( int a , int b ) ){

	int a , b ;
	scanf("%d %d",&a,&b) ;

	(*ptr)(a,b) ;

	return ;

}