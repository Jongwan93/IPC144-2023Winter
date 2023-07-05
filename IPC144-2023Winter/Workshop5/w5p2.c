/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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


#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 0, month = 0, i;
    char m1, m2, m3;
    double rate = -1.0, morningTotal = 0.0, eveningTotal = 0.0, morningAverage = 0.0, eveningAverage = 0.0;
    printf("General Well-being Log\n");
    printf("======================\n");
    while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d%*c", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    }

    printf("\n");
    printf("*** Log date set! ***\n");

    switch (month)
    {
    case 1:
        m1 = 'J';
        m2 = 'A';
        m3 = 'n';
        break;
    case 2:
        m1 = 'F';
        m2 = 'E';
        m3 = 'B';
        break;
    case 3:
        m1 = 'M';
        m2 = 'A';
        m3 = 'R';
        break;
    case 4:
        m1 = 'A';
        m2 = 'P';
        m3 = 'R';
        break;
    case 5:
        m1 = 'M';
        m2 = 'A';
        m3 = 'Y';
        break;
    case 6:
        m1 = 'J';
        m2 = 'U';
        m3 = 'N';
        break;
    case 7:
        m1 = 'J';
        m2 = 'U';
        m3 = 'L';
        break;
    case 8:
        m1 = 'A';
        m2 = 'U';
        m3 = 'G';
        break;
    case 9:
        m1 = 'S';
        m2 = 'E';
        m3 = 'P';
        break;
    case 10:
        m1 = 'O';
        m2 = 'C';
        m3 = 'T';
        break;
    case 11:
        m1 = 'N';
        m2 = 'O';
        m3 = 'V';
        break;
    case 12:
        m1 = 'D';
        m2 = 'E';
        m3 = 'C';
        break;
    }

    for (i = 1; i <= LOG_DAYS; i++)
    {
        printf("\n");
        if (i < 10)
        {
            printf("%d-%c%c%c-0%d", year, m1, m2, m3, i);
        }
        else
        {
            printf("%d-%c%c%c-%d", year, m1, m2, m3, i);
        }
        printf("\n");
        while (rate < 0.0 || rate > 5.0)
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &rate);
            if (rate < 0.0 || rate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        morningTotal += rate;
        rate = -1.0;
        while (rate < 0.0 || rate > 5.0)
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &rate);
            if (rate < 0.0 || rate > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        }
        eveningTotal += rate;
        rate = -1.0;
    }
    
    printf("\n");
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningTotal);
    printf("Evening total rating:%7.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n", morningTotal + eveningTotal);

    printf("\n");
    morningAverage = (morningTotal / LOG_DAYS * 100 + 0.5) / 100;
    eveningAverage = (eveningTotal / LOG_DAYS * 100 + 0.5) / 100;
    printf("Average morning rating:%5.1lf\n", morningAverage);
    printf("Average evening rating:%5.1lf\n", eveningAverage);
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n", (morningAverage + eveningAverage) / 2);

    return 0;
}