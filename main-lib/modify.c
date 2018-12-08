#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include "global.h"

char date_m[10];
char name_m[20];
char price_m[10];
//int iprice=0;
char query_date[]="update AccBook set date=\'";
char query_name[]="update AccBook set name=\'";
char query_price[]="update AccBook set price=\'";
char str2[100];
char dda_m[]="\'";
char name_mid[] = "and price = \'";
char where_name[] = "where name =\'";

char where_date[] = "where date =\'";
char date_mid[] = "and price =\'";

char price_mid[] = "and date =\'";

void make_sql_date()
{
  //put date to char date
  printf("Write the date to be modified:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("Write down its name:\n");
  scanf("%s",name_m);
  printf("Write down its price\n");
  scanf("%s",price_m);

  strcat(str2,query_date);
  strcat(str2,date_m);
  strcat(str2,dda_m);
  strcat(str2,where_name);
  strcat(str2,name_m);
  strcat(str2,dda_m);
  strcat(str2,name_mid);
  strcat(str2,price_m);
  strcat(str2,dda_m);
  printf("%s\n",str2);
}

void make_sql_name()
{

  printf("Write the name to be modified:\n");
  scanf("%s",name_m);
  //put date to char date
  printf("Write down its date:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("Write down its price\n");
  scanf("%s",price_m);

  strcat(str2,query_name);
  strcat(str2,name_m);
  strcat(str2,dda_m);
  strcat(str2,where_date);
  strcat(str2,date_m);
  strcat(str2,dda_m);
  strcat(str2,date_mid);
  strcat(str2,price_m);
  strcat(str2,dda_m);

  printf("%s\n",str2);
}

void make_sql_price()
{

  printf("Write the price to be modified\n");
  scanf("%s",price_m);
  //put date to char date
  printf("Write down its date:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("Write down its name:\n");
  scanf("%s",name_m);


  strcat(str2,query_price);
  strcat(str2,price_m);
  strcat(str2,dda_m);
  strcat(str2,where_name);
  strcat(str2,name_m); 
  strcat(str2,dda_m);
  strcat(str2,price_mid);
  strcat(str2,date_m);
  strcat(str2,dda_m); 

  printf("%s\n",str2);
}
int modify()
{
  //make_sql1();
  int select=0;
  printf("Which Values do you want Modify? : 1.date , 2.name, 3.price\n");
  scanf("%d",&select);
  switch( select )
  {
	case 1:
		printf("Modify date values\n");
		make_sql_date();
		break;
	case 2:
		printf("Modify name values\n");
		make_sql_name();
		break;
	case 3:
		printf("Modify price values\n");
		make_sql_price();
		break;
	default:
		printf("choose correct modify values\n");

  }
  rc = sqlite3_exec(db,str2,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_modify error : %s\n",sqlite3_errmsg(db));
		printf("database modify value error\n");
		return -1;
  		       }
  //reset
    for(int i=0;i<100;i++)
  {
    str2[i]=0;
  }




return 0;
}
