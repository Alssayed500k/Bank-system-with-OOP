#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"

using namespace std;


class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency , string Title = "Currency card")
	{
		cout << Title;
		cout << "\n__________________\n";

		cout << "\nCountry        : " << Currency.Country();
		cout << "\nCurrency Code  : " << Currency.CurrencyCode();
		cout << "\nCurrency Name  : " << Currency.CurrencyName();
		cout << "\nRate(1$)        : " << Currency.Rate();

		cout << "\n__________________\n";
	}

	static clsCurrency _GetCurrency( string Message )
	{
		//Currency1
		cout << Message<<endl;
		string Currency1Code = clsString::ReadString();
		while (!clsCurrency::IsExsitsCurrency(Currency1Code))
		{
			cout << "\nCurrency Not found!Enter another one:";
			Currency1Code = clsString::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(Currency1Code);
		return Currency;
	}

	static float _ReadAmount(clsCurrency Currency)
	{
		float Amount;
		cout << "Please Enter Amount of " << Currency.CurrencyCode() << ":";
		return (float)clsInputValidate::ReadNumber<double>();
	}
	static void _PrintCalculationResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		float AmountInUSD = CurrencyFrom.ConvertCurrencyToUSD(Amount);
		_PrintCurrencyCard(CurrencyFrom, "Convert from:");
		cout<< Amount << " = " << AmountInUSD <<" USD"<<endl;
		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;//Exsit from fun
		}

		//Convert to other currency...
		AmountInUSD = CurrencyFrom.ConvertCurrencyToOtherCurrency(CurrencyTo , Amount);
		_PrintCurrencyCard(CurrencyTo, "Converting from Usd to:");
		cout  << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " " << CurrencyTo.CurrencyCode();


	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		_DrawMainScreenHeader("Currency Calculator Screen");

		char AnotherCalculation = 'y';

		while (AnotherCalculation == 'y' || AnotherCalculation == 'Y')
		{
			clsCurrency CurrencyFrom = _GetCurrency("Please enter currency1 code : ");
			clsCurrency CurrencyTo = _GetCurrency("Please enter currency2 code : ");
			float Amount = _ReadAmount(CurrencyFrom);
			
			_PrintCalculationResult(CurrencyFrom, CurrencyTo, Amount);
			
			cout << "\nDo you want to perform another calculation (Y-N)?";
			cin >> AnotherCalculation;
		}

		
		
	}

	

};

