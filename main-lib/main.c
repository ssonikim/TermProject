#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sqlite3.h>
#include "global.h"
#include "write.h"
#include "erase.h"
#include "show.h"
#include "modify.h"

sqlite3 *db;
int rc;
const char *sql;
char *zErr;

void PrintMenu()
{
  printf("=====Menu====\n");
  printf("1.Write AcountBook\n");
  printf("2.Show AccountBook\n");
  printf("3.Find purchase history\n");
  printf("4.Delete purchase history\n");
  printf("5.Sorting Prices\n");
  printf("6.Modify purchase history\n");
  printf("7.Close Program\n");
  printf("Please Input Menu Number: ");
}

int makemain_db()
{


  sql = "CREATE TABLE IF NOT EXISTS AccBook(date text,name text, price int)";
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

  int InputMenu=0; //for switch values

  while(1)
  {
    PrintMenu();
    int InputMenu; //for switch values
    scanf("%d",&InputMenu); //input number of menu
   // system("clear"); //clear
    switch(InputMenu)
    {
      case 1: //write
      {
        printf("write\n");
	write();
        //sleep(1);
        break;
      }
      case 2: //show
      {
        printf("show\n");
	show();
        break;
      }

      case 3: //find
      {
        printf("find\n");
        break;
      }
      case 4: //delete
      {
        printf("delete\n");
	erase();
        break;
      }
      case 5: //sorting
      {
        printf("sorting\n");
        break;
      }
      case 6: //modify
      {

        printf("modify\n");
	modify();

        break;
      }
      case 7: //close
      {
        printf("close\n");
        return 0;
      }
      default: //something wrong
      {
        printf("you have entered something wrong!\n try again please\n");
        break;
      }
    }
    //system("clear");
  }
  rc = sqlite3_close(db);
  return 0;
}
