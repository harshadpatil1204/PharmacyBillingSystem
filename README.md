
#include<stdio.h>
#include<string.h>

//------------------------------------------------------------//

void login();
void signup();
void medicinechart();
void patientdetails();
void calculatebill();
void changedisease();

//------------------------------------------------------------//

void fever();
void Cold();
void Diabetes();
void BP();
void Headache();
void Asthma();
void Typhoid();
void Malaria();
void Dengue();
void Allergy();

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

char doctorName[] = "Harshad Patil";

//------------------------------------------------------------//

int main(){

    int num;

    printf("=====================================================\n");
    printf("         WELCOME TO M & M MEDICAL SYSTEM             \n");
    printf("=====================================================\n");

    while(1){

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
                printf("\nD] Change Disease");
                printf("\nE] Logout");
                printf("\nF] Change User");
                printf("\nG] Exit");

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
                        changedisease();
                        break;

                    case 'E':
                    case 'e':

                        loginsuccess = 0;

                        printf("\nLogged Out Successfully\n");

                        login();
                        break;

                    case 'F':
                    case 'f':

                        printf("\nRegister New User\n");

                        signup();
                        break;

                    case 'G':
                    case 'g':

                        printf("\nThank You For Visiting M & M Medical\n");
                        return 0;

                    default:
                        printf("\nInvalid Choice\n");
                }
            }
        }
    }

    return 0;
}

//------------------------------------------------------------//

void signup(){

    printf("\nEnter Patient Name : ");
    scanf(" %[^\n]", s.name);

    while(1){

        printf("Enter Mobile Number : ");
        scanf("%lld", &s.Mno);

        if(s.Mno >= 1000000000 && s.Mno <= 9999999999){

            break;
        }

        printf("\nWrong Mobile Number! Please Enter Correct 10 Digit Mobile Number.\n");
    }

    printf("Enter Password : ");
    scanf("%s", s.pass);

    changedisease();

    printf("Enter Age : ");
    scanf("%d", &s.age);

    int genderChoice;

    printf("\nSelect Gender\n");

    printf("1. Male\n");
    printf("2. Female\n");
    printf("3. Others\n");

    printf("Enter Choice : ");
    scanf("%d", &genderChoice);

    switch(genderChoice){

        case 1:
            strcpy(s.gender, "Male");
            break;

        case 2:
            strcpy(s.gender, "Female");
            break;

        case 3:
            strcpy(s.gender, "Others");
            break;

        default:
            strcpy(s.gender, "Others");
    }

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

    char name[200], pass[100];

    while(1){

        printf("\nEnter Patient Name : ");
        scanf(" %[^\n]", name);

        printf("Enter Password : ");
        scanf("%s", pass);

        if(strcmp(name, s.name) == 0 && strcmp(pass, s.pass) == 0){

            printf("\n-----------------------------------\n");
            printf("        LOGIN SUCCESSFUL           \n");
            printf("-----------------------------------\n");

            loginsuccess = 1;
            break;
        }
        else{

            printf("\nInvalid Username or Password\n");
            printf("Please Enter Correct Login Details\n");
        }
    }
}

//------------------------------------------------------------//

void patientdetails(){

    printf("\n\n");
    printf("=====================================================\n");
    printf("                  PATIENT DETAILS                    \n");
    printf("=====================================================\n");

    printf("Patient Name       : %s\n", s.name);
    printf("Patient Mobile No. : %lld\n", s.Mno);
    printf("Patient Age        : %d\n", s.age);
    printf("Patient Gender     : %s\n", s.gender);
    printf("Patient Disease    : %s\n", m.disease);
    printf("Patient Room No.   : 18\n");
    printf("Doctor Name        : Dr. %s\n", doctorName);
    printf("Doctor Mobile No.  : 9876543210\n");

    printf("=====================================================\n");
}

//------------------------------------------------------------//

void changedisease(){

    int choice;

    printf("\n");
    printf("========================================\n");
    printf("           SELECT DISEASE               \n");
    printf("========================================\n");

    printf("| 1. Fever                       |\n");
    printf("| 2. Cold                        |\n");
    printf("| 3. Diabetes                    |\n");
    printf("| 4. BP                          |\n");
    printf("| 5. Headache                    |\n");
    printf("| 6. Asthma                      |\n");
    printf("| 7. Typhoid                     |\n");
    printf("| 8. Malaria                     |\n");
    printf("| 9. Dengue                      |\n");
    printf("|10. Allergy                     |\n");

    printf("\nEnter Choice : ");
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
            printf("\nInvalid Choice\n");
            return;
    }

    printf("\nDisease Selected : %s\n", m.disease);

    sum = 0;
    d = 0;
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

    if(strcmp(m.disease,"Fever") == 0){

        fever();
    }

    else if(strcmp(m.disease,"Cold") == 0){

        Cold();
    }

    else if(strcmp(m.disease,"Diabetes") == 0){

        Diabetes();
    }

    else if(strcmp(m.disease,"BP") == 0){

        BP();
    }

    else if(strcmp(m.disease,"Headache") == 0){

        Headache();
    }

    else if(strcmp(m.disease,"Asthma") == 0){

        Asthma();
    }

    else if(strcmp(m.disease,"Typhoid") == 0){

        Typhoid();
    }

    else if(strcmp(m.disease,"Malaria") == 0){

        Malaria();
    }

    else if(strcmp(m.disease,"Dengue") == 0){

        Dengue();
    }

    else if(strcmp(m.disease,"Allergy") == 0){

        Allergy();
    }

    printf("-----------------------------------------------------\n");

    printf("Medicine Charges For %d Days : Rs %d\n",
           d, sum * d);

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

    printf("Course Duration     : %d Days\n", d);

    printf("--------------------------------------------------------------------\n");

    printf("Medicine Charges    : %d Rs\n", total);

    printf("--------------------------------------------------------------------\n");

    printf("TOTAL BILL          : %d Rs\n", total);

    printf("====================================================================\n");
    printf("              PAYMENT STATUS : SUCCESSFUL                          \n");
    printf("====================================================================\n");

    printf("\nThank You For Choosing M & M Medical Store\n");
}

//------------------------------------------------------------//

void fever(){

    int dose1, dose2, dose3;

    printf("| 1. Paracetamol  Rs 10 |\n");
    printf("| 2. Crocin       Rs 12 |\n");
    printf("| 3. Dolo 650     Rs 15 |\n");

    printf("\nEnter Doses For Paracetamol : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Crocin : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Dolo 650 : ");
    scanf("%d",&dose3);

    sum = (dose1 * 10) + (dose2 * 12) + (dose3 * 15);
}

//------------------------------------------------------------//

void Cold(){

    int dose1, dose2, dose3;

    printf("| 1. Cetirizine   Rs 8  |\n");
    printf("| 2. Sinarest     Rs 11 |\n");
    printf("| 3. Alex Syrup   Rs 14 |\n");

    printf("\nEnter Doses For Cetirizine : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Sinarest : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Alex Syrup : ");
    scanf("%d",&dose3);

    sum = (dose1 * 8) + (dose2 * 11) + (dose3 * 14);
}

//------------------------------------------------------------//

void Diabetes(){

    int dose1, dose2, dose3;

    printf("| 1. Metformin    Rs 20  |\n");
    printf("| 2. Glimepiride  Rs 18  |\n");
    printf("| 3. Insulin      Rs 500 |\n");

    printf("\nEnter Doses For Metformin : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Glimepiride : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Insulin : ");
    scanf("%d",&dose3);

    sum = (dose1 * 20) + (dose2 * 18) + (dose3 * 500);
}

//------------------------------------------------------------//

void BP(){

    int dose1, dose2, dose3;

    printf("| 1. Amlodipine   Rs 15 |\n");
    printf("| 2. Atenolol     Rs 17 |\n");
    printf("| 3. Losartan     Rs 22 |\n");

    printf("\nEnter Doses For Amlodipine : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Atenolol : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Losartan : ");
    scanf("%d",&dose3);

    sum = (dose1 * 15) + (dose2 * 17) + (dose3 * 22);
}

//------------------------------------------------------------//

void Headache(){

    int dose1, dose2, dose3;

    printf("| 1. Saridon      Rs 9  |\n");
    printf("| 2. Combiflam    Rs 11 |\n");
    printf("| 3. Dolo 650     Rs 15 |\n");

    printf("\nEnter Doses For Saridon : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Combiflam : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Dolo 650 : ");
    scanf("%d",&dose3);

    sum = (dose1 * 9) + (dose2 * 11) + (dose3 * 15);
}

//------------------------------------------------------------//

void Asthma(){

    int dose1, dose2, dose3;

    printf("| 1. Inhaler      Rs 35 |\n");
    printf("| 2. Montair      Rs 18 |\n");
    printf("| 3. Deriphyllin  Rs 20 |\n");

    printf("\nEnter Doses For Inhaler : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Montair : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Deriphyllin : ");
    scanf("%d",&dose3);

    sum = (dose1 * 35) + (dose2 * 18) + (dose3 * 20);
}

//------------------------------------------------------------//

void Typhoid(){

    int dose1, dose2, dose3;

    printf("| 1. Azithromycin Rs 25 |\n");
    printf("| 2. Cefixime     Rs 30 |\n");
    printf("| 3. Paracetamol  Rs 10 |\n");

    printf("\nEnter Doses For Azithromycin : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Cefixime : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Paracetamol : ");
    scanf("%d",&dose3);

    sum = (dose1 * 25) + (dose2 * 30) + (dose3 * 10);
}

//------------------------------------------------------------//

void Malaria(){

    int dose1, dose2, dose3;

    printf("| 1. Chloroquine  Rs 22 |\n");
    printf("| 2. Primaquine   Rs 18 |\n");
    printf("| 3. Quinine      Rs 26 |\n");

    printf("\nEnter Doses For Chloroquine : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Primaquine : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Quinine : ");
    scanf("%d",&dose3);

    sum = (dose1 * 22) + (dose2 * 18) + (dose3 * 26);
}

//------------------------------------------------------------//

void Dengue(){

    int dose1, dose2, dose3;

    printf("| 1. Dolo 650     Rs 15 |\n");
    printf("| 2. ORS          Rs 5  |\n");
    printf("| 3. Papaya Syrup Rs 30 |\n");

    printf("\nEnter Doses For Dolo 650 : ");
    scanf("%d",&dose1);

    printf("Enter Doses For ORS : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Papaya Syrup : ");
    scanf("%d",&dose3);

    sum = (dose1 * 15) + (dose2 * 5) + (dose3 * 30);
}

//------------------------------------------------------------//

void Allergy(){

    int dose1, dose2, dose3;

    printf("| 1. Cetirizine   Rs 9  |\n");
    printf("| 2. Allegra      Rs 15 |\n");
    printf("| 3. Avil         Rs 12 |\n");

    printf("\nEnter Doses For Cetirizine : ");
    scanf("%d",&dose1);

    printf("Enter Doses For Allegra : ");
    scanf("%d",&dose2);

    printf("Enter Doses For Avil : ");
    scanf("%d",&dose3);

    sum = (dose1 * 9) + (dose2 * 15) + (dose3 * 12);
}
