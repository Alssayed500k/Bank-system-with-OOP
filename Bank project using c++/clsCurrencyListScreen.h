#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsCurrency.h"

using namespace std;
class clsCurrencyListScreen: protected clsScreen
{
	static void _PrintCurrencyLine(clsCurrency Currency)
	{
        cout << "| " << left << setw(26) << Currency.Country();
        cout << "| " << left << setw(20) << Currency.CurrencyCode();
        cout << "| " << left << setw(28) << Currency.CurrencyName();
        cout << "| " << left << setw(20) << Currency.Rate();

        cout << "\n";
	}

public:
    static void ShowCurrenciesListScreen()
    {
        vector<clsCurrency> vCurrencyList;
        vCurrencyList = clsCurrency::GetCurrenciesList();

        _DrawMainScreenHeader("Currency List Screen");
        cout << "\n_________________________________________________________";
        cout << "__________________________________________\n";

        cout << "| " << left << setw(26) << "Country";
        cout << "| " << left << setw(20) << "Currency Code";
        cout << "| " << left << setw(28) << "Curreny Name";
        cout << "| " << left << setw(20) << "Rate(1$)";
        cout << "\n________________________________________________________";
        cout << "___________________________________________\n";

        if (vCurrencyList.size() == 0)
        {
            cout << "\n\n\t\t\t\t\tNo Currency List available on system!\n";
        }
        else
        {
            for (clsCurrency Currency : vCurrencyList)
            {
               _PrintCurrencyLine(Currency);
            }

        }
    }
};

