#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpDateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenuScreen.h"
#include"clsUsersManageMenuScreen.h"
#include"clsCurrencyMainMenu.h"
#include"clsLogOutScreen.h"
#include"clsLoginScreen.h"
#include"clsShowLoginRegisterScreen.h"
#include"clsCurrencyMainMenu.h"
#include<iomanip>
#include"Global.h"
using namespace std;
class clsMainMenuScreen : protected clsScreen
{
private:
	enum _enMainMenuOptions
	{
		eShowClientsList = 1,
		eAddClient = 2,
		eDleteclient = 3,
		eUpdateClient = 4,
		eFindClient = 5,
		eMenuTransactions = 6,
		eManageUsers = 7,
		eShowLoginRegister = 8,
		eCurrencyExchange = 9,
		eLogout = 10,
    };

	
	static bool _ApplyUsersPermissions(clsUser CurrenUser)
	{
		//-1 full access on this the app
		return ((CurrentUser.getUserPermissions() == -1)
			||
			//Access limit
			(CurrentUser.getUserPermissions() & 8)
			);
	}
	static short _ReadMainMenuOption()
	{
		short MenuNumber = 0;
		cout  <<"\t\t\t\t      Choose what do you want to do[1 to 10] ? ";
		return clsInputValidate::ReadNumberBetween(1, 10);

	}
	//main options
	static void _ShowClientListScreen()
	{
		//cout << "Show client list will show here soon" << endl;
	     clsClientsListScreen::ShowClientsList();
	}
	static void _ShowAddClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
		//cout << "Add Client will show here soon" << endl;
	}
	static void _DeleteClientScreen()
	{
		clsDeleteClientscreen::DeleteClientscreen();
		//cout << "Delete Client will show here soon" << endl;
		
	}
	static void _UpdateClientScreen()
	{
		//cout << "Update Client will show here soon" << endl;
		clsUpDateClientScreen::UpdateClientInfo();
	}
	static void _FindClientScreen()
	{
		//cout << "Find Client will show here soon" << endl;
		clsFindClientScreen::FindClient();
	}
	static void _MenuTransactionsScreen()
	{
		//cout << " Menu transactions will show here soon" << endl;
		clsTransactionsMenuScreen::TransactionsMenu();
	}
	static void _ManageUsers()
	{
		//cout << "Manage users will show here soon" << endl;
		clsUsersManageMenuScreen::ShowUsesrsManageMenu();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsShowLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchange()
	{
		clsCurrencyMainMenu::ShowMainMenuScreen();
	}
	static void _LogOut()
	{
		clsLogOutScreen::ShowLogOutScreen();
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any Key to go back main menu:";
		system("pause>0");//Stop app running.
		ShowMainMenuScreen();
	}
	static void _PerFormMainMenuOptions(_enMainMenuOptions Choice)
	{
		switch (Choice)
		{
		   case _enMainMenuOptions::eShowClientsList:
		   {
			 system("cls");//clear console
			_ShowClientListScreen();
			_GoBackToMainMenu(); //main menu call itself
			break;
		   }
		   case _enMainMenuOptions::eAddClient:
		   {
			system("cls");//clear console
			_ShowAddClientScreen();
			_GoBackToMainMenu(); //main menu call itself
			break;
		   }
		   case _enMainMenuOptions::eUpdateClient:
		   {
			   system("cls");//clear console
			   _UpdateClientScreen(); 
			   _GoBackToMainMenu();//main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eFindClient:
		   {
			   system("cls");//clear console
			   _FindClientScreen(); 
			   _GoBackToMainMenu();//main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eDleteclient:
		   {
			   system("cls");//clear console
			   _DeleteClientScreen(); 
			   _GoBackToMainMenu();//main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eMenuTransactions:
		   {
			   system("cls");//clear console
			   _MenuTransactionsScreen();
			   _GoBackToMainMenu(); //main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eManageUsers:
		   {
			   system("cls");//clear console
			   _ManageUsers();
			   _GoBackToMainMenu(); //main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eShowLoginRegister:
		   {
			   system("cls");//clear console
			   _ShowLoginRegisterScreen();
			   _GoBackToMainMenu(); //main menu call itself
			   break;
		   }
		   case _enMainMenuOptions::eCurrencyExchange:
		   {
			   system("cls");//clear console
			   _ShowCurrencyExchange();
			   _GoBackToMainMenu(); //main menu call itself
			   break;
		   }

		   default:
		   {
			   system("cls");//clear console
			   _LogOut();
			  
		   }

		}


		
    }
public:

	static void ShowMainMenuScreen()
	{
		     system("cls");
		    _DrawMainScreenHeader("\t\tMain Screen");

	     	cout << setw(39) << left << " " << "==========================================\n\n";
		    cout << setw(50) << left << " " << "\tMain Menu \n\n";
		    cout << setw(39) << left << " " << "==========================================\n";
		    cout << setw(39) << left << " " << "\t[1] Show Client List\n";
		    cout << setw(39) << left <<  " " <<"\t[2] Add New Client\n";
			cout << setw(39) << left << " " << "\t[3] Delete Client\n";
			cout << setw(39) << left << " " << "\t[4] Update Client Info\n";
			cout << setw(39) << left << " " << "\t[5] Find Client\n";
			cout << setw(39) << left << " " << "\t[6] Transactions (Deposit , Withdraw)\n";
			cout << setw(39) << left << " " << "\t[7] Manage Users\n";
			cout << setw(39) << left << " " << "\t[8] Login Register List\n";
			cout << setw(39) << left << " " << "\t[9] Currency Exchange\n";
			cout << setw(39) << left << " " << "\t[10] Logout\n";
			cout << setw(39) << left << " "<< "==========================================\n\n";

			
			_PerFormMainMenuOptions( (_enMainMenuOptions) _ReadMainMenuOption());

	}


};

