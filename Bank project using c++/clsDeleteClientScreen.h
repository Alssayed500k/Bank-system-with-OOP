#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
class clsDeleteClientscreen :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\n" << setw(52) << right << "Client Card";
		cout << "\n" << setw(58) << right << "__________________\n";
		cout << "\n"<<  setw(56) << right << "First name     : " << Client.getFirstName();
		cout << "\n" << setw(56) << right << "Last name      : "      << Client.getLastName();
		cout << "\n" << setw(56) << right << "Full name      : " << Client.getFirstName() + " " + Client.getLastName();
		cout << "\n" << setw(56) << right << "Email          : " << Client.getEmail();
		cout << "\n" << setw(56) << right << "Phone          : " << Client.getPhone();
		cout << "\n" << setw(56) << right << "Account number : " << Client.getAccountNumber();
		cout << "\n" << setw(56) << right << "Password       : " << Client.getPinCode() ;
		cout << "\n" << setw(56) << right << "Account balance: " << Client.getAccountBalance();

		cout << "\n" << setw(58) << right << "__________________\n";
	}

public:
    static void DeleteClientscreen()
    {
        if (!_CheckIsAccessRight(clsUser::bDleteclient))
        {
            return;// do nothing exit from  this the fun..
        }

        string Title = "\tDelete Client";
        _DrawMainScreenHeader(Title);

        cout<<setw(76)<<right<<"Please enter client number account :";
        string AccountNumber = clsString::ReadString();

        while (!clsBankClient::IsExistsClient(AccountNumber))
        {
            cout << "\n" << setw(79) << right << "Client not found!, Enter another one : ";
            AccountNumber = clsString::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        char DeleteConfirm = 'y';
        _Print(Client1);
        cout << "\n"<<setw(90)<<right<<"Are you sure you want to delete this the client y/n ? ";
        cin >> DeleteConfirm;

        if (DeleteConfirm == 'Y' || DeleteConfirm == 'y')
        {

            if (Client1.Delete())
            {
                cout << "\n"<<setw(62)<<right<<"Done,delete successfully";
                _Print(Client1);
            }
            else
            {
                cout << "\n" << setw(76) << right << "Failed!delete not successed";
            }
            return;
        }
        cout << "\n" << setw(56) << right << "Delete cancelled..";

    }

};



