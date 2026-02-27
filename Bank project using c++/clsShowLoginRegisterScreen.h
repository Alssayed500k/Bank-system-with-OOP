#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"


using namespace std;
class clsShowLoginRegisterScreen:protected clsScreen
{
private:
	static void _PrintLoginRegisterLine( clsUser::stLoginRecord LoginRecord)
	{
        cout << "| " << left << setw(30) << LoginRecord.DateTime;
        cout << "| " << left << setw(20) << LoginRecord.UserName;
        cout << "| " << left << setw(12) << LoginRecord.Password;
        cout << "| " << left << setw(20) << LoginRecord.Permissions;
        

        cout << "\n";
	}
public:
    static void ShowLoginRegisterScreen()
    {
        if (!_CheckIsAccessRight(clsUser::bLoginRegister))
        {
            return;// do nothing exit from  this the fun..
        }
        vector <clsUser::stLoginRecord> vLoginRecords = clsUser::vLoadUsersLoginTimeFromFile();

        string Title = "Register Login  List Screen";
        string SupTitle = "(" + to_string(vLoginRecords.size()) + ")Record(s)";


        _DrawMainScreenHeader(Title, SupTitle);
        cout << "\n_________________________________________________________";
        cout << "__________________________________________\n";

        cout << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(20) << "User Name/ID";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << "\n________________________________________________________";
        cout << "___________________________________________\n";

        if (vLoginRecords.size() == 0)
        {
            cout << "\n\n\t\t\t\t\tNo Users record available on the system!\n";
        }
        else
        {
            for ( clsUser::stLoginRecord LoginRecord : vLoginRecords)
            {
                _PrintLoginRegisterLine(LoginRecord);
            }

        }

        cout << "\n______________________________________________________________";
        cout << "_____________________________________\n";

    }
};

