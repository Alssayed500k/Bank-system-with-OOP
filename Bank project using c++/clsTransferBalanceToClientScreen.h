#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsString.h"
using namespace std;

class clsTransferBalanceToClientScreen:protected clsScreen
{
private:
	static double _ReadTransferAmount()
	{
		cout << "\nEnter transfer amount:";
		return clsInputValidate::ReadNumber<double>();
	}
	static string _ReadAccountNumber(string Message = "")
	{
		string AccountNumber;
		cout << "\n"+Message;
		cin >> AccountNumber;

		while (!clsBankClient::IsExistsClient(AccountNumber))
		{
			cout << "\nClient Not found,Enter exists client acount number:";
			cin>>AccountNumber;
		}

		return AccountNumber;
	}
	static void _Print(clsBankClient Client)
	{
		cout << "\n" << setw(52) << right << "Client Card";
		cout << "\n" << setw(58) << right << "__________________\n";
		cout << "\n" << setw(56) << right << "First name     : " << Client.getFirstName();
		cout << "\n" << setw(56) << right << "Last name      : " << Client.getLastName();
		cout << "\n" << setw(56) << right << "Full name      : " << Client.getFirstName() + " " + Client.getLastName();
		cout << "\n" << setw(56) << right << "Email          : " << Client.getEmail();
		cout << "\n" << setw(56) << right << "Phone          : " << Client.getPhone();
		cout << "\n" << setw(56) << right << "Account number : " << Client.getAccountNumber();
		cout << "\n" << setw(64) << right << "Password       : ********";
		cout << "\n" << setw(56) << right << "Account balance: " << Client.getAccountBalance();

		cout << "\n" << setw(58) << right << "__________________\n";
	}
public:
	static void ShowTransferToClientScreen()
	{
		string Title = "Transfer Between Clients Screen";
		_DrawMainScreenHeader(Title);

		//Client 1

		string AccountNumber = _ReadAccountNumber("Please enter a account number :");
		clsBankClient SourceClient = clsBankClient::Find(AccountNumber);
		_Print(SourceClient);

		double TransferAmount = _ReadTransferAmount();
		while (TransferAmount > SourceClient.getAccountBalance() )
		{
			cout << "\nFailed!,Insufficient balance.Withdrawal amount exceeds your availiable balance:";
			cout << SourceClient.getAccountBalance();
			TransferAmount = _ReadTransferAmount();
		}
		
		//Destination Client
		cout << "\nPlease enter Recipient account number:";
	    AccountNumber = _ReadAccountNumber();
		while (SourceClient.getAccountNumber() == AccountNumber)
		{
			//Not allow a user tranferred himself
			cout << "\nThis transaction not allowed enter another one:";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient DestinationClient = clsBankClient::Find(AccountNumber);
		_Print(DestinationClient);

		//Performation Transfer operation
		char Confirm = 'y';
		cout << "Are you sure you want to perform this transactions y/n? ";
		cin >> Confirm;

		if (Confirm == 'Y' || Confirm == 'y')
		{
			cout << "\nPlease enter transformer client password to confirm this transaction: ";
			string SourcClientPassword;
			SourcClientPassword = clsString::ReadString();

			while (SourceClient.getPinCode() != SourcClientPassword)
			{
				
				cout << "\nFailed trasnsaction!,Wrong password";
				cout << " try again:";
				SourcClientPassword = clsString::ReadString();
			}
			SourceClient.TransferToClient(DestinationClient, TransferAmount);
			_Print(SourceClient);
			_Print(DestinationClient);
			cout << "\nDone,transaction successfully:-)";
			return;
		}
		cout << "\nTransaction cancelled..";

	}


};

