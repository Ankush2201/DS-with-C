#include<stdio.h>

void main(){
    int n;
    char a,b,c;
    printf("ENTER THE NO. OF DISK\n");
    scanf("%d",&n);
    printf("The disk is %d \n",n);
    tower(n,'a','b','c');
}
void tower(int num,char beg,char aux,char end){
    if(num<=0)
        printf("invalid entry\n");
    else if(num==1)
        printf("Disk moved from %c to %c\n",beg ,end);
    else{
        tower(num-1,beg,end,aux);
        tower(1,beg,aux,end);
        tower(num-1,aux,beg, end);
    }
}