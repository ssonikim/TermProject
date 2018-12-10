#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "find.h"

char ex_value_find[6];
int strcmp_flag_find=0;
int find_mode =0; // find by 0 date 1 name 
char date_find[20];
char name_find[20];
char query_dt[]=" where date= '";
char query_n[]=" where name= '";
char str_find[100];
char query_last[]="\';";




int cbSelect_find(void *data, int ncols, char** values, char** headers)
{
  int i=0; //0 = ex date!= current date 1 is equal
  printf("\n%s\n\n",(const char*) data);
  if (strcmp_flag_find!=0&&strcmp(ex_value_find,values[0])==0)
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
  strcmp_flag_find=1;
  strcpy(ex_value_find,values[0]);
  return 0;
}
void select_mode()
{
  find_mode=0;
  printf("Please select whether to find by 1.date or 2.name \n");
  scanf("%d",&find_mode);  //get find mode num 1 date 2 name
  printf("Please input data what you want.\n");
  switch(find_mode)
  {
   case(1):
   {
     scanf("%s",date_find);
     strcat(str_find,query_dt);
     strcat(str_find,date_find);
     strcat(str_find,query_last);
     break;
   }
   case(2):
   {
     scanf("%s",name_find);
     strcat(str_find,query_n);
     strcat(str_find,name_find);
     strcat(str_find,query_last);
     break;
   }
   default:
   {
     printf("you have to input number only 1.date or 2.name !\n ");
     select_mode();
   }
  }
}
int find()
{
  strcmp_flag_find=0; //update 12.8 for modify error
  
  strcpy(str_find,"SELECT * from AccBook");
  select_mode();
  printf("%s\n",str_find);
  printf("\n\t\t\t\tA . C . C . B . O . O . K\n");
  const char* data= "=====================================================================================";

  rc = sqlite3_exec(db, str_find, cbSelect_find, (void*)data, &zErr);
  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_exec error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
  return 0;
}

