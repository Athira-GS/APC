#include"common.h"

int apc_sub(char num1[],char num2[])
{
	Dlist *head1=NULL;
	Dlist *tail1=NULL;
	Dlist *head2=NULL;
	Dlist *tail2=NULL;
	Dlist *head3=NULL;
	Dlist *tail3=NULL;

	int len_1=strlen(num1) -1;
	printf("len1 is %d\n", len_1);
	int len_2=strlen(num2)-1;
	int i,j;
	char arr_1[10];
	char arr_2[10];
	int int_arr_1;
	int int_arr_2;
	int sign =0;

	//for num1
	while(1)
	{

		//check whether len_1 is greater than 9 or not
		if(len_1 >=9)
		{
			printf("hi\n:");
			//store 9 characters of num1 into an arry
			for(i=(len_1-9)+1,j=0;i<=len_1;i++,j++)
			{
				arr_1[j]=num1[i];
			}
			arr_1[j]='\0';
			printf("arr_1=%s\n",arr_1);
			//convert character to integer
			int_arr_1=atoi(arr_1);
			printf("int_arr_1=%d\n",int_arr_1);
			//call insert at first function to store  each 9 digits in a double linked list
			insert_at_first(&head1,&tail1,int_arr_1);
			//updating len_1
			len_1=len_1-9;

		}
		else
		{
			for(i=0,j=0;i<=len_1;i++,j++)
			{
				arr_1[j]=num1[i];
			}
			arr_1[j]='\0';
			//convert character to integer
			int_arr_1=atoi(arr_1);
			//call insert at first function to store  each 9 digits in a double linked list
			insert_at_first(&head1,&tail1,int_arr_1);

			break;


		}

	}
	printf("LL1:");
	print(head1,sign);


	//for num2

	while(1)
	{
		//check whether len_1 is greater than 9 or not
		if(len_2 >=9)
		{
			//store 9 characters of num1 into an arry
			for(i=(len_2-9)+1,j=0;i<=len_2;i++,j++)
			{
				arr_2[j]=num2[i];

			}
			arr_2[j]='\0';
			printf("arr_2=%s\n",arr_2);
			//convert character to integer
			int_arr_2=atoi(arr_2);
			printf("int_arr_2=%d\n",int_arr_2);
			//call insert at first function to store  each 9 digits in a double linked list
			insert_at_first(&head2,&tail2,int_arr_2);
			//updating len_1
			len_2=len_2-9;

		}
		else
		{
			for(i=0,j=0;i<=len_2;i++,j++)
			{
				arr_2[j]=num2[i];
			}
			arr_2[j]='\0';
			//convert character to integer
			int_arr_2=atoi(arr_2);
			//call insert at first function to store  each 9 digits in a double linked list
			insert_at_first(&head2,&tail2,int_arr_2);
			break;


		}

	}
	printf("LL2:");
	print(head2,sign);

	//declare temp1 &temp2
	Dlist *temp1,*temp2;
	temp1=tail1;
	temp2=tail2;
	int diff;


	//assigning sign variable for 3 conditions
	while(1)
	{
		//if num1 is greater than num2
		if((temp2 == NULL) && (temp1!=NULL))
		{
			//declare sign as 0
			sign=0;
			break;
		}
		//if num2 is greater than num1
		if((temp1==NULL) && (temp2!=NULL))
		{
			//declare sign as 0
			sign=1;
			break;
		}
		//if both num1 and num2 have equal no.of digits
		if((temp1==NULL) && (temp2==NULL))
		{
			//declare sign
			sign=2;
			break;
		}

		//updating temp1 and temp2
		temp1=temp1->prev;
		temp2=temp2->prev;
	}
	printf("sign=%d\n",sign);


	//finding sign for 3rd case in which both num1 and num2 have same no.of digits

	if(sign == 2)
	//if((temp1==NULL) && (temp2==NULL))
	{
		printf("hi");
		//reinitialising temp1 &temp2
		temp1=tail1;
		temp2=tail2;
		while(1)
		{
			//compare each nodes of num1 and num2
			if(temp1->data > temp2->data)
			{
				sign=0;

			}
			else
			{
				sign=1;

			}


			//updating temp1 &temp2
			temp1=temp1->prev;
			temp2=temp2->prev;
			if((temp1 == NULL) && (temp2==NULL))
			{
				break;
			}

		}
	}
		//if num2 >num 1
		if(sign == 1)
		{
			//declare temp1 and temp2 because we need to reverse numbers
			temp1=tail2;
			temp2=tail1;
			while(1)
			{


			//comparing datas of each node
			if(temp1->data < temp2->data)
			{
				//taking borrow from previous node and add with this node
				diff = (1000000000+temp1->data) - temp2->data;
				//subtracting borrow taken from previous node
				temp1->prev->data=temp1->prev->data - 1;

			}
			else
			{
				diff=temp1->data - temp2->data;
			}
			//store the difference into 3rd LL
			insert_at_first(&head3,&tail3,diff);
			temp1=temp1->prev;
			temp2=temp2->prev;

			if((temp1 == NULL) || (temp2 == NULL))
			{
				break;
			}
			}



		}
		//if num1 is greater than num2
		if(sign == 0)
		{
			temp1=tail1;
			temp2=tail2;
			while(1)
			{
			//comparing datas of each node
			if(temp1->data < temp2->data)
			{
				//taking borrow from previous node and add with this node
				diff = (1000000000+temp1->data) - temp2->data;
				//subtracting borrow taken from previous node
				temp1->prev->data=temp1->prev->data - 1;

			}
			else
			{
				diff=temp1->data - temp2->data;
			}
			//store the difference into 3rd LL
			insert_at_first(&head3,&tail3,diff);
			
			temp1=temp1->prev;
			temp2=temp2->prev;

			if((temp1 == NULL) || (temp2 == NULL))
			{
				break;
			}

		}

	}

//if num1 is greater we need to store the remaining digits of num1 to 3rd LL

if((temp1!=NULL) && (temp2==NULL))
{
//	temp1=temp1->prev;
	while(temp1!=NULL)
	{
		insert_at_first(&head3,&tail3,temp1->data);


		temp1=temp1->prev;
	}
}


//if num2 is greater we need to store the remaining digits of num2 to 3rd LL
if((temp2!=NULL) && (temp1==NULL))
{
//	temp2=temp2->prev;
	while(temp2!=NULL)
	{
		insert_at_first(&head3,&tail3,temp2->data);
		temp2=temp2->prev;

	}
}
//printing 3rd LL
print(head3,sign);

	 //freeing the list
    delete_list(&head1,&tail1);
    delete_list(&head2,&tail2);
    delete_list(&head3,&tail3);











}





















