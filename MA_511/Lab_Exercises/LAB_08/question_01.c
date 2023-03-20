#include <stdio.h>
#include <stdlib.h>

struct node{
	
	double num ;
	struct node *next ;

};

void printList( struct node * ) ;
struct node * createNode( double ) ;
struct node * appendNode( struct node * , struct node * ) ;
void insertAtTarget( struct node * , double ) ;
struct node * getTarget( struct node * , double ) ;

int main( void ){
	
	int N ;
	printf("Enter the value of N :: ") ;
	scanf("%d",&N);

	struct node * head = NULL , * end = NULL ;
	
	double d ;

	for( int i = 1 ; i <= N ; i++ ){
		
		scanf("%lf",&d) ;

		if( head == NULL ){
			
			head = end = createNode(d) ;

		} else{
			
			end = appendNode(end,createNode(d)) ;
		}

	}

	printList(head);
	printf("\n") ;
	
	printf("Enter the real number to be inserted :: ");
	scanf("%lf",&d);

	if( d <= head->num ){
		struct node * ptr = createNode(d) ;
		ptr->next = head ;
		head = ptr ;
	} else if( d >= end->num ){
		end = appendNode(end,createNode(d)) ;
	} else{
		insertAtTarget(getTarget(head,d),d) ;
	}

	printList(head);	

	return 0 ;
}

void printList( struct node * ptr ){
	
	while( ptr ){
		if( !ptr->next ){

			printf("%.2lf.",ptr->num) ;
		} else{
			
			printf("%.2lf --> ",ptr->num) ;

		}	
		ptr = ptr->next ;
	}

	return ;

}

struct node * createNode( double n ){
	
	struct node *ptr = (struct node *)malloc(sizeof(struct node)) ;
	ptr->num = n ;
	ptr->next = NULL ;

	return ptr ;

}

struct node * appendNode( struct node * oldEnd , struct node * newEnd ){
	
	oldEnd->next = newEnd ;
	return newEnd ;

}

void insertAtTarget( struct node * ptr , double d ){
	
	struct node * temp = createNode(d) ;
	temp->next = ptr->next ;
	ptr->next = temp ;

}

struct node * getTarget( struct node * head , double d ){
	
	struct node * t = head ;

	while( (t->next)->num <= d ){
		t = t->next ;
	}

	return t ;

}
