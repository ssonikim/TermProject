#include <stdio.h>
#include <sqlite3.h>

int insert_data()
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

  sql = "insert into AccBook values('apple',500)";
  rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_insert error : %s\n",sqlite3_errmsg(db));
		return -1;
		      }

 rc = sqlite3_close(db);

return 0;
}

int make_database()
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
		fprintf(stderr,"sqlite3_make table error : %s\n",sqlite3_errmsg(db));
		return -1;
  }

 rc = sqlite3_close(db);

return 0;
}

int main(void)
{
  make_database();
  insert_data();
  return 0;

}
