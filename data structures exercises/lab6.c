
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int num;
	int note;
	struct node *left;
	struct node *right;

};


struct node *insertElement(struct node **,int,int);
void inorderTraversal(struct node *);
int tree_level(struct node *);
void display_level(struct node*,struct node*,int,char);
void display_level_order(struct node *);



struct node *insertElement(struct node **tree, int val1,int val2){
	struct node *ptr, *nodeptr, *parentptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->num=val1;
	ptr->note=val2;
	ptr->left=NULL;
	ptr->right=NULL;

	if(*tree==NULL){
		(*tree)=ptr;
		(*tree)->left=NULL;
		(*tree)->right=NULL;
	}
	else{
		parentptr=NULL;
		nodeptr=(*tree);
		while(nodeptr!=NULL){
			parentptr=nodeptr;
			if(val2<nodeptr->note){
				nodeptr=nodeptr->left;
			}
			else{
				nodeptr=nodeptr->right;
			}
		}
		if(val2<parentptr->note){
			parentptr->left=ptr;
		}
		else{
			parentptr->right=ptr;
		}
	}

	return (*tree);


	}

void inorderTraversal(struct node *tree){

	if(tree!=NULL){
		inorderTraversal(tree->left);
		printf("%d %d\n",tree->num,tree->note);
		inorderTraversal(tree->right);
	}
}

int tree_level(struct node *tree){
	if(tree==NULL){
		return 0;
	}
	else{
		int left_l,right_l;
		left_l=tree_level(tree->left);
		right_l=tree_level(tree->right);

		if(left_l>right_l){
			return (left_l+1);
		}
		else{
			return (right_l+1);
		}
	}

}

void display_level_order(struct node *tree){
	int h,i;
	h=tree_level(tree);

	for(i=0;i<h;i++){
		display_level(tree,NULL,i,' ');
		printf("\n");
	}
}

void display_level(struct node *tree,struct node *ptr,int x,char y){
	if(tree==NULL){
		return;
	}
	else if(x==0){
		if(ptr!=NULL){
			printf("%d %d (%d %c) ",tree->num,tree->note,ptr->note,y);
		}
		else{
			printf("%d %d",tree->num,tree->note);
		}
	}
	else{
		display_level(tree->left,tree,x-1,'L');
		display_level(tree->right,tree,x-1,'R');
	}
}


int main(){
	struct node *tree=NULL;
	int numara,notlar;



	while(1){
		scanf("%d",&numara);
		if(numara==-1){
			break;
		}
		scanf("%d",&notlar);
		tree=insertElement(&tree,numara,notlar);

	}

	inorderTraversal(tree);
	printf("\n");
	display_level_order(tree);

	return 0;
}
