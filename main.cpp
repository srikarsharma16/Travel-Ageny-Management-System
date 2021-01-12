#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

enum state {menu, loggedin};
enum state currentstate=menu;

typedef struct user
{
    char username[100];
    char password[100];
    char place[100];
    float price;
    int numtick;
    int day;
    int month;
    int year;
    int valid = 1;
    struct user *next;
}user;

void ShowBrochure();
user* Initializelist(user*);
user* AddUser(user*);
void LoginUser(user*);
void BookTicket(user*);
void PrintTicket(user*);
void CancelTicket(user*);
void ChangePassword(user*);
void LogoutUser();
void CheckTicket(user*);
void DisplayAll(user*);
void WriteToFile(user*);
void Help();

int datevalidate(int dd, int mm, int yy);
void ExitProgram();
void show(int pricelist[])
{
    for(int i = 0; i < 11; ++i)
        cout << pricelist[i] << " ";
}
char currentuser[100];

int main()
{
    cout<<"\n\n\n\n\n";   //welcome screen
  cout<<"              **      :::::::  !!!!!!!!           \n";
  cout<<"           _____  **      ::       !!    !!         _____  \n";
  cout<<"                **      ::       !!    !!                \n";
  cout<<"              ******  :::::::  !!!!!!!!            \n";
  cout<<"\n\n\n\n\n";
  cout<<"            SV TRAVELS AND TOURISM              \n";
  cout<<"	      ~	__  ~ __  ~ __                  \n";
  cout<<"	       |==|  |==|  |==|                 \n";
  cout<<"	     __|__|__|__|__|__|_                \n";
  cout<<"	  __|___________________|___            \n";
  cout<<"       __|__[]__[]__[]__[]__[]__[]__|___         \n";
  cout<<"      |............................o.../ \n";
  cout<<"      \\.............................../ \n";
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  cout<<" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
  cout<<"  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n";
  cout<<"    ~    ~     ~    ~    ~    ~    ~    ~    ~  \n";
  cout<<"     ~    ~      ~    ~     ~    ~    ~      ~\n";
    user *h=NULL;
    int ch1,ch2;
    h=Initializelist(h);
    while(1)
    {
        if(currentstate==menu)
        {
            printf("\n\t\t\t\tAdd User - 1 \n\t\t\t\tLogin User - 2\n\t\t\t\tBrochure - 3\n\t\t\t\tExit - 4\n\n\t\t\t\tPlease Enter your choice:");
            scanf("%d",&ch1);
            switch(ch1)
            {
            case 1:
                h=AddUser(h);
                break;
            case 2:
                LoginUser(h);
                break;
            case 3:
                ShowBrochure();
                break;
            case 4:
                ExitProgram();
                exit(0);
                break;
            default:
                printf("Not a valid input at this stage\n");
            }
        }
        else if(currentstate==loggedin)
            {
            system("CLS");
            printf("\n++++++++++++++++++++++++++++++\n");
            printf("\n+ TICKET BOOKING SYSTEM +");
            printf("\n++++++++++++++++++++++++++++++\n");
            printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCheck Ticket - 2\n\t\t\t\tCancel Ticket - 3\n\t\t\t\tChange Password - 4\n\t\t\t\tLogout user - 5\n\t\t\t\tBrochure - 6\n\t\t\t\tExit - 7\n\t\t\t\tenter the choice:");
            scanf("%d",&ch2);
            switch(ch2)
            {
            case 1:
                BookTicket(h);
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                CheckTicket(h);
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                CancelTicket(h);
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                ChangePassword(h);
                system("PAUSE");
                system("CLS");
                break;
            case 5:
                LogoutUser();
                system("PAUSE");
                system("CLS");
                break;
            case 6:
                ShowBrochure();
                system("PAUSE");
                system("CLS");
                break;
            case 7:
                ExitProgram();
                exit(0);
                break;
            default:
                printf("not a valid input\n");
            }
        }
        else
            break;
    }
    return 0;

}

user* Initializelist(user *h)
{
    user* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    float ff;
    fp=fopen("useRM.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
    while(fscanf(fp,"%s %s %s %f %d %d %d %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick,&temp.day,&temp.month,&temp.year)!=EOF)
    {
        ptr=(user*)malloc(sizeof(user));
        strcpy(ptr->username,temp.username);
        strcpy(ptr->password,temp.password);
        strcpy(ptr->place,temp.place);
        ptr->price=temp.price;
        ptr->numtick=temp.numtick;
        ptr->day=temp.day;
        ptr->month=temp.month;
        ptr->year=temp.year;
        ptr->next=NULL;

        if(h==NULL)
            h=t=ptr;
        else
        {
            h->next=ptr;
            h=ptr;
        }
    }
        fclose(fp);
        return t;
}
void WriteToFile(user *h)
{
    FILE *fp;
    fp=fopen("useRM.txt","w");
    while(h!=NULL)
    {
        fprintf(fp,"%s %s %s %f %d %d %d %d \n",h->username,h->password,h->place,h->price,h->numtick,h->day,h->month,h->year);
        h=h->next;
    }
    fclose(fp);
}

void ShowBrochure()
{
    system("CLS");
    printf("\nPRICE LIST\n===============\n1.KER : Kerala Tour Package (6D/5N) Rs - 17999\n 2.AND : Andaman Tour Package (6D/5N) Rs - 17999\n 3.KAS : Kashmir Tour Package (7D/6N) Rs - 31999 \n 4.HIM : Himachal Tour Package (7D/6N) Rs - 25999\n 5.COR : Explore Coorg Packages (3D/2N) Rs - 16200\n 6.MAN : Manali Trip Package (6D/5N) Rs - 25000\n 7.SIK : Visit Gangtok and Darjeeling Package (5D/4N) Rs - 19233\n 8.SHIL : Excursion to Shillong (4D/3N) Rs - 20500\n 9.GOA : Weekend in Goa (3D/3N) Rs - 17999\n 10.LAD : Ladakh Package (5D/4N) Rs - 20400\n 11.RAJ : Colourful Rajasthan Package (9D/8N) Rs - 68000\n ");
}
void CheckTicket(user *h)
{
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(!strcmp(h->place,"\0")|| h->price==0.0 || h->numtick==0 || h->day==0 || h->month==0 || h->year==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float total=0.0;
    total=(h->price)*(h->numtick);
    printf("You have booked %d tickets for a sum total of Rs %f for tour code %s on following date %d - %d - %d \n",h->numtick,total,h->place,h->day,h->month,h->year);
}

user* AddUser(user* h)
{
    user *t;
    t=h;
    user *nw;
    nw=(user*)malloc(sizeof(user));
    fflush(stdin);
    printf("Enter username or email\n");
    scanf("%s",nw->username);
    while(h!=NULL)
    {
        if(!strcmp(h->username,nw->username))
        {
            printf("The email already exists\n");
            return t;
        }
        h=h->next;
    }
    h=t;
    fflush(stdin);
    printf("Enter password\n");
    scanf("%s",&nw->password);
    nw->next=NULL;
    strcpy(nw->place,"N/A");
    nw->price=0.0;
    nw->numtick=0;
    nw->day=0;
    nw->month=0;
    nw->year=0;

    if(h==NULL)
    {
        h=t=nw;
    }
    else
    {
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=nw;
    }
    WriteToFile(t);
    return t;
}

void LoginUser(user* h)
{
    char username[100];
    char password[100];
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter email/username\n\t\t");
    scanf("%s",username);
    fflush(stdin);
    printf("\n\t\tEnter Password:\n\t\t");
    scanf("%s",password);
    while(h!=NULL)
    {
        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))
        {
            currentstate=loggedin;
            strcpy(currentuser,username);
            printf("\n\t\tLogin Successful!!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))
        {
            printf("Password Mismatch\n");
            return;
        }
        h=h->next;
    }
    printf("Sorry, no such user record was found\n");
}

void BookTicket(user *h)
{
    user *t=h;
    char place[100];
    int day;
    int month;
    int year;
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(h->price!=0.0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    ShowBrochure();
    int pricelist[11]={17999,27999,31999,25999,16200,25000,19233,20500,17999,20400,68000};
    fflush(stdin);
    printf("\nEnter place code(eg: INDO,MAS)\n");
    scanf("%s",place);
    char choice;
    fflush(stdin);
    printf("\n Wold you like to confirm Booking?\n[1] -Yes\n[2] -No\n");
    scanf("%c",&choice);
    float price;
    if(choice!='1')
        return;
    if(strcmp(place,"KER")==0)
        price=pricelist[0];
    else if(strcmp(place,"AND")==0)
        price=pricelist[1];
    else if(strcmp(place,"KAS")==0)
        price=pricelist[2];
    else if(strcmp(place,"HIM")==0)
        price=pricelist[3];
    else if(strcmp(place,"COR")==0)
        price=pricelist[4];
    else if(strcmp(place,"MAN")==0)
        price=pricelist[5];
    else if(strcmp(place,"SIK")==0)
        price=pricelist[6];
    else if(strcmp(place,"SHIL")==0)
        price=pricelist[7];
    else if(strcmp(place,"GOA")==0)
        price=pricelist[8];
    else if(strcmp(place,"LAD")==0)
        price=pricelist[9];
    else if(strcmp(place,"RAJ")==0)
        price=pricelist[10];
    else
    {
        printf("That tour code doesn't exist\n");
        return;
    }
    printf("Enter the number of tickets you want to book?\n");
    scanf("%d",&h->numtick);
    if(h->numtick==0)
        return;
    strcpy(h->place,place);
    h->price=price;
    printf("\n\n\t**************Date of Departure*************");
    printf("\n\n *NOTE:Format for entering:DAY(press enter) MONTH(press enter) YEAR *");
    printf("\n\n\t Enter your preferred date of departure:");
    cout<<"Enter Date "<<" : ";
      scanf("%d",&h->day);
      scanf("%d",&h->month);
      scanf("%d",&h->year);
    h->day,day;
    h->month,month;
    h->year,year;
    WriteToFile(t);
    printf("Booking Done!!\n");
    system("PAUSE");
}

void CancelTicket(user *h)
{
    user *t=h;
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }

    int flag=-1;

    if(h==NULL)
        printf("No such user\n");

    if(strcmp(h->place,"KER")==0)
        flag++;
    else if(strcmp(h->place,"AND")==0)
        flag++;
    else if(strcmp(h->place,"KAS")==0)
        flag++;
    else if(strcmp(h->place,"HIM")==0)
        flag++;
    else if(strcmp(h->place,"COR")==0)
        flag++;
    else if(strcmp(h->place,"MAN")==0)
        flag++;
    else if(strcmp(h->place,"SIK")==0)
        flag++;
    else if(strcmp(h->place,"SHIL")==0)
        flag++;
    else if(strcmp(h->place,"GOA")==0)
        flag++;
    else if(strcmp(h->place,"LAD")==0)
        flag++;
    else if(strcmp(h->place,"RAJ")==0)
        flag++;
    else
    {
        printf("You haven't booked a package yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has successfully cancelled  A refund of Rs %f for Tour Code %s for %d ticket on %d-%d-%d will be made to your original source",h->price,h->place,h->numtick,h->day,h->month,h->year);
        strcpy(h->place,"N/A");
        h->price=0.0;
        h->numtick=0;
        h->day=0;
        h->month=0;
        h->year=0;
        WriteToFile(t);
    }
}
void ChangePassword(user *h)
{
    user *t=h;
    char passcurr[100];
    fflush(stdin);
    printf("Enter your current password to continue:\n");
    scanf("%s",passcurr);
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(!strcmp(passcurr,h->password))
    {
        printf("Enter new password:\n");
        scanf("%s",h->password);
    }
    WriteToFile(t);
}

void LogoutUser()
{
    if((currentstate=menu) || (strcmp(currentuser,"\0")==0))
    {
        printf("you must be logged in to logout\n");
        return;
    }
    strcpy(currentuser,"\0");
    currentstate = menu;
    printf("You have successfully logged out\n");
}

void ExitProgram()
{
    printf("Exiting...\n\n");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}
