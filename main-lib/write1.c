#include <sqlite3.h>
#include <stdio.h>
#include "global.h"
int write()
{
  char date_in[100];
  char name_in[100];
  int price_in;

  printf("Type Date\n");
  scanf("%s",date_in);

  printf("Type Name\n");
  scanf("%s",name_in);

  printf("Type Price\n");
  scanf("%d",&price_in);

  //sprintf(sql,"insert into AccBook values ('%s','%s',%d);",
  sprintf(sql,"insert into AccBook values ('%s','%s','%d');",date_in,name_in,price_in);
  //scanf("%s %s %s",date,name,price);

//  scanf("%s %s %s",&date_in,&name_in,&price_in);
  //sql = "insert into AccBook values('1.1','apple',500);";

  //sql = "insert into AccBook values(date,name,price);";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
		printf("database write error\n");
		return -1;
			}
  //sql = "insert into AccBook values('1.2','banana',500);";

  //rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   //if (SQLITE_OK != rc){
//		fprintf(stderr,"rc=%d\n",rc);
//		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
//		printf("database write close error\n");
//		return -1;
 // 			}


return 0;
}
