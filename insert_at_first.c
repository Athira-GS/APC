#include"common.h"
int insert_at_first(Dlist **head,Dlist **tail,int data)
{
    //1.Declaration 
    Dlist *new,*prev,*next;
    //1.1 Create a node
    new = malloc(sizeof(Dlist));

//2.Error Check
if(new == NULL)
{
    return FAILURE;
}

//3. Update data and link part
new->data = data;
new->prev=NULL;
new->next=NULL;

//4. Check whether list is empty or not
if(*head == NULL)
{
    //4.1 Update  the head pointer
    *head = new;
    *tail=new;
    return SUCCESS;
}
//update head
new->next=*head;
(*head)->prev=new;

//7.Establish link
*head = new;
return SUCCESS;
}

