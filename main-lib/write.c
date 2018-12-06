#include <sqlite3.h>
#include <stdio.h>
#include "global.h"
#include <string.h>
char date[10];
char name[20];
int price=0;
char query[]="insert into Accbook values";



int write()
{
  printf("put date:\n");
  scanf("%s",date);
  
  printf("put name:\n");
  scanf("%s",name);

  printf("put price:\n");
  scanf("%d",&price);
  strcpy(query)
  sprintf(sql, "insert into Accbook values(%s,%s)", date, name);
//  sqlite3_exec(pSQLite3, insertDataQuery, callback, 0, &szErrMsg);

 // sql = "insert into AccBook values('%s','%s','%d'),;";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
		printf("database write close error\n");
		return -1;
  }




  return 0;
}
