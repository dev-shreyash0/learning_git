#include <stdio.h>
#include <stdlib.h>

struct node{

        int num ;
        struct node * left ;
        struct node * right ;

};

struct node * getMinNode( struct node * ptr ){

        if( !ptr->left ){
                return ptr ;
        }

        return getMinNode( ptr->left ) ;

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

void levelOrder( struct node * ptr , int l1 , int l2 ){

        if( !ptr ){
                return ;
        }

	if( l1 == l2 ) printf("%d ",ptr->num) ;

        levelOrder(ptr->left,l1,l2+1) ;
        levelOrder(ptr->right,l1,l2+1) ;

        return ;

}

struct node * delete( struct node * root , int n  ){

        if( !root ){
                return root ;
        }

        if( n == root->num ){

               if( root->left == NULL && root->right == NULL ){

                       free(root) ;
                       return NULL ;

               } else if( root->right == NULL ){

                       struct node * temp = root->left ;
                       free(root) ;
                       return temp ;

               } else if( root->left == NULL ){

                       struct node * temp = root->right ;
                       free(root) ;
                       return temp ;

               }else{

                       struct node * succesorNode = getMinNode(root->right) ;
                       root->num = succesorNode->num ;
                       root->right = delete(root->right,succesorNode->num) ;

               }

        } else if( n < root->num ){

                root->left = delete(root->left,n) ;

        }else{

                root->right = delete(root->right,n) ;

        }

        return root ;

}

void getHeight( struct node * root , int l , int *h ){

	if( root == NULL ){
		if( l > *h ){
			*h = l ;
		}
		return ;
	}
	
	getHeight(root->left,l+1,h) ;
	getHeight(root->right,l+1,h) ;

	return ;
	
}

struct node * deleteLevel( struct node * root , int l , int h ){
	
	if( l > h || root == NULL ) return root ;

	if( l == h ) return delete( root , root->num ) ;

	root->left = deleteLevel(root->left,l+1,h) ;
	root->right = deleteLevel(root->right,l+1,h) ;

	return root ;
}

int main( void ){

        int N ;
        printf("Enter the number of elements to be inserted :: ") ;
        scanf("%d",&N) ;
	printf("Enter the elements :: ") ;
        struct node * root = NULL ;
        int n ;

        for( int i = 0 ; i < N ; i++ ){

                scanf("%d",&n) ;
                root = insert(root,n) ;

        }

	printf("\n") ;
	
	int *h = (int *)malloc(sizeof(int)) ;
	*h = 0 ;

	getHeight(root,0,h) ;
	
	for( int i = 1 ; i <= *h ; i++ ){
		levelOrder(root,i,1) ;
		printf("\n") ;
	} 

        printf("Enter the level to delete( starting from 1 ) :: ") ;
        scanf("%d",&n) ;
        printf("\n") ;
	
	root = deleteLevel( root , 1 , n ) ;
        printf("\n") ;
	printf("\n") ;
	printf("Binary Tree after deleting level %d is :: ", n) ;
	printf("\n") ;
	for( int i = 1 ; i <= *h ; i++ ){
                levelOrder(root,i,1) ;
                printf("\n") ;
        }

       	printf("\n") ;

        return 0 ;

}

