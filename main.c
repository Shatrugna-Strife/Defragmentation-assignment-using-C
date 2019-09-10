#include <stdio.h>
#include <stdlib.h>
#define MAX 52
#include<header1.h>
#include<header2.h>





void createnewlist(){
int i;
for(i=0;i<MAX;i++) 
ramarray[i]=-1;
int k=freem;
ramarray[freem+2]=0;
while(k<MAX-MAX%3){
sizeofrlist++;
ramarray[k+1]=k+3;
if(k!=freem) ramarray[k+2]=k-3;
k+=3;
}
ramarray[k-2]=0;
}

int newplace(){
sizeofrlist--;
totalnodes++;
int oldFreee=freem;
freem=ramarray[freem+1];
ramarray[freem+2]=0;
return oldFreee;
}




void newfrelis(int node){
ramarray[node+1]=freem;
ramarray[freem+2]=node;
freem=node;
ramarray[node]=-1;
ramarray[node+2]=0;
sizeofrlist++;
totalnodes--;
return;
}

int main()
{
int pointer=1;
createnewlist();
while(pointer!=0){
printf("Select from the given options:\n");
printf("Create a new list-1\n");
printf("Insert a new element in a given list in sorted order-2\n");
printf("Delete an element from a given list-3\n");
printf("Count total elements excluding free list-4\n");
printf("Count total elements of a list-5 \n");
printf("Display all lists-6 \n");
printf("Display free list-7 \n");
printf("Perform defragmentation-8 \n");
printf("Press 0 to exit \n");
printf("Select an option: ");
scanf("%d",&pointer);
switch(pointer){
case 1: createnewlist();
break;
case 2: insertinlist();
break;
case 3: deleteelementfromlist();
break;
case 4: printf("Program outputs: Total number of nodes in all lists are %d\n",totalnodes);
break;
case 5: printf("Enter the List Number: ");
scanf("%d",&k);
printf("Program outputs: Total number of nodes in list %d\n",noofelelis(k));
break;
case 6: printalllist();
break;
case 7: pfrelis();
break;
case 8: defragmentize();
break;
}
}
return 0;
}
