#include"common.h"

int main(char argc,char **argv)
{
int len,i,j,k,count_1=0,count_2=0;
len=strlen(argv[1]);
printf("len=%d\n",len);
char num[len];
strcpy(num,argv[1]);
char optr;
int sign=0;
for(i=0;i<len;i++)
{
	printf("%c",num[i]);
}

for(i=0;((num[i]!='+') && (num[i]!='-'));i++)
{
	count_1++;
}


//finding the length of num2
for(i=i+1;num[i]!='\0';i++)
{
	count_2++;
}
printf("count_1=%d\n",count_1);
printf("count_2=%d\n",count_2);
//declare num1 and num2
char num1[count_1],num2[count_2];
//extracting num1 and num2
for(i=0,j=0;(num[i]!='+') && (num[i]!='-');i++,j++)
{
	num1[j]=num[i];
}
num1[j]='\0';
 optr=num[i];
printf("%c\n",optr);

char num1_temp[100];
strcpy(num1_temp, num1);
printf("num1=%s\n",num1);


for(i=i+1,k=0;num[i]!='\0';i++,k++)
{
	num2[k]=num[i];
}
num2[k]='\0';
//printf("num1=%s\n",num1);
//printf("num2=%s\n",num2);

printf("num1_temp=%s\n",num1_temp);

if(optr == '+')
{

//call function for addition
apc_add(num1_temp,num2);
}
if(optr == '-')
{
	apc_sub(num1_temp,num2);
}




}
