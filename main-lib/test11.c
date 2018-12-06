#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char date[10];
char name[20];
int iprice=0;
char cprice[20];
char query[]="insert into Accbook values(\'";
char ddapoint[]="\',";
char dda[]="\'";
char last[]="\')";
int main(){
 printf("put date:\n");
  scanf("%s",date);
  
  printf("put name:\n");
  scanf("%s",name);

  printf("put price:\n");
  scanf("%d",&iprice);
  sprintf(cprice,"%d",iprice);

  strcat(query,date);
  printf("%s\n",ddapoint);
   printf("%s\n",dda);
 // strcat(query,query_ddapoint);
 // strcat(query,query_dda);
  strcat(query,name);
  printf("%s\n",query);
//  strcat(query,query_ddapoint);
  printf("%s\n",query);
 // strcat(query,query_dda);
  printf("%s\n",query);
  strcat(query,cprice);
  printf("%s\n",query);
//  strcat(query,query_last);
  printf("%s\n",query);
//  strcat(query_dda,name);
//  printf("%s\n",query_dda);
}
