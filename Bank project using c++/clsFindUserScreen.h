#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsUser.h";
class clsFindUserScreen:protected clsScreen
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
	static void ShowFindUserScreen()
	{
		string Title = "\tFind User Screen";
		_DrawMainScreenHeader(Title);


		cout << "Enter Exsits User ID to Find:";
		string UserID = clsString::ReadString();
		while (!clsUser::IsUserExsits(UserID))
		{
			cout << "\nThe user ID Not Found,Please another one:";
			UserID = clsString::ReadString();
		}
		clsUser User = clsUser::Find(UserID);
		_Print(User);

		return;
	}
};

