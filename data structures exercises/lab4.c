#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
	char data[50];
	struct stack *next;
};

struct stack *ekle(struct stack *top,char *val){
	struct stack *ptr;
	ptr=(struct stack*)malloc(sizeof(struct stack));
	strcpy(ptr->data,val);
	if(top==NULL){
		ptr->next=NULL;
		top=ptr;
	}
	else{
		ptr->next=top;
		top=ptr;
	}
	return top;
}

struct stack *cikar(struct stack *top){
	struct stack *ptr;
	ptr = top;
 	top = top -> next;
 	free(ptr);

	return top;
	}

void find_error(char arr[],char tags[][50],int *count) {
    int i,j;
	*count = 0;
	for(i=0;arr[i]!='\0';i++){
        if(arr[i]=='<'){
        	int start=i+1;
        	int end=-1;

    		for(j=start;arr[j]!='\0';j++){
                if(arr[j]=='>'){
                    end=j;
                    break;
                }
            }
            if(end!=-1){
                int k;
                for(k=start;k<end && k-start<49;k++){
                    tags[*count][k-start]=arr[k];
                }
                tags[*count][k-start]='\0';
                (*count)++;
            }
            i = end;
        }
    }
}

int main(){
	struct stack *top=NULL;
	int count,i,j,p;
	char html[1000];
	char arr[100][50];
	char arr2[10];
	scanf(" %[^\n]",html);

	find_error(html,arr,&count);

    for (i=0;i<count;i++) {
        if(arr[i][0]!='/'){
			top=ekle(top,arr[i]);
		}
    	else{
			size_t uzunluk1=strlen(arr[i]);
			arr2[10];
			for(j=0;j<uzunluk1;j++){
				arr2[j]=arr[i][1+j]	;
			}
			if(strcmp(arr2,top->data)==0){
				top=cikar(top);
			}
		}
	}

	if(top->data==NULL){
		printf("correct");
	}
	else{
		printf("error <%s>",top->data);
	}

	return 0;
}
