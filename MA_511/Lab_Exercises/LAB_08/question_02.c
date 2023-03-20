#include <stdio.h>
#include <stdlib.h>

struct node{

        double num ;
        struct node *next ;

};

void printList( struct node * ) ;
struct node * createNode( double ) ;
struct node * appendNode( struct node * , struct node * ) ;
int notFound( struct node * , double ) ;
struct node * delete( struct node * , double ) ;

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

        printf("Enter the number to be deleted :: ");
        scanf("%lf",&d);
	
	while( notFound(head,d) ){
		printf("NOT FOUND, Enter another number :: ") ;
		scanf("%lf",&d) ;
	}

	head = delete(head,d) ;
        
        printLis(head);
	printf("\n");
        return 0 ;
}

int notFound( struct node * ptr , double d ){
	
	while( ptr ){
		if( ptr->num == d ){
			return 0 ;
		}
		ptr = ptr->next ;
	}

	return 1 ;

}
void printList( struct node * ptr ){

        while( ptr ){
                if( !ptr->next ){

                        printf("%d.",(int)ptr->num) ;
                } else{

                        printf("%d --> ",(int)ptr->num) ;

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

struct node * delete( struct node * ptr , double d ){
	
	struct node *head = ptr , *prev = NULL , *curr = ptr ;

	while(curr){
		
		if( curr->num == d ){
			
			if( curr == head ){
				head = curr->next ;
			}else{
				prev->next = curr->next ;
			}

			curr = head ;

		} else{
			
			prev = curr ;
			curr = curr->next ;
		}

	}
	
	return head ;

}
