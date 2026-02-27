#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsShowUsersList:protected clsScreen 
{
private:
	static void _PrintClientRecordLine(clsUser User)
	{
        cout << "| " << left << setw(20) << User.getFullName();
		cout << "| " << left << setw(12) << User.getPhone();
		cout << "| " << left << setw(20) << User.getEmail();
        cout << "| " << left << setw(10) <<User.getUserID();
		cout << "| " << left << setw(10) << User.getUserPassword();
        //Means full access (Admin) .
        if (clsString::LowerAllString(User.getUserID()) == "admin")
        {
            cout << "|" << left << setw(12) << "Admin";
        }
        else
        {
            cout << "| " << left << setw(12) << User.getUserPermissions();
        }
		
		cout << "\n";

	}

public:
	static void ShowUsersListScreen()
	{
        vector<clsUser> vUsers;
        vUsers = clsUser::GetUsersList();


        string Title = "User List screen";
        string SupTitle = "User List (" + to_string(vUsers.size()) + ") User(s)";


        _DrawMainScreenHeader(Title, SupTitle);
        cout << "\n_________________________________________________________";
        cout << "__________________________________________\n";

        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "User ID";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n________________________________________________________";
        cout << "___________________________________________\n";

        if (vUsers.size() == 0)
        {
            cout << "\n\n\t\t\t\t\tNo Users data available on the system!\n";
        }
        else
        {
            for (clsUser User : vUsers)
            {
                _PrintClientRecordLine(User);
            }

        }

        cout << "\n______________________________________________________________";
        cout << "_____________________________________\n";

    }
};


	


