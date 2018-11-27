
#include <stdio.h>
#include <sqlite3.h>

int capi_example_1()
{
  sqlite3 *db;
  int rc;
  char *sql;
  char *zErr;

  rc = sqlite3_open("test1.db",&db);
  if(SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_open error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
  sql = "CREATE TABLE IF NOT EXISTS AccBook(name text, price int)";
  rc = sqlite3_exec(db, sql,NULL,NULL,&zErr);


  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_close error : %s\n",sqlite3_errmsg(db));
		return -1;
  }

  sql = "insert into AccBook values('banana',500)";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

 rc = sqlite3_close(db);

return 0;
}

int main(void)
{
  capi_example_1();
  return 0;

}
