#pragma once
#include<iostream>

#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsString.h"

using namespace std;

class clsFindClientScreen :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card";
		cout << "\n__________________\n";

		cout << "\nFirst name     : " << Client.getFirstName();
		cout << "\nLast name      : " << Client.getLastName();
		cout << "\nFull name      : " << Client.getFirstName() + " " + Client.getLastName();
		cout << "\nEmail          : " << Client.getEmail();
		cout << "\nPhone          : " << Client.getPhone();
		cout << "\nAccount number : " << Client.getAccountNumber();
		cout << "\nPassword       : " << Client.getPinCode();
		cout << "\nAccount balance: " << Client.getAccountBalance();

		cout << "\n__________________\n";
	}

public:
	static void FindClient()
	{
		if (!_CheckIsAccessRight(clsUser::bFindClient))
		{
			return;// do nothing exit from  this the fun..
		}
		_DrawMainScreenHeader("\tFind Client Screen");

		string AccountNumber;
		cout << "\nEnter Client account number to search : ";
		AccountNumber = clsString::ReadString();

		while (!clsBankClient::IsExistsClient(AccountNumber))
		{
			cout << "\nClient Not Found! enter another one:";
			AccountNumber = clsString::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);

		return;
	}

};
