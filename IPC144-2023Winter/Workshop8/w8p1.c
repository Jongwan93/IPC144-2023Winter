/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Jong wan Steven Hur
Student ID#: 122372220
Email      : shur1@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *numA)
{
	int num = 0;
	do {
		scanf("%d", &num);
		if (num <= 0) printf("ERROR: Enter a positive value: ");
	} while (num <= 0);

	if (numA != NULL) *numA = num;
	return num;
};

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblA)
{
	double num = 0.0;
	do {
		scanf("%lf", &num);
		if (num <= 0) printf("ERROR: Enter a positive value: ");
	} while (num <= 0);

	if (dblA != NULL) *dblA = num;
	return num;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PROD);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_SUG);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int sequence)
{
	struct CatFoodInfo info = { 0 };
	printf("Cat Food Product #%d\n", sequence + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&info.sku);

	printf("PRICE         : $");
	getDoublePositive(&info.productPrice);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.productWeight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&info.calories);
	printf("\n");

	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo *info)
{
	printf("%07d %10.2lf %10.1lf %8d\n", info->sku, info->productPrice, info->productWeight, 
		info->calories);
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo infoArr[MAX_NUM_PROD] = { { 0 } };
	int i;

	openingMessage();
	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		infoArr[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		displayCatFoodData(&infoArr[i]);
	}
}