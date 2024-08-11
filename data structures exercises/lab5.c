#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data[50];
	int priority;
	struct node *next;
};

void display(struct node* start){

	struct node *temp;
	temp=start;

	while(temp!=NULL){
		printf("%s\n",temp->data);
		temp=temp->next;
	}

}

void sort(struct node *start){
	if(start==NULL || start->next==NULL){
		return;
	}

	struct node *ptr1,*ptr2,*new_node;
	int i;
	char arr[50];

	ptr1=start;

	while(ptr1->next !=NULL){
		new_node=ptr1->next;
		ptr2=start;

		while(ptr2!=new_node){
			if(ptr2->priority >new_node->priority ||(ptr2->priority==new_node->priority && strcmp(ptr2->data,new_node->data)>0)){
				i=ptr2->priority;
				ptr2->priority=new_node->priority;
				new_node->priority=i;

				strcpy(arr,ptr2->data);
				strcpy(ptr2->data,new_node->data);
				strcpy(new_node->data,arr);
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}




}


int main(){
	struct node *ptr,*temp,*head;
	char input[50];

	head=NULL;
	temp=NULL;

	scanf(" %[^\n]",input);

	while(strcmp(input,"-1")!=0){

		ptr=(struct node*)malloc(sizeof(struct node));



		if(strcmp(input,"Annem")==0 || strcmp(input,"Babam")==0|| strcmp(input,"Kardesim")==0){
			strcpy(ptr->data,input);
			ptr->priority=1;

		}
		else if(strcmp(input,"Dayim")==0|| strcmp(input,"Teyzem")==0|| strcmp(input,"Amcam")==0||strcmp(input,"Halam")==0){
			strcpy(ptr->data,input);
			ptr->priority=2;

		}
		else if(strcmp(input,"Isyeri")==0 ||strcmp(input,"Okul")==0){
			strcpy(ptr->data,input);
			ptr->priority=3;

		}
		else if(strcmp(input,"Arkadasim1")==0|| strcmp(input,"Arkadasim2")==0||strcmp(input,"Arkadasim3")==0 || strcmp(input,"Arkadasim4")==0|| strcmp(input,"Arkadasim5")==0){
			strcpy(ptr->data,input);
			ptr->priority=4;

		}
		else if(strcmp(input,"Banka")==0 || strcmp(input,"Kargo")==0){
			strcpy(ptr->data,input);
			ptr->priority=5;

		}
		else if(strcmp(input,"Reklam")==0){
			strcpy(ptr->data,input);
			ptr->priority=6;
		}



		ptr->next=NULL;


		if(head==NULL){
			head=ptr;
			temp=ptr;
		}
		else{
			temp->next=ptr;
			temp=ptr;

		}

		scanf(" %[^\n]",input);



	}
	sort(head);
	display(head);

	while(head!=NULL){
		ptr=head;
		head=head->next;
		free(ptr);
	}

	return 0;


}
