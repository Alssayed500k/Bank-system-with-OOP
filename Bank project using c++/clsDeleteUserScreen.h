#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsString.h"

using namespace std;
class clsDeleteUserScreen :clsScreen
{
private:
	static void _Print(clsUser User)
	{
		cout << "\n" << "User Data";
		cout << "\n" << "__________________\n";
		cout << "\n" << "First name     : " << User.getFirstName();
		cout << "\n" << "Last name      : " << User.getLastName();
		cout << "\n" << "Full name      : " << User.getFullName();
		cout << "\n" << "Email          : " << User.getEmail();
		cout << "\n" << "Phone          : " << User.getPhone();
		cout << "\n" << "User ID        : " << User.getUserID();
		cout << "\n" << "Password       : " << User.getUserPassword();
		if (User.getUserPermissions() == -2)
		{
			cout << "\n" << "User Permissins: Admin";
		}
		else
		{
			cout << "\n" << "User Permissins: " << User.getUserPermissions();
		}


		cout << "\n" << "__________________\n";
	}

public:
	static void clsShowDeleteUserScreen()
	{
		_DrawMainScreenHeader("\tDelete User Screen");

		cout << "\nEnter a exists user ID :";
		string UserID = clsString::ReadString();

		while (!clsUser::IsUserExsits(UserID))
		{
			cout << "\nThe User with ID [" + UserID + "] Not found enter another one:";
			string UserID = clsString::ReadString();
		}
		clsUser User = clsUser::Find(UserID);
		_Print(User);

		//Not allow to delete the admin
		if (clsString::LowerAllString(User.getUserID()) == "admin")
		{
			cout << "\nThe admin couldn;t be deleted!";
			return;//Break method running...
		}

		char DeleteConfirm = 'y';
		cout << "Are you sure you want to delete this the user y/n? ";
		cin >> DeleteConfirm;
		if (tolower(DeleteConfirm) == 'y')
		{
			if (User.Delete())
			{
				cout << "\nDone!The user deleted successfully.";
				_Print(User);
			}
			else
			{
				cout << "\nFailed!the user Not deleted";

			}
			return;
		}
		cout << "\nDelete cancelled";

	}

};

