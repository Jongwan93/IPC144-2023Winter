/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, count = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    putchar('\n');
    if (count == 0)
    {
        printf("*** No records found ***\n");
    }
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int selection = 1;
    while (selection != 0)
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }
    }
    putchar('\n');
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int i, count = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            patient[i].patientNumber = nextPatientNumber(patient, max);
            inputPatient(&patient[i]);
            count++;
            printf("*** New patient record added ***\n");
            putchar('\n');
            i = max;
        }
    }
    if (count == 0)
    {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
    }
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientNumber = 0, patientPosition = 0;
    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    if (patientPosition < 0)
    {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
        suspend();
    }
    else if (patientPosition >= 0)
    {
        putchar('\n');
        menuPatientEdit(&patient[patientPosition]);
    }
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientNumber = 0, patientPosition = 0, outOfRange = 0;
    char choice = 0;
    char tmp = 0;
    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    patientPosition = findPatientIndexByPatientNum(patientNumber, patient, max);
    putchar('\n');
    if (patientPosition < 0)
    {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else
    {
        displayPatientData(&patient[patientPosition], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        do
        {
            scanf(" %c%c", &choice, &tmp);
            outOfRange = (choice != 'y' && choice != 'n') || tmp != '\n';
            if (outOfRange)
            {
                printf("ERROR: Character must be one of [yn]: ");
                clearInputBuffer();
            }
        } while (outOfRange);

        if (choice == 'n')
        {
            printf("Operation aborted.\n");
        }
        else if (choice == 'y')
        {
            patient[patientPosition].patientNumber = 0;
            patient[patientPosition].name[0] = '\0';
            patient[patientPosition].phone.description[0] = '\0';
            patient[patientPosition].phone.number[0] = '\0';
            printf("Patient record has been removed!\n");
        }
        putchar('\n');
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(const struct ClinicData* data)
{
    int i, j;
    sortData(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxAppointments; j++)
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }
    putchar('\n');
}


// View appointment schedule for the user input date
void viewAppointmentSchedule(const struct ClinicData* data)
{
    int i, j;
    struct Date date;
    getDate(&date.year, &date.month, &date.day);
    putchar('\n');
    sortData(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxAppointments; j++)
        {
            if (data->appointments[i].patientNumber == data->patients[j].patientNumber &&
                data->appointments[i].date.year == date.year &&
                data->appointments[i].date.month == date.month &&
                data->appointments[i].date.day == date.day)
            {
                displayScheduleData(&data->patients[j], &data->appointments[i], 0);
            }
        }
    }
    putchar('\n');
}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment* app, const int maxAppointments, struct Patient* pt, const int maxPatients)
{
    int i, count = 0, patientNumber, index, flag = 1, slot;
    struct Date date;
    struct Time time;
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);
    slot = findEmptySlot(app, maxPatients);
    if (slot == -1)
    {
        printf("ERROR: Appointment listing is FULL!\n");
    }
    else
    {
        if (index == -1)
        {
            printf("ERROR: Patient record not found!\n");
            putchar('\n');
        }
        else
        {
            while (flag)
            {
                count = 0;
                getDate(&date.year, &date.month, &date.day);
                getTime(&time.hour, &time.min);
                for (i = 0; i < maxAppointments; i++)
                {
                    if (time.min == app[i].time.min &&
                        time.hour == app[i].time.hour &&
                        date.day == app[i].date.day &&
                        date.month == app[i].date.month &&
                        date.year == app[i].date.year)
                    {
                        putchar('\n');
                        printf("ERROR: Appointment timeslot is not available!\n");
                        putchar('\n');
                        count++;
                        i = maxAppointments;
                    }
                }
                if (count == 0)
                {
                    while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || time.min % MINUTE_INTERVAL != 0)
                    {
                        printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                        putchar('\n');
                        getTime(&time.hour, &time.min);
                    }
                    flag = 0;
                }
            }
            app[index].date = date;
            app[index].time = time;
            app[index].patientNumber = patientNumber;
            putchar('\n');
            printf("*** Appointment scheduled! ***\n");
            putchar('\n');
        }
    }
}


// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* app, const int maxAppointments, struct Patient* pt, const int maxPatients)
{
    int patientNumber, patientPosition, check = 0;
    struct Date date;
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    patientPosition = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);
    if (patientPosition < 0)
    {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else
    {
        getDate(&date.year, &date.month, &date.day);
        putchar('\n');
        check = appointmentCheck(date, app, maxAppointments, patientNumber);
        if (check >= 0)
        {
            displayPatientData(&pt[patientPosition], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");
            if (inputCharOption("yn") == 'y')
            {
                app[check].patientNumber = '\0';
                app[check].date.year = '\0';
                app[check].date.month = '\0';
                app[check].date.day = '\0';
                app[check].time.hour = '\0';
                app[check].time.min = '\0';

                putchar('\n');
                printf("Appointment record has been removed!\n");
                putchar('\n');
            }
            else
            {
                printf("ERROR: No appointment for this date!\n");
                putchar('\n');
            }
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber = 0, patientIndex = 0;
    putchar('\n');
    printf("Search by patient number: ");
    patientNumber = inputIntPositive();
    patientIndex = findPatientIndexByPatientNum(patientNumber, patient, max);
    putchar('\n');
    if (patientIndex < 0)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientData(&patient[patientIndex], FMT_FORM);
    }
    putchar('\n');
    suspend();
}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    putchar('\n');
    int i, count = 0;
    char phoneNumber[PHONE_LEN + 1] = { 0 };
    printf("Search by phone number: ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++;
        }
    }
    if (count == 0)
    {
        putchar('\n');
        printf("*** No records found ***\n");
    }
    putchar('\n');
    suspend();
}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxNum = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber >= maxNum)
        {
            maxNum = patient[i].patientNumber + 1;
        }
    }
    return maxNum;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    return -1;
}

// check if appointment is valid
int appointmentCheck(const struct Date date, const struct Appointment* app, const int maxAppointments, const int patientNumber)
{
    int i, index = -1;
    for (i = 0; i < maxAppointments; i++)
    {
        if ((app[i].patientNumber == patientNumber) &&
            (date.year == app[i].date.year) &&
            (date.month == app[i].date.month) &&
            (date.day == app[i].date.day))
        {
            index = i;
            i = maxAppointments;
        }
    }
    return index;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int selection = 0;
    char des1[PHONE_DESC_LEN + 1] = { "CELL" };
    char des2[PHONE_DESC_LEN + 1] = { "HOME" };
    char des3[PHONE_DESC_LEN + 1] = { "WORK" };
    char des4[PHONE_DESC_LEN + 1] = { "TBD" };
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    printf("\n");
    if (selection == 1)
        strcpy(phone->description, des1);
    else if (selection == 2)
        strcpy(phone->description, des2);
    else if (selection == 3)
        strcpy(phone->description, des3);
    else if (selection == 4)
        strcpy(phone->description, des4);
    if (selection != 4)
    {

        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        putchar('\n');
    }
    else
    {
        phone->number[0] = '\0';
    }
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i = 0;
    FILE* fp;
    fp = fopen(datafile, "r");

    if (fp == NULL)
    {
        putchar('\n');
        printf("Fail to open the file\n");
        suspend();
    }
    else
    {
        for(i = 0; i < max; i++)
        {
            fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[i].patientNumber,
                patients[i].name,
                patients[i].phone.description,
                patients[i].phone.number);
        }
    }
    fclose(fp);
    return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i, count = 0;
    FILE* fp;
    fp = fopen(datafile, "r");

    if (fp == NULL)
    {
        putchar('\n');
        printf("Fail to open the file\n");
        suspend();
    }
    else
    {
        for (i = 0; i < max; i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", 
                &appoints[i].patientNumber,
                &appoints[i].date.year,
                &appoints[i].date.month,
                &appoints[i].date.day,
                &appoints[i].time.hour,
                &appoints[i].time.min);
            if (!feof(fp))
            {
                count++;
            }
        }
        
    }
    fclose(fp);
    return count;
}

