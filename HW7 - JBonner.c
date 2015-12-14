#include <stdio.h>
#include <stdlib.h>
#include "HW7_Functions.c"

int main(){
    char save_o[3];
    int choice= 0;

    load_file();

    printf("\nWhat would you like to do?\n");
    printf("1 - Insert something in the list\n");
    printf("2 - Delete something from the list\n");
  	printf("3 - Print out its contents\n");
  	printf("4 - Return the element selected\n");
  	printf("5 - Save contents of list?\n");
  	printf("Enter 1 through 5 or enter 0 to terminate:\n");
  	scanf("%d", &choice);

    while(choice != 0 ){

        switch(choice)  {
            case 1:
                insertsomething();
                printitout();
                break;
            case 2:
                deletesomething(); //Crashes Randomly, top works, bottom works, and middle but still crashes IDK...
                break;
            case 3:
                printitout();
                break;
            case 4:
                servesomething(); //Works but does not like underscore or - so will not work with those, also how do you check if they enter wrong label namek
                break;
            case 5:
                save();
                break;
            default:
                printf("OK, bye\n");
                return 0;
                }
                printf("\nSooooo... What now?\n");
                printf("1-Insert, 2-Delete, 3-Print List, 4-Item Priority, 5-Save to File, 0-Terminate\n");
                scanf("%d", &choice);
}

    if(choice == 0){
        printf("Do you want to save? Y/N\n");
        scanf("%s", save_o);
        if(strcmp(save_o,"y") == 0 || strcmp(save_o,"Y") == 0){
            save();
        }
        else
            printf("\nFile Not Saved\n");
    return 0;
    }
}
