#include <stdio.h>
#include <stdlib.h>
#define SIZE 28

// if array[j]==0 then previous node/next node does not exist.
// if array[j]==-1 then j belongs to the freeList.
//indexing in the array starts from 1

int ramarray[SIZE];
int startarray[SIZE];
int freem=1;
int numLists=0;
int sizeOfFreeList=0;
int nodesInserted=0;

void createFreeList(){
    int i;
    for(i=0;i<SIZE;i++) ramarray[i]=-1; //initialise free elements of array with value -1
    int k=freem;
    ramarray[freem+2]=0;
    while(k<SIZE-SIZE%3){
        sizeOfFreeList++;
        ramarray[k+1]=k+3;
        if(k!=freem) ramarray[k+2]=k-3;
        k+=3;
    }
    ramarray[k-2]=0;
}

int getNewIndex(){
    sizeOfFreeList--;
    nodesInserted++;
    int oldFreee=freem;
    freem=ramarray[freem+1];
    ramarray[freem+2]=0;
    return oldFreee;
}

void createNewList(){
    printf("The sequence number of the newly created list is:%d\n",++numLists);
    int key;
    printf("Enter key value to be inserted in the newly created list-%d :",numLists);
    scanf("%d",&key);
    if(numLists>SIZE){
        printf("�FAILURE: MEMORY NOT AVAILABLE\n");
        numLists--;
        return;
    }
    printf("SUCCESS\n");
    int head=getNewIndex();
    startarray[numLists]=head;
    ramarray[head]=key;
    ramarray[head+1]=ramarray[head+2]=0;
    return;
}

void insertInList(){

    int n,key;
    printf("List you want to insert in: ");
    scanf("%d",&n);
    printf("Enter the key value: ");
    scanf("%d",&key);
    if(!startarray[n]){
        printf("FAILURE: NO SUCH LIST EXISTS\n");
        return;
    }
    if(!sizeOfFreeList){
        printf("�FAILURE: MEMORY NOT AVAILABLE\n");
        return;
    }
    printf("SUCCESS\n");
    sizeOfFreeList--;
    int head=startarray[n];
    if(key<ramarray[head]){
        //inserting node at the beginning
        int newHead=getNewIndex();
        startarray[n]=newHead;
        ramarray[newHead]=key;
        ramarray[newHead+1]=head;
        ramarray[newHead+2]=0;
        ramarray[head+2]=newHead;
        return;
    }
    int tmp=head,prev=0;
    while(tmp){
        if(key<ramarray[tmp]) break;
        prev=tmp;
        tmp=ramarray[tmp+1];
    }
    if(!tmp){
        //inserting node at the end
        int newNode=getNewIndex();
        ramarray[prev+1]=newNode;
        ramarray[newNode]=key;
        ramarray[newNode+1]=0;
        ramarray[newNode+2]=prev;
        return;
    }
    int newNode=getNewIndex();
    prev=ramarray[tmp+2];
    ramarray[tmp+2]=newNode;
    ramarray[newNode+2]=prev;
    ramarray[newNode]=key;
    ramarray[newNode+1]=tmp;
    ramarray[prev+1]=newNode;
    return;
}

void NewFreeList(int node){
    //making this node as the head of the free list i.e. free=node
    ramarray[node+1]=freem;
    ramarray[freem+2]=node;
    freem=node;
    ramarray[node]=-1;
    ramarray[node+2]=0;
    sizeOfFreeList++;
    nodesInserted--;
    return;
}

void DeleteFromList(){
    int n,key;
    printf("List you want to delete from: ");
    scanf("%d",&n);
    printf("Enter the key value: ");
    scanf("%d",&key);
    if(!startarray[n]){
        printf("�FAILURE:LIST EMPTY\n");
        return;
    }
    int head=startarray[n];
    int tmp=head,prev=0;
    while(tmp){
        if(key==ramarray[tmp]) break;
        prev=tmp;
        tmp=ramarray[tmp+1];
    }
    if(!tmp){
        printf("FAILURE:ELEMENT NOT PRESENT IN LIST\n");
        return;
    }
    printf("SUCCESS\n");
    if(prev==0){
        //deletion at the starting of the list
        startarray[n]=ramarray[tmp+1];
        int next=ramarray[tmp+1];
        ramarray[next+2]=0;
        NewFreeList(tmp);
    }
    else if(!ramarray[tmp+1]){
        //deleting at the end of the list
        ramarray[prev+1]=0;
        NewFreeList(tmp);
    }
    else{
        int next=ramarray[tmp+1];
        ramarray[prev+1]=next;
        ramarray[next+2]=prev;
        NewFreeList(tmp);
    }
}

int NoOfElementsInList(int n){
    int head=startarray[n],tmp=head,prev=0;
    int count=0;
    while(tmp){
        count++;
        tmp=ramarray[tmp+1];
    }
    return count;
}

void traverse(int n){
    int head=startarray[n],tmp=head,prev=0;
    while(tmp){
        int key=ramarray[tmp];
        int next=ramarray[tmp+1];
        int prev=ramarray[tmp+2];
        if(!next && !prev) printf("%d     NIL    NIL\n",key);
        else if(!next) printf("%d     NIL    %d\n",key,prev);
        else if(!prev) printf("%d     %d     NIL\n",key,next);
        else printf("%d     %d     %d \n",key,next,prev);
        tmp=ramarray[tmp+1];
    }
}

void printalllist(){
    int i;
    for(i=1;i<SIZE;i++) {//our array is one-indexed
        if(startarray[i]){
            printf("Elements of list-%d are: \n",i);
            printf("key    next    prev\n");
            traverse(i);
            printf("\n");
        }
    }
}

void printFreeList(){
    int k=freem;
    printf("[ %d",k);
    while(ramarray[k+1]) k=ramarray[k+1],printf(",%d",k);
    printf(" ]\n");
    return ;
}

void Fragmentize(int n)
{
    int head=startarray[n],tmp=head,prev=0;
    while(tmp){
        int k;
        for(k=1;k<tmp;k+=3){
            if(ramarray[k]==-1){ // free memory space in array detected before current object
                ramarray[k]=ramarray[tmp];
                ramarray[tmp]=-1;
                if(ramarray[tmp+2]==0){
                    //the list begins here
                    startarray[n]=k;
                    ramarray[k+2]=0;
                    ramarray[k+1]=ramarray[tmp+1];
                    ramarray[tmp]=-1;
                    if(ramarray[tmp+1]) ramarray[ramarray[tmp+1]+2]=k;
                    break;
                }
                else if(ramarray[tmp+1]==0){
                    //the list ends here
                    prev=ramarray[tmp+2];
                    ramarray[prev+1]=k;
                    ramarray[k+2]=prev;
                    ramarray[k+1]=0;
                    ramarray[tmp]=-1;
                    break;
                }
                else{
                    //in the middle
                    prev=ramarray[tmp+2];
                    int next=ramarray[tmp+1];
                    ramarray[prev+1]=k;
                    ramarray[next+2]=k;
                    ramarray[k+1]=next;
                    ramarray[k+2]=prev;
                    ramarray[tmp]=-1;
                    break;
                }
            }
        }
        tmp=ramarray[tmp+1];
    }
}

void defragmentize(){
    int i;
    for(i=1;i<SIZE;i++){
        if(startarray[i]){
            Fragmentize(i);
        }
    }
    for(i=1;i<SIZE;i+=3){
        if(ramarray[i]==-1) {freem=i;break;}
    }
    for(i=freem;i<SIZE;i+=3){
        ramarray[i]=-1;
        if(i+3<SIZE) ramarray[i+1]=i+3;
        else ramarray[i+1]=0;
        if(i!=freem) ramarray[i+2]=i-3;
        else ramarray[i+2]=0;
    }
    printf("SUCCESS\n");
}

int main()
{
    int n=1,i,k;
    createFreeList();
    while(n!=0){
        //for(i=1;i<SIZE;i++) printf("%d\n",array[i]);
        printf("Select from the given options:\n");
        printf("1. Create a new list\n");
        printf("2. Insert a new element in a given list in sorted order\n");
        printf("3. Delete an element from a given list\n");
        printf("4. Count total elements excluding free list\n");
        printf("5. Count total elements of a list \n");
        printf("6. Display all lists \n");
        printf("7. Display free list \n");
        printf("8. Perform defragmentation \n");
        printf("9. Press 0 to exit \n");
        printf("Select an option: ");
        scanf("%d",&n);
        switch(n){
            case 1: createNewList();
                    break;
            case 2: insertInList();
                    break;
            case 3: DeleteFromList();
                    break;
            case 4: printf("Program outputs: Total number of nodes in all lists are %d\n",nodesInserted);
                    break;
            case 5: printf("Enter the List Number: ");
                    scanf("%d",&k);
                    printf("Program outputs: Total number of nodes in list %d\n",NoOfElementsInList(k));
                    break;
            case 6: printalllist();
                    break;
            case 7: printFreeList();
                    break;
            case 8: defragmentize();
                    break;
        }
    }
    return 0;
}
