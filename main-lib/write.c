
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>

//12.10 price %s -> %d
char date[10];
char name[20];
int int_price=0;
char price[20];
char query[]="insert into Accbook values(\'";
char str[100];
char ddapoint[]="\',";
char point[]=",";
char dda[]="\'";
char last[]=");";

int user_mywallet;
char c_wallet[20];
//char lastwallet[20];

char * Strrev(char *Dest)
{
	int Len = strlen(Dest);
	int i = 0;

	while (1)
	{
		int temp;
		temp = Dest[i];
		Dest[i] = Dest[Len-1-i];
		Dest[Len-1-i] = temp;
		i++;
		if (i == Len-i || i > Len-i)
		{
			Dest[Len] = 0;
			return Dest;
		}
	}
}

char* Itoa(int Value, char* Buffer, int Radix)
{
	int sign = (Value < 0) ? -1 : 1;
	Value *= sign;
	int Index = 0;
	while (1)
	{
		Buffer[Index] = Value %Radix;
		Buffer[Index] += (Buffer[Index] < 10) ? '0' : 'a' - 10;
		if (Value <= 0)
		{
			if (sign == -1)
			{
				Buffer[Index++] = '-';
			}
			break;
		}
		Index++;
		Value /= Radix;
	}
	Buffer[Index] = 0;
	return Strrev(Buffer);

}

void make_sql()
{
  //put date to char date
  printf("Please Enter the date of purchase:\n");
  scanf("%s",date);
  //put date to char name
  printf("Please Enter your purchased item Name:\n");
  scanf("%s",name);
  //put date to char price
  printf("Please enter the price of the item:\n");
  scanf("%s",price);  // 12.10
  int_price= atoi(price);  //12.10

  if(reset_flag==2)
  {
    user_mywallet=atoi(lastwallet);
  }
  user_mywallet=user_mywallet-int_price;
  Itoa(user_mywallet,c_wallet,10);

  strcat(str,query);
  strcat(str,date);
  strcat(str,ddapoint);
  strcat(str,dda);
  strcat(str,name);
  strcat(str,ddapoint);
  strcat(str,price);
  strcat(str,point);
  strcat(str,c_wallet);
  strcat(str,last);
  //check str
  printf("%s\n",str);
}


int write()
{
  make_sql();
  rc = sqlite3_exec(db,str,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
		printf("database write close error\n");
		return -1;
  }
  //reset
  for(int i=0;i<100;i++)
  {
    str[i]=0;
  }

  return 0;
}
