/*
 * Name & Surname: Melih BULUT.
 * Date: 22.03.2022
 * The purpose of the program: Program to Calculate Angle Between Hour and Minute Hands in Analog Clock.
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
int ClockControl (int durum){                                                                 //Only positive number selection
    int num;
    char buf[1024];
    int success;                                                                     // flag for successful conversion
    do
    {
        printf("");
        if (!fgets(buf, 1024, stdin))
        {
            return 1;                                                                // reading input failed:
        }
        char *endptr;                                                                // have some input, convert it to integer:

        errno = 0;                                                                   // reset error number
        num = strtol(buf, &endptr, 10);
        if (durum==1) {
            if (num >= 24) {
                printf("Hour must be lower 24! Please try again.");
                success = 0;
            }
            else if (endptr == buf) {
                printf("You entered a character. Please enter number\n");               // no character was read
                fflush(stdout);
                success = 0;
            } else if (num < 0) {
                printf("You entered negative number. Please try again!\n");              //No negative numbers
                success = 0;
            } else if (*endptr && *endptr != '\n') {
                printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
                success = 0;                                                              // so we didn't convert the whole input
            }
            else
            {
                success = 1;
            }
        }
            if(durum == 2){
                if (num >= 60){
                    printf("Minute must be lower 60! Please try again.");
                    success = 0;
                } else if (endptr == buf) {
                    printf("You entered a character. Please enter number\n");               // no character was read
                    fflush(stdout);
                    success = 0;
                } else if (num < 0) {
                    printf("You entered negative number. Please try again!\n");              //No negative numbers
                    success = 0;
                } else if (*endptr && *endptr != '\n') {
                    printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
                    success = 0;                                                              // so we didn't convert the whole input
                }
                else
                {
                    success = 1;
                }
            }
        if(durum == 3){
            if (num > 4){
                printf("You entered an invalid value! Please try again.");
                success = 0;
            } else if (endptr == buf) {
                printf("You entered a character. Please enter number\n");               // no character was read
                fflush(stdout);
                success = 0;
            } else if (num < 0) {
                printf("You entered negative number. Please try again!\n");              //No negative numbers
                success = 0;
            } else if (*endptr && *endptr != '\n') {
                printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
                success = 0;                                                              // so we didn't convert the whole input
            }
            else
            {
                success = 1;
            }
        }
        if(durum == 4){
            if (num > 8){
                printf("You have selected an invalid country time! Try again!");
                success = 0;
            } else if (endptr == buf) {
                printf("You entered a character. Please enter number\n");               // no character was read
                fflush(stdout);
                success = 0;
            } else if (num < 0) {
                printf("You entered negative number. Please try again!\n");              //No negative numbers
                success = 0;
            } else if (*endptr && *endptr != '\n') {
                printf("You entered invalid number. Please try again!\n");               // *endptr is neither end of string nor newline,
                success = 0;                                                              // so we didn't convert the whole input
            }
            else
            {
                success = 1;
            }
        }

    } while (!success);                                                              // repeat until we got a valid number

    return num;
}
void CalculateAngle (double hour_angle, double minute_angle, double second_angle){
    double result_hour, result_minute,result_second;
    double wide_angle;
    double acute_angle;
    int which_angle;
        if(hour_angle > 12 ){
            hour_angle = hour_angle - 12;
        }
        result_hour = hour_angle * 30 + minute_angle * 0.5 + second_angle / 120;
        result_minute = minute_angle * 6 + second_angle * 0.1;
        result_second = second_angle * 6;

        printf("Which two would you like to calculate the angles between?\n"
               "1) Hour-Minute\n"
               "2) Hour-Second\n"
               "3) Minute-Second\n"
               "4) All\n"
               "-> ");
        which_angle = ClockControl(3);
    switch (which_angle) {
        case 1:
            wide_angle = fabs(result_hour - result_minute);
            acute_angle = 360 -wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the hour and minute hands: %.1f\n", wide_angle);
            printf("Acute angle between hour and minute hands: %.1f\n",acute_angle);
            break;
        case 2:
            wide_angle = fabs(result_hour - result_second);
            acute_angle = 360 -wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the hour and second hands: %.1f\n", wide_angle);
            printf("Acute angle between hour and second hands: %.1f\n",acute_angle);
            break;
        case 3:
            wide_angle = fabs(result_minute - result_second);
            acute_angle = 360 -wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the second and minute hands: %.1f\n", wide_angle);
            printf("Acute angle between second and minute hands: %.1f\n",acute_angle);
            break;
        case 4:
            wide_angle = fabs(result_hour - result_minute);
            acute_angle = 360 -wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the hour and minute hands: %.1f\n", wide_angle);
            printf("Acute angle between hour and minute hands: %.1f\n",acute_angle);
            wide_angle = fabs(result_hour - result_second);
            acute_angle = 360 - wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the hour and second hands: %.1f\n", wide_angle);
            printf("Acute angle between hour and second hands: %.1f\n",acute_angle);
            wide_angle = fabs(result_minute - result_second);
            acute_angle = 360 -wide_angle;
            if(wide_angle - acute_angle < 0){
                double temp;
                temp = wide_angle;
                wide_angle = acute_angle;
                acute_angle = temp;
            }
            printf("Wide angle between the second and minute hands: %.1f\n", wide_angle);
            printf("Acute angle between second and minute hands: %.1f\n",acute_angle);
            break;
        default:
            printf("You entered an invalid value! Please try again.\n");
    }
}
void RandomClock(){
    double random_hour, random_minute, random_second;
    srand(time(NULL));
    random_hour = rand() % 24;
    random_minute =rand() % 60;
    random_second = rand() % 60;
    printf("Time you entered : %.0f.%.0f.%.0f\n", random_hour, random_minute, random_second);
    CalculateAngle(random_hour, random_minute, random_second);
}
void Countries_Clock(){
        int country;
        printf("Enter the desired country time:\n"
               "1) Turkey\n"
               "2) Germany\n"
               "3) United Kingdom\n"
               "4) Spain\n"
               "5) Azerbaijan\n"
               "6) Los Angeles, United States\n"
               "7) Beijing,China\n"
               "8)Oslo, Norway\n");
        country = ClockControl(4);
        if (country == 1) {
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour , timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 2) {
            //Germany
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour - 2, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour - 2, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 3) {
            //United Kingdom
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour - 3, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour - 3, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 4) {
            //Spain
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour - 2, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour - 2, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 5) {
            //Azerbaijan
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour + 1, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour + 1, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 6) {
            //Los Angeles, United States
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour - 10, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour - 10, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 7) {
            //Beijing,China
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour + 5, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour + 5, timeptr->tm_min, timeptr->tm_sec);
        } else if (country == 8) {
            //Oslo, Norway
            time_t gec;
            gec = time(NULL);
            struct tm *timeptr = localtime(&gec);
            printf("%d.%d.%d\n", timeptr->tm_hour + 5, timeptr->tm_min, timeptr->tm_sec);
            CalculateAngle(timeptr->tm_hour + 5, timeptr->tm_min, timeptr->tm_sec);
        }

}
int main() {
    while(1) {
        double hour;
        double minute;
        double second;
        char runAgain;
        int clock_choice;
        printf("Program to Calculate Angle Between Hour and Minute Hands in Analog Clock.\n");
        printf("------------------------------------------------------------------------------\n");
        printf("How would you like to set your watch:\n"
               "1) Manual\n"
               "2) Random\n"
               "3) Country Clock\n"
               "->");
        clock_choice = ClockControl(3);
        if(clock_choice == 1) {
            printf("Enter the hour:");
            hour = ClockControl(1);
            printf("Enter the minute:");
            minute = ClockControl(2);
            printf("Enter the second: ");
            second = ClockControl(2);
            printf("Time you entered : %.0f.%.0f.%.0f\n", hour, minute, second);
            CalculateAngle(hour, minute, second);
        }
        else if( clock_choice == 2){
            RandomClock();
        }else if(clock_choice == 3){
            Countries_Clock();
        }
        printf("\nWould you like to restart the program from the beginning?(N:No, Y:Yes)\n");
        scanf("%s",&runAgain);
        if (runAgain != 'y' && runAgain != 'Y') {
            if (runAgain != 'n' && runAgain != 'N') {
                printf("You entered indefinite value!");
                break;
            } else {
                printf("Thank you using the program.");
                break;
            }
        }
        fflush(stdin);
    }
    return 0;
}
