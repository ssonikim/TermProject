#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include "global.h"
char date1[10];
char name1[20];
//int iprice=0;
char query1[]="delete from AccBook where date = \'";
char str1[100];
char dda1[]="\'";
char mid[] = "and name = \'";

void make_sql1()
{
  //put date to char date
  printf("put date:\n");
  scanf("%s",date1);
  //put date to char name
  printf("put name:\n");
  scanf("%s",name1);

  strcat(str1,query1);
  strcat(str1,date1);
  strcat(str1,dda1);
  strcat(str1,mid);
  strcat(str1,name1);
  strcat(str1,dda1);
  printf("%s\n",str1);
}
int erase()
{
  make_sql1();

  rc = sqlite3_exec(db,str1,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_remove error : %s\n",sqlite3_errmsg(db));
		printf("database remove value error\n");
		return -1;
  		       }
  //reset
    for(int i=0;i<100;i++)
  {
    str1[i]=0;
  }
  




return 0;
}
