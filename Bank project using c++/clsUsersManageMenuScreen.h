#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsShowUsersList.h"
#include"clsAddNewUserScreen.h"
#include"clsUpdateUserInfoScreen.h"
#include"clsFindUserScreen.h"
#include"clsDeleteUserScreen.h"
using namespace std;
class clsUsersManageMenuScreen : protected clsScreen
{
private:
	enum enUsersManageMenu { 
		eUsersList = 1,
		eAdduser = 2,
		eFindUser=3,
		eUpdateUser=4,
		eDeleteUser=5,
	};
	static short _ReadUsersManageMenu()
	{
		cout << "\t\t\t\t      Choose what do you want to do [1 to 6] ? ";
		return clsInputValidate::ReadNumberBetween(1, 6);
	}
	static void _ShowAddUserScreen()
	{
		//cout << "\nAdd user will be here";
		clsAddNewUserScreen::ShowAddUserScreen();
	}
	static void _ShowUsersListScreen()
	{
		//cout << "\nUsers list will be here";
		clsShowUsersList::ShowUsersListScreen();
	}
	static void _ShowFindUserScreen()
	{
		//cout << "\nFind user will be here";
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate user will be here";
		clsUpdateUserInfoScreen::ShowUpdateUserScreen();
	}
	static void _ShowDeleteUserScreeen()
	{
		//cout << "\nDelete user will be here";
		clsDeleteUserScreen::clsShowDeleteUserScreen();
	}

	static void _BackToUsersManageMenu()
	{
		cout << "\nPress any key to back users manage menu..\n";
		system("pause>0");
		ShowUsesrsManageMenu();

	}
	void static _PerformUsersManageMenu(enUsersManageMenu Choice)
	{
		switch (Choice)
		{
		  case enUsersManageMenu::eUsersList:
		  {
			  system("cls");
			  _ShowUsersListScreen();
			  _BackToUsersManageMenu();
			  break;
		  }
		  case enUsersManageMenu::eAdduser:
		  {
			  system("cls");
			  _ShowAddUserScreen();
			  _BackToUsersManageMenu();
			  break;
		  }
		  case enUsersManageMenu::eFindUser:
		  {
			  system("cls");
			  _ShowFindUserScreen();
			  _BackToUsersManageMenu();
			  break;
		  }
		  case enUsersManageMenu::eUpdateUser:
		  {
			  system("cls");
			  _ShowUpdateUserScreen();
			  _BackToUsersManageMenu();
			  break;
		  }
		  case enUsersManageMenu::eDeleteUser:
		  {
			  system("cls");
			  _ShowDeleteUserScreeen();
			  _BackToUsersManageMenu();
			  break;
		  }
		  default:
		  {
			  //Do nothing here by default back to main menu
		  }
		}
		

	}

public:
	static void ShowUsesrsManageMenu()
	{
		if (!_CheckIsAccessRight(clsUser::bManageUsers))
		{
			return;// do nothing exit from  this the fun..
		}
		system("cls");
		_DrawMainScreenHeader("\tUsers Manage Menu Screen");

		cout << setw(39) << left << " " << "==========================================\n\n";
		cout << setw(44) << left << " " << "\tUsers Manage Menu Options \n\n";
		cout << setw(39) << left << " " << "==========================================\n";
		cout << setw(39) << left << " " << "\t[1] Show Users List\n";
		cout << setw(39) << left << " " << "\t[2] Add User\n";
		cout << setw(39) << left << " " << "\t[3] Find User\n";
		cout << setw(39) << left << " " << "\t[4] Update User \n";
		cout << setw(39) << left << " " << "\t[5] Delete User\n";
		cout << setw(39) << left << " " << "\t[6] Main Menu\n";
		cout << setw(39) << left << " " << "==========================================\n\n";

		_PerformUsersManageMenu((enUsersManageMenu)_ReadUsersManageMenu());
	}



};

