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
#define MIN_COST 100.00
#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00

int main(void)
{
    double netIncome, costOfItem = 0.0, totalCost = 0.0, priorityTotalCost;
    int listOfItems = 2, importanceOfItem, outOfRange = 0, i, priority, selection;
    char finance;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    printf("\n");
    do {              //NET income
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        printf("\n");
    } while (netIncome < MIN_INCOME || netIncome > MAX_INCOME);

    do {        //number of list of times
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &listOfItems);
        outOfRange = listOfItems < MIN_ITEMS || listOfItems > MAX_ITEMS;
        if (outOfRange)  printf("ERROR: List is restricted to between 1 and 10 items.\n");
        printf("\n");
    } while (listOfItems < MIN_ITEMS || listOfItems > MAX_ITEMS);

    int productPriority[MAX_LIST] = { 0 };             //array created
    char financeOption[MAX_LIST] = { 0 };
    double cost[MAX_LIST] = { 0 };

    for (i = 0; i < listOfItems; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        do {   //cost of item
            printf("   Item cost: $");
            scanf("%lf", &costOfItem);
            outOfRange = costOfItem < MIN_COST;
            if (outOfRange) printf("      ERROR: Cost must be at least $100.00\n");
        } while (costOfItem < MIN_COST);
        cost[i] = costOfItem;
        totalCost += cost[i];   //total cost calculation

        do {   //importance of item
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d%*c", &importanceOfItem);
            outOfRange = importanceOfItem < 1 || importanceOfItem > 3;
            if (outOfRange) printf("      ERROR: Value must be between 1 and 3\n");
        } while (importanceOfItem < 1 || importanceOfItem > 3);
        productPriority[i] = importanceOfItem;

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
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, productPriority[i], financeOption[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);
    
    do {
        do {
            printf("\n");
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");
            printf("Selection: ");
            scanf("%d", &selection);
            outOfRange = selection < 0 || selection > 2;
            printf("\n");
            if (outOfRange) printf("ERROR: Invalid menu selection.\n");
        } while (outOfRange);

        int years;
        float months;
        if (selection == 1)
        {
            years = (int)totalCost / (int)(netIncome * 12);
            months = (totalCost / (netIncome * 12)) - years;
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", years, (int)(months*12+1));

            for (i = 0; i < MAX_LIST; i++)
            {
                if (financeOption[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i = MAX_ITEMS;
                }
            }
            printf("====================================================\n");
        }
        if (selection == 2)
        {
            priorityTotalCost = 0.0;
            do {
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priority);
                outOfRange = priority < 1 || priority > 3;
                if(outOfRange) printf("ERROR: Invalid menu selection.\n");
            } while (outOfRange);
            printf("\n");

            for (i = 0; i < MAX_LIST; i++)
            {
                if (productPriority[i] == priority)
                {
                    priorityTotalCost += cost[i];
                }
            }
            years = (int)priorityTotalCost / (int)(netIncome * 12);
            months = (priorityTotalCost / (netIncome * 12)) - years;
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);
            printf("Amount:   $%.2lf\n", priorityTotalCost);
            printf("Forecast: %d years, %d months\n", years, (int)(months * 12 + 1));

            for (i = 0; i < MAX_LIST; i++)
            {
                if (productPriority[i] == priority && financeOption[i] == 'y')
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    i = MAX_ITEMS;
                }
            }
            printf("====================================================\n");
        }

    } while (selection != 0);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}