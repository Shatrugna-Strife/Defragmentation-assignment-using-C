#include<stdio.h>
#include<header1.h>
void insertinlist(){

int n,value;
printf("List you want to insert in: ");
scanf("%d",&n);
printf("Enter the key value: ");
scanf("%d",&value);
if(!startarray[n]){
printf("FAILURE: NO SUCH LIST EXISTS\n");
return;
}
if(!sizeofrlist){
printf("FAILURE: MEMORY NOT AVAILABLE\n");
return;
}
printf("SUCCESS\n");
sizeofrlist--;
int head=startarray[n];
if(value<ramarray[head]){
int newHead=newplace();
startarray[n]=newHead;
ramarray[newHead]=value;
ramarray[newHead+1]=head;
ramarray[newHead+2]=0;
ramarray[head+2]=newHead;
return;
}
int temporary=head,previous=0;
while(temporary){
if(value<ramarray[temporary]) break;
previous=temporary;
temporary=ramarray[temporary+1];
}
if(!temporary){
int newNode=newplace();
ramarray[previous+1]=newNode;
ramarray[newNode]=value;
ramarray[newNode+1]=0;
ramarray[newNode+2]=previous;
return;
}
int newNode=newplace();
previous=ramarray[temporary+2];
ramarray[temporary+2]=newNode;
ramarray[newNode+2]=previous;
ramarray[newNode]=value;
ramarray[newNode+1]=temporary;
ramarray[previous+1]=newNode;
return;
}
