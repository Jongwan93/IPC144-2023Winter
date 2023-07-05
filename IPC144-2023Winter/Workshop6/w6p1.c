/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  :
Student ID#:
Email      :
Section    :

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ITEMS 10
#define MIN_ITEMS 1
#define MAX_LIST 10

int main(void)
{
    const double minCost = 100.00, minIncome = 500.00, maxIncome = 400000.00;
    double netIncome, costOfItem = 0.0, totalCost = 0.0;
    int listOfItems = 2, importanceOfItem, outOfRange = 0, i;
    char finance;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    
    printf("\n");
    do {              //NET income
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        printf("\n");
    } while (netIncome < minIncome || netIncome > maxIncome);

    do {        //number of list of times
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &listOfItems);
        outOfRange = listOfItems < MIN_ITEMS || listOfItems > MAX_ITEMS;
        if (outOfRange)  printf("ERROR: List is restricted to between 1 and 10 items.\n");
        printf("\n");
    } while (listOfItems < MIN_ITEMS || listOfItems > MAX_ITEMS);

    int priority[MAX_LIST];             //array created
    char financeOption[MAX_LIST];
    double cost[MAX_LIST];

    for (i = 0; i < listOfItems; i++)
    {
        printf("Item-%d Details:\n", i+1);
        do {   //cost of item
            printf("   Item cost: $");
            scanf("%lf", &costOfItem);
            outOfRange = costOfItem < minCost;
            if (outOfRange) printf("      ERROR: Cost must be at least $100.00\n");
        } while (costOfItem < minCost);
        cost[i] = costOfItem;
        totalCost += cost[i];   //total cost calculation

        do {   //importance of item
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d%*c", &importanceOfItem);
            outOfRange = importanceOfItem < 1 || importanceOfItem > 3;
            if (outOfRange) printf("      ERROR: Value must be between 1 and 3\n");
        } while (importanceOfItem < 1 || importanceOfItem > 3);
        priority[i] = importanceOfItem;

        do {   //finance of item
            printf("   Does this item have financing options? [y/n]: ");
            scanf("%c%*c", &finance);
            outOfRange = finance != 'y' && finance != 'n';
            if (outOfRange) printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (finance != 'y' && finance != 'n');
        financeOption[i] = finance;
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");        //display
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < listOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], financeOption[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    printf("Best of luck in all your future endeavours!\n");
    return 0;
}