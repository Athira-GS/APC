#include "common.h"
int print(Dlist *head,int sign)
{
	
    if(head==NULL)
    {   
        return FAILURE;
    } 

  printf("\n");	
  if(sign == 1)
  {
	  printf(" - ");
  }
    while(head != NULL)
    { 
		

        printf("-->%09d",head->data);
        head= head->next;
    }   
  printf("\n"); 
    return SUCCESS;

}

