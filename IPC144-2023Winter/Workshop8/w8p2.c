/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *numA)
{
	int num;
	do {
		scanf("%d", &num);
		if (num <= 0) printf("ERROR: Enter a positive value: ");
	} while (num <= 0);

	if (numA != NULL) *numA = num;
	return num;
};

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *dblA)
{
	double num;
	do {
		scanf("%lf", &num);
		if (num <= 0) printf("ERROR: Enter a positive value: ");
	} while (num <= 0);

	if (dblA != NULL) *dblA = num;
	return num;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProd)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");

	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProd);
	printf("NOTE: A 'serving' is %dg\n", GRAMS_SUG);
	printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence)
{
	struct CatFoodInfo info = { 0 };
	printf("Cat Food Product #%d\n", sequence + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&info.sku);

	printf("PRICE         : $");
	getDoublePositive(&info.productPrice);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.productWeightLbs);

	printf("CALORIES/SERV.: ");
	getIntPositive(&info.caloriesPerServ);
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
void displayCatFoodData(const int sku, const double *productPrice, const double *productWeightLbs, const int caloriesPerServ)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *productPrice, *productWeightLbs,
		caloriesPerServ);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *killoResult)
{
	double num;
	num = *lbs / CONVERT;

	if (killoResult != NULL) *killoResult = num;
	return num;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *gramResult)
{
	double num;
	int result;
	num = convertLbsKg(lbs, &num);
	result = num * 1000;

	if (gramResult != NULL) *gramResult = result;
	return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double *lbs, double *killo, int *gram)
{
	double num1;
	int num2;
	num1 = convertLbsKg(lbs, &num1);
	num2 = convertLbsG(lbs, &num2);
	*killo = num1;
	*gram = num2;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalprodGram, double *servResult)
{
	double result;
	result = (float)totalprodGram / (float)servingSizeG;

	if (servResult != NULL) *servResult = result;
	return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double prodPrice, const double totalNumServ, double *costResult)
{
	double num;
	num = (float)prodPrice / (float)totalNumServ;

	if (costResult != NULL) *costResult = num;
	return num;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double prodPricePerServ, const double totalCal, double *calResult)
{
	double num;
	num = (float)prodPricePerServ / (float)totalCal;

	if (calResult != NULL) *calResult = num;
	return num;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catInfo)
{
	struct ReportData data = { 0 };
	double totalCal;
	data.prodSku = catInfo.sku;
	data.prodPrice = catInfo.productPrice;
	data.caloriesPerServ = catInfo.caloriesPerServ;
	data.prodWeightLbs = catInfo.productWeightLbs;
	data.prodWeightKg = convertLbsKg(&catInfo.productWeightLbs, &data.prodWeightKg);
	data.prodWeightGr = convertLbsG(&catInfo.productWeightLbs, &data.prodWeightGr);
	data.totalNumOfServ = calculateServings(GRAMS_SUG, data.prodWeightGr, &data.totalNumOfServ);
	data.costPerServ = calculateCostPerServing(data.prodPrice, data.totalNumOfServ, &data.costPerServ);
	totalCal = data.caloriesPerServ * data.totalNumOfServ;
	data.costCalServ = calculateCostPerCal(data.prodPrice, totalCal, &data.costCalServ);

	return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_SUG);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", 
		data.prodSku, data.prodPrice, data.prodWeightLbs, data.prodWeightKg, data.prodWeightGr, data.caloriesPerServ, data.totalNumOfServ, data.costPerServ, data.costCalServ);
	if (cheapest > 0) printf(" ***");
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catInfo)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", catInfo.sku, catInfo.productPrice);

	printf("\n");
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catInfoArr[MAX_NUM_PROD] = { { 0 } };
	struct ReportData dataArr[MAX_NUM_PROD] = { { 0 } };
	int i, j, cheapest, finalProd;
	double cheapestCost;

	openingMessage(MAX_NUM_PROD);
	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		catInfoArr[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		displayCatFoodData(catInfoArr[i].sku, &catInfoArr[i].productPrice, &catInfoArr[i].productWeightLbs, catInfoArr[i].caloriesPerServ);
	}

	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		dataArr[i] = calculateReportData(catInfoArr[i]);
		if (i == MAX_NUM_PROD - 1)
		{
			cheapestCost = dataArr[0].costPerServ;
			for (j = 0; j < MAX_NUM_PROD; j++)
			{
				if(dataArr[j].costPerServ < cheapestCost)
				{
					cheapestCost = dataArr[j].costPerServ;
				}
			}
		}
	}

	printf("\n");
	displayReportHeader();
	for (i = 0; i < MAX_NUM_PROD; i++)
	{
		cheapest = 0;
		if (dataArr[i].costPerServ == cheapestCost)
		{
			cheapest = i;
			finalProd = i;
		}
		displayReportData(dataArr[i], cheapest);
	}

	printf("\n");
	displayFinalAnalysis(catInfoArr[finalProd]);
}
