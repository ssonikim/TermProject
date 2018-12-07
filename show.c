#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
char ex_value[6];
int *strcmp_flag=0;
int i=0;
int cbSelect(void *data, int ncols, char** values, char** headers)
{
  i=0;
  printf("\n%s\n\n",(const char*) data);
  if (strcmp_flag!=0&&strcmp(ex_value,values[0])==0)
  {
    i=1;
    printf("\t\t\t");
  }
  for(i;i<ncols;i++){
    printf("%s=%s\t\t\t", headers[i], values[i]);
    if (i==ncols-1)
    {
      printf("\n"); //last line enter
    }
  }
  strcmp_flag=1;
  strcpy(ex_value,values[0]);
  return 0;
}

int Show_AccBook()
{
  sqlite3 *db;
  int rc;
  char *sql; //doing sql
  char *zErr;

  rc = sqlite3_open("AccBook.db",&db);
  if(SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_open error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
  //open db
  sql = "CREATE TABLE IF NOT EXISTS AccBook" //later delete code !!
        "(date text, name text, price int);"
        "INSERT INTO AccBook values('12.15','banana',500);"
        "SELECT * from AccBook;";
  const char* data= "=====================================================================================";
  
  rc = sqlite3_exec(db, sql, cbSelect, (void*)data, &zErr);
  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_exec error : %s\n",sqlite3_errmsg(db));
		return -1;
  }

  rc = sqlite3_close(db);
  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_close error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
  return 0;
}

int main(void)
{
  printf("\n\t\t\t\tA . C . C . B . O . O . K\n");
  Show_AccBook();
  return 0;

}