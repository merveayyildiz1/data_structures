#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(){
    char str[100],reverse_str[100];

    printf("enter string: ");

    fgets(str,sizeof(str),stdin);
    int i=0;
    int j=strlen(str)-1;

    while(str[i]!='\0'){
            reverse_str[j]=str[i];
            i++;
            j--;
    }
    reverse_str[strlen(str)]='\0';
    puts(reverse_str);

    return 0;
}
