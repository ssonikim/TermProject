#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void PrintMenu()
{
  printf("====Menu===\n");
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
    system("clear");
  }
  return 0;
}
