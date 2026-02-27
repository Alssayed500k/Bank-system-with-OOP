#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
using namespace std;

class clsClientsListScreen :protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(14) << Client.getAccountNumber();
        cout << "| " << left << setw(20) << Client.getFirstName() + " " + Client.getLastName();
        cout << "| " << left << setw(12) << Client.getPhone();
        cout << "| " << left << setw(20) << Client.getEmail();
        cout << "| " << left << setw(10) << Client.getPinCode();
        cout << "| " << left << setw(12) << Client.getAccountBalance();

        cout << "\n";

    }

public:
    static void ShowClientsList()
    {
        if (!_CheckIsAccessRight(clsUser::bShowClientsList))
        {
            return;// do nothing exit from  this the fun..
        }
        vector<clsBankClient> vClients;
        vClients = clsBankClient::GetClientsList();


        string Title = "Clients List screen";
        string SupTitle = "Clients List (" + to_string(vClients.size()) + ") Client(s).";

       
        _DrawMainScreenHeader(Title, SupTitle);
        cout << "\n_________________________________________________________";
        cout << "__________________________________________\n";

        cout << "| " << left << setw(7) << "Account Number";
        cout << "| " << left << setw(20) << "client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n________________________________________________________";
        cout << "___________________________________________\n";

        if (vClients.size() == 0)
        {
            cout << "\n\n\t\t\t\t\tNo Clients record available on the system!\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                _PrintClientRecordLine(Client);
            }

        }

        cout << "\n______________________________________________________________";
        cout << "_____________________________________\n";

    }
};

