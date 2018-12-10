#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "sorting.h"

char ex_value_sorting[6];
int strcmp_flag_sorting=0;
int sorting_mode=0;
char sorting_DESC[]=" ORDER BY price DESC;";
char sorting_ASC[]=" ORDER BY price ASC;";
char str_sorting[100]="SELECT * FROM AccBook";
char str_return[]="SELECT * FROM AccBook";

int cbSelect_sorting(void *data, int ncols, char** values, char** headers)
{
  int i=0; //0 = ex date!= current date 1 is equal
  printf("\n%s\n\n",(const char*) data);
  if (strcmp_flag_sorting!=0&&strcmp(ex_value_sorting,values[0])==0)
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
  strcmp_flag_sorting=1;
  strcpy(ex_value_sorting,values[0]);
  return 0;
}
void select_order()
{
  sorting_mode=0;
  printf("Please select sorting mode by 1. Sort the prices in expensive or 2. Sort the prices in cheap \n");
  scanf("%d",&sorting_mode);//get sorting mode num 1 DESC 2 ASC
  printf("Please input what you want.\n");
  system("clear");
  switch(sorting_mode)
  {
   case(1):
   {
     strcat(str_sorting,sorting_DESC);
     break;
   }
   case(2):
   {
     strcat(str_sorting,sorting_ASC);
     break;
   }
   default:
   {
     printf("you have to input number only 1.DESC or 2.ASC !\n ");
     select_order();
   }
  }
}
int sorting()
{
  strcmp_flag_sorting=0; //12.8 for modify error
  select_order(); //1. DESC ,2. ASC 
  printf("%s\n",str_sorting);
  printf("\n\t\t\t\tA . C . C . B . O . O . K\n");
  const char* data= "=====================================================================================";

  rc = sqlite3_exec(db, str_sorting, cbSelect_sorting, (void*)data, &zErr);
  if (SQLITE_OK != rc){
		fprintf(stderr,"rc=%d\n",rc);
		fprintf(stderr,"sqlite3_exec error : %s\n",sqlite3_errmsg(db));
		return -1;
  }
//  for(int i=0; i<100; i++)
//  {
//    str_sorting[i]=0;
//  }
  strcpy(str_sorting,str_return);
  return 0;
}

