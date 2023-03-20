#include <stdio.h>

int main(void){

	// Program to convert temperature value from Celcius to Fahrenheit
	
	double cTemp,fTemp ;

	printf("Enter the value of temperature in degree Celcius :: ");
	scanf("%lf",&cTemp);

	fTemp = 32 + ((9/5)*cTemp) ;

	printf("%lf degree Celcius = %lf degree Fahrenheit.\n",cTemp,fTemp) ;

	return 0 ;

}
