#include <stdio.h>
#include <stdlib.h>

struct node{
        
        double num ;
        struct node *next ;

};

void printList( struct node * ) ;
struct node * createNode( double ) ;
struct node * appendNode( struct node * , struct node * ) ;
int ifFound( struct node * , double ) ;
void deleteNs( struct node * , double ) ;
struct node * createList( int ) ;
struct node * deleteZeros( struct node * ) ;

int main( void ){

        int N ;
        printf("Enter the value of N :: ") ;
        scanf("%d",&N);

        struct node * head = createList(N) ;

        printList(head);
        printf("\n") ;

        head = deleteZeros(head) ;

        printList(head);
        printf("\n");

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

int ifFound( struct node * ptr , double d ){

        ptr = ptr->next ;

        while( ptr ){

                if( ptr->num == d ){
                        return 1 ;
                }

                ptr = ptr->next ;

        }

        return 0 ;

}

void deleteNs( struct node * head , double N ){

        struct node * curr = head->next , * prev = head ;

        while( curr ){

                if( curr->num == N ){
                        curr = prev->next = curr->next ;
                        return ;
                } else{
                        prev = curr ;
                        curr = curr->next ;
                }

        } 

        return ;

}

struct node * createList( int N ){

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

        return head ;

}  

struct node * deleteZeros( struct node * head ){

        struct node * curr = head , *prev = NULL ; 

        while( curr ){

                if( ifFound(curr,(-1)*(curr->num)) ){
                        deleteNs(curr,(-1)*(curr->num)) ;
                        if( prev == NULL ){
                                head = curr->next ;
                                curr = head ;
                        }else{
                                prev->next = curr->next ;
                                curr = prev->next ;
                        }
                }else{
                        prev = curr ;
                        curr = curr->next ;
                }

        }

        return head ;
}                                                                                                                               
