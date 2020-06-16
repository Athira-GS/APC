#include"common.h"

int apc_add(char num1[],char num2[])
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
	printf("len2 is %d\n", len_2);
	int i,j;
	char arr_1[10];
	char arr_2[10];
	int int_arr_1;
	int int_arr_2;
	int sign=0;

	//for num1
	while(1)
	{

		//check whether len_1 is greater than 9 or not
		if(len_1 >=10)
		{
		//	printf("hi\n:");
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
			printf("len_1=%d\n",len_1);

		}
		else
		{
			printf("len_1=%d\n",len_1);
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
		if(len_2 >=10)
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
			printf("len_2=%d\n",len_2);

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
	int carry=0,sum=0;

	while(1)
	{
		//finding the sum
		sum=temp1->data+temp2->data+carry;
		//check whether carry present or not
		if(sum >= 1000000000)
		{
			carry=1;
			//subtract carry inorder to store only 9 digits
			sum=sum-1000000000;
		}
		else
		{
			//redeclare carry as 0
			carry=0;
		}
		//call insert_at-first function to store the sum to 3rd double linked list
		printf("1st while sum is %d\n",sum);
		insert_at_first(&head3,&tail3,sum);

		//terminate the loop if either temp1 or temp2 reached head
		if((temp1 == head1) || (temp2 == head2))
		{
			//if(carry==1)
			//	{

			//	insert_at_first(&head3,&tail3,carry);
			//		}
			break;
		}
		//updating temp1 and temp2
		temp1=temp1->prev;
		temp2=temp2->prev;
	}

//if both num1 and num2 are equal length
	if((temp1==head1) && (temp2==head2))
	{
		if(carry==1)
		{
		printf("t1=h, t2=h sum is %d\n",sum);
			insert_at_first(&head3,&tail3,carry);

		}
	}
//if num1 is greater than num2
	if((temp1!=head1) && (temp2==head2))
	{
		temp1=temp1->prev;
		while(1)
		{
			//finding the sum if temp2 is not there
			sum=temp1->data+carry;
			//check whether carry present or not
			if(sum >= 1000000000)
			{
				carry=1;
				//subtract carry inorder to store only 9 digits
				sum=sum-1000000000;
			}
			else
			{
				//redeclare carry as 0
				carry=0;
			}
		printf("t1!=h, t2=h sum is %d\n",sum);
			insert_at_first(&head3,&tail3,sum);
			if(temp1 == head1)
			{
				if(carry==1)
				{
					insert_at_first(&head3,&tail3,carry);
				}

				break;

			}
			//updating temp1
			temp1=temp1->prev;
		}

		//	insert_at_first(&head3,&tail3,sum);

	}

	if((temp2!=head2) && (temp1==head1))
	{
	temp2=temp2->prev;
		while(1)
		{
			//finding the sum if temp2 is not there
			sum=temp2->data+carry;
			//check whether carry present or not
			if(sum >= 1000000000)
			{
				carry=1;
				//subtract carry inorder to store only 9 digits
				sum=sum-1000000000;
			}
			else
			{
				//redeclare carry as 0
				carry=0;
			}
		printf("t2!=h, t1=h sum is %d\n",sum);
			insert_at_first(&head3,&tail3,sum);
			if(temp2 == head2)
			{
				if(carry==1)
				{
					insert_at_first(&head3,&tail3,carry);
				}
				break;
			}
			//updating temp1
			temp2=temp2->prev;
		}
		//insert_at_first(&head3,&tail3,sum);
	}

		
	
printf("LL3:");

	//print 3rd linkedlist
	print(head3,sign);
	//freeing the list
	delete_list(&head1,&tail1);
	delete_list(&head2,&tail2);
	delete_list(&head3,&tail3);






}
