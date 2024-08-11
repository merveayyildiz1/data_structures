#include<stdio.h>
int main(){
    int i,arr[20],n,pos;
    printf("enter the number of elements: \n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the position from which the number has to be deleted: ");
    scanf("%d",&pos);
    for(i=pos;i<=n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

    printf("new array is: \n");

    for(int i=0;i<n;i++){
        printf("arr[%d]=%d\n",i,arr[i]);

    }


    return 0;
}
