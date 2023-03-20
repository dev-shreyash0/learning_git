#include <stdio.h>
#include <math.h>
int main(void){
    float radius ;
    float xCor ;
    float yCor ;
    printf("Enter the value of radius : ");
    scanf("%f",&radius);
    printf("\n");
    printf("Enter the value of x-coordinate : ");
    scanf("%f",&xCor);
    printf("\n");
    printf("Enter the value of y-coordinate : ");
    scanf("%f",&yCor);
    printf("\n");
    float dSquare = (xCor*xCor)+(yCor*yCor) ;
    float distance =(double)sqrt((double)dSquare) ;

    if( distance < radius ){
       printf("Point lies inside the circle.");
    } else if( distance == radius ){
              printf("Point lies on the circle.");
    } else{
	    printf("Point lies outside the circle.");
    }	    

}
