/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :    Jong wan Steven Hur
Student ID#:    122372220
Email      :    shur1@myseneca.ca
Section    :    NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "core.h"
#include "clinic.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// get input from user and verify it is a whole number
int inputInt()
{
    int num = 0;
    char c = 0;
    while (c != '\n')
    {
        scanf("%d%c", &num, &c);
        if (c != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return num;
}

// get input from user and verify it is a positive whole number
int inputIntPositive()
{
    int num = 0, outOfRange = 0;
    do
    {
        scanf("%d%*c", &num);
        outOfRange = num < 0;
        if (outOfRange)
        {
            //clearInputBuffer();
            printf("ERROR! Value must be >= 0: ");
        }
    } while (outOfRange);
    return num;
}

// verify if the input is in between the range
int inputIntRange(const int lowBound, const int upperBound)
{
    int num = 0;
    do
    {
        num = inputInt();
        if (num >= lowBound && num <= upperBound)
        {
            return num;
        }
        else if (num < lowBound || num > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowBound, upperBound);
        }
    } while (num < lowBound || num > upperBound);
    return 0;
}

// check if user input matches one of the element in array
char inputCharOption(const char inputArr[])
{
    char c;
    do
    {
        c = getchar();
        if (strchr(inputArr, c))
        {
            clearInputBuffer();
            return c;
        }
        else
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [yn]: ");
        }
    } while (c != '\n');
    return c;
}

// check if user input string has length in between the range
void inputCString(char* cstringValue, const int minRange, const int maxRange)
{
    int len = 0;
    char tmpArr[100] = { 0 };
    do
    {
        scanf("%[^\n]s%*c", tmpArr);
        len = strlen(tmpArr);
        if (len > maxRange || len < minRange)
        {
            if (maxRange == minRange)
                printf("Invalid 10-digit number! Number: ");
            else if (len > maxRange)
                printf("ERROR: String length must be no more than %d chars: ", maxRange);
            else if (minRange < maxRange)
                printf("ERROR: String length must be between %d and %d chars: ", minRange, maxRange);
            clearInputBuffer();
        }
    } while (len > maxRange || len < minRange);
    strcpy(cstringValue, tmpArr);
    clearInputBuffer();
}

// displays the phone number in a proper form
void displayFormattedPhone(const char* phoneNumber)
{
    int i, digit = 0;
    if (phoneNumber == NULL)
        printf("(___)___-____");
    else
    {
        for (i = 0; phoneNumber[i] != '\0'; i++)
        {
            if (isdigit(phoneNumber[i]))
                digit++;
        }
        if (digit == 10)
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
                phoneNumber[0], phoneNumber[1], phoneNumber[2],
                phoneNumber[3], phoneNumber[4], phoneNumber[5],
                phoneNumber[6], phoneNumber[7], phoneNumber[8],
                phoneNumber[9]);
        else
            printf("(___)___-____");
    }
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// sort the data using bubble sort
void sortData(struct Appointment* app, const int max)
{
    int i, j;
    struct Appointment temp;
    for (i = 0; i < max - 1; i++)
    {
        for (j = 0; j < max - i - 1; j++)
        {
            if (app[j].date.year > app[j + 1].date.year ||
                (app[j].date.year == app[j + 1].date.year &&
                (app[j].date.month > app[j + 1].date.month ||
                (app[j].date.month == app[j + 1].date.month &&
                (app[j].date.day > app[j + 1].date.day ||
                (app[j].date.day == app[j + 1].date.day &&
                (app[j].time.hour > app[j + 1].time.hour ||
                (app[j].time.hour == app[j + 1].time.hour &&
                 app[j].time.min > app[j + 1].time.min))))))))
            {
                temp = app[j];
                app[j] = app[j + 1];
                app[j + 1] = temp;
            }
        }
    }
}

// Get user input for year, month, day
void getDate(int* year, int* month, int* day)
{
    printf("Year        : ");
    *year = inputIntPositive();
    printf("Month (1-12): ");
    *month = inputIntRange(1, 12);
    if (*year % 4 == 0 && *month == 2)
    {
        printf("Day (1-29)  : ");
        *day = inputIntRange(1, 29);
    }
    else if (*year % 4 != 0 && *month == 2)
    {
        printf("Day (1-28)  : ");
        *day = inputIntRange(1, 28);
    }
    else if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
    {
        printf("Day (1-30)  : ");
        *day = inputIntRange(1, 30);
    }
    else
    {
        printf("Day (1-31)  : ");
        *day = inputIntRange(1, 31);
    }
}

// Get user input for hour and minuite
void getTime(int* hour, int* min)
{
    printf("Hour (0-23)  : ");
    *hour = inputIntRange(0, 23);
    printf("Minute (0-59): ");
    *min = inputIntRange(0, 59);
}

// Check if there is any empty slot to add a new appointment
int findEmptySlot(struct Appointment* app, const int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (app[i].patientNumber == 0)
        {
            return i;
        }
    }
    return -1;
}

