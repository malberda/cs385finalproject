//project.c
//michael alberda
//madi dabolt



#include "init.h"


int main()
{
   

   struct Qnode* qhead;
    qhead=(struct Qnode*)malloc(sizeof(Qnode));
    qhead->state[0]=0;
    qhead->next=NULL;
   struct Enode* ehead;
    ehead=(struct Enode*)malloc(sizeof(Enode));
    ehead->input=0;
    ehead->next=NULL;
   struct Qnode* fhead;
    fhead=(struct Qnode*)malloc(sizeof(Qnode));
    fhead->state[0]=0;
    fhead->next=NULL;
   struct Tnode* thead;
    thead=(struct Tnode*)malloc(sizeof(Tnode));
    thead->input=0;
    thead->next=NULL;

   InitLists(qhead, ehead, fhead, thead);

   

}

 


