#include <sqlite3.h>
#include <stdio.h>
#include <global.h>
int write()
{
//  sqlite3 *db;
//  int rc;
//  char *sql;
//  char *zErr;

  sql = "insert into AccBook values('apple',500);";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_close error : %s\n",sqlite3_errmsg(db));
		printf("database write close error\n");
		return -1;
  }




return 0;
}
