#include<stdio.h>
#include<header1.h>

void printalllist(){
int i;
for(i=1;i<MAX;i++) {
if(startarray[i]){
printf("Elements of list-%d are: \n",i);
printf("key    next    previous\n");
{
int n=i;
int head=startarray[n],temporary=head,previous=0;
while(temporary){
int value=ramarray[temporary];
int next=ramarray[temporary+1];
int previous=ramarray[temporary+2];
if(!next && !previous) printf("%d     NIL    NIL\n",value);
else if(!next) printf("%d     NIL    %d\n",value,previous);
else if(!previous) printf("%d     %d     NIL\n",value,next);
else printf("%d     %d     %d \n",value,next,previous);
temporary=ramarray[temporary+1];
}
}
printf("\n");
}
}
}
