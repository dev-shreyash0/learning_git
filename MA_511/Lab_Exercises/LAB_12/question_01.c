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

void preOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }
	
	printf("%d ",ptr->num) ;
        preOrder(ptr->left) ;
        preOrder(ptr->right) ;

        return ;

}

void postOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }

        postOrder(ptr->left) ;
        postOrder(ptr->right) ;
	printf("%d ",ptr->num) ;

        return ;

}

struct node * getMinNode( struct node * ptr ){
	
	if( !ptr->left ){
		return ptr ;
	}

	return getMinNode( ptr->left ) ;

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


int main( void ){
	
	int N ;
	printf("Enter the number of elements to be inserted :: ") ;
	scanf("%d",&N) ;

	struct node * root = NULL ;
	int n ;

	for( int i = 0 ; i < N ; i++ ){
		
		scanf("%d",&n) ;
		root = insert(root,n) ;

	}

//	preOrder(root) ;
//	printf("\n") ;

	inOrder(root) ;
	printf("\n") ;
	
//	postOrder(root) ;
//	printf("\n") ;
	
	printf("Enter the value to delete :: ") ;
	scanf("%d",&n) ;
	printf("\n") ;
	root = delete(root,n) ;
	
	inOrder(root) ;
        printf("\n") ;

	return 0 ;

}
