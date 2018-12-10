#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "global.h"

//#include "show.h"

char ex_value[6];
int strcmp_flag=0;

int i=0; //0 ex-date != current date 1 is equal
//char lastwallet[20];

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

      printf("\n your money= %s\n", values[i]); //last line enter
      for(int j=0;j<20;j++)
      {
        lastwallet[j]=0;
      }
      strcpy(lastwallet,values[i]);

    }
  }
  strcmp_flag=1;
  strcpy(ex_value,values[0]);
  return 0;
}

int show()
{

  strcmp_flag=0; // update - 12.8 for modify error 
  sql = "SELECT * from AccBook;";
  printf("\n\t\t\t\tA . C . C . B . O . O . K\n");
  const char* data= "=======================================================================================================================";

  rc = sqlite3_exec(db, sql, cbSelect, (void*)data, &zErr);

  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_exec error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
  return 0;
}

