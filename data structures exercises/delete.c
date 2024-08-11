#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(){
    char str[50],new_str[50];
    int bas,son,silinecek_sayi;

    printf("enter string: ");
    fgets(str,sizeof(str),stdin);

    printf("silinecek ilk index: ");
    scanf("%d",&bas);
    printf("silinecek son index: ");
    scanf("%d",&son);
    silinecek_sayi=son-bas+1;


    int i,j=0;


        for(int i=0;i<strlen(str);i++){
            if(i<bas || i>son){
                new_str[j++]=str[i];
            }
        }
        new_str[j]='\0';


    puts(new_str);


    return 0;
}
