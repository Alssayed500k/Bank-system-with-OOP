#pragma once
#include"clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
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
	static void WithDrawScreen()
	{
		_DrawMainScreenHeader("\tWithDrawal Screen" , "\tEnter 0 to cancel withdraw");

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
		double WithdrawAmount = 0;
		cout << "\nEnter withdraw amount:";
		WithdrawAmount = clsInputValidate::ReadNumber<double>();

		
		while ( !Client.Withdraw(WithdrawAmount) )
		{
			cout << "\nWithdrawal failed!, withdrawal is great then Client balance:";
			cout << Client.getAccountBalance();
			cout << "\nEnter withdraw amount : ";
			WithdrawAmount = clsInputValidate::ReadNumber<double>();

			//in case the client has no a enaugh balance
			// once a user enter 0 the withdrawl stopping..
			if (WithdrawAmount == 0)
			{
				cout << "\nWithdrawal Operation cancelled";
				return;
			}
			
		}
		//in case the client has no a enaugh balance
			// once a user enter 0 the withdrawl stopping..
		if (WithdrawAmount == 0)
		{
			cout << "\nWithdrawal Operation cancelled";
			return;
		}

		char Confirm = 'y';
		cout << "\nAre you sure you want to perform this transaction ? y/n\n";
		cin >> Confirm;
		
		

		if (Confirm == 'y' || Confirm == 'Y')
		{
			cout << "\nDone,withdraw successfully:-)";
			cout << "\nNew balance : " << Client.getAccountBalance();
			return;
		}
		cout << "\nWithdrawal Operation cancelled";

	}
};

