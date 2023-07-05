/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char type1, type2, type3, cream1, cream2, cream3;
    int bagWeight1, bagWeight2, bagWeight3;
    char strength, userCream;
    int serving, num = 0;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");

    printf("\n");
    printf("Enter the coffee product information being sold today...\n");


    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type1 == 'l' || type1 == 'L', type1 == 'm' || type1 == 'M', type1 == 'r' || type1 == 'R', bagWeight1, bagWeight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'r' || type2 == 'R', bagWeight2, bagWeight2 / GRAMS_IN_LBS, cream2 == 'y' || cream2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type3 == 'l' || type3 == 'L', type3 == 'm' || type3 == 'M', type3 == 'r' || type3 == 'R', bagWeight3, bagWeight3 / GRAMS_IN_LBS, cream3 == 'y' || cream3 == 'Y');

    do {
        printf("\n");
        printf("Enter how you like your coffee...\n");
        printf("\n");
        printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
        scanf(" %c", &strength);
        printf("Do you like your coffee with cream ([Y]es,[N]o): ");
        scanf(" %c", &userCream);
        printf("Typical number of daily servings: ");
        scanf("%d", &serving);
        printf("\n");
        printf("The below table shows how your preferences align to the available products:\n");
        printf("\n");
        printf("--------------------+-------------+-------+\n");
        printf("  |     Coffee      |  Packaged   | With  |\n");
        printf("ID|      Type       | Bag Weight  | Cream |\n");
        printf("--+-----------------+-------------+-------+\n");
        printf(" 1|       %d         |      %d      |   %d   |\n",
            ((strength == 'l' || strength == 'L') && (type1 == 'l' || type1 == 'L')) ||
            ((strength == 'r' || strength == 'R') && (type1 == 'r' || type1 == 'R')) ||
            ((strength == 'm' || strength == 'M') && (type1 == 'm' || type1 == 'M')),
            (serving >= 1 && serving <= 4 && bagWeight1 <= 250) ||
            (serving >= 5 && serving <= 9 && bagWeight1 > 250 && bagWeight1 <= 500) ||
            (serving >= 10 && bagWeight1 > 500 && bagWeight1 <= 1000),
            ((userCream == 'y' || userCream == 'Y') && (cream1 == 'y' || cream1 == 'Y')) ||
            ((userCream == 'n' || userCream == 'N') && (cream1 == 'n' || cream1 == 'N')));
        printf(" 2|       %d         |      %d      |   %d   |\n",
            ((strength == 'l' || strength == 'L') && (type2 == 'l' || type2 == 'L')) ||
            ((strength == 'r' || strength == 'R') && (type2 == 'r' || type2 == 'R')) ||
            ((strength == 'm' || strength == 'M') && (type2 == 'm' || type2 == 'M')),
            (serving >= 1 && serving <= 4 && bagWeight2 <= 250) ||
            (serving >= 5 && serving <= 9 && bagWeight2 > 250 && bagWeight2 <= 500) ||
            (serving >= 10 && bagWeight2 > 500 && bagWeight2 <= 1000),
            ((userCream == 'y' || userCream == 'Y') && (cream2 == 'y' || cream2 == 'Y')) ||
            ((userCream == 'n' || userCream == 'N') && (cream2 == 'n' || cream2 == 'N')));
        printf(" 3|       %d         |      %d      |   %d   |\n",
            ((strength == 'l' || strength == 'L') && (type3 == 'l' || type3 == 'L')) ||
            ((strength == 'r' || strength == 'R') && (type3 == 'r' || type3 == 'R')) ||
            ((strength == 'm' || strength == 'M') && (type3 == 'm' || type3 == 'M')),
            (serving >= 1 && serving <= 4 && bagWeight3 <= 250) ||
            (serving >= 5 && serving <= 9 && bagWeight3 > 250 && bagWeight3 <= 500) ||
            (serving >= 10 && bagWeight3 > 500 && bagWeight3 <= 1000),
            ((userCream == 'y' || userCream == 'Y') && (cream3 == 'y' || cream3 == 'Y')) ||
            ((userCream == 'n' || userCream == 'N') && (cream3 == 'n' || cream3 == 'N')));
        num++;
    } while (num < 2);
    
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/