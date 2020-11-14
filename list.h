#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#define MAX 128

struct Qnode {
  char state[MAX];
  struct Qnode* next;
}Qnode;

struct Enode {
  char input;
  struct Enode* next;
}Enode;

struct Tnode {
  char istate[MAX];
  char input;
  char fstate[MAX];
  struct Tnode* next;
}Tnode;

void Tprint(struct Tnode *head)
{
  int i;
  i=0;
  struct Tnode* curr=head;
  printf("print\n");
  while(curr!=NULL)
  {printf("(%s %c)->(%s)\n",curr->istate, curr->input, curr->fstate);curr=curr->next;i++;}
  printf("\n");

}

struct Tnode * Tadd(struct Tnode* head, char *istate, char input, char*fstate, int l1, int l2)
{
    struct Tnode* new = (struct Tnode*) malloc(sizeof(struct Tnode)); 
    struct Tnode *curr = head;  
  new->input=input;
  int i,j;
  
  for(i=0;i<l1;i++){new->istate[i]=istate[i];}
  for(i=0;i<l2;i++){new->fstate[i]=fstate[i];}
  //new->istate=istate;
  //new->fstate=fstate;
  new->istate[l1]=0;
  new->fstate[l2]=0;

  if(head->input==0)
  {
   head->input=new->input;
  for(i=0;i<l1;i++){head->istate[i]=istate[i];}
  for(i=0;i<l2;i++){head->fstate[i]=fstate[i];}
   head->next=NULL;
   return head;
  }
  else
  {
   while (1) 
   {if(curr->next==NULL){curr->next=new;break;}curr = curr->next;} 


    /*curr=head;
        while (curr!= NULL) 
        {printf("the list is %s\n",curr->state);curr = curr->next;} */

    return head; 


  }
 


}




void Eprint(struct Enode* head)
{
  int i;
  i=0;
  struct Enode* curr=head;
  printf("print\n");
  while(curr!=NULL)
  {printf("%c", curr->input);curr=curr->next;i++;}
  printf("\n");
}

struct Enode* Eadd(struct Enode* head,char input)
{
    struct Enode* new = (struct Enode*) malloc(sizeof(struct Enode)); 
    struct Enode *curr = head;  
  if(head->input==0)
  {head->input=input;return head;}
  while(curr->next!=NULL)
  {curr=curr->next;}
  curr->next=new;
  new->input=input;
  new->next=NULL;
  return head;
}



//Qprint function
void Qprint(struct Qnode* head)
{
  int i;
  i=0;
  struct Qnode* curr=head;
  printf("print\n");
  while(curr!=NULL)
  {printf("%s", curr->state);curr=curr->next;i++;}
  printf("\n");  
}

//Qadd function
struct Qnode* Qadd(char* str, struct Qnode* head, int length)
{
    char string[length];
    int i;
    for(i=0;i<length;i++){string[i]=str[i];}
    //printf("for comparison, %s %s\n", string, str);
    struct Qnode* new = (struct Qnode*) malloc(sizeof(struct Qnode)); 
    struct Qnode *curr = head;  
    for(i=0;i<length;i++){new->state[i]  = string[i];}
    new->state[i+1]=0; 
    new->next = NULL; 
    //printf("just checkings %s %s\n", str, new->state);
    if(head->state[0]==0)
    {//printf("head is new %s %s\n",new->state, head->state);
     for(i=0;i<length;i++){head->state[i]=new->state[i];}head->next=NULL;return head;}

    /*if (head == NULL) 
    {  head=new;


       head ->next= NULL; 
       
       if(head==NULL){head=head->next;}
       return; 
    } */
    curr=head;
    while (1) 
        {if(curr->next==NULL){curr->next=new;break;}curr = curr->next;} 


    curr=head;
        while (curr!= NULL) 
        //{printf("the list is %s\n",curr->state);curr = curr->next;} 

    return head; 


}








