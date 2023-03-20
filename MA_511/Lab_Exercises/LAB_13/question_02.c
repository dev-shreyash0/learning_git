#include <stdio.h>
#include <stdlib.h>

struct node{

        int num ;
        struct node * left ;
        struct node * right ;

};

struct node * createNode( int n ){

        struct node * ptr = (struct node *)malloc(sizeof(struct node)) ;
        ptr->num = n ;
        ptr->left = NULL ;
        ptr->right = NULL ;

        return ptr ;

}

struct node * insert( struct node * root , int n ){

        if( !root ){
                root = createNode(n) ;
        } else if( n < root->num ){
                root->left = insert(root->left,n) ;
        } else{
                root->right = insert(root->right,n) ;
        }

        return root ;

}

void inOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }

        inOrder(ptr->left) ;
        printf("%d ",ptr->num) ;
        inOrder(ptr->right) ;

        return ;

}

void search( struct node * root , int *f , int n ){
	
	if( root == NULL ) return ;

	if( root->num == n ) *f = 1 ;
	else if( n < root->num ) search(root->left,f,n) ;
	else search(root->right,f,n) ;

	return ;

}

int main( void ){

	struct node * root = NULL ;
	int n ;

	int *f = ( int * )malloc( sizeof(int) ) ;
	
	printf("\n") ;
	printf("Enter an integer to insert :: ") ;
	scanf("%d",&n) ;

	root = insert(root,n) ;
	
	char ch ;
	printf("Y/N ? :: ") ;
	scanf(" %c",&ch) ;

	while( ch == 'Y' ){
			
		printf("Enter an integer to insert :: ") ;
	        scanf("%d",&n) ;
		
		*f = 0 ;
		search( root , f , n ) ;

		if( *f == 1 ){
			printf("The integer is present, please enter again :: \n") ;
		} else{
			root = insert(root,n) ;
		}

		printf("Y/N ? :: ") ;
       	 	scanf(" %c",&ch) ;
			
	}

	printf("\n") ;
	inOrder(root) ;
	printf("\n") ;

	return 0 ;

}
