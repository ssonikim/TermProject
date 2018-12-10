#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sqlite3.h>
#include "global.h"
#include "write.h"
#include "erase.h"
#include "show.h"
#include "find.h"
#include "sorting.h"

sqlite3 *db;
int rc;
const char *sql;
char *zErr;
char user_name[10];
int reset_flag=0;
char lastwallet[20];


void PrintMenu()
{
  printf("=====Menu====\n");
  printf("1.Write AcountBook\n");
  printf("2.Show AccountBook\n"); 
  printf("3.Find purchase history\n"); 
  printf("4.Delete purchase history\n"); 
  printf("5.Sorting\n"); 
  printf("6.Modify\n");
  printf("7.Close\n");
  printf("Please Input Menu Number: ");
}

int makemain_db()
{


  sql = "CREATE TABLE IF NOT EXISTS AccBook(Date text, Name text, Price int, Remaining money int)";
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
  printf("Would you like to create a new AccountBook?\n 1.Yes 2.No\n"); //1. reset 2. continue 
  scanf("%d",&reset_flag);
  if(reset_flag==1)
  {
  //put all_clean function
    printf("reset complete!\n");
    printf("Put in your data...\n ");  //get user data 12.10
    printf("Put in your total money:");
    scanf("%d",&user_mywallet);
    printf("Hi your total money is :%d\n",user_mywallet);
  }
  else if(reset_flag==2)
  int InputMenu=0; //for switch values
  while(1)
  {
    PrintMenu();
    int InputMenu; //for switch values
    scanf("%d",&InputMenu); //input number of menu
    system("clear"); //clear
    switch(InputMenu)
    {
      case 1: //write
      {
        printf("write\n");
	if(reset_flag==2)
        {
          show();
        }
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
        find();
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
        sorting();
        break;
      }
      case 6: //modify
      {

        printf("gogogo\n");
	

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
