#include <stdio.h>
#include <stdlib.h>

//Pr
int eTotal(int a);
int oTotal(int a);

//Use global variables so you can use them in both functions
int oddTotal, evenTotal;

int main(){

    //variables that hold regular numbers, even numbers, odd numbers, and name
    int num, evenNum, oddNum;
    char name[15];

    //Set the variables equal to zero
    evenNum = oddNum = 0;
    evenTotal = oddTotal = 0;

    //Ask the user for their name
    printf("What is your name?\n");
    scanf("%s", name);

    //Ask the user to input their name
    printf("Pick a number, any number!\n");
    scanf("%d", &num);


    //Run a while loop that runs until the number is equal to zero.
    while (num != 0){

    //Run a if loop to see if the number is even, if it is add 1 to the variable evenNum, if not add 1 to oddNum
        if (num %2 == 0)
        {
            evenNum++;
        }else{
            oddNum++;
        }

        //Run a if loop to see if the number is even, if it is call the even user defined function and start adding up the even numbers, if not call the odd user defined function and start adding up the odd numbers.
        if (num %2 == 0){
         evenTotal = eTotal(num);

        }else{
        oddTotal = oTotal(num);
        }
        scanf("%d", &num);
    }

    //if number is zero print out results
    if (num == 0){

    printf("%s, the numbers you entered are broken down as follows:\n", name);
    printf("You entered %d even numbers with a total value of %d.\n", evenNum, evenTotal);
    printf("You also entered %d odd numbers with a total value of %d.", oddNum, oddTotal);
    }


    return 0;
}

//Use a user defined function which holds the even numbers when it comes and adds the next number to it.
int eTotal(int a){

   int b = 0;
    b = evenTotal + a;
            return b;
}
//Use a user defined function which holds the odd numbers and when it comes adds the next number to it.
int oTotal(int a){

   int b = 0;
    b = oddTotal + a;
            return b;
}
