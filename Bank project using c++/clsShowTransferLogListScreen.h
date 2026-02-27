#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>

using namespace std;

class clsShowTransferLogListScreen : protected clsScreen
{
private:
    static void _PrintTransferLogLine(clsBankClient::stTransferLog TransferLogLine)
    {
        cout << "| " << left << setw(20) << TransferLogLine.DateTime;
        cout << "| " << left << setw(12) << TransferLogLine.AccountNumberFrom;
        cout << "| " << left << setw(12) << TransferLogLine.AccountNumberTo;
        cout << "| " << left << setw(15) << TransferLogLine.TransferAmount;
        cout << "| " << left << setw(12) << TransferLogLine.Account_1BalanceAfterTranfer;
        cout << "| " << left << setw(12) << TransferLogLine.Account_2BalanceAfterTranfer;
        cout << "| " << left << setw(20) << TransferLogLine.UserName;
        cout << "\n";

    }

public:
    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLog> vTransferLogRecords = clsBankClient::vGetTransferLogList();

        string Title = "Transfer Log List Screen";
        string SupTitle = "(" + to_string(vTransferLogRecords.size()) + ")Record(s)";


        _DrawMainScreenHeader(Title, SupTitle);
        cout << "\n___________________________________________________________";
        cout << "_____________________________________________________________\n";

        cout << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(12) << "S.Acc";
        cout << "| " << left << setw(12) << "D.Acc";
        cout << "| " << left << setw(12) << "Transfer Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "D.Balance";
        cout << "| " << left << setw(20) << "User Name/ID";
        cout << "\n___________________________________________________________";
        cout << "_____________________________________________________________\n";

        if (vTransferLogRecords.size() == 0)
        {
            cout << "\n\n\t\t\t\t\tNo Transfer Log record available on the system!\n";
        }
        else
        {
            for (clsBankClient::stTransferLog TransferLog : vTransferLogRecords)
            {
                _PrintTransferLogLine(TransferLog);
            }

        }

        cout << "\n___________________________________________________________";
        cout << "_____________________________________________________________\n";

    }

};

