#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:

	template <typename T> static T IsNumberBetween(T Number, T From, T To)
	{
		return Number >= From && Number <= To;

	}


	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{

		//Date >=From && Date <=To
		if (
			clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			&&
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)

			)
			return true;

		//Date>=To && Date <=from
		if (
			clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)
			&&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)
			)
			return true;


		return false;

	}
	template <typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range! ")
	{
		T Number;
		cin >> Number;

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage << From << " and " << To << ":";
			cin >> Number;
		}
		return Number;
	}
	template <typename T> static T ReadNumber(string ErrorMessage = "Invalid input, Enter again:\n")
	{
		T Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//ignore all string..

			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

