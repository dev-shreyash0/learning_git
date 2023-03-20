#include <stdio.h>
#include <stdlib.h>

struct node{

        int num1 , num2 , num3 ;
        struct node *next ;

};

void printList( struct node * ) ;
struct node * createNode( void ) ;
struct node * appendNode( struct node * , struct node * ) ;
struct node * createCircularList( int ) ;
struct node * deleteZeros( struct node * ) ;

int main( void ){

        int N ;
        printf("Enter the value of N :: ") ;
        scanf("%d",&N);
	
	if( N == 0 ){
		return 0 ;
	}

	struct node * head = createCircularList(N) ;

	printList(head);
        printf("\n") ;

	head = deleteZeros(head) ;

	printList(head);
        printf("\n") ;
	
	return 0 ;

}

struct node * createCircularList( int N ){

	struct node * head = NULL , *end = NULL ;

	for( int i = 0 ; i < N ; i++ ){
		
		if( head == NULL ){

                        head = end = createNode() ;

                } else{

                        end = appendNode(end,createNode()) ;
                }

	}

	end->next = head ;

	return head ;

}

void printList( struct node * ptr ){

	if( ptr == NULL ){
		return ;
	}

	struct node * temp = ptr ;
	printf("(%d,%d,%d) --> ",ptr->num1,ptr->num2,ptr->num3) ;
	ptr = ptr->next ;

        while( ptr != temp ){
                
                printf("(%d,%d,%d) --> ",ptr->num1,ptr->num2,ptr->num3) ;
           
                ptr = ptr->next ;
        }

	printf("(%d,%d,%d).",ptr->num1,ptr->num2,ptr->num3) ;

        return ;

}

struct node * createNode( void ){
	
        struct node *ptr = (struct node *)malloc(sizeof(struct node)) ;
        scanf("%d",&ptr->num1);
	scanf("%d",&ptr->num2);
	scanf("%d",&ptr->num3);
        ptr->next = NULL ;

        return ptr ;

}

struct node * appendNode( struct node * oldEnd , struct node * newEnd ){

        oldEnd->next = newEnd ;
        return newEnd ;

}

struct node * deleteZeros( struct node * ptr ){

	struct node *head = ptr , *prev = ptr , *curr = ptr->next ;
	
	int d ;

	while( curr != head ){
	
		d = curr->num1 + curr->num2 + curr->num3 ;

                if( d == 0 ){
		
			curr = prev->next = curr->next ;
	
		}else{
			
			prev = curr ;
			curr = curr->next ;

		}

        }

	d = curr->num1 + curr->num2 + curr->num3 ;
	
	if( d == 0 ){
		
		head = head->next ;
		prev->next = head ;

	}
	
	d = head->num1 + head->num2 + head->num3 ;

	if( head == head->next && (d == 0) ){
		return NULL ;
	} else{

		return head ;
	}

}
