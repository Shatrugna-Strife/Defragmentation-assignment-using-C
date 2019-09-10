#include<stdio.h>
#include<header1.h>
void pfrelis(){
    int k=freem;
    printf("[ %d",k);
    while(ramarray[k+1]) k=ramarray[k+1],printf(",%d",k);
    printf(" ]\n");
    return ;
}
