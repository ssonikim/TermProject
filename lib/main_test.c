#include<stdio.h>
#include<sqlite3.h>
#include<write.h>
#include<global.h>

//sqlite3 *db;
//int rc;
//char *sql;
//char *zErr;

int makemain_db()
{

 

  sql = "CREATE TABLE IF NOT EXISTS AccBook(name text, price int)";
  rc = sqlite3_exec(db, sql,NULL,NULL,&zErr);

  //exec error
  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_create_table error : %s\n",sqlite3_errmsg(db));
		printf("database first create table error\n");
		return -1;
  }

  

return 0;
}

int main()
{
  rc = sqlite3_open("AccountBook.db",&db);
  // open error
  if(SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_open error : %s\n",sqlite3_errmsg(db));
		printf("database first open error\n");
		return -1;
  }
  makemain_db();
  write();

  rc = sqlite3_close(db);
  return 0;
}
