//Projects Start Here
//Project Number 1 - one of the programs in C (sum of the digits of a number using recursion)
#include <stdio.h>
int sum (int num)
{
    if (num != 0)
    {
        return (num % 10 + sum (num / 10));
    }
    else
    {
       return 0;
    }
}
int main()
{
    int n,result;
    printf("enter the number : ");
    scanf("%d",&n);
    result = sum(n);
    printf("Sum of digits in %d is %d\n", n, result);
    return 0;
}
//Project Number 2 - Bank management system using C 
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
int i,j;
int main_exit;
void menu();
int atm();
void close();
struct date
{
    int month,day,year;
};
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t==== ADD RECORD  ====");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void close(void)
{
    printf("\n\n\n\nBrought To You by code-projects.org");
    }


void menu(void)
{   int choice;
    system("cls");
    system("color 7");
    printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] Create a new account\n\t\t[2] Update information of existing account\n\t\t[3] Transactions\n\t\t[4] Check the details of existing account\n\t\t[5] Remove existing account\n\t\t[6] View customer's list\n\t\t[7] ATM Feature\n\t\t[8] Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:atm();
        break;
        case 8:close();
        break;
    }



}
int main()
{
    char pass[10],password[10]="pass";
    int i=0;
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);
    /*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {
            printf("*");
            pass[i]=getch();
            i++;
        }
    }while (pass[i]!=13);
    pass[10]='\0';*/
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
                system("pause");
				system("cls");

            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}

//ATM FEATURE - nsb code-projects
int atm(){
	//Functions

void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();

int login(void)
{
  float number = 1234;
  int pass;
  printf("\n\n\t\t\tEnter the PIN No:");
  scanf("%d", &pass);

  if (pass == number)
    {
      printf("\n\nPIN Matched!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      mainMenu();
    }
  else
    {
      printf("Invalid\n Try Again");
      login();
    }
  return 0;
}


//Main Code
	    //Local Declarations
    int option;
    float balance = 15000.00;
    int choose;
    bool again = true;

    // insert code here...
    login();
    while (again) {



    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
     system("CLS"); 

        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;

            case 4:
                menuExit();
                return 0;

            default:
                errorMessage();
                break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
         system("CLS"); 



        if (choose == 2) {
            again = false;
            menuExit();

        }else{
        	mainMenu();
		}

}


    return 0;

}//main code



//Functions

void mainMenu() {

    printf("\n\n\t\t==========Welcome to ATM Feature==========\n\n");
    printf("\n\t\t----Please choose one of the options below----\n");
    printf("\n\t\t< 1 >  Check Balance\n");
    printf("\n\t\t< 2 >  Deposit\n");
    printf("\n\t\t< 3 >  Withdraw\n");
    printf("\n\t\t< 4 >  Exit\n\n");

}//Main Menu

void checkBalance(float balance) {
    printf("You Choose to See your Balance\n");
    printf("****Your Available Balance is:   $%.2f\n\n", balance);

}//Check Balance

float moneyDeposit(float balance) {
    float deposit;
    printf("You choose to Deposit a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);


    balance += deposit;

    printf("****Your New Balance is:   $%.2f\n\n", balance);
    return balance;


}//money deposit

float moneyWithdraw(float balance) {
    float withdraw;
    bool back = true;

    printf("You choose to Withdraw a money\n");
    printf("$$$$Your Balance is: $%.2f\n\n", balance);

    while (back) {
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);


    if (withdraw < balance) {
        back = false;
        balance -= withdraw;
        printf("$$$$Your withdrawing money is:  $%.2f\n", withdraw);
        printf("****Your New Balance is:   $%.2f\n\n", balance);

    }

        else  {

        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:   $%.2f\n\n", balance);

    }
    }
    return balance;


}//money withdraw

void menuExit() {
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
    printf("-----      Brought To by code-projects.org      -----\n");


}//exit menu

void errorMessage() {
    printf("+++!!!You selected invalid number!!!+++\n");
}
//Project Number 3 - C program to display the contents of the file
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
int main()
{
     char name[30],ch;
     printf("enter the details : ");
     ofstream fout("student",ios::out|ios::binary);
     ifstream fin("student1",ios::in|ios::binary);
     for(int i=5;i>=0;i--)
     {
          fin.get(name,30);
          fin.get(ch);
          fin>>marks;
          fin.get(ch);
          cout<<"student name : "<<name;
          cout<<"\tmarks:"<<marks<<"\n";
     }
     while(!fin.eof())
     {
          fin.read((char*)&ch,sizeof(ch));
          fin.write((char*)&ch,sizeof(ch));
     }
     fin.close();
     fout.close();
     return 0;
}
//Project Number 4 - Cricket Scoring Sheet using C 
#include <stdio.h>
#include <stdlib.h>
void req_rate(float a, float b, float c,float d,float e);
void runs_needed(int a,int b,int c,int d, int e);
void projected_score(int a,int b,int c,int d,float e);
void result(int a,int b,int e,int g,char f,char c[],char d[]);
float curr_rate(float a, float b, float c);
void ball_played(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i, int *j);
int string_comp(char a[],char b[],char c[]);
float curr_rate(float a, float b, float c);
int main(int argc, char *argv[]) {
	int wd=0,nb=0,lb=0,b=0,extras=0,overs=0,T_overs=0, k=0,balls=0, T=0,score=0,wickets=0, target=0,q=0,c[11],j=1,f=0,s=0;
	float c_rate;
	char toss[15], team_1[15], team_2[15], choice, runs;
	printf("Match between:\n");
	gets(team_1);
	printf("versus\n");
	gets(team_2);
	printf("Toss won by: ");
	gets(toss);
	printf("Enter B to choose bat first and F to field first: ");
	scanf("%c",&choice);
	printf("Enter overs to be played by each side: ");
	scanf("%d",&T_overs);
	system("cls");
	T=string_comp(team_1,team_2,toss);
	while(overs<=T_overs||overs>=T_overs){
		do{
			if(wickets>q){
				*(c+wickets)=score;
			}
			q=wickets;
			system("cls");
			printf("\t\t\t%s vs %s (%d-overs match)\n",team_1,team_2,T_overs);
			if(T==1){
				if(choice=='B'||choice=='b'){
					printf("%s won the toss and elected to bat first\n",team_1);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_1,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s won the toss and elected to field first\n",team_1);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_2,score,wickets,overs,balls);
				}
			}
			else if(T==2){
				if(choice=='B'||choice=='b'){
					printf("%s won the toss and elected to bat first\n",team_2);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_2,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s won the toss and elected to field first\n",team_2);
					printf("\n\n%s %d-%d\t\tovers %d.%d\t\t",team_1,score,wickets,overs,balls);
				}
			}
			if (overs>0&&score>20){
				if(overs==T_overs||wickets==10){
					printf("\n");
					k++;
					break;
				}
				c_rate= curr_rate(score,overs,balls);
				printf("run rate %0.2f\n",c_rate);
			}
			if(balls==0){
				printf("\n");
				if(extras>0){
					printf("extras: %d(wd %d,nb %d,lb %d,b %d)\t",extras,wd,nb,lb,b);
				}
				if(f>0||s>0){
					printf("boundaries: %d fours,%d sixes\n",f,s);
				}
				else
				printf("\n");
			}
			if (overs>0&&score>20&&balls==0){
				projected_score(score,overs,T_overs,balls,c_rate);
			}
			printf("\n");
			if(overs==T_overs||wickets==10){
				k++;
				break;
			}
			ball_played(&balls,&score,&wickets,&extras,&wd,&nb,&lb,&b,&f,&s);
		}while(balls<6);
		if(balls==6){
			balls=0;
		}
		if(overs<T_overs){
			overs++;
		}
		if(k>0){
			break;
		}
	}
	printf("\nextras: %d(wd %d,nb %d,lb %d,b %d)\tboundaries: %d fours,%d sixes\n",extras,wd,nb,lb,b,f,s);
	if(wickets>0){
		printf("\nfall of wickets:  ");
		for(j=1;j<=wickets;j++){
			if(j==1||j==6)
			printf("\n");
			else
			printf("\t");
			printf("%d-%d",j,c[j]);
		}
	}
	printf("\n\ninnings completed.");
	sleep(10);
	for(k=10;k>=0;k--){
		system("cls");
		printf("\n\n\n\n\t\t\tINNINGS BREAK...\n\t\t\t\t%d",k);
		sleep(1);
	}
	target=score+1,score=0,overs=0,k=0,wd=0,nb=0,lb=0,b=0,balls=0,wickets=0,extras=0,j=1,q=0,f=0,s=0;
	while(overs<=T_overs||overs>=T_overs){
		do{
			if(wickets>q){
				*(c+wickets)=score;
			}
			q=wickets;
			system("cls");
			printf("\t\t\t%s vs %s (%d-overs match)\n",team_1,team_2,T_overs);
			if(T==1){
				if(choice=='B'||choice=='b'){
					printf("%s gives target of %d runs to %s to win\n",team_1,target,team_2);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_2,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s gives target of %d runs to %s to win\n",team_2,target,team_1);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_1,score,wickets,overs,balls);
				}
			}
			else if(T==2){
				if(choice=='B'||choice=='b'){
					printf("%s gives target of %d runs to %s to win\n",team_2,target,team_1);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_1,score,wickets,overs,balls);
				}
				else if(choice=='F'||choice=='f'){
					printf("%s gives target of %d runs to %s to win\n",team_1,target,team_2);
					printf("\n\n%s %d-%d\t  overs %d.%d\t",team_2,score,wickets,overs,balls);
				}
			}
			if (overs>0&&score>20){
				if(overs==T_overs||wickets==10||target<=score){
					printf("\n");
					k++;
					break;
				}
				c_rate= curr_rate(score,overs,balls);
				printf("run rate %0.2f",c_rate);
				req_rate(score,overs,T_overs,balls,target);
			}
			if(balls==0){
				printf("\n");
				if(extras>0){
					printf("extras: %d(wd %d,nb %d,lb %d,b %d)\t",extras,wd,nb,lb,b);
				}
				if(f>0||s>0){
					printf("boundaries: %d fours,%d sixes\n",f,s);
				}
				else
				printf("\n");
			}
			if (overs>0&&score>20){
				runs_needed(score,overs,T_overs,balls,target);
			}
			printf("\n");
			if(wickets==10||target<=score||overs==T_overs){
				k++;
				break;
			}
			ball_played(&balls,&score,&wickets,&extras,&wd,&nb,&lb,&b,&f,&s);
		}while(balls<6&&overs<T_overs);
		if(balls==6){
			balls=0;
		}
		if(overs<T_overs){
			overs++;
		}
		if(k>0){
			break;
		}
	}
	printf("\nextras: %d(wd %d,nb %d,lb %d,b %d)\tboundaries: %d fours,%d sixes\n",extras,wd,nb,lb,b,f,s);
	if(wickets>0){
		printf("\nfall of wickets:  ");
		for(j=1;j<=wickets;j++){
			if(j==1||j==6)
			printf("\n");
			else
			printf("\t");
			printf("%d-%d",j,c[j]);
		}
	}
	printf("\n\ninnings completed.");
	sleep(10);
	for(k=0;k<=7;k++){
		system("cls");
		sleep(1);
		printf("\n\n\n");
		result(target,score,T,wickets,choice,team_1,team_2);
		sleep(1);
	}
	getche();
	return 0;
}
float curr_rate(float a, float b, float c){
	float d;
	if (c==0)
		d=a/b;
	else
		d=a/(b+(c/10));
	return d;
}
int string_comp(char a[],char b[],char c[]){
	int i=0,ab=0,j=0,k=0;
	strupr(a);
	strupr(b);
	strupr(c);
	for(i=0;i<3;i++){
		if(a[i]==c[i])
		j++;
		else if(b[i]==c[i])
		k++;
		else
		break;
	}
	if(j==3)
	ab=1;
	else if(k==3)
	ab=2;
	else
	ab=0;
	return ab;
}
void ball_played(int *a,int *b,int *c,int *d,int *e,int *f,int *g,int *h,int *i,int *j){
	char runs;
	int t;
	scanf("%c",&runs);
	switch(runs){
		case '0':
			*a=*a+1;
			break;
		case '1':
			*b=*b+1;
			*a=*a+1;
			break;
		case '2':
			*b=*b+2;
			*a=*a+1;
			break;
		case '3':
			*b=*b+3;
			*a=*a+1;
			break;
		case '4':
			*b=*b+4;
			*a=*a+1;
			*i=*i+1;
			break;
		case '5':
			*b=*b+5;
			*a=*a+1;
			break;
		case '6':
			*b=*b+6;
			*a=*a+1;
			*j=*j+1;
			break;
		case 'w':
		case 'W':
			printf("enter runs on wide ball: ");
			scanf("%d",&t);
			*b=*b+1+t;
			*d=*d+1+t;
			*e=*e+1+t;
			break;
		case 'n':
		case 'N':
		    printf("enter runs on no ball: ");
			scanf("%d",&t);
			*b=*b+t+1;
			*d=*d+1;
			*f=*f+1;
			break;
		case 'l':
		case 'L':
			printf("enter runs as leg byes: ");
			scanf("%d",&t);
			*b=*b+t;
			*a=*a+1;
			*d=*d+t;
			*g=*g+t;
			break;
		case 'b':
		case 'B':
			printf("enter runs as byes: ");
			scanf("%d",&t);
			*b=*b+t;
			*a=*a+1;
			*d=*d+t;
			*h=*h+t;
			break;
		case 'o':
		case 'O':
			*a=*a+1;
			*c=*c+1;
			printf("enter runs if wicket is runout: ");
			scanf("%d",&t);
			*b=*b+t;
			break;
	}
}
void result(int a,int b,int e,int g,char f,char c[],char d[]){
	int h,i;
	h=(a-1)-b;
	i=10-g;
	if((a-1)==b){
		printf("\t\t\tMATCH DRAWN.");
	}
	else if(a>b){	
		if(e==1){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",c,h,c);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",d,h,d);
		}
		else if(e==2){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",d,h,d);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d runs\n\t\t\tCONGRATULATIONS TEAM %s!",c,h,c);
		}
	}
	else if(a<b||a==b){
		if(e==1){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",d,i,d);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",c,i,c);
		}
		else if(e==2){
			if(f=='B'||f=='b')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",c,i,c);
			else if(f=='F'||f=='f')
			printf("\t\t\t%s won by %d wickets\n\t\t\tCONGRATULATIONS TEAM %s!",d,i,d);
		}
	}
}
void projected_score(int a,int b,int c,int d,float e){
	int ab,ba;
	ab=(c-b)+(d/10);
	ba=(ab*e)+a;
	printf("\nPROJECTED SCORE:\n%d at %0.2f RPO(curr. rate)\n%d at 6 RPO\n%d at 8 RPO\n%d at 10 RPO\n",ba,e,(ab*6)+a,(ab*8)+a,(ab*10)+a);
}
void runs_needed(int a,int b,int c,int d, int e){
	int f,h;
	f=(c*6)-((b*6)+d);
	h=e-a;
	printf("%d runs needed to win from %d balls",h,f);
}
void req_rate(float a, float b, float c,float d,float e){
	float f,g,h,i;
	f=e-a;
	if(d==0){
		h=c;
	}
	else{
		h=(c-1)+0.6;
	}
	i=b+(d/10);
	g=f/(h-i);
	printf("\t  req. run rate %0.2f\n",g);
}
//All Projects End Here . Thank You .
