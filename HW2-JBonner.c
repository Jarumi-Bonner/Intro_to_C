//HW #2 - J. Bonner
// Basic program
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
#define AIRPLANE_SPEED 565.0

int main()
{
    float time_to_paris, time_to_rome;
    float diameter_of_planet;
    float circumference;
    char name[15];
    float distanceO_P = 4704.18;
    float distanceO_R = 5111.96;
    float kilometer_conversion = 1.60934;
    float flight_timeO_P;
    float flight_timeO_R;
    float time_to_leave;

    //Part 1 - Diameter calculation
    //Earth is the planet I usually enter with a circumference of 24,901
    printf("Please enter the name of planet\n");
    scanf("%s", name);

    printf("Please enter circumference of %s\n", name);
    scanf("%f", &circumference);

    //To get the diameter you must divide the circumference by PI
    diameter_of_planet = circumference / PI;

    printf("The diameter of planet %s at the Equator is %.2f miles\n\n", name, diameter_of_planet);

    system("PAUSE");

    //Part 2 - Distance and Time calculations
    //Distance from Orlando to Paris is 4,704.18 miles; source http://www.mapcrow.info/Distance_between_Orlando_US_and_Paris_FR.html
    //To find out the distance to Paris in kilometers you must multiply the distance in miles by the kilometer conversion factor.
    distanceO_P = distanceO_P * kilometer_conversion;
    printf("The distance between Orlando and Paris, France in kilometers is %.2f \n\n", distanceO_P);

    //Distance from Orlando to Rome is 5,111.96 miles; source http://www.mapcrow.info/Distance_between_Orlando_US_and_Rome_IT.html
    //To find out the distance to Rome in kilometers you must multiply the distance in miles by the kilometer conversion factor.
    distanceO_R = distanceO_R * kilometer_conversion;
    printf("The distance between Orlando and Rome, Italy in kilometers is %.2f \n\n", distanceO_R);

    //In order to find how long it takes to reach Paris, France you must divide the distance by the kilometer conversion factor and then divide by the airplane speed.
    flight_timeO_P = (distanceO_P / kilometer_conversion) / AIRPLANE_SPEED;
    printf("The flight time between Orlando and Paris, France is %.2f \n\n", flight_timeO_P);

    //In order to find how long it takes to reach Rome, Italy you must divide the distance by the kilometer conversion factor and then divide by the airplane speed.
    flight_timeO_R = (distanceO_R / kilometer_conversion) / AIRPLANE_SPEED;
    printf("The flight time between Orlando and Rome, Italy is %.2f \n\n", flight_timeO_R);

    //To figure out what time the two flights have to leave, so each plane to reaches the final destination at the same time, you must subtract the two flight times and multiply that time by 60 minutes.
    time_to_leave = (flight_timeO_R - flight_timeO_P) * 60;
    printf("In order to arrive at the exact time, Orlando to Rome must leave %.0f minuets before the flight to Paris\n", time_to_leave);


    return 0;
}
