#include"common.h"
int delete_list(Dlist **head,Dlist **tail)
{
    //1.Declaration 
    Dlist *temp,*temp2;

    //2.Error Check
    if(*head == NULL)
    {   
        return LIST_EMPTY;
    }   


    temp= *head;
    //if no nodes are there head and tail should point to nothing
    *head=NULL;
    *tail=NULL;
    //traverse till last node
    while(temp != NULL)
    {   
        //store the temp in a new variable temp2
        temp2=temp;
        //increment temp
        temp=temp->next;
        //freeing the previous node
        free(temp2);

    }   

    return SUCCESS;
}

