#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include "global.h"
char date_d[10];
char name_d[20];
char query_d[]="delete from AccBook where date = \'";
char str1[100];
char dda_d[]="\'";
char mid[] = "and name = \'";
int delete_money;

void make_sql_d()
{
  //put date to char date
  printf("Enter the date of the record to be deleted:\n");
  scanf("%s",date_d);
  //put date to char name
  printf("Enter the name of the record to be deleted:\n");
  scanf("%s",name_d);
  printf("Enter the price of the record to be deleted:\n");
  scanf("%d",&delete_money);
  user_mywallet += delete_money;
  strcat(str1,query_d);
  strcat(str1,date_d);
  strcat(str1,dda_d);
  strcat(str1,mid);
  strcat(str1,name_d);
  strcat(str1,dda_d);
  printf("%s\n",str1);
}

int erase()
{
  make_sql_d();

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
