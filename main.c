#include<stdio.h>
#include<stdlib.h>

int main()
{
  int InputMenu; //for switch values
  while(1)
  {
    printf("Plese select Menu what you want.\n"); //select
    printf("1.Start!\n");  //start
    printf("2.END!\n");  //end
    scanf("%d",&InputMenu); //input number of menu
    system("clear"); //clear
    switch(InputMenu)
    {
      case 1: //Start
      {
        printf("gogogo\n");
        break;
      }
      case 2: //End
      {
        printf("byebyebye\n");
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
