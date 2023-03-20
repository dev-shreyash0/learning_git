#include <stdio.h>
int main(void){
    float pii = 3.14159 ;
    float r ;
    printf("Enter the value of radius : ");
    scanf("%f" , &r);
    float area = pii * r * r ;
    float perimeter = 2 * pii * r ;
    printf("\n");
    printf("Area of the given circle = %f",area);
    printf("\n");
    printf("Perimeter of the given circle = %f",perimeter);
}
