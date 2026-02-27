#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include"clsString.h"
#include"clsPerson.h"

using namespace std;
class clsBankClient :public clsPerson 
{
private:
	enum enMode { EmptyObject = 0, UpdateObject = 1 , AddNew=2 };
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance = 0;
	enMode _Mode;
	bool   _MarkForDelete = false;
	
	
	static clsBankClient _ConvertLineToClientObject(string Line , string Seperator ="#//#")
	{
		vector <string> vClient = clsString::Split(Line, Seperator);

		return  clsBankClient(enMode::UpdateObject ,
			vClient[0],//FirstName
		    vClient[1],//LastName
			vClient[2],//Email
			vClient[3],//Phone
			vClient[4],//Account number
        	vClient[5],//Pincode
			stod(vClient[6]) );//AccountBalance
	}

	static clsBankClient _GetEmptyObject()
	{
		return clsBankClient(enMode::EmptyObject, "", "", "", "", "", "", 0);
	}

    static string _ConvertObjectToLine(clsBankClient Client ,string  Seperator="#//#")
	{
		string ClientData = "";
		ClientData += Client.FirstName + Seperator;
		ClientData += Client.LastName  + Seperator; 
		ClientData += Client.Email     + Seperator;
		ClientData += Client.Phone     + Seperator; 
		ClientData += Client._AccountNumber + Seperator;
		ClientData += Client._PinCode  + Seperator;
		ClientData += to_string(Client._AccountBalance);
		return ClientData;

	}

	static vector < clsBankClient> _LoadClientDataFromFile(string FileName = "Clients.txt", string Seperator = "#//#")
	{
		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		string Line = "";

		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				vClients.push_back(_ConvertLineToClientObject(Line));
			}
			MyFile.close();
		}
		return vClients;
		
	}

	static void _SaveClientsDateToFile(vector<clsBankClient> vClients , string Seperator = "#//#")
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out);//Mode Overrwite
		
		if (Myfile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.IsMarkForDelete() == false)
				{
					//we write that is not marked for delete only..
					Myfile << _ConvertObjectToLine(C) << endl;
				}
				
			}
			Myfile.close();
		}

	}

	void _SaveClientDateLineToFile(string ClientLiene , string NameFile="Clients.txt")
	{
		fstream Myfile;
		Myfile.open(NameFile, ios::app);

		if (Myfile.is_open())
		{
			
			Myfile << ClientLiene <<endl;
		}
		Myfile.close();
	}

	void _Update()
		{
			vector<clsBankClient>_vClients;
			_vClients = _LoadClientDataFromFile();

			for (clsBankClient& C : _vClients)
			{
				if (C.AccountNumber == this->AccountNumber)
				{
					C = *this;
					break;
				}
			}
			_SaveClientsDateToFile(_vClients);

		}

	void _Add()
	{

		_SaveClientDateLineToFile(_ConvertObjectToLine(*this));
	}
	
	//*****************Private Transfer log section******************//
	string _PrePareTransferlogLine(clsBankClient DClient, double Amount , clsUser UserName, string Seperator = "#//#")
	{
		string TransferLogLine;
		TransferLogLine = clsDate::DateTimeToString() + Seperator;
		TransferLogLine += this->_AccountNumber + Seperator;
		TransferLogLine += DClient.getAccountNumber()+Seperator;
		TransferLogLine += to_string(Amount) +Seperator;
		TransferLogLine += to_string(this->_AccountBalance ) + Seperator;
		TransferLogLine += to_string(DClient.getAccountBalance())+Seperator;
		TransferLogLine += UserName.getUserID();

		return TransferLogLine;
	}
	

public:

	clsBankClient( enMode Mode  ,string FirstName, string LastName, string Email,
    string Phone,string AccountNumber, string PinCode, double AccountBalance) :
	clsPerson(FirstName, LastName, Phone, Email)
	{
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;
	}

	void setAccountNumber(string AccountNumber)
	{
		_AccountNumber= AccountNumber;
	}
	string getAccountNumber()
	{
		return _AccountNumber;
	}
	_declspec(property (get = getAccountNumber, put = setAccountNumber)) string AccountNumber;

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}
	_declspec(property (get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(double Balance)
	{
		_AccountBalance = Balance;
	}
	double getAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property (get = getAccountBalance, put = setAccountBalance)) double AccountBalance;
	//the method dosen't related layer bisuiness logic ,
	//it is better to move it to layer UI..
	/*void Print()
	{
		cout << "\nClient Card";
		cout << "\n__________________\n";

		cout << "\nFirst name     : "     << FirstName;
		cout << "\nLast name      : "     << LastName;
		cout << "\nFull name      : "     << FirstName + " " + LastName;
		cout << "\nEmail          : "     << Email;
		cout << "\nPhone          : "     << Phone;
		cout << "\nAccount number : "     << _AccountNumber;
		cout << "\nPassword       : "     << _PinCode;
		cout << "\nAccount balance: "     << _AccountBalance;

		cout << "\n__________________\n";
	}*/
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		
		MyFile.open("Clients.txt", ios::in);//Read Mode

		string Line = "";
		if (MyFile.is_open())
		{
			
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.getAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

		}
		return _GetEmptyObject();
	}
	//Overloading of method Find  client by account number and pincode.
	static clsBankClient Find(string AccountNumber , string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//ReadMode

		string Line = "";
		if (MyFile.is_open())
		{

			while (getline(MyFile, Line))
			{
				clsBankClient ClientBank = _ConvertLineToClientObject(Line);
				if (ClientBank.getAccountNumber() == AccountNumber && ClientBank.getPinCode() == PinCode)
				{
					MyFile.close();
					return ClientBank;
				}

			}

		}
		return _GetEmptyObject();
	}

    bool IsEmptyObject()
	{
		
		return _Mode == enMode::EmptyObject;
	}
   
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient (enMode::AddNew, "", "", "", "", AccountNumber, "", 0);

	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}
	bool IsMarkForDelete()
	{
		return this->_MarkForDelete;
	}

	bool Delete()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadClientDataFromFile();

		for (clsBankClient& Client : vClients)
		{
			if (Client._AccountNumber == this->_AccountNumber)
			{
				Client._MarkForDelete = true;
				_SaveClientsDateToFile(vClients);
				*this = _GetEmptyObject();
				return true;
			}
		}
		return false;
		
	}

	void Deposit(double Amount)
	{
		this->_AccountBalance += Amount;
		Save();

	}

	bool Withdraw(double WithdrawAmount)
	{
		if (WithdrawAmount > this->_AccountBalance  )
		{
			return false;//failed withdraw
		}
		else
		{
			this->_AccountBalance -= WithdrawAmount;
			Save();
			return true;
		}
	}
	
	bool TransferToClient( clsBankClient& DestinatioClient,double Amount , clsUser UserName=CurrentUser) 
	{
		if (this->_AccountBalance < Amount)
			return false;
		this->Withdraw(Amount);
		DestinatioClient.Deposit(Amount);
		RegisterTransferOperationLogInFile(DestinatioClient, Amount, UserName);
	}

   enum enSaveResults { savFaildEmptyObject = 0, savSuccessed = 1  , savFaildNumberIsExsits=2};
   enSaveResults Save()
   {
	   enSaveResults SaveResults;
	   switch (_Mode)
	   {
	   case enMode::EmptyObject:
		   return enSaveResults::savFaildEmptyObject;

	   case enMode::UpdateObject:
		   _Update();
		   return  enSaveResults::savSuccessed;

	   case enMode::AddNew:
		   if (IsExistsClient(_AccountNumber))
		   {
			   return enSaveResults::savFaildNumberIsExsits;
		   }
		   else
		   {
			   _Mode = enMode::UpdateObject;
			   _Add();
			   return enSaveResults::savSuccessed;
		   }
	   }
   }

   static double  GetClientsTotalBalances()
   {
	   double Balances = 0.0;
	   //Load all clients data from file or database..
	   vector <clsBankClient> vClients = clsBankClient::GetClientsList();
	   for (clsBankClient Client : vClients)
	   {
		   Balances += Client.getAccountBalance();
	   }
	   return Balances;
   }

   static bool IsExistsClient(string Accountnumber)
   {
	   clsBankClient Client = clsBankClient::Find(Accountnumber);

	   return (!Client.IsEmptyObject());
   }

   //*****************Public Transfer log section******************//
   struct stTransferLog
   {
	   string DateTime;
	   string AccountNumberFrom;
	   string AccountNumberTo;
	   double TransferAmount = 0;
	   double Account_1BalanceAfterTranfer = 0;
	   double Account_2BalanceAfterTranfer = 0;
	   string UserName;
   };
   static stTransferLog GetEmptyRecord()
   {
	   stTransferLog EmptyRecord;
	   EmptyRecord.AccountNumberFrom = "", 
	   EmptyRecord.AccountNumberTo = "",
	   EmptyRecord.TransferAmount = 0, 
	   EmptyRecord.Account_1BalanceAfterTranfer = 0,
	   EmptyRecord.Account_2BalanceAfterTranfer = 0,
	   EmptyRecord.UserName = "";
	   return EmptyRecord;
	       
   }
   static stTransferLog ConvertTransferLogLineToRecord(string Line,string Seperator = "#//#")
   {
	   vector<string>vTransferLog;
	   vTransferLog = clsString::Split(Line, Seperator);

	   if (vTransferLog.size() != 7)
		   return GetEmptyRecord();

	   stTransferLog TransferLog;
	   TransferLog.DateTime = vTransferLog[0];
	   TransferLog.AccountNumberFrom = vTransferLog[1];
	   TransferLog.AccountNumberTo = vTransferLog[2];
	   TransferLog.TransferAmount = stod(vTransferLog[3]);
	   TransferLog.Account_1BalanceAfterTranfer = stod(vTransferLog[4]);
	   TransferLog.Account_2BalanceAfterTranfer = stod(vTransferLog[5]);
	   TransferLog.UserName = vTransferLog[6];
	   return TransferLog;



   }
   void RegisterTransferOperationLogInFile(clsBankClient DesniationClient, double Amount ,clsUser UserName , string Seperator = "#//#")
   {
	   fstream MyFile;
	   MyFile.open("TransferLog.txt", ios::out | ios::app);
	   if (MyFile.is_open())
	   {
		   MyFile << _PrePareTransferlogLine(DesniationClient ,Amount ,UserName) << endl;

		   MyFile.close();
	   }
	   
   }
  static vector<stTransferLog>vGetTransferLogList()
   {
	   vector<stTransferLog>vTransferLogList;
	   string FileName = "TransferLog.txt";
	   fstream MyFile(FileName, ios::in);

	   if (MyFile.is_open())
	   {
		   string Line;
		   while (getline(MyFile, Line))
		   {
			   vTransferLogList.push_back(ConvertTransferLogLineToRecord(Line));
		   }
	   }
	   MyFile.close();
	   return vTransferLogList;

   }
};

