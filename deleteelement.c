#include<stdio.h>
#include<header1.h>
void deleteelementfromlist(){
int n,key;
printf("List you want to delete from: ");
scanf("%d",&n);
printf("Enter the key value: ");
scanf("%d",&key);
if(!startarray[n]){
printf("FAILURE:LIST EMPTY\n");
return;
}
int head=startarray[n];
int temporary=head,previous=0;
while(temporary){
if(key==ramarray[temporary]) break;
previous=temporary;
temporary=ramarray[temporary+1];
}
if(!temporary){
printf("FAILURE:ELEMENT NOT PRESENT IN LIST\n");
return;
}
printf("SUCCESS\n");
if(previous==0){
startarray[n]=ramarray[temporary+1];
int next=ramarray[temporary+1];
ramarray[next+2]=0;
newfrelis(temporary);
}
else if(!ramarray[temporary+1]){
ramarray[previous+1]=0;
newfrelis(temporary);
}
else{
int next=ramarray[temporary+1];
ramarray[previous+1]=next;
ramarray[next+2]=previous;
newfrelis(temporary);
}
}
