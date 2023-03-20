#include <stdio.h>
#include <stdlib.h>

struct node{

        int num ;
	struct node *prev ;
        struct node *next ;

};

void printList( struct node * ) ;
struct node * createNode( void ) ;
struct node * createList( void ) ;
void insert( struct node * , struct node * ) ;
struct node * delete( struct node * ) ;

struct node * delete( struct node * head ){
	
	struct node * curr = head , * ptr = NULL ;

	while( curr ){
		
		if( (curr->num)%2 ){
			
			if( curr == head ){
				head = head->next ;
				curr = head ;
			} else{
				ptr = curr->next ;

				if( ptr ){
					curr = curr->prev ;
                               	 	curr->next = ptr ;
                                	ptr->prev = curr ;
                                	curr = ptr ;
				} else{
					curr = (curr->prev)->next = NULL ;
				}

			}

		} else{
			
			curr = curr->next ;

		}

	}

	return head ;

}

void insert( struct node * curr , struct node * ptr ){

	while( ptr->num >= curr->num ){
		curr = curr->next ;
	}

	curr = curr->prev ;

	ptr->prev = curr ;
	ptr->next = curr->next ;
	(curr->next)->prev = ptr ;
	curr->next = ptr ;

	return ;

}

struct node * createNode(){

        struct node *ptr = (struct node *)malloc(sizeof(struct node)) ;
        scanf("%d",&ptr->num) ;
	ptr->prev = NULL ;
        ptr->next = NULL ;

        return ptr ;
}

void printList( struct node * ptr ){

        while( ptr ){
                if( !ptr->next ){

                        printf("%d.",ptr->num) ;
                } else{

                        printf("%d <--> ",ptr->num) ;

                }
                ptr = ptr->next ;
        }

        return ;

}


struct node * createList( void ){

	printf("Enter the first element :: ") ;
	
	struct node * head = NULL , * end = NULL , * ptr = NULL ;

	end =  head = createNode() ;

	char ch ;

	printf("Want to insert more elements ? (y/n) :: ") ;
	scanf(" %c",&ch) ;
	printf("\n") ;

	while( ch == 'y' ){
		
		printf("Enter Element :: ") ;

		ptr = createNode() ;

		if( ptr->num <= head->num ){
			head->prev = ptr ;
			ptr->next = head ;
			head = ptr ;
		} else if( ptr->num >= end->num ){
			ptr->prev = end ;
			end = end->next = ptr ;
		} else{
			insert(head,ptr) ;
		}

		printf("\n") ;
		printf("List After Insertion of %d :: ", ptr->num ) ;
		printList(head) ;
		printf("\n") ;
		printf("\n") ;
		printf("Want to insert more elements ? (y/n) :: ") ;
		scanf(" %c",&ch) ;
		printf("\n") ;

	}

	return head ;

}

int main( void ){

	struct node * head = createList() ;
	
	printf("\n") ;
	printf("Linked List before deletion is :: ") ;
	printList(head) ;
	printf("\n") ;
	printf("\n") ;
	head = delete(head) ;
	printf("Linked List before deletion is :: ") ;
	printList(head) ;
	printf("\n") ;
	printf("\n") ;
	return 0 ;

}
