#include <stdio.h>
#include <string.h>

struct stud{

	int rollNumber ;
	char fullName[100] ;
	int marks[3] ;

};

void print( struct stud ) ;

int main(void){
	
	int N ;
	printf("Enter the Number of students :: ");
	scanf("%d",&N);

	struct stud studentInfo[N] ;

	for( int n = 0 ; n < N ; n++ ){
                
		printf("Enter the roll number of the %dth student :: ",n+1);
        	scanf("%d",&studentInfo[n].rollNumber);

		printf("Enter the full name of the %dth student :: ",n+1);
		scanf(" %[^\n]",studentInfo[n].fullName);

		printf("Enter the marks of three courses of the  %dth student :: ",n+1);
		for( int i = 0 ; i < 3 ; i++ ){	
			scanf("%d",&studentInfo[n].marks[i]);
		}

	}

	char queryName[100] ;
	printf("Enter the query name :: ");
	scanf(" %[^\n]",queryName);
	
	int count = 0 ;
	int fI ;
	for( int n = 0 ; n < N ; n++ ){
		if( strcmp(queryName,studentInfo[n].fullName) == 0 ){
			count++ ;
			fI = n ;				
		}
	}

	if( count == 0 ){
		printf("No Match Found\n");
	} else if( count == 1 ){
		print( studentInfo[fI] ) ;
	} else{
		int queryRollNum ;
		printf("There are %d students with the given name. Please enter the roll number :: ",count);
		scanf("%d",&queryRollNum);

		for( int n = 0 ; n < N ; n++ ){
			if( queryRollNum == studentInfo[n].rollNumber ){
				print( studentInfo[n] );

			}
		}
	}

	return 0 ;
}

void print( struct stud studentInfo ){

	printf("Details of the student are :: \n");

	printf("Roll Number :: %d\n",studentInfo.rollNumber);
	printf("Name :: %s\n",studentInfo.fullName);
	int hM = studentInfo.marks[0] ;
	int tM = hM ;
	for( int j = 1 ; j < 3 ; j++ ){
		if( hM < studentInfo.marks[j] ){
			hM = studentInfo.marks[j] ;
		}
		tM += studentInfo.marks[j] ;
	}
	printf("Highest Marks :: %d\n",hM);
	printf("Total Marks :: %d\n",tM);

	return ;

}
