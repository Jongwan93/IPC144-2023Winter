/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double small;
    double medium;
    double large;
    int patShirtCount, salShirtCount, tomShirtCount;                               //count of shirts each person purchased

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &large);
    printf("\n");
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", small);
    printf("MEDIUM : $%.2lf\n", medium);
    printf("LARGE  : $%.2lf\n", large);

    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &patShirtCount);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomShirtCount);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salShirtCount);

    printf("\n");
    const double TAX = 0.13;
    float patSubTotal = patShirtCount * small;                                      //sub-total of each person
    float salSubTotal = salShirtCount * medium;
    float tomSubTotal = tomShirtCount * large;
    int patTaxes = patSubTotal * TAX * 100 + 0.5;                                   //tax of each person
    int tomTaxes = tomSubTotal * TAX * 100 + 0.5;
    int salTaxes = salSubTotal * TAX * 100 + 0.5;
    int patTotal = (patSubTotal + (patSubTotal * TAX)) * 100 + 0.5;                 //total of each person including tax
    int salTotal = (salSubTotal + (salSubTotal * TAX)) * 100 + 0.5;
    int tomTotal = (tomSubTotal + (tomSubTotal * TAX)) * 100 + 0.5;
    float subTotal = patSubTotal + salSubTotal + tomSubTotal;                       //sub-total of all 3 people
    float taxes = (patTaxes + salTaxes + tomTaxes) / 100.0;                         //tax of all 3 people
    float total = (patTotal + salTotal + tomTotal) / 100.0;                         //total of all 3 people

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, small, patShirtCount, patSubTotal, patTaxes / 100.0, patTotal / 100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medium, salShirtCount, salSubTotal, salTaxes / 100.0, salTotal / 100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, large, tomShirtCount, tomSubTotal, tomTaxes / 100.0, tomTotal / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n", subTotal, taxes, total);

    printf("\n");
    int toonies, loonies, quarters, dimes, nickels, pennies;
    float balance;
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");

    printf("\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal);
    toonies = subTotal / 2;
    balance = subTotal - toonies * 2;
    printf("Toonies  %3d %9.4lf\n", toonies, balance);
    loonies = balance;
    balance -= loonies;
    printf("Loonies  %3d %9.4lf\n", loonies, balance);
    quarters = balance * 100 / 25;
    balance -= quarters * 25 / 100.0;
    printf("Quarters %3d %9.4lf\n", quarters, balance);
    dimes = balance * 100 / 10;
    balance -= dimes * 10 / 100.0;
    printf("Dimes    %3d %9.4lf\n", dimes, balance);
    nickels = balance * 100 / 5;
    balance -= nickels * 5 / 100.0;
    printf("Nickels  %3d %9.4lf\n", nickels, balance);
    pennies = balance * 100;
    balance -= pennies / 100.0;
    printf("Pennies  %3d %9.4lf\n", pennies, balance);

    printf("\n");
    int qty = patShirtCount + salShirtCount + tomShirtCount;
    printf("Average cost/shirt: $%.4lf\n", subTotal / qty);

    printf("\n");
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total);
    toonies = total / 2;
    balance = total - toonies * 2;
    printf("Toonies  %3d %9.4lf\n", toonies, balance);
    loonies = balance;
    balance -= loonies;
    printf("Loonies  %3d %9.4lf\n", loonies, balance);
    quarters = balance * 100 / 25;
    balance -= quarters * 25 / 100.0;
    printf("Quarters %3d %9.4lf\n", quarters, balance);
    dimes = balance * 100 / 10;
    balance -= dimes * 10 / 100.0;
    printf("Dimes    %3d %9.4lf\n", dimes, balance);
    nickels = balance * 100 / 5;
    balance -= nickels * 5 / 100.0;
    printf("Nickels  %3d %9.4lf\n", nickels, balance);
    pennies = balance * 100;
    balance -= pennies / 100.0;
    printf("Pennies  %3d %9.4lf\n", pennies, balance);
    
    printf("\n");
    printf("Average cost/shirt: $%.4lf\n", total / qty);
 
    return 0;
}