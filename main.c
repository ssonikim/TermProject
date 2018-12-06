#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

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

int main()
{

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
        sleep(1);
        break;
      }
      case 2: //show
      {
        printf("show\n");
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
        break;
      }
      case 5: //sorting
      {
        printf("sorting\n");
        break;
      }
      case 6: //modify
      {

        printf("gogogo\n");
	char s[256];
	int p;
	printf("write your product and price\n");
	scanf("%s %d",s,&p);
	printf("your product is %s, and price is %d\n",s,p);

        printf("modify\n");

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
  return 0;
}
