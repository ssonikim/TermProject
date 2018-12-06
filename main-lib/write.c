
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

char date[10];
char name[20];
int iprice=0;
char cprice[20];
char query[]="insert into Accbook values(\'";
char query_ddapoint[]="\',";
char query_dda[]="\'";
char query_last[]="\')";


int write()
{
  printf("put date:\n");
  scanf("%s",date);
  
  printf("put name:\n");
  scanf("%s",name);

  printf("put price:\n");
  scanf("%d",&iprice);
  sprintf(cprice,"%d",iprice);

 // strcat(query,date);
 // printf("%s",query);
 // strcat(query,query_ddapoint);
//  strcat(query,query_dda);
//  strcat(query,name);
 // printf("%s",query);
 // strcat(query,query_ddapoint);
 // strcat(query,query_dda);
//  strcat(query,cprice);
//  printf("%s",query);
//  strcat(query,query_last);
//  printf("%s",query);
//  sprintf(sql, "insert into Accbook values(%s,%s)", date, name);

  sql = "insert into AccBook values('@date','ds',2342);";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
		printf("database write close error\n");
		return -1;
  }




  return 0;
}
