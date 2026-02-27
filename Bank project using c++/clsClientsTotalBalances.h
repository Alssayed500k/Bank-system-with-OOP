#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"
class clsClientsTotalBalances :protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << left << setw(25) << Client.getAccountNumber();
		cout << "| " << left << setw(40) << Client.getFirstName() + " " + Client.getLastName();
		cout << "| " << left << setw(12) << Client.getAccountBalance();
		cout << "\n";

	}
public:
	static void ShowClientsTotalbalances()
	{
		vector<clsBankClient>  vClients = clsBankClient::GetClientsList();
		string Title = "\tTotal balances Screen";
		string SupTitle = to_string(vClients.size()) + " Client(s)";

		_DrawMainScreenHeader(Title , "\t"+SupTitle);

        cout << "\n_________________________________________________________";
        cout << "__________________________________________\n";

        cout << "| " << left << setw(25) << "Account Number";
        cout << "| " << left << setw(40) << "client Name";
        cout << "| " << left << setw(37) << "Balance";
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

		double Totalbalances = clsBankClient::GetClientsTotalBalances();
		cout <<"\n"<<setw(66) << right << "Clients Total Balances : " << Totalbalances;
        cout << "\n" << setw(101) << right << "(" + clsUtil::NumberToText(Totalbalances) + ")";
	}
};

