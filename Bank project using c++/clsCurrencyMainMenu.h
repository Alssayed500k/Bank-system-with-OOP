#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrencyListScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyMainMenu : protected clsScreen
{
private:
	enum enCurrencyMainMenu{
		ShowCurrencyList=1,
		FindCurrency=2,
		UpdateRatescreen=3,
		CurrencyCalculator=4,
	};
	static short _ReadCurrencyMainMenu()
	{
		cout << "\nChoose what do you want to do [1-5]?";
		return clsInputValidate::ReadNumberBetween(1, 5);
	}
	static void _ShowCurrencyListScreen()
	{
		//cout << "\nCurrency List will be here.";
		clsCurrencyListScreen::ShowCurrenciesListScreen();
	}
	static void _FindCurrencyScreen()
		{
			//cout << "\nFind Currency will be here.";
		clsFindCurrency::FindCurrencyScreen();
		}
	static void _UpdateRatescreen()
	{
		//cout << "\nUpdate Rate will be here.";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _CurrencyCalculatorScreen()
	{
		//cout << "\nCurrency calculator will be here.";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyMainMenu()
	{
		cout << "\nPress Any key to back main menu...";
		system("pause>0");
		ShowMainMenuScreen();
	}

	static  void _PerformCurrencyMainMenu(enCurrencyMainMenu Choice)
	{
		switch (Choice)
		{
		case enCurrencyMainMenu::ShowCurrencyList:
		{
			system("cls");
			_ShowCurrencyListScreen();
			_GoBackToCurrencyMainMenu();
			break;
		}
		case enCurrencyMainMenu::FindCurrency:
		{
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrencyMainMenu();
			break;
		}
		case enCurrencyMainMenu::UpdateRatescreen:
		{
			system("cls");
			_UpdateRatescreen();
			_GoBackToCurrencyMainMenu();
			break;
		}
		case enCurrencyMainMenu::CurrencyCalculator:
		{
			system("cls");
			_CurrencyCalculatorScreen();
			_GoBackToCurrencyMainMenu();
			break;
		}
		default:
		{
			//do nothing here it will go back main menu screen by default
		}
		}
	}
public:
	static void ShowMainMenuScreen()
	{
		system("cls");
		_DrawMainScreenHeader("\t\Currency Exchange Main Screen");

		cout << setw(39) << left << " " << "==========================================\n\n";
		cout << setw(50) << left << " " << "Currency Exchange Menu \n\n";
		cout << setw(39) << left << " " << "==========================================\n";
		cout << setw(39) << left << " " << "\t[1] Show Currency List\n";
		cout << setw(39) << left << " " << "\t[2] Find Currency\n";
		cout << setw(39) << left << " " << "\t[3] Update Rate\n";
		cout << setw(39) << left << " " << "\t[4] Currency Calculator\n";
		cout << setw(39) << left << " " << "\t[5] Main Menu\n";
		cout << setw(39) << left << " " << "==========================================\n\n";
		_PerformCurrencyMainMenu((enCurrencyMainMenu)_ReadCurrencyMainMenu());

	}
};

