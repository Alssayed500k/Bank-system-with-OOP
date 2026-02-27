#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTransferBalanceToClientScreen.h"
#include"clsClientsTotalBalances.h"
#include"clsShowTransferLogListScreen.h"


class clsTransactionsMenuScreen : protected clsScreen
{
private:
	enum enTransactionMenu {
		eDeposit = 1,
		eWithdraw = 2,
		eTransferToClient=3,
		eBalancesTotal=4,
		eTransferLogList=5,
		eBackToMainMenu = 6,
	};

	static enTransactionMenu _ReadTransactionsMenu()
	{
		short Choice = 0;
		cout  <<setw(36)<<left<<"Choose what do you want to do [1 to 6 ] :";
		Choice = clsInputValidate::ReadNumberBetween(1, 6);
		return (enTransactionMenu) Choice;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositScreen();

	}

	static void _ShowWithdrawScreen()
	{
		
		//cout << "\nWithdrawl will be here soon";
		clsWithdrawScreen::WithDrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		
		//cout << "\nbalances total will be here soon...";
		clsClientsTotalBalances::ShowClientsTotalbalances();
	}

	static void _ShowTransferToClientScreen()
	{
		//cout << "\nTransfer To Client will be here..";
		clsTransferBalanceToClientScreen::ShowTransferToClientScreen();
	}
	static void _ShowTransferLogListScreen()
	{
		clsShowTransferLogListScreen::ShowTransferLogScreen();
	}

	static void _BackToTransactionsMenu()
	{
		cout << "\nPress any key to back transactions menu..";
		system("pause>0");
		TransactionsMenu();
	}

	static void _PerformTransactionMenu(enTransactionMenu Choice) 
	{
		switch (Choice)
		{
		case enTransactionMenu::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_BackToTransactionsMenu();
			break;
		}
		case enTransactionMenu::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_BackToTransactionsMenu();
			break;
		}
		case enTransactionMenu::eTransferToClient:
		{
			system("cls");
			_ShowTransferToClientScreen();
			_BackToTransactionsMenu();

		}
		case enTransactionMenu::eBalancesTotal:
		{
			 system("cls");
			_ShowTotalBalancesScreen();
			_BackToTransactionsMenu();

		}
		case enTransactionMenu::eTransferLogList:
		{
			system("cls");
			_ShowTransferLogListScreen();
			_BackToTransactionsMenu();

		}
		default:
		{
			//Here not add any a thing the main menu screen will handel here..
		}
		}

	}

public:
	static void TransactionsMenu()
	{
		if (!_CheckIsAccessRight(clsUser::bMenuTransactions))
		{
			return;// do nothing exit from  this the fun..
		}
		system("cls");
		_DrawMainScreenHeader("\tTransactions Main Menu Screen");

		cout << setw(39) << left << " " << "==========================================\n\n";
		cout << setw(44) << left << " " << "\tTransactions Menu Options\n\n";
		cout << setw(39) << left << " " << "==========================================\n";
		cout << setw(39) << left << " " << "\t[1] Deposit\n";
		cout << setw(39) << left << " " << "\t[2] Withdraw\n";
		cout << setw(39) << left << " " << "\t[3] Transfer to Client\n";
		cout << setw(39) << left << " " << "\t[4] Show balances total\n";
		cout << setw(39) << left << " " << "\t[5] Show Transfer Log list\n";
		cout << setw(39) << left << " " << "\t[5] Main Menu\n";
		cout << setw(39) << left << " " << "==========================================\n\n";

		_PerformTransactionMenu(_ReadTransactionsMenu());

	}
};
 
