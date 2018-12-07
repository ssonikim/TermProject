
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>

char date[10];
char name[20];
int iprice=0;
char price[20];
char query[]="insert into Accbook values(\'";
char str[100];
char ddapoint[]="\',";
char dda[]="\'";
char last[]="\');";

void make_sql()
{
  //put date to char date
  printf("put date:\n");
  scanf("%s",date);
  //put date to char name
  printf("put name:\n");
  scanf("%s",name);
  //put date to char price
  printf("put price:\n");
  scanf("%s",price);

  strcat(str,query);
  strcat(str,date);
  strcat(str,ddapoint);
  strcat(str,dda);
  strcat(str,name);
  strcat(str,ddapoint);
  strcat(str,dda);
  strcat(str,price);
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
