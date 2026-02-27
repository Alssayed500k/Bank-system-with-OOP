#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsString.h"


using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
        cout << right << setw(57) << "Enter First name:";
		Client.setFirstName(clsString::ReadString());
        cout << right << setw(56) << "Enter Last name:";
		Client.setLastName(clsString::ReadString());
        cout << right << setw(52) << "Enter Email:";
		Client.setEmaile(clsString::ReadString());
        cout <<  right << setw(58) << "Enter Phone Numer:";
		Client.setPhone(clsString::ReadString());
        cout << right << setw(55) << "Enter Password:";
		Client.setPinCode(clsString::ReadString());
        cout << right << setw(54) << "Enter Balance:";
		Client.setAccountBalance(clsInputValidate::ReadNumber<double>());

    }

    static void _Print(clsBankClient Client)
    {
        cout << "\n" <<setw(52) << right << "Client Card";
        cout << "\n" << setw(58) << right << "__________________\n";
        cout << "\n" << setw(56) << right << "First name     : " << Client.getFirstName();
        cout << "\n" << setw(56) << right << "Last name      : " << Client.getLastName();
        cout << "\n" << setw(56) << right << "Full name      : " << Client.getFirstName() + " " + Client.getLastName();
        cout << "\n" << setw(56) << right << "Email          : " << Client.getEmail();
        cout << "\n" << setw(56) << right << "Phone          : " << Client.getPhone();
        cout << "\n" << setw(56) << right << "Account number : " << Client.getAccountNumber();
        cout << "\n" << setw(56) << right << "Password       : " << Client.getPinCode();
        cout << "\n" << setw(56) << right << "Account balance: " << Client.getAccountBalance();

        cout << "\n" << setw(58) << right << "__________________\n";
    }

public:
	static void AddNewClient()
    {
        if (!_CheckIsAccessRight(clsUser::bAddClient) )
        {
            return;// do nothing exit from  this the fun..
        }

        string Title = "Add New Client ";
        _DrawMainScreenHeader(Title);

        cout<< right << setw(71) << "Please Enter  account number : ";
        string AccountNumber = clsString::ReadString();

        while (clsBankClient::IsExistsClient(AccountNumber))
        {
            cout << "\t\t\t\t\tThe number has already been used,Enter another one:";
            AccountNumber = clsString::ReadString();
        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResults;
        SaveResults = Client.Save();

        switch (SaveResults)
        {

        case clsBankClient::enSaveResults::savSuccessed:
            
            cout << "\n\t\t\t\t\tClient added successfully:-)\n";
            _Print(Client);
            break;

        case  clsBankClient::enSaveResults::savFaildEmptyObject:
            system("cls");//clear consel.
            cout << "\n\t\tFailed! Client not added  becase it's empty :-(";
            break;

        case clsBankClient::enSaveResults::savFaildNumberIsExsits:
            cout << "\n\t\tFalid! account number is exsits :-(";
            break;


        }




    }


};

