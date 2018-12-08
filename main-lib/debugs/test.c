
#include <stdio.h>
#include <string.h>


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
  printf("put date:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("put name:\n");
  scanf("%s",name_m);
  printf("put price\n");
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
  //put date to char date
  printf("put date:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("put name:\n");
  scanf("%s",name_m);
  printf("put price\n");
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
  //put date to char date
  printf("put date:\n");
  scanf("%s",date_m);
  //put date to char name
  printf("put name:\n");
  scanf("%s",name_m);
  printf("put price\n");
  scanf("%s",price_m);

  strcat(str2,query_price);
  strcat(str2,price_m);
  strcat(str2,dda_m);
  strcat(str2,where_name);
  strcat(str2,name_m); 
  strcat(str2,dda_m);
  strcat(str2,price_mid);
  strcat(str2,price_m);
  strcat(str2,dda_m); 

  printf("%s\n",str2);
}

void main()
{
 make_sql_price();
}
