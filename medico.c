#include<stdio.h>
#include<string.h>

//------------------------------------------------------------//

void patientSignup();
void patientLogin();
void doctorSignup();
void doctorLogin();
void medicinechart();
void patientdetails();
void calculatebill();

//------------------------------------------------------------//

struct signup {

    char name[100];
    char pass[100];
    int age;
    char gender[20];
    long long int Mno;

};

struct signup s;

//------------------------------------------------------------//

struct doctor {

    char id[50];
    char pass[50];
    char name[100];

};

struct doctor d;

//------------------------------------------------------------//

char doctorName[100] = "Not Assigned";
char patientDisease[100];

int patientLoginSuccess = 0;
int doctorLoginSuccess = 0;

int totalBill = 0;
int days = 0;

//------------------------------------------------------------//

char diseases[10][50] = {

    "Fever",
    "Cold",
    "Cough",
    "Diabetes",
    "Blood Pressure",
    "Asthma",
    "Headache",
    "Typhoid",
    "Skin Allergy",
    "Stomach Infection"

};

//------------------------------------------------------------//

char medicines[10][3][50] = {

    {"Paracetamol", "Dolo650", "Crocin"},
    {"Cetirizine", "Sinarest", "Coldact"},
    {"Benadryl", "TusQ", "Ascoril"},
    {"Insulin", "Metformin", "Glycomet"},
    {"Telma", "Amlodipine", "Losartan"},
    {"Asthalin", "Budecort", "Deriphyllin"},
    {"Saridon", "Disprin", "Combiflam"},
    {"Azithromycin", "Monocef", "Ofloxacin"},
    {"CandidCream", "Atarax", "Levocet"},
    {"Pantoprazole", "ORS", "Rantac"}

};

//------------------------------------------------------------//

int prices[10][3] = {

    {50,60,40},
    {30,35,45},
    {70,65,55},
    {120,150,110},
    {90,85,80},
    {100,95,85},
    {25,20,30},
    {160,170,150},
    {60,55,50},
    {40,25,35}

};

//------------------------------------------------------------//

int main() {

    int choice;
    char ch;

    printf("=====================================================\n");
    printf("         WELCOME TO M & M MEDICAL SYSTEM             \n");
    printf("=====================================================\n");

    printf("\nAvailable Diseases:\n");
    printf("Fever, Cold, Cough, Diabetes,\n");
    printf("Blood Pressure, Asthma, Headache,\n");
    printf("Typhoid, Skin Allergy, Stomach Infection\n");

    printf("\n1. Patient Sign Up\n");
    printf("2. Patient Login\n");
    printf("3. Doctor Sign Up\n");
    printf("4. Doctor Login\n");
    printf("5. Exit\n");

    printf("\nEnter Your Choice : ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            patientSignup();
            break;

        case 2:
            patientLogin();
            break;

        case 3:
            doctorSignup();
            break;

        case 4:
            doctorLogin();
            break;

        case 5:
            printf("\nThank You For Visiting\n");
            return 0;

        default:
            printf("\nInvalid Choice\n");
            return 0;
    }

    //------------------------------------------------------------//

    if(patientLoginSuccess == 1 || doctorLoginSuccess == 1) {

        while(1) {

            printf("\n\n=====================================================\n");
            printf("                    MAIN MENU                        \n");
            printf("=====================================================\n");

            printf("A. Medicine Chart\n");
            printf("B. Patient Details\n");
            printf("C. Calculate Bill\n");
            printf("D. Exit\n");

            printf("\nEnter Your Choice : ");
            scanf(" %c", &ch);

            switch(ch) {

                case 'A':
                case 'a':
                    medicinechart();
                    break;

                case 'B':
                case 'b':
                    patientdetails();
                    break;

                case 'C':
                case 'c':
                    calculatebill();
                    break;

                case 'D':
                case 'd':
                    printf("\nThank You For Using M & M Medical System\n");
                    return 0;

                default:
                    printf("\nInvalid Choice\n");
            }
        }
    }

    return 0;
}

//------------------------------------------------------------//

void patientSignup() {

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", s.name);

    printf("Enter Mobile Number : ");
    scanf("%lld", &s.Mno);

    printf("Enter Password : ");
    scanf("%s", s.pass);

    printf("Enter Disease : ");
    scanf(" %[^\n]", patientDisease);

    printf("Enter Age : ");
    scanf("%d", &s.age);

    printf("Enter Gender : ");
    scanf("%s", s.gender);

    printf("\nPatient Registration Successful\n");

    patientLogin();
}

//------------------------------------------------------------//

void patientLogin() {

    char name[100];
    char pass[100];

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", name);

    printf("Enter Password : ");
    scanf("%s", pass);

    if(strcmp(name, s.name) == 0 && strcmp(pass, s.pass) == 0) {

        printf("\nPatient Login Successful\n");
        patientLoginSuccess = 1;
    }
    else {

        printf("\nInvalid Patient Login Details\n");
    }
}

//------------------------------------------------------------//

void doctorSignup() {

    printf("\nEnter Doctor Name : ");
    scanf(" %[^\n]", d.name);

    printf("Create Doctor ID : ");
    scanf("%s", d.id);

    printf("Create Password : ");
    scanf("%s", d.pass);

    printf("\nDoctor Registration Successful\n");
}

//------------------------------------------------------------//

void doctorLogin() {

    char id[50];
    char pass[50];

    printf("\nEnter Doctor ID : ");
    scanf("%s", id);

    printf("Enter Doctor Password : ");
    scanf("%s", pass);

    if(strcmp(id, d.id) == 0 && strcmp(pass, d.pass) == 0) {

        doctorLoginSuccess = 1;

        strcpy(doctorName, d.name);

        printf("\nDoctor Login Successful\n");
    }
    else {

        printf("\nWrong Doctor Login Details\n");
    }
}

//------------------------------------------------------------//

void patientdetails() {

    printf("\n=====================================================\n");
    printf("                  PATIENT DETAILS                    \n");
    printf("=====================================================\n");

    printf("Patient Name       : %s\n", s.name);
    printf("Patient Age        : %d\n", s.age);
    printf("Patient Gender     : %s\n", s.gender);
    printf("Patient Disease    : %s\n", patientDisease);
    printf("Doctor Name        : Dr. %s\n", doctorName);

    printf("=====================================================\n");
}

//------------------------------------------------------------//

void medicinechart() {

    int i, j;
    int found = 0;

    totalBill = 0;

    printf("\nEnter Number Of Days : ");
    scanf("%d", &days);

    printf("\n=====================================================\n");
    printf("                 MEDICINE CHART                      \n");
    printf("=====================================================\n");

    for(i = 0; i < 10; i++) {

        if(strcmp(patientDisease, diseases[i]) == 0) {

            found = 1;

            printf("\nDisease : %s\n", diseases[i]);

            for(j = 0; j < 3; j++) {

                printf("%d. %-20s Rs %d\n",
                       j + 1,
                       medicines[i][j],
                       prices[i][j]);

                totalBill = totalBill + prices[i][j];
            }

            break;
        }
    }

    if(found == 0) {

        printf("\nDisease Not Found\n");
        return;
    }

    totalBill = totalBill * days;

    printf("-----------------------------------------------------\n");
    printf("Total Medicine Charges For %d Days : Rs %d\n",
           days,
           totalBill);

    printf("=====================================================\n");
}

//------------------------------------------------------------//

void calculatebill() {

    printf("\n=====================================================\n");
    printf("                 MEDICAL RECEIPT                     \n");
    printf("=====================================================\n");

    printf("Patient Name     : %s\n", s.name);
    printf("Patient Age      : %d\n", s.age);
    printf("Patient Disease  : %s\n", patientDisease);
    printf("Doctor Name      : Dr. %s\n", doctorName);

    printf("-----------------------------------------------------\n");

    printf("Total Bill       : Rs %d\n", totalBill);

    printf("-----------------------------------------------------\n");

    printf("Payment Status   : SUCCESSFUL\n");

    printf("=====================================================\n");

    printf("\nThank You For Visiting M & M Medical\n");
}
