#pragma once
#include<iostream>
#include"clsMainMenuScreen.h"
#include"clsScreen.h"
#include"Global.h"
#include"clsSaveLoginTime.h"

using namespace std;


class clsLoginScreen:protected clsScreen
{

private:
	static bool _Login()
	{
		string UserID, UserPassword;
		bool FailedLogin = false;
		bool BlockedLogin = false;
		short UserTries = 3;
		do 
		{
			
			if (FailedLogin)
			{
				--UserTries;
				cout << "Invalid UserId/Password\n";
				cout << "You have : [" << UserTries << "] Attempts\n\n";
			}

			if (UserTries == 0)
			{
				cout << "\nYou have been blocked! after 3 failed login attempts";
				return true;
			}
			cout << "Enter User ID:";
			cin >> UserID;
			cout << "Enter User password:";
			cin >> UserPassword;
			
			CurrentUser = clsUser::Find(UserID, UserPassword);
			FailedLogin = CurrentUser.IsEmptyObject();

		} while (FailedLogin);
		//login sccessfully
		CurrentUser.SaveUserLoginTime();
		clsMainMenuScreen::ShowMainMenuScreen();
		return BlockedLogin;
	}

public:
	static void ShowLoginScreen()
	{
		bool BlockedLogin = false;
		while (!BlockedLogin)
		{
			_DrawMainScreenHeader("\tLogin Screen");
			BlockedLogin = _Login();
		}
		
		
	}


};

