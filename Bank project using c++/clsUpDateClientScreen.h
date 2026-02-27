#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsBankClient.h"

class clsUpDateClientScreen : clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		Client.setFirstName(clsString::ReadString("\nEnter First name : "));
		Client.setLastName(clsString::ReadString("Enter Last name : "));
		Client.setEmaile(clsString::ReadString("Enter Email : "));
		Client.setPhone(clsString::ReadString("Enter Phone Numer : "));
		Client.setPinCode(clsString::ReadString("Enter Password : "));
		cout << "Enter Balance : ";
		Client.setAccountBalance(clsInputValidate::ReadNumber<double>());

	}

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
	static void UpdateClientInfo()
	{
		if (!_CheckIsAccessRight(clsUser::bUpdateClient))
		{
			return;// do nothing exit from  this the fun..
		}
		//screen header..
		_DrawMainScreenHeader("\tClient update Screen");

		string AccountNumber = clsString::ReadString("please enter exists Account number : ");

		while (!clsBankClient::IsExistsClient(AccountNumber))
		{
			cout << "\nFalid! Client Not found,Enter exists account number : ";
			AccountNumber = clsString::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);//Creat object of client

		_Print(Client);
		char Confirm = 'y';
		cout << "\nAre you sure to update this client ? y/n\n";
		cin >> Confirm;
		if (Confirm == 'Y' || Confirm == 'y')
		{
			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResults;
			SaveResults = Client.Save();

			switch (SaveResults)
			{
			  case clsBankClient::enSaveResults::savSuccessed:
			  {
				  cout << "\n\nClient updated sucessfully:-)";
				  _Print(Client);
				  break;
			  }
			  case clsBankClient::enSaveResults::savFaildEmptyObject:
			  {
				  cout << "\n\nFalid! Client not updated becase empty object!";
				  _Print(Client);
				  break;
			  }


			}
			return;
		}
		
		   cout << "\nUpdated cancelled.....";
	}
};

