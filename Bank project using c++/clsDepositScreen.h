#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsDepositScreen : protected clsScreen
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
	static void DepositScreen()
	{
		_DrawMainScreenHeader("\tDeposit Screen");

		string AccountNumber;
		cout << "\nEnter client account number: ";
		AccountNumber = clsString::ReadString();

		while (!clsBankClient::IsExistsClient(AccountNumber))
		{
			cout << "\nClient not found! Enter another one :";
			AccountNumber = clsString::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		double DepositAmount = 0;
		cout << "\nEnter deposit amount:";
		DepositAmount = clsInputValidate::ReadNumber<double>();

		char Confirm = 'y';
		cout << "\nAre you sure to perform this transaction ? y/n\n";
		cin >> Confirm;

		if (Confirm == 'y' || Confirm == 'Y')
		{
			Client.Deposit(DepositAmount);
			cout << "\nDone,Depositted successfully:-)";
			cout << "\nNew balance : " << Client.getAccountBalance();
			return;
		}
		cout << "\nDeposite Operation cancelled";

	}

};

