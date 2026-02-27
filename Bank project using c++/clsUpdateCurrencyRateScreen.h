#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"string"
#include"clsScreen.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
	static string _ReadCurrencyCode()
	{
		string CurrencyCode;
		cout << "\nPlease Enter Currency code to update:";
		cin >> CurrencyCode;
	    clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		while (Currency.IsEmptyObject())
		{
			cout << "\nCurrency Not found! Enter another one:";
			cin >> CurrencyCode;
		}
		return CurrencyCode;
	}
	static void _Print(clsCurrency Currency)
	{
		cout << "\nCurrency card";
		cout << "\n__________________\n";

		cout << "\nCountry        : " << Currency.Country();
		cout << "\nCurrency Code  : " << Currency.CurrencyCode();
		cout << "\nCurrency Name  : " << Currency.CurrencyName();
		cout << "\nRate(1$)        : " << Currency.Rate();

		cout << "\n__________________\n";
	}
	static float _ReadNewRate()
	{
		
		cout << "\nplease enter new rate of currency to update : ";
		return clsInputValidate::ReadNumber<double>();
	}
public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawMainScreenHeader("Update currency screen");
		string CurrencyCode = _ReadCurrencyCode();
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(CurrencyCode);
		_Print(Currency);

		char UpdateConfirm = 'y';
		cout << "\nAre you sure you want to update this currency (Y-N)?";
		cin >> UpdateConfirm;

		if (tolower(UpdateConfirm) == 'y')
		{
			cout << "\nUpdate Currncy Rate";
			cout << "\n-----------------";
			float NewRate = _ReadNewRate();

			Currency.Update(NewRate);

			//update successfully
			cout << "\nThe currency rate updated sccessfully.";
			_Print(Currency);
			return;
		}
		else
			cout << "The update cancelled";
		


	}


};

