#include <stdio.h>

struct classInfo{

	int gradePoint[10] ;
	int credit[10] ;

} student[100] ;

int main(void){

	int N ;
	printf("Enter the number of students in a class (upto 100) :: ");
	scanf("%d",&N);

	for( int n = 0 ; n < N ; n++ ){

		int C ;
		printf("Enter the number of courses taken by student %d (upto 10) :: ",n+1) ;
		scanf("%d",&C);

		for( int c = 0 ; c < C ; c++ ){

			printf("Enter the grade point of %dth course :: ",c+1);
			scanf("%d",&student[n].gradePoint[c]);
			printf("Enter the credit of the %dth course :: ",c+1);
			scanf("%d",&student[n].credit[c]);

		}

		double spiN = 0 , spiD = 0 ;

		for( int i = 0 ; i < C ; i++ ){

			spiN += student[n].gradePoint[i] * student[n].credit[i] ;
			spiD += student[n].credit[i] ;

		}

		printf("SPI of student %d is :: %lf.\n",n+1,spiN/spiD) ;


	}

	return 0 ;


}