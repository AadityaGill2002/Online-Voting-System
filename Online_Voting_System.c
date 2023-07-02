#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct voter_information
{
    char aadhar[12];
    char name[50];
    char dob[10];
    struct voter_information *next;
} Node;

Node *head;
Node *sample, *start = NULL;
Node *main_logs(Node *);
Node *voter_entry(Node *);
Node *search_voter(char x[], char y[], char z[], Node *, int *);
void voting();
void not_again();
void admin_entry();
void display();
void stop();
void winner();
void exit_();

int attempts = 3;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

int main()
{
    while (1)
    {

        system("cls");
        printf("\n\n\n");
        printf("\t            * * * * * * WELCOME TO THE ONLINE VOTING PORTAL * * * * * *        \n\n\n\n\n");

        printf("\t           ************************************************************        \n\n\n\n\n");

        printf("\t           * * * * * Please Press 1 for logging into vote main Logs * * * * *    \n\n\n");
        int T;

        scanf("%d", &T);
        if (T == 1)
        {
            start = main_logs(start);
        }
    }

    return 0;
}

Node *main_logs(Node *start)
{

    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1.  VOTER ENTRY     \n");
    Sleep(500);
    printf("        \t\t\t2.  ADMIN PANEL ENTRY    \n");
    Sleep(500);
    printf("        \t\t\t3.  WINNER DECLARATION          \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU ARE ELIGIBLE TO CAST VOTE ELSE NOT ELIGIBLE    \n\n\n");
    Sleep(500);
    printf("    \t * * * * * * PLEASE DO ENTRY ACCORDINGLY FROM ABOVE MENTIONED ENTRIES * * * * * * \n\n\n");
    int T;
    scanf("%d", &T);
    if (T == 1)
    {
        start = voter_entry(start);
    }
    if (T == 2)
    {
        admin_entry();
    }
    if (T == 3)
    {
        winner();
    }
    if (T != 1 || T != 2 || T != 3)
    {
        printf("\n\n PLEASE ENTER A VALID ENTRY FROM ABOVE MENTIONED ENTRIES \n\n");
        main_logs(start);
    }

    return start;
}

Node *voter_entry(Node *start)
{
    int count = 0;
    int *z;
    z = &count;
    Node *temp;
    char name[50], dob[15], aadhar[20];
    system("cls");
    printf("\n\n\n\n");
    printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES IN THE VOTING DIRECTORY THEN YOU ARE ELIGIBLE FOR VOTING ELSE NOT\n\n");
    Sleep(500);
    printf("\t\t\t IF INVALID CREDENTIALS ARE ENTERED %d TIMES, THE PORTAL WILL CLOSE AUTOMATICALLY\n\n\n", attempts);
    Sleep(500);
    printf("\n\n\n");
    Sleep(500);
    printf("\t\t\tEnter your AADHAR ID number : -  ");
    gets(aadhar);
    gets(aadhar);
    printf("\t\t\tEnter Your NAME : -  ");
    gets(name);
    printf("\t\t\tEnter Your BIRTH DATE  in dd-mm-yyyy format : -  ");
    gets(dob);
    temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->aadhar, aadhar);
    strcpy(temp->name, name);
    strcpy(temp->dob, dob);
    temp->next = NULL;
    head = temp;
    while (temp != NULL)
    {
        if ((strcmp(temp->aadhar, "10001") == 0 && strcmp(temp->name, "Sher Gill") == 0 && strcmp(temp->dob, "01-10-2002") == 0) ||
            (strcmp(temp->aadhar, "10002") == 0 && strcmp(temp->name, "Bhuvnesh Purohit") == 0 && strcmp(temp->dob, "18-09-2001") == 0) ||
            (strcmp(temp->aadhar, "10003") == 0 && strcmp(temp->name, "Himanshu Jangid") == 0 && strcmp(temp->dob, "28-01-2002") == 0) ||
            (strcmp(temp->aadhar, "10004") == 0 && strcmp(temp->name, "Gungun Mehta") == 0 && strcmp(temp->dob, "01-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10005") == 0 && strcmp(temp->name, "Aniket Arora") == 0 && strcmp(temp->dob, "28-08-1999") == 0) ||
            (strcmp(temp->aadhar, "10006") == 0 && strcmp(temp->name, "Dipika Singh") == 0 && strcmp(temp->dob, "20-10-2000") == 0) ||
            (strcmp(temp->aadhar, "10007") == 0 && strcmp(temp->name, "Arya Jha") == 0 && strcmp(temp->dob, "02-03-1999") == 0) ||
            (strcmp(temp->aadhar, "10008") == 0 && strcmp(temp->name, "Ravi Raj") == 0 && strcmp(temp->dob, "26-12-1999") == 0) ||
            (strcmp(temp->aadhar, "10009") == 0 && strcmp(temp->name, "Shubham Rai") == 0 && strcmp(temp->dob, "02-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10010") == 0 && strcmp(temp->name, "Priya Pandey") == 0 && strcmp(temp->dob, "03-01-1999") == 0))

        {
            attempts = 3;
            start = search_voter(temp->aadhar, temp->name, temp->dob, start, &count);

            if (count == 0)
            {
                voting();
            }
            else
            {
                not_again();
            }
        }
        else
        {
            attempts--;
            if (attempts == 0)
            {
                stop();
                break;
            }
            printf("\n\n\n\n");
            printf("\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
            Sleep(500);
            printf("\t\t\tPlz Re-Enter\n\n");
            Sleep(500);
            system("pause");
            start = main_logs(start);
        }
        temp = temp->next;
    }
    return start;
}

Node *search_voter(char x[], char y[], char z[], Node *start, int *U)
{
    *U = 0;
    Node *tail, *sample;
    if (start == NULL)
    {/* if it's 1st voter */
        sample = (Node *)malloc(sizeof(Node));
        strcpy(sample->aadhar, x);
        strcpy(sample->name, y);
        strcpy(sample->dob, z);

        start = sample;
        sample->next = NULL;
    }
    else
    {/* if it's not 1st voter than checking for duplicacy */
        tail = start;
        while (tail != NULL)
        {
            if ((strcmp(tail->aadhar, x) == 0 && strcmp(tail->name, y) == 0 && strcmp(tail->dob, z) == 0))
            {
                *U = 1;

                break;
            }
            tail = tail->next;
        }

        if (*U == 0)
        {/* No duplicacy found i.e. voter has not voted earlier */

            sample = (Node *)malloc(sizeof(Node));

            strcpy(sample->aadhar, x);

            strcpy(sample->name, y);

            strcpy(sample->dob, z);
            tail = sample;
            sample->next = NULL;
        }
    }
    return start;
}

void voting()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(500);
    printf("\t\t\t NAME  --------------------------->   SYMBOL\n\n");
    Sleep(500);
    printf("\t\t\t 1.Jayesh P. Modi                   1.Lotus\n");
    Sleep(500);
    printf("\t\t\t 2.Sanskar Gandhi                   2.Hand\n");
    Sleep(500);
    printf("\t\t\t 3.Harilal Kumar                    3.Broomstick\n");
    Sleep(500);
    printf("\t\t\t 4.Kuntal Banerjee                  4.Fish\n");
    Sleep(500);
    printf("\t\t\t 5.Deepika Sharma                   5.Wheel\n\n\n");

    int vote, j;
    printf("\n\t\t\t Enter Your Choice : - ");
    for (j = 1; j <= 1; j++)
    {
        scanf("%d", &vote);

        if (vote == 1)
        {
            vote1++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Jayesh P. Modi\n");
            break;
        }
        if (vote == 2)
        {
            vote2++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sanskar Gandhi\n");
            break;
        }
        if (vote == 3)
        {
            vote3++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Harilal Kumar\n");
            break;
        }
        if (vote == 4)
        {
            vote4++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Kuntal Banerjee\n");
            break;
        }
        if (vote == 5)
        {
            vote5++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Deepika Sharma\n");
            break;
        }
        if (vote != 1 || vote != 2 || vote != 3 || vote != 4 || vote != 5)
        {
            printf("\n\t\t* * * * * * * * * * * * * INVALID CHOICE ENTERED * * * * * * * * * * * * * * \t\t\n");
            printf("\n\t\t\t\tENTER AGAIN\t\t\t\t\n");
        }
    }
    printf("\n\n* * * * * * * * * * * * * THANK YOU * * * * * * * * * * * * * \n\n");
    printf("press any key");
    getch();
}

void not_again()
{
    int A;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        * * * * * YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY * * * * *       \n\n\n");
    Sleep(500);
    printf("\t\t\t        * * * * * YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE * * * * *     \n\n\n");
    Sleep(500);
    printf("\t\t\t Press 1 for Entering Main  Logs\n\n");
    Sleep(500);

    scanf("%d", &A);
    if (A == 1)
    {
        main_logs(start);
    }
}

void stop()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t (:- SORRY YOU ENTERED WRONG CREDENTIALS FOR 3 TIMES IN A ROW -:) \n\n\n");
    Sleep(500);
    printf("\t\t\t\t\t TRY AGAIN AFTER A WHILE \n\n\n");
    Sleep(500);
    printf("\t\t\t\t\t * * * * * Thank You * * * * * \n\n\n");
    Sleep(10000);
    printf("press any key");
    getch();
}

void admin_entry()
{
    int B;
    printf("\n\n\n\n");
    printf("\t\t\t\t\tEnter Your Admin Password : -   ");
    scanf("%d", &B);
    if (B == 501)
    {
        display();
    }
    else
    {
        printf("\n\nINVALID ADMIN PASSWORD\n");
    }
}

void display()
{
    int P;
    system("cls");

    printf("\n\n\n\n");
    printf("\t\t\tPresent Vote Counts of Election is :\n\n");
    Sleep(500);
    printf("\t\t\t  Jayesh P. Modi  got       %d Votes\n", vote1);
    Sleep(500);
    printf("\t\t\t  Sanskar Gandhi  got       %d Votes\n", vote2);
    Sleep(500);
    printf("\t\t\t  Harilal Kumar   got       %d Votes\n", vote3);
    Sleep(500);
    printf("\t\t\t  Kuntal Banerjee got       %d Votes\n", vote4);
    Sleep(500);
    printf("\t\t\t  Deepika Sharma  got       %d Votes\n\n\n\n", vote5);
    Sleep(500);

    printf("\t\t\t\t\tPress Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE PASSWORD TO CLOSE VOTING PORTAL\n ");
    scanf("%d", &P);
    if (P == 405)
        exit_();
    else
        main_logs(start);
}

void winner()
{
    system("cls");
    printf("\n\n\n\n");
    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1)
        printf("\t\t\tThe present Winner is 'Jayesh P. Modi' and he has got %d votes\n\n\n\n", vote1);

    if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2)
        printf("\t\t\tThe present Winner is 'Sanskar Gandhi' and he has got %d votes\n\n\n\n", vote2);

    if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3)
        printf("\t\t\tThe present Winner is 'Harilal Kumar' and he has got %d votes\n\n\n\n", vote3);

    if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4)
        printf("\t\t\tThe present Winner is 'Kuntal Banerjee' and he has got %d votes\n\n\n\n", vote4);

    if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5)
        printf("\t\t\tThe present Winner is 'Deepika Sharma' and s he has got %d votes\n\n\n\n", vote5);

    printf("\t\t\t\tEnter Any Key for Main Log\n\n");
    getch();
    main_logs(start);
}

void exit_()
{
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n");
    Sleep(300);
    printf("\t\t\t * * * * * Thank You For Using This ONLINE PLATFORM For VOTING* * * * *   \n\n\n");
    Sleep(300);
    exit(0);
}
