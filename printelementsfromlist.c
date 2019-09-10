#include<stdio.h>
#include<header1.h>
int noofelelis(int n){
int head=startarray[n],temporary=head,prev=0;
int count=0;
while(temporary){
count++;
temporary=ramarray[temporary+1];
}
return count;
}
