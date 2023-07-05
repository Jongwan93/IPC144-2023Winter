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

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PROD 3
#define GRAMS_SUG 64
#define CONVERT 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double productPrice;
    int caloriesPerServ;
    double productWeightLbs;
};

struct ReportData
{
    int prodSku;
    double prodPrice;
    int caloriesPerServ;
    double prodWeightLbs;
    double prodWeightKg;
    int prodWeightGr;
    double totalNumOfServ;
    double costPerServ;
    double costCalServ;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *numA);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *dblA);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProd);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *productPrice, const double *productWeightLbs, const int caloriesPerServ);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbs, double *killoResult);

// 9. convert lbs: g
int convertLbsG(const double *lbs, int *gramResult);

// 10. convert lbs: kg / g
void convertLbs(const double *lbs, double *killo, int *gram);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalprodGram, double *servResult);

// 12. calculate: cost per serving
double calculateCostPerServing(const double prodPrice, const double totalNumServ, double *costResult);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double prodPricePerServ, const double totalCal, double *calResult);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
