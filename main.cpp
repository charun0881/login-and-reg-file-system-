
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*forward declaration of the function.*/
void login();
void registration();
void forgot_pass();

int main()
{
    int choice;
    cout << "\t\t\t__________________________ WELCOME ________________________\n\n\n";
    cout << "\t\t\t_________________________ | MENU | ________________________\n\n\n";
    cout << "\t Press 1 to LOGIN.                     |\n";
    cout << "\t Press 2 for registration.             |\n";
    cout << "\t Press 3 if you forgot your passowrd.  |\n";
    cout << "\t Enter your choice : ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;
    case 3:
        forgot_pass();
        break;

    default:
        /* clears the screen every time loop runs*/
        cout << "\tInvalid input yar!";
        break;
    }

    return 0;
}
void login()
{
    int count = 0;
    string userId, password, id, pass;

    /*GETTING THE USERNAME AND PASSWORD FOR THE USER.*/
    cout << "\t Enter the username : ";
    cin >> userId;
    cout << "\t Password : ";
    cin >> password;

    /* READING THE INFO OF THE USER FORM THE FILE USING ifstream AND input OBJECT TO STORE IN THE
    VARIABLES id AND pass WHICH IS COMPARED WITH THE ENTERED userId AND password.*/
    ifstream input("user_data.txt"); /*input KO THAU MA J LEKHNA NI PAYINXA.*/
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
        }
        input.close(); /*CLOSING THE FILE "user_data.txt".*/

        if (count == 1)
        {
            cout <<"\n\n\n\t*"<< userId << "* YOU ARE LOGGED IN.";
            cout << endl;
        }
        else
        {
            cout << "\t****** Login failed!****** Please go through registration to register this username or recheck your login input.\n\n\n";
            main();
        }
    }
}
void registration()
{
    string r_userId, r_password, r_id, r_pass;

    cout << "\t Enter the username to be registered : ";
    cin >> r_userId;
    cout << endl;
    cout << "\t Set a new password for your Id : ";
    cin >> r_password;
    cout << endl;

    ofstream f1("user_data.txt", ios::app); /* ofstream IS USED TO WRITE DATA INTO A FILE AND ios MEANS input-output-stream AND
    THE FILE IS OPENED IN app MODE WHICH APPENDS THE NEW DATA AT THE END OF THE FILE.*/
    f1 << r_userId << " " << r_password;

    cout << "\t UserName registered successfully.\n";
    main();
}
void forgot_pass()
{
    int choice;

    cout << "\t Did you forget your password? Press 1 to search your account by your username or Press 2 to go to the MAINMENU : \n ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
    { /* yaha malai 'transfer of control bypasses initialization of : * vanera error aayeko thyo.
    so yaha case ma MULTIPLE BLOCK OF CODE huda USE BRACES*/
        int count = 0;
        string s_userId, s_id, s_password, s_pass;
        /* SEARCHING THE DATABASE FOR THE USERNAME REFERED BY THE USER.*/
        ifstream f2("user_data.txt");
        cout << "\t Enter your username to get your password : ";
        cin >> s_userId;
        while (f2 >> s_id >> s_pass)
        {
            if (s_id == s_userId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n\n Your username is found.  *AND* Your password is *" << s_pass << "*" << endl;
            main();
        }
        else
        {
            cout << "\n\n\n Sorry the account with username-" << s_userId << "- is not found.\n";
            main();
        }
        break;
    }
    case 2:
        main();
        break;

    default:
        cout << "Wrong choice. Please enter 1 or 2 as per the menu.\n";
        forgot_pass();
        break;
    }
}