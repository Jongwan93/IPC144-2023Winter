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
    int apples, oranges, pears, tomatoes, cabbages;
    int pickApples = 0, pickOranges = 0, pickPears = 0, pickTomatoes = 0, pickCabbages = 0;
    int pick, quit = 0;

    do {
        printf("Grocery Shopping\n");
        printf("================\n");
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        while (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        }

        printf("\n");
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        while (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &oranges);
        }

        printf("\n");
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        while (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many pears do you need? : ");
            scanf("%d", &pears);
        }

        printf("\n");
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes);
        while (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        }

        printf("\n");
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages);
        while (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        }

        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");

        printf("\n");   //picking up the Apples
        while (apples > 0 && pickApples != apples)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > (apples - pickApples))
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples - pickApples);
            }
            else
            {
                pickApples += pick;
            }
            if (pickApples > 0 && pick > 0 && pick <= apples - pickApples)
            {
                printf("Looks like we still need some APPLES...\n");
            }
        }
        if (pickApples == apples)
        {
            printf("Great, that's the apples done!\n");
        }

        printf("\n");   //picking up the Oranges
        while (oranges > 0 && pickOranges != oranges)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > (oranges - pickOranges))
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges - pickOranges);
            }
            else
            {
                pickOranges += pick;
            }
            if (pickOranges > 0 && pick > 0 && pick <= oranges - pickOranges)
            {
                printf("Looks like we still need some ORANGES...\n");
            }
        }
        printf("Great, that's the oranges done!\n");

        printf("\n");   //picking up the Pears
        while (pears > 0 && pickPears != pears)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > (pears - pickPears))
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears - pickPears);
            }
            else
            {
                pickPears += pick;
            }
            if (pickPears > 0 && pick > 0 && pick <= pears - pickPears)
            {
                printf("Looks like we still need some PEARS...\n");
            }
        }
        printf("Great, that's the pears done!\n");

        printf("\n");   //picking up the Tomatoes
        while (tomatoes > 0 && pickTomatoes != tomatoes)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > (tomatoes - pickTomatoes))
            {
                printf("You picked too many... only %d more TOMATOES(S) are needed.\n", tomatoes - pickTomatoes);
            }
            else
            {
                pickTomatoes += pick;
            }
            if (pickTomatoes > 0 && pick > 0 && pick <= tomatoes - pickTomatoes)
            {
                printf("Looks like we still need some TOMATOES...\n");
            }
        }
        printf("Great, that's the tomatoes done!\n");

        printf("\n");   //picking up the Cabbages
        while (cabbages > 0 && pickCabbages != cabbages)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pick);
            if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if (pick > (cabbages - pickCabbages))
            {
                printf("You picked too many... only %d more CABBAGES(S) are needed.\n", cabbages - pickCabbages);
            }
            else
            {
                pickCabbages += pick;
            }
            if (pickCabbages > 0 && pick > 0 && pick <= cabbages - pickCabbages)
            {
                printf("Looks like we still need some CABBAGES...\n");
            }
        }
        printf("\n");
        printf("Great, that's the cabbages done!\n");

        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &quit);
        printf("\n");
    } while (quit != 1);
    return 0;
}