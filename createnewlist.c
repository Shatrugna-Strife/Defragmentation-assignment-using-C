#include<stdio.h>
#include<header1.h>
void createnewlist(){
printf("The sequence number of the newly created list is:%d\n",++numberoflist);
int key;
printf("Enter key value to be inserted in the newly created list-%d :",numberoflist);
scanf("%d",&key);
if(numberoflist>MAX){
printf("FAILURE: MEMORY NOT AVAILABLE\n");
numberoflist--;
return;
}
printf("SUCCESS\n");
int head=newplace();
startarray[numberoflist]=head;
ramarray[head]=key;
ramarray[head+1]=ramarray[head+2]=0;
return;
}
