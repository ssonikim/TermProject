#include <sqlite3.h>
#include <stdio.h>
#include "global.h"
int write()
{

  sql = "insert into AccBook values('12.16','apple',500);";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_write value error : %s\n",sqlite3_errmsg(db));
		printf("database write close error\n");
		return -1;
  }




return 0;
}
