#include<stdio.h>


//hafýzanýn ilk adresine eriþebilmek için ptr döndüren fonk.
int *input(){
    int *ptr,i;
    ptr=(int *)malloc(5*sizeof(int));
    printf("enter 5 numbers: ");
    for(int i=0;i<5;i++){
        scanf("%d",ptr+i));
    }
    return ptr;
}

int main(){
    //adres ptr iþaretçisi tarafýndan alýnýr.
    int i,sum=0;
    int *ptr=input();
    for(i=0;i<5;i++){
        sum+=*(ptr+i);
    }
    printf("sum is: %d",sum);
    free(ptr);
    ptr=NULL;

    return 0;
}
