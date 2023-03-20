#include <stdio.h>
#include <stdlib.h>

struct node{
	int num ;
	struct node * left ;
	struct node * right ;
};

void inOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }

        inOrder(ptr->left) ;
        printf("%d ",ptr->num) ;
        inOrder(ptr->right) ;

        return ;

}

void preOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }

        printf("%d ",ptr->num) ;
        preOrder(ptr->left) ;
        preOrder(ptr->right) ;

        return ;

}

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

struct node * deleteLeaf( struct node * root ){
	
	if( root == NULL || root->left == NULL && root->right == NULL ) return NULL ;

	root->left = deleteLeaf(root->left) ;
	root->right = deleteLeaf(root->right) ;

	return root ;

}


int main( void ){
	
	printf("\n") ;
        int N ;
        printf("Enter the number of nodes :: ") ;
        scanf("%d",&N) ;

        struct node * root = NULL ;
        int n ;
	
	printf("\n") ;
	printf("Enter the integers :: ") ;
        
	for( int i = 0 ; i < N ; i++ ){

                scanf("%d",&n) ;
                root = insert(root,n) ;

        }

	printf("\n") ;
	printf("Binary Tree PreOrder :: ") ;
        preOrder(root) ;
        printf("\n") ;

	printf("\n") ;
        printf("Binary Tree InOrder :: ") ;
        inOrder(root) ;
        printf("\n") ;

        root = deleteLeaf(root) ;
	printf("\n") ;
	printf("After Deletion :: ") ;
	printf("\n") ;
	printf("\n") ;
        printf("Binary Tree PreOrder :: ") ;
        preOrder(root) ;
        printf("\n") ;

        printf("\n") ;
        printf("Binary Tree InOrder :: ") ;
        inOrder(root) ;
        printf("\n") ;
	printf("\n") ;

        return 0 ;

}

