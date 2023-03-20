#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N ;

struct coordinates{

	double x ;
	double y ;

}point[100] ;

int main(void){

	printf("Enter the value of N upto 100 :: ");
	scanf("%d",&N);

	int seed ;
	printf("Enter the value of seed :: ");
	scanf("%d",&seed);

	srand(seed) ;

	for( int i = 0 ; i < N ; i++ ){
		point[i].x = (rand()/(double)(RAND_MAX))*N ;
		point[i].y = (rand()/(double)(RAND_MAX))*N ;
	}

	double radius , xC , yC ;
	printf("Enter the value of radius :: ");
	scanf("%lf",&radius);
	printf("Enter the x-coordinate of center of circle :: ");
	scanf("%lf",&xC);
	printf("Enter the y-coordinate of center of circle :: ");
	scanf("%lf",&yC);

	for( int i = 0 ; i < N ; i++ ){

		double distance = sqrt( pow( (xC-point[i].x) , 2 ) + pow( (yC-point[i].y) , 2 ) ) ;

		if( distance < radius ){
			printf("Point  %lf,%lf  lies inside the circle.\n",point[i].x,point[i].y) ;
		} else if( distance == radius ){
			printf("Point  %lf,%lf  lies on the circle.\n",point[i].x,point[i].y) ;
		} else{
			printf("Point  %lf,%lf  lies outside the circle.\n",point[i].x,point[i].y) ;
		}

	}

	return 0 ;

}