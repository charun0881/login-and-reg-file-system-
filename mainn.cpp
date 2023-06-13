#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;


void login();
void registration();
void forgot();

int main()
{
        int c;   // c for choice
        cout<<"\t\t\t__________________________________________________________________________\n\n\n";
        cout<<"\t\t\t                     Welcome to the Login page                               \n\n";
        cout<<"\t\t\t______________________        MENU        ________________________________\n\n";
        cout<<"                                                                                \n\n";
        cout<<"\t|  Press 1 to LOGIN                    |"<<endl;
        cout<<"\t|  Press 2 to REGISTER                 |"<<endl;
        cout<<"\t|  Press 3 if you forgot your PASSWORD |"<<endl;
        cout<<"\t|  Press 4 to Exit                     |"<<endl;
        cout<<"\n\t\t\tPlease Enter your choice :";
        cin>>c;
        cout<<endl;
        switch(c)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registration();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"\t\t\tThankyou!\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"\t\t\tPlease select from the options given above , Try again..\n"<<endl;
                        main();
        }

}

void login()
{
        
        
        int count;
        string userId,password,id,pass;
        system("cls");
        cout<<"\t\t\tplease enter the username & password"<<endl;
        cout<<"\t\t\tUSERNAME :";
        cin>>userId;
        cout<<"\t\t\tPASSWORD :";
        cin>>password;

        ifstream input("records.txt");
        while(input>>id>>pass)                     //here reading is taking place
        {
                if(id==userId && pass==password)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();     //this is for closing the file
        if(count==1)
        {
                cout<<userId<<"\n Your Login is Successful\nThanks for logging in!\n";
               // cin.get();
              //  cin.get();
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void registration()
{

        string ruserId,rpassword,rid,rpass;
        system("cls");
        cout<<"\t\t\tEnter the username :";
        cin>>ruserId;
        cout<<"\n\t\t\tEnter the password :";
        cin>>rpassword;

        ofstream f1("records.txt",ios::app);
        f1<<ruserId<<' '<<rpassword<<endl;             //here we are writing the information in the file.
        system("cls");
        cout<<"\n\t\t\tRegistration is Successful\n";
        main();


}

void forgot()
{
        int option;
        system("cls");
        cout<<"\t\t\tYou forgot your password? No worries\n";
        cout<<"Press 1 to Search your id by username"<<endl;
        //cout<<"2.Search your id by password"<<endl;
        cout<<"Press 2 to go Back to the Main menu"<<endl;
        cout<<"\t\t\tEnter your choice :";
        cin>>option;
        switch(option)
        {
                case 1:
                {
                        int count=0;
                        string suserId,sId,spass;
                        cout<<"\n\t\t\tEnter the username which you remembered :";
                        cin>>suserId;

                        ifstream f2("records.txt");
                        while(f2>>sId>>spass)
                        {
                                if(sId==suserId)
                                {
                                        count=1;
                                }
                        }
                        f2.close();
                        if(count==1)
                        {
                                cout<<"\n\n\tYour account is found\n";
                                cout<<"\n\tYour password is "<<spass;
                            //    cin.get();
                            //    cin.get();
                              //  system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\n\tSorry, Account not found! \n";
                            //    cin.get();
                            //    cin.get();
                                main();
                        }
                        
                        break;
                }
          /*      case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }

                        break;
                } */

                case 2:
                {
                       // cin.get();
                        main();
                }
                default:
                        cout<<"\t\t\tWrong choice! Please try again"<<endl;
                        forgot();
        }
}

