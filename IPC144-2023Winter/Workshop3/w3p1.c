/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int p1id = 111;
    double p1Price = 111.49;
    char p1Tax = 'Y';
    int p2id = 222;
    double p2Price = 222.99;
    char p2Tax = 'N';
    int p3id = 111;
    double p3Price = 334.49;
    char p3Tax = 'N';
    double average = (p1Price + p2Price + p3Price) / 3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", p1id);
    printf("  Taxed: %c\n", p1Tax);
    printf("  Price: $%.4lf\n", p1Price);
    
    printf("\n");
    printf("Product-2 (ID:%d)\n", p2id);
    printf("  Taxed: %c\n", p2Tax);
    printf("  Price: $%.4lf\n", p2Price);

    printf("\n");
    printf("Product-3 (ID:%d)\n", p3id);
    printf("  Taxed: %c\n", p3Tax);
    printf("  Price: $%.4lf\n", p3Price);

    printf("\n");
    printf("The average of all prices is: $%.4lf\n", average);

    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");

    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", p1Tax == 'Y');
    printf("2. Are product 2 and 3 both NOT taxable (N)? -> %d\n\n", p2Tax == 'N' && p3Tax == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, p3Price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", p3Price > p1Price + p2Price);
    printf("5. Is the price of product 1 equal to or more than the price difference of product 3 LESS product 2? -> %d (price difference: $%.2lf)\n\n", p1Price >= p3Price - p2Price, p3Price - p2Price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", p2Price >= average);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", p1id != p2id && p1id != p3id);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", p2id != p1id && p2id != p3id);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", p3id != p1id && p3id != p2id);

    return 0;
}