#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsFindCurrency : protected clsScreen
{
private:
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency card";
		cout << "\n__________________\n";

		cout << "\nCountry        : " <<Currency.Country();
		cout << "\nCurrency Code  : " << Currency.CurrencyCode();
		cout << "\nCurrency Name  : " << Currency.CurrencyName();
		cout << "\nRate($)        : " << Currency.Rate();

		cout << "\n__________________\n";
	}
	enum enFindBy{ ByCountry = 1,ByCode=2 };
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmptyObject())
		{
			cout << "\nCurrency found (-:";
			_Print(Currency);

		}
		else
		{
			cout << "\nCurrency Not found )-:";
		}
	}

public:
	static void FindCurrencyScreen()
	{
		_DrawMainScreenHeader("Find Currency Scrren");
        
		short FindType = 1;
		cout << "\nFind by [1] Country or [2] Code?";
		FindType = clsInputValidate::ReadNumberBetween(1, 2);

		if (FindType == enFindBy::ByCode)
		{
			cout << "\nPlease enter currency code to find:";
			string CurrencyCode = clsString::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			cout << "\nPlease enter  a country to find its currency:";
			string CurrencyCountry = clsString::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyByCountry(CurrencyCountry);
			_ShowResult(Currency);
			return;
		}

	}
};

