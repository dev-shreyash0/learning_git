#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

	int n ;
	printf("Enter the side length of square :: ");
	scanf("%d",&n);

	double * X = ( double * )malloc( n * sizeof(double) ) ;
	double * Y = ( double * )malloc( n * sizeof(double) ) ;

	int seed ;

	printf("Enter the value of seed :: ");
	scanf("%d",&seed);

	srand( seed ) ;

	for( int i = 0 ; i < n ; i++ ){
	
		*(X+i) = ( (rand()*1.0) / ( (long)RAND_MAX + 1 )) * n ;
		*(Y+i) = ( (rand()*1.0) / ( (long)RAND_MAX + 1 )) * n ;

	}

	double xC , yC , r ;

	printf("Enter the values of x-coordinate and y-coordinate of the center :: ");
	scanf("%lf",&xC);
	scanf("%lf",&yC);
	printf("Enter the value of radius :: ");
	scanf("%lf",&r);

	for( int i = 0 ; i < n ; i++ ){
	
		double dC = sqrt( pow(X[i]-xC,2) + pow(Y[i]-yC,2) ) ;

		if( dC < r ){
			printf("Point %c %lf , %lf %c lies inside the given circle.\n",'(',X[i],Y[i],')') ;
		} else if( dC == r ){
			printf("Point %c %lf , %lf %c lies on the given circle.\n",'(',X[i],Y[i],')') ;
		} else{
			printf("Point %c %lf , %lf %c lies outside the given circle.\n",'(',X[i],Y[i],')') ;
		}
	
	}	

	double maxDistance = (-1) * RAND_MAX , distance ;

	for( int i = 0 ; i < n ; i++ ){
		for( int j = i+1 ; j < n ; j++ ){
			distance = sqrt( pow(X[i]-X[j],2) + pow(Y[i]-Y[j],2) );
			if( distance > maxDistance ){
				maxDistance = distance ;
			}
		}
	}


	printf("Max Distance between the points is :: %lf.\n",maxDistance) ;

	free(X);
	free(Y);

	return 0 ;

}	
