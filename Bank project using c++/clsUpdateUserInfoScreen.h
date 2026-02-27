#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsUser.h";

using namespace std;

class clsUpdateUserInfoScreen :protected clsScreen
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
		if (clsString::LowerAllString(User.getUserID()) =="admin")
		{
			cout << "\n" << "User Permissins: Admin";
		}
		else
		{
			cout << "\n" << "User Permissins: " << User.getUserPermissions();
		}


		cout << "\n" << "__________________\n";
	}
	static int _ReadUserPermissions()
	{
		int Permissions = 0;
		string MainMenuOptions[7] =
		{
		" Show Clients List ",
		" Add Client ",
		" Dlete Client ",
		" Update Client ",
		" Find Client ",
		" Transactions Menu ",
		" Manage Users ",
		};
		int MainMenuInBinary[7] = {
			clsUser::enbMainMenueOptions::bShowClientsList,
			clsUser::enbMainMenueOptions::bAddClient,
			clsUser::enbMainMenueOptions::bDleteclient,
			clsUser::enbMainMenueOptions::bUpdateClient,
			clsUser::enbMainMenueOptions::bFindClient,
			clsUser::enbMainMenueOptions::bMenuTransactions,
			clsUser::enbMainMenueOptions::bManageUsers,
		};

		char Choice = 'Y';
		cout << "\nDo you want to give this the user full access [Y-N]?";
		cin >> Choice;
		if (tolower(Choice) == 'y')
		{
			return -1;
		}


		for (short i = 0; i < 7; i++)
		{

			cout << "Do you want give a user" + MainMenuOptions[i] + "Permissions y/n?";
			cin >> Choice;
			if (tolower(Choice) == 'y')
			{
				Permissions += MainMenuInBinary[i];
			}
		}
		return Permissions;


	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First name:";
		User.setFirstName(clsString::ReadString());
		cout << "Enter Last name:";
		User.setLastName(clsString::ReadString());
		cout << "Enter Email:";
		User.setEmaile(clsString::ReadString());
		cout << "Enter Phone Numer:";
		User.setPhone(clsString::ReadString());
		cout << "Enter Password:";
		User.setUserPassword(clsString::ReadString());

		//Not allow to update admin permissions
		if (clsString::LowerAllString(User.getUserID())=="admin")
		{
			return;
		}

		cout << "Chosse User permissions:";
		User.setUserPermissions(_ReadUserPermissions());
	}

public:
	static void ShowUpdateUserScreen()
	{
		string Title = "\tUpdate User Screen";
		_DrawMainScreenHeader(Title);


		cout << "Enter Exsits User ID to update:";
		string UserID = clsString::ReadString();
		while (!clsUser::IsUserExsits(UserID))
		{
			cout << "\nThe user ID Not Found,Please another one:";
			UserID = clsString::ReadString();
		}
		clsUser User = clsUser::Find(UserID);
		_Print(User);
		_ReadUserInfo(User);

		clsUser::enSaveResults Save;
		Save = User.Save();
		switch (Save)
		{
		  case clsUser::enSaveResults::SccessSave:
		  {
			_Print(User);
			cout << "\nThe user updated successfully:-)";
			break;
		  }
		  case clsUser::enSaveResults::FailedSaveEmptyObject:
		  {
			_Print(User);
			cout << "\nFailed! user Not updated becase,empty object";
			break;
		  }
		}


	}
};

