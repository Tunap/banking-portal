#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <process.h>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>

using namespace std;

int main();
class bank
{
    string passw[32];
    long pAcc;
    char pass[32];
    char pName[30];
    char pAddr[200];
    unsigned long long pMobile;
    int balance;
    char ltran[100][100];
    public:
    void adminlogin();
    void admin();
    void Search();
    void NewAccount();
    void Login();
    void Transact();
    void Transfer();
    void Remove();
    void Show();
    void edit(long);
    void task(long);
    void pre(long);
        };

void bank::adminlogin()
{
    START:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=ADMIN LOGIN=-=-=-=-=-=-\n";
    cout<<"\n\nUsername -> ";
    string user;
    cin >>user;
    cout<<"\nPassword -> ";
    int i;
    string passw[32];
    char b;
    for(i=0;;)
    {
        char b = getch();
        if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
        {
            passw[i]=b;
            cout<<"*";
            ++i;
        }
        if(b=='\b'&&i>=1)
        {
            --i;
            cout<<"\b \b";
        }
        if(b=='\r')
        {
            passw[i]='\0';
            break;
        }
    }
    if(i<=5)
    {
        cout<<"\n\nMinimum 6 characters required.";
        getch();
        goto START;
    }

    if(user=="exaflops")
                   {
                    cout<<"\n\nLogin Successful.";
                    getch();
         admin();
                   }
                else

         cout<<"\n\nWrong Username or Password. Try again.";
         getch();
         goto START;

}


void bank::admin()
{
    START:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=ADMIN PANEL=-=-=-=-=-=-\n";
    cout<<"\n\nWelcome Admin,\n";
    cout<<"\n\n1. Search\n\n2. Log Out\n\nOption: ";
    int a;
    cin>>a;
    bank b;
    if(a==1)
    {
        b.Search();
        goto START;
    }
    if(a==2)
    {
        main();
    }
}

void bank::Search()
{
    START:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=SEARCH BY=-=-=-=-=-=-\n";
    cout<<"\n\nWelcome Admin,\n";
    cout<<"\n\n1. Account Number\n\n2. Name\n\n3. Address\n\n4. Go Back\n\nOption: ";
    int a;
    cin>>a;
    bank b;
    if(a==1)
    {
        ifstream file;
        file.open("Bank.dat",ios::binary);
        cout<<"\n\nEnter Account Number : ";
        long Acc;
        cin>>Acc;
        file.seekg(0);
        int found = 0;
        while(file.read((char*)this,sizeof(bank)))
        {
            found = 0;
            if(pAcc == Acc)
            {
                Show();
                found = 1;
                getch();
                break;
            }
        }
        if(found == 0)
        {
            cout<<"\n\nNo data found.";
            getch();
        }
        file.close();
        goto START;
    }
    if(a==2)
    {
        ifstream file;
        file.open("Bank.dat",ios::binary);
        cout<<"\nEnter Name : ";
        char Name[30];
        fflush(stdin);
        gets(Name);
        int i,j;
        int found = 0;
        int ffound = 0;
        file.seekg(0);
        while(file.read((char *)this,sizeof(bank)))
        {
            found = 0;
            for(i=0,j=0;Name[i]!='\0'&& pName[j]!='\0';)
            {
                if(toupper(Name[i])==toupper(pName[j]))
                {
                    ++i;
                    ++j;
                    found = 1;
                    ffound = 1;
                }
                else
                {
                    found = 0;
                    ++j;
                }
            }
            if (found == 1)
            {
                Show();
                getch();
            }
        }
        if(ffound == 0)
        {
            cout<<"\nNo data found.";
            getch();
        }
        file.close();
        goto START;

    }
    if(a==3)
    {
        ifstream file;
        file.open("Bank.dat",ios::binary);
        cout<<"\nEnter Address : ";
        char Addr[30];
        fflush(stdin);
        gets(Addr);
        int i,j;
        int found = 0;
        int ffound = 0;
        file.seekg(0);
        while(file.read((char *)this,sizeof(bank)))
        {
            found = 0;
            for(i=0,j=0;Addr[i]!='\0'&& pAddr[j]!='\0';)
            {
                if(toupper(Addr[i])==toupper(pAddr[j]))
                {
                    ++i;
                    ++j;
                    found = 1;
                    ffound = 1;
                }
                else
                {
                    found = 0;
                    ++j;
                }
            }
            if (found == 1)
            {
                Show();
                getch();
            }
        }
        if(ffound == 0)
        {
            cout<<"\nNo data found.";
            getch();
        }
        file.close();
        goto START;
    }
if(a==4)
    {
        b.admin();
    }
}

void bank::pre(long Acc)
{
    ifstream file;
    file.open("Bank.dat",ios::binary);
    file.seekg(0);
    while(file.read((char*)this,sizeof(bank)))
    {
        if(Acc==pAcc) break;
    }
    cout<<"\n\n--------------------------Account Summary-----------------------------\n";
    cout<<"\nName: "<<pName<<"\nAddress: "<<pAddr<<"\nMobile Number: "<<pMobile<<"\nBalance: Rs. "<<balance;
    cout<<"\n\nDo you wish to view last 10 transactions?(y/n): ";
}

void bank::task(long Acc)
{
    START:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=ACCOUNT HOME=-=-=-=-=-=-\n";
    cout<<"\n\nWelcome "<<pName<<",\n";
    cout<<"\n\n1. Delete Account\n\n2. Withdraw/Deposit Money\n\n3. Account Summary\n\n4. Last 10 Transactions\n\n5. Log Out\n\nOption: ";
    int a;
    cin>>a;

if(a==5)
   {
       main();
   }
    if(a==3)
    {
        pre(Acc);
        char y;
        cin>>y;
        if(y=='y'||y=='Y')
            a=4;
        else  goto START;
    }
    if(a==4)
    {
        cout<<"\n\n========================LAST 10 TRANSACTIONS=========================\n\n";
        ifstream file;
        file.open("Bank.dat",ios::binary);
        file.seekg(0);
        while(file.read((char*)this,sizeof(bank)))
        {
            if(pAcc == Acc) break;
        }
        for( int i= 0;i<10;++i)
            cout<<"\n"<<ltran[i];
        getch();
        goto START;
    }
    if(a==1)
    {
        cout<<"\n\nAre you sure you want to delete this account?(y/n): ";
        char ans;
        cin>>ans;
        if(ans=='Y'||ans=='y')
        {
        cout<<"\n\nDeleting your account...";
        ifstream file;
        file.open("Bank.dat",ios::binary);
        ofstream temp;
        temp.open("Temp.dat",ios::binary);
        while(file.read((char*)this,sizeof(bank)))
        {
            if(Acc!=pAcc) temp.write((char*)this,sizeof(bank));
        }
        file.close();
        temp.close();
        remove("Bank.dat");
        rename("Temp.dat","Bank.dat");
        cout<<"\n\nYour account was successfully deleted.";
        getch();
        return;
        }
        else goto START;
    }
    if(a==2)
    {
        cout<<"\n\n1. Withdraw\n2. Deposit\n\nOption: ";
        int am;
        int amo;
        cin>>am;
        fstream file;
        file.open("Bank.dat",ios::in|ios::out|ios::binary);
        file.seekp(0);
        while(file.read((char*)this,sizeof(bank)))
        {
            if(Acc==pAcc) break;
        }
        if(am == 1)
        {
            cout<<"\nEnter amount: Rs. ";
            cin>>amo;
            if(balance < amo)
            {
                cout<<"\n\nInsufficient Balance!";
                cout<<"\nYou can withdraw maximum of Rs. "<<balance<<".\n";
                getch();
                goto START;
            }
            else
            {
                amo = -1 * amo;
                goto TASK;
            }

        }
        else if(am == 2) {
        cout<<"\nEnter amount: Rs. ";
        cin>>amo;
        amo = +1*amo;
        goto TASK;}
        else
        {
            cout<<"\n\nWrong Choice.";
            getch();
            goto START;
        }
        TASK:
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        cout<<"\nTransaction was successful.";
        int pos = -1 * sizeof(bank);
        file.seekp(pos,ios::cur);
        balance += amo;
        int i;
        for(i=99;i>0;--i)
        {
            strcpy(ltran[i],ltran[i-1]);
        }
        char str1[200];
        char str[200];
        if(am == 1)
        {
        amo = -1 * amo;
        strftime(str1,100,"[%d/%m/%Y : %X]",timeinfo);
        sprintf(str,"[[Withdraw] Rs. %d  << %s",amo,str1);
        }
        else if(am == 2)
        {
            strftime (str1,100,"[%d/%m/%Y : %X]",timeinfo);
            sprintf(str,"[Deposit] Rs. %d  << %s",amo,str1);
        }
        strcpy(ltran[0],str);
        file.write((char*)this,sizeof(bank));
        cout<<"\n\n"<<str;
        getch();
        goto START;
    }
}
void bank::Login()
{
    PASSINPUT:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=LOGIN=-=-=-=-=-=-\n";
    cout<<"\n\nAccount Number -> ";
    long Acc;
    cin >>Acc;
    cout<<"\nPassword -> ";
    int i;
    char npass[32];
    char a;
    for(i=0;;)
    {
        char a = getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            npass[i]=a;
            cout<<"*";
            ++i;
        }
        if(a=='\b'&&i>=1)
        {
            --i;
            cout<<"\b \b";
        }
        if(a=='\r')
        {
            npass[i]='\0';
            break;
        }
    }
    if(i<=5)
    {
        cout<<"\n\nMinimum 6 characters required.";
        getch();
        goto PASSINPUT;
    }
    ifstream log;
    log.open("Bank.dat",ios::binary);
    log.seekg(0);
    int check=0;
    while(log.read((char *)this,sizeof(bank)))
    {
        check = 0;
        if(Acc!=pAcc) continue;
        else
        {
            int i,j;
            for(i=0,j=0;npass[i]!='\0'||pass[j]!='\0';++i,++j)
            {
                if(pass[j]!=npass[i])
                {
                    check = 0;
                    break;
                }
                else check = 1;
            }
        }
        if(check == 1)
        {
            break;
        }
     }
     log.close();
     if(check == 1)
     {
         cout<<"\n\nLogin Successful.";
         getch();

         task(Acc);
     }
     else
     {
         {
         cout<<"\n\nWrong Account Number or Password. Try again.";
         getch();
         goto PASSINPUT;
         }

     }
}

void bank::Show()
{
    cout<<"\n\n-=-=-=-=-=-=DATA=-=-=-=-=-=-\n";
    cout<<"\nAccount Number : "<<pAcc;
    cout<<"\nName : "<<pName;
    cout<<"\nAddress : "<<pAddr;
    cout<<"\nMobile : "<<pMobile;
}
void bank::NewAccount()
{
    char Name[30];
    unsigned long long Mobile;
    long Acc;
    char Add[200];
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=REGISTRATION=-=-=-=-=-=-\n\n";
    cout<<"\nEnter Name: ";
    fflush(stdin);
    gets(Name);
    cout<<"\nAddress: ";
    fflush(stdin);
    gets(Add);
    cout<<"\nMobile Number: ";
    cin>>Mobile;
    srand(time(NULL));
    ifstream temp;
    temp.open("Bank.dat",ios::binary);
    ACCNO:
    temp.seekg(0);
    Acc = rand() % 11999 + 100000;
    int f=0;
    while(temp.read((char *)this,sizeof(bank)))
    {
        if(Acc == pAcc)
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        goto ACCNO;
    }
    temp.close();
    cout<<"\nYour Account Number is (Remember it): "<<pAcc;
    start:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=REGISTRATION=-=-=-=-=-=-\n\n";
    cout<<"\nName : "<<Name<<"\n\nAddress : "<<Add<<"\n\nMobile Number : "<<Mobile<<"\n\nYour Account Number is (Remember it): "<<Acc;
    cout<<"\n\nEnter Password: ";
    char a;
    int i=0;
    for(i;;)
    {
       a=getch();
       if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
    }
    if (i<=5)
    {
        cout<<"\nMinimum 6 characters required.";
        getch();
        goto start;
    }

    ofstream file;
    file.open("Bank.dat",ios::binary|ios::app);
    strcpy(pName,Name);
    strcpy(pAddr,Add);
    pAcc = Acc;
    pMobile = Mobile;
    balance = 0;
    for(i=0;i<100;++i)
        ltran[i][0]='\0';
    file.write((char *)this,sizeof(bank));
    file.close();
    cout<<"\n\nAccount Created Successfully.";
    getch();
        Login();
        }

int main()
{
    START:
    system("cls");
    cout<<"\n\n                       WELCOME TO EXAFLOPS BANKING PORTAL\n\n";
    cout<<"      =*=*=*=*=*=*=*=C=O=D=E=D=*=B=Y=*=T=U=N=A=P=*=P=A=U=L=*=*=*=*=*=*=*=\n\n\n\n";
    cout<<"-=-=-=-=-=-=MAIN MENU=-=-=-=-=-=-\n";
    cout<<"\n1. Login\n\n2. Open New Account\n\n3. Exit\n\n4. Admin Panel\n\nOption: ";
    int a;
    cin>>a;
    if(a==3)
    {
        exit(0);
    }
    bank b;

    if(a==4)
    {
        b.adminlogin();
        goto START;
    }
    if(a==2)
    {
        b.NewAccount();
        a=1;
    }
    if(a==1)
    {
        b.Login();
        goto START;
    }
    return 0;
    }
