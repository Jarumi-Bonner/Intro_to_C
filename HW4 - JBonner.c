//HW  #4 J. Bonner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//The Prototypes for the user-defined functions
int get_value();
void calc_results(int []);

int main(){
    //Seed srand so rand works properly
    srand(NULL);

    //Declare variables and array
    int temp[25], htemp;
    int i, tday, tyear;
    char month[25];

    //Ask user for the month and date and year
    printf("What is today's Date?(Month, Day, Year)\n");
    scanf("%s" "%d" "%d", month, &tday, &tyear);

    //Print out results it just ask for
    printf("\nTemperature Conditions on %s %d, %d:\n", month, tday, tyear);
    printf("\nTime of Day\t Temperature in degrees F\n");

    //Create a for loop that goes through array and sets the values to the random numbers generated and print it
    for(i = 0; i < 25; i++){

       htemp = get_value();
       temp[i] = htemp;

    printf("%d \t \t %d \n", i, temp[i]);
    }
    calc_results(temp);
    return 0;
}

//Generates random numbers that are in between 60-100
int get_value(){

    return (rand()%40) +60;
}

//Determine what the min and max is by going through the array, and then figure out the average
void calc_results(int temp[]){
    int j;
    int max = temp[0], min = temp[0];
    float sum, tempavg;
    sum = 0;

    for(j =0; j<25; j++){
        if(min > temp[j]){
            min = temp[j];
        }
        if (max < temp[j]){
            max = temp[j];
        }

        sum += temp[j];
    }
    tempavg = sum / 25;

    printf("\nMaximum Temperature for the day: %d Degrees F\n", max);
    printf("Minimum Temperature for the day: %d Degrees F\n", min);
    printf("Average Temperature for the day: %.2f Degrees F\n", tempavg);
}
