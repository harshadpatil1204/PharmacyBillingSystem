#include<stdio.h>
#include<string.h>

//------------------------------------------------------------//

void login();
void signup();
void medicinechart();
void patientdetails();
void calculatebill();

//------------------------------------------------------------//

struct signup{

    char name[200];
    char pass[100];
    int age;
    char gender[20];
    long long int Mno;
};

struct signup s;

//------------------------------------------------------------//

struct medicine{

    char disease[500];
};

struct medicine m;

//------------------------------------------------------------//

int loginsuccess = 0;

int sum = 0;
int d = 0;

// Fixed Doctor Name
char doctorName[] = "Amit Sharma";

//------------------------------------------------------------//

int main(){

    int num;

    printf("=====================================================\n");
    printf("         WELCOME TO M & M MEDICAL SYSTEM             \n");
    printf("=====================================================\n");

    printf("\n================ AVAILABLE DISEASES =================\n");

printf("1. Fever\n");
printf("2. Cold\n");
printf("3. Diabetes\n");
printf("4. BP\n");
printf("5. Headache\n");
printf("6. Asthma\n");
printf("7. Typhoid\n");
printf("8. Malaria\n");
printf("9. Dengue\n");
printf("10. Allergy\n");

printf("=====================================================\n");

printf("\n1] Sign Up");
printf("\n2] Login");
printf("\n3] Exit\n");
    printf("\nEnter Your Choice : ");
    scanf("%d",&num);

    switch(num){

        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            printf("\nThanks For Connecting Us\n");
            return 0;

        default:
            printf("\nInvalid Choice\n");
            return 0;
    }

    //------------------------------------------------------------//

    if(loginsuccess == 1){

        char ch;

        while(1){

            printf("\n\n");
            printf("=====================================================\n");
            printf("                    MAIN MENU                        \n");
            printf("=====================================================\n");

            printf("\nA] Medicine Chart");
            printf("\nB] Patient Details");
            printf("\nC] Calculate Bill");
            printf("\nD] Exit");

            printf("\n\nEnter Your Choice : ");
            scanf(" %c",&ch);

            switch(ch){

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
                    printf("\nThank You For Visiting M & M Medical\n");
                    return 0;

                default:
                    printf("\nInvalid Choice\n");
            }
        }
    }
    else{

        printf("\nWrong Details !!!\n");
    }

    return 0;
}

//------------------------------------------------------------//

void signup(){

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", s.name);

    printf("Enter Mobile Number : ");
    scanf("%lld", &s.Mno);

    printf("Enter Password : ");
    scanf("%s", s.pass);

    printf("\nChoose Disease:\n");

    printf("1. Fever\n");
    printf("2. Cold\n");
    printf("3. Diabetes\n");
    printf("4. BP\n");
    printf("5. Headache\n");
    printf("6. Asthma\n");
    printf("7. Typhoid\n");
    printf("8. Malaria\n");
    printf("9. Dengue\n");
    printf("10. Allergy\n");

    int choice;

    printf("Enter Choice : ");
    scanf("%d",&choice);

    switch(choice){

        case 1:
            strcpy(m.disease,"Fever");
            break;

        case 2:
            strcpy(m.disease,"Cold");
            break;

        case 3:
            strcpy(m.disease,"Diabetes");
            break;

        case 4:
            strcpy(m.disease,"BP");
            break;

        case 5:
            strcpy(m.disease,"Headache");
            break;

        case 6:
            strcpy(m.disease,"Asthma");
            break;

        case 7:
            strcpy(m.disease,"Typhoid");
            break;

        case 8:
            strcpy(m.disease,"Malaria");
            break;

        case 9:
            strcpy(m.disease,"Dengue");
            break;

        case 10:
            strcpy(m.disease,"Allergy");
            break;

        default:
            strcpy(m.disease,"General");
    }

    printf("Enter Age : ");
    scanf("%d", &s.age);

    printf("Enter Gender : ");
    scanf("%s", s.gender);

    //------------------------------------------------------------//

    printf("\n\n");
    printf("=====================================================\n");
    printf("              REGISTRATION SUCCESSFUL                \n");
    printf("=====================================================\n");

    printf("Patient Name   : %s\n", s.name);
    printf("Mobile Number  : %lld\n", s.Mno);
    printf("Disease        : %s\n", m.disease);
    printf("Age            : %d\n", s.age);
    printf("Gender         : %s\n", s.gender);

    printf("=====================================================\n");

    printf("\nPlease Login To Continue\n");

    login();
}

//------------------------------------------------------------//

void login(){

    char name[100], pass[100];

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", name);

    printf("Enter Password : ");
    scanf("%s", pass);

    if(strcmp(name, s.name) == 0 && strcmp(pass, s.pass) == 0){

        printf("\n-----------------------------------\n");
        printf("        LOGIN SUCCESSFUL           \n");
        printf("-----------------------------------\n");

        loginsuccess = 1;
    }
    else{

        printf("\nInvalid Username or Password\n");
        loginsuccess = 0;
    }
}

//------------------------------------------------------------//

void patientdetails(){

    printf("\n\n");
    printf("=====================================================\n");
    printf("                  PATIENT DETAILS                    \n");
    printf("=====================================================\n");

    printf("Patient Name       : %s\n", s.name);
    printf("Patient Age        : %d\n", s.age);
    printf("Patient Gender     : %s\n", s.gender);
    printf("Patient Disease    : %s\n", m.disease);
    printf("Patient Room No.   : 18\n");
    printf("Doctor Name        : Dr. %s\n", doctorName);
    printf("Doctor Mobile No.  : 9876543210\n");

    printf("=====================================================\n");
}

//------------------------------------------------------------//

void medicinechart(){

    sum = 0;

    printf("\nDoctor Name : Dr. %s\n", doctorName);

    printf("Enter Number Of Days For Medicine Course : ");
    scanf("%d", &d);

    printf("\n\n");
    printf("=====================================================\n");
    printf("                MEDICINE CHART                       \n");
    printf("=====================================================\n");

    //------------------------------------------------------------//

    if(strcmp(m.disease,"Fever") == 0){

        printf("1. Paracetamol       Rs 100\n");
        printf("2. Crocin            Rs 120\n");
        printf("3. Dolo 650          Rs 150\n");

        sum = 100 + 120 + 150;
    }

    else if(strcmp(m.disease,"Cold") == 0){

        printf("1. Cetirizine        Rs 90\n");
        printf("2. Sinarest          Rs 110\n");
        printf("3. Cough Syrup       Rs 130\n");

        sum = 90 + 110 + 130;
    }

    else if(strcmp(m.disease,"Diabetes") == 0){

        printf("1. Insulin           Rs 500\n");
        printf("2. Metformin         Rs 300\n");
        printf("3. Glimepiride       Rs 250\n");

        sum = 500 + 300 + 250;
    }

    else if(strcmp(m.disease,"BP") == 0){

        printf("1. Amlodipine        Rs 200\n");
        printf("2. Atenolol          Rs 180\n");
        printf("3. Telmisartan       Rs 220\n");

        sum = 200 + 180 + 220;
    }

    else if(strcmp(m.disease,"Headache") == 0){

        printf("1. Aspirin           Rs 100\n");
        printf("2. Ibuprofen         Rs 150\n");
        printf("3. Combiflam         Rs 170\n");

        sum = 100 + 150 + 170;
    }

    else if(strcmp(m.disease,"Asthma") == 0){

        printf("1. Inhaler           Rs 400\n");
        printf("2. Salbutamol        Rs 250\n");
        printf("3. Montelukast       Rs 300\n");

        sum = 400 + 250 + 300;
    }

    else if(strcmp(m.disease,"Typhoid") == 0){

        printf("1. Azithromycin      Rs 350\n");
        printf("2. Cefixime          Rs 300\n");
        printf("3. ORS               Rs 80\n");

        sum = 350 + 300 + 80;
    }

    else if(strcmp(m.disease,"Malaria") == 0){

        printf("1. Chloroquine       Rs 280\n");
        printf("2. Primaquine        Rs 240\n");
        printf("3. Paracetamol       Rs 100\n");

        sum = 280 + 240 + 100;
    }

    else if(strcmp(m.disease,"Dengue") == 0){

        printf("1. Platelet Syrup    Rs 450\n");
        printf("2. Dolo 650          Rs 150\n");
        printf("3. ORS               Rs 80\n");

        sum = 450 + 150 + 80;
    }

    else if(strcmp(m.disease,"Allergy") == 0){

        printf("1. Cetirizine        Rs 90\n");
        printf("2. Allegra           Rs 140\n");
        printf("3. Antiallergic Syrup Rs 160\n");

        sum = 90 + 140 + 160;
    }

    //------------------------------------------------------------//

    printf("-----------------------------------------------------\n");
    printf("Medicine Charges For %d Days : Rs %d\n", d, sum * d);

    printf("=====================================================\n");
}

//------------------------------------------------------------//

void calculatebill(){

    int total;

    if(d == 0 || sum == 0){

        printf("\nPlease Open Medicine Chart First!\n");
        printf("Go To Main Menu -> Medicine Chart\n");

        return;
    }

    total = sum * d;

    printf("\n\n");

    printf("====================================================================\n");
    printf("                 M & M OFFICIAL MEDICAL RECEIPT                    \n");
    printf("====================================================================\n");

    printf("Medical Store       : M & M Medical Store\n");
    printf("Bill No.            : BILL-01\n");
    printf("Doctor Name         : Dr. %s\n", doctorName);
    printf("Patient Name        : %s\n", s.name);
    printf("Patient Age         : %d\n", s.age);
    printf("Patient Disease     : %s\n", m.disease);

    printf("--------------------------------------------------------------------\n");

    printf("Medicine Charges    : %d Rs\n", sum * d);

    printf("--------------------------------------------------------------------\n");

    printf("TOTAL BILL          : %d Rs\n", total);

    printf("====================================================================\n");
    printf("              PAYMENT STATUS : SUCCESSFUL                          \n");
    printf("====================================================================\n");

    printf("\nThank You For Choosing M & M Medical Store\n");
}
