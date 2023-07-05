/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    char loopType;
    int num, i;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    printf("D = do/while | W = while | F = for | Q = quit\n");
    printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d%*c", &loopType, &num);

    while (loopType != 'Q' || num != 0)
    {
        if (loopType != 'D' && loopType != 'W' && loopType != 'F')
        {
            if (loopType == 'Q' && num != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            else
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
        }
        else if (num < 3 || num > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
        else if (loopType == 'D')
        {
            printf("DO-WHILE: ");
            do
            {
                printf("%c", loopType);
               num--;
            } while (0 < num);
            printf("\n");
        }
        else if (loopType == 'W')
        {
            printf("WHILE   : ");
            while (0 < num)
            {
                printf("%c", loopType);
                num--;
            }
            printf("\n");
        }
        else if (loopType == 'F')
        {
            printf("FOR     : ");
            for (i = 0; i < num; i++)
            {
                printf("%c", loopType);
            }
            printf("\n");
        }
        printf("\n");
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d%*c", &loopType, &num);
    }
    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}