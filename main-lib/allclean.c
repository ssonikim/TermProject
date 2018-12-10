#include <sqlite3.h>
#include <stdio.h>
#include "global.h"

int allclean()
{
  sql = "delete from AccBook;";

  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

   if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_all clean error : %s\n",sqlite3_errmsg(db));
		printf("database all clean error\n");
		return -1;
  		       }



return 0;
}
