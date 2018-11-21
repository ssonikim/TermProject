#include<stdio.h>
#include<stdlib.h>

int main(void)

{
  int inputMenu;
  while(1)
  {
	PrintMenu();
	scanf("%d",&inputMenu);
	system("cls");
	switch(inputMenu){
	case 1:{
	    Add_item();
	    break;
 	case 2:{
         
            printTable();
            break;
         }
         case 3:{
         
            Find();
            break;
         }
         case 4:{
         
            Delete_item();
            break;
            
         }

         case 5:{
         
            printf("Shut down Program.");
            return 0;
         }
         default:{
         
            printf("Wrong Input Menu.");
            break;
         }
         
      }
}

  return 0;
}
