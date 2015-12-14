//HW  #5 J. Bonner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//The Prototypes for the user-defined functions
void read_temps();
void calc_results(int []);
int ftemp[25];
FILE * finalF;

int main(){

    //Declare variables and array
    int htemp;
    int i, tday, tyear;
    char month[25];

    //Create file that you will print out

    finalF = fopen("calc-temps.txt", "w");

    //Ask user for the month and date and year
    printf("What is today's Date?(Month Day Year)\n");
    scanf("%s" "%d" "%d", month, &tday, &tyear);


    //Ask user to input the file name
    char filename[30];
    printf("\nWhat is the files name? (Include '.txt')\n");
    scanf("%s", filename);

    //Print out results
    fprintf(finalF, "Temperature Conditions on %s %d, %d:\n", month, tday, tyear);
    fprintf(finalF, "\nTime of Day\t Temperature in degrees F\n");

    //Calls funtion that reads the file
   read_temps(filename);


    fclose(finalF);
    return 0;
}

//Reads outside file and sets data to array
void read_temps(char filename[30]){

    FILE * fP;
    fP = fopen(filename, "r");
    int k;

   for(k = 0; k < 25; k++){
       fscanf(fP, "%d\n", &ftemp[k]);
}
  fclose(fP);

  calc_results(ftemp);
}

//Determine what the min and max is by going through the array, and then figure out the average
void calc_results(int ftemp[]){
    int j, i;
    int max = ftemp[0], min = ftemp[0];
    float sum, tempavg;
    sum = 0;

    for(j =0; j<25; j++){
        if(min > ftemp[j]){
            min = ftemp[j];
        }
        if (max < ftemp[j]){
            max = ftemp[j];
        }

        sum += ftemp[j];
    }
    tempavg = sum / 25;

    for(i = 0; i < 25; i++){

    fprintf(finalF, "%d \t \t %d \n", i, ftemp[i]);
    }

    fprintf(finalF,"\nMaximum Temperature for the day: %d Degrees F\n", max);
    fprintf(finalF, "Minimum Temperature for the day: %d Degrees F\n", min);
    fprintf(finalF, "Average Temperature for the day: %.2f Degrees F\n", tempavg);
}
