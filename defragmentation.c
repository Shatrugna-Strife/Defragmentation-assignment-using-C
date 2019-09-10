#include<stdio.h>
#include<header1.h>
void defragmentize(){
int i;
for(i=1;i<MAX;i++){
if(startarray[i]){
int n=i;
int head=startarray[n],temporary=head,previous=0;
while(temporary){
int k;
for(k=1;k<temporary;k+=3){
if(ramarray[k]==-1){ 
ramarray[k]=ramarray[temporary];
ramarray[temporary]=-1;
if(ramarray[temporary+2]==0){
startarray[n]=k;
ramarray[k+2]=0;
ramarray[k+1]=ramarray[temporary+1];
ramarray[temporary]=-1;
if(ramarray[temporary+1]) ramarray[ramarray[temporary+1]+2]=k;
break;
}
else if(ramarray[temporary+1]==0){
previous=ramarray[temporary+2];
ramarray[previous+1]=k;
ramarray[k+2]=previous;
ramarray[k+1]=0;
ramarray[temporary]=-1;
break;
}
else{
previous=ramarray[temporary+2];
int next=ramarray[temporary+1];
ramarray[previous+1]=k;
ramarray[next+2]=k;
ramarray[k+1]=next;
ramarray[k+2]=previous;
ramarray[temporary]=-1;
break;
}
}
}
temporary=ramarray[temporary+1];
}
}
}
for(i=1;i<MAX;i+=3){
if(ramarray[i]==-1) {freem=i;break;}
}
for(i=freem;i<MAX;i+=3){
ramarray[i]=-1;
if(i+3<MAX) ramarray[i+1]=i+3;
else ramarray[i+1]=0;
if(i!=freem) ramarray[i+2]=i-3;
else ramarray[i+2]=0;
}
printf("SUCCESS\n");
}
