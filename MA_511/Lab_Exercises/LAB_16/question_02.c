#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void preOrder( struct node * ptr ){

        if( !ptr ){
                return ;
        }

        printf("%d ",ptr->num) ;
        preOrder(ptr->left) ;
        preOrder(ptr->right) ;

        return ;

}

void getHeight( struct node * root , int l , int *H ){

	if( root == NULL ){
		
		if( l > *H ) *H = l ;
		return ;

	}

	getHeight( root->left , l+1 , H ) ;
	getHeight( root->right , l+1 , H ) ;

	return ;

}
int main( void ){

        int m ;

        printf("Enter the value of m :: ") ;
        scanf("%d",&m) ;
        
        srand( time(0) ) ;

        FILE *fp1 = fopen("tree.dat","w") ;

        double r ;
        int k ;

        printf("Contents of file1 :: ") ;

        for( int i = 0 ; i < m ; i++ ){

                r = ( rand() * 1.0 )/((long)RAND_MAX + 1 ) ;

                k = 1 + (int)(r*50) ;
                printf("%d ",k) ;
                fprintf(fp1,"%d\n",k) ;
                
        }

        fclose(fp1) ;

	fp1 = fopen("tree.dat","r+") ;
	
	struct node * root = NULL ;

	int h ;

	for( int i = 0 ; i < m ; i++ ){
		
		fscanf(fp1,"%d",&h) ;
		root = insert(root,h) ;

	}

	printf("\n") ;
	printf("Binary Search Tree PreOrder :: ") ;
	preOrder(root) ;
        printf(".\n") ;

	int *H = (int *)malloc(sizeof(int)) ;

	*H = 0 ;

	getHeight(root,0,H) ;

	printf("\n") ;
	printf("Height :: %d.\n",*H) ;

	fclose(fp1) ;
	return 0 ;

}	
