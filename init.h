//list.h
#include "list.h"


void InitLists(struct Qnode * Qhead, struct Enode * Ehead, struct Qnode * Fhead, struct Tnode * Thead)
{
   char tempstr[MAX];
   char tempchar;
   FILE *fi;
   FILE *fo;
   char *inputname="input.txt";
   char *outputname="output.txt";           //opens and begins reading the file
   fi=fopen(inputname, "r");
   fo=fopen(outputname, "w");
   if (fi == NULL)
   {
        printf("Could not open file %s\n",inputname);
        return;
   }


			//finds list of states
  tempchar=fgetc(fi);
    if(tempchar!='Q')
     {printf("formatting is wrong at the beginning1\n");return;}
  tempchar=fgetc(fi);
    if(tempchar!='=')
     {printf("formatting is wrong at the beginning1\n");return;}
  tempchar=fgetc(fi);
    if(tempchar!='{')
     {printf("formatting is wrong at the beginning1\n");return;}
  
int i;

  while(1)  
  {
    i=0;
    tempchar=fgetc(fi);
    //printf("tempchar %c\n", tempchar);
    if(tempchar!=',' && tempchar!='}')
    {tempstr[i]=tempchar;}

    else if (tempchar == ',')
    {
       tempstr[i+1]=0;

       Qhead=Qadd(tempstr,Qhead,i+1);

	//printf("the head is %s, then %s",Qhead->state, Qhead->next->state);
        //Qprint(Qhead);
    }


    else if (tempchar == '}')
    {break;}

    i++;
  }
    Qprint(Qhead);
			//finds list of inputs
  tempchar=fgetc(fi);
  tempchar=fgetc(fi);
    if(tempchar!='E')
     {printf("formatting is wrong at the beginning1\n");return;}
  tempchar=fgetc(fi);
    if(tempchar!='=')
     {printf("formatting is wrong at the beginning1\n");return;}
  tempchar=fgetc(fi);
    if(tempchar!='{')
     {printf("formatting is wrong at the beginning1\n");return;}

  while(1)
  {
    tempchar=fgetc(fi);
    if(tempchar=='}'){break;}
    if(tempchar!=','){Ehead=Eadd(Ehead, tempchar);}
  }
    Eprint(Ehead);

			//finds initial state
  char initstate[MAX];
  for(i=0;i<3;i++){tempchar=fgetc(fi);}
  i=0;
  while(tempchar!='}'){initstate[i]=tempchar;tempchar=fgetc(fi);}
  initstate[i+1]=0;
  printf("print \n%s\n",initstate);

			//finds subset of states that are 'final'
  char tempstring[MAX];
  for(i=0;i<5;i++){tempchar=fgetc(fi);}
  i=0;
  while(tempchar!='}')
  {
    if(tempchar==','){Fhead=Qadd(tempstring, Fhead, i);i=0;}
    else{tempstring[i]=tempchar;i++;}

    tempchar=fgetc(fi);
  }
  Fhead=Qadd(tempstring, Fhead, i);
  Qprint(Fhead);

			//creates linked list of transition functions
  for(i=0;i<7;i++)
  {tempchar=fgetc(fi);}
//for(i=0;i<6;i++)
//{tempchar=fgetc(fi);printf("%c",tempchar);}
  i=0;
  int j;
  char tempc;
  char tstring[MAX];
  while(tempchar!='}')

 while(tempchar!='}')
 {
  tempchar=fgetc(fi);
  i=0;

  while(tempchar!=',')
  {
   tempstring[i]=tempchar;
   tempchar=fgetc(fi);i++;
  }
   tempstring[i+1]=0;
   tempc=fgetc(fi);
   for(j=0;j<4;j++){tempchar=fgetc(fi);}
  j=0;

  while(tempchar!=')')
  {
   tstring[j]=tempchar;
   tempchar=fgetc(fi);j++;
  }
  tstring[j+1]=0;printf("the strings are %s %c %s",tempstring, tempc, tstring);
  Thead=Tadd(Thead, tempstring, tempc, tstring, i, j);
  tempchar=fgetc(fi);
  tempchar=fgetc(fi);
  Tprint(Thead);
 }
Tprint(Thead);



}

