#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include<fstream>
#include"clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:

	enum enMode { ModeUpdate = 1, ModeEmpty = 2, ModeAddNew = 3 };
	enMode _eMode;
	string _UserID;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;
	struct  stLoginRecord;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUser = clsString::Split(Line, Seperator);
		//Handle error in case the code crashed
		if (vUser.size() !=7)
		{
			return _GetEmptyObject();
		}
		return  clsUser(enMode::ModeUpdate,
			vUser[0],//FirstName
			vUser[1],//LastName
			vUser[2],//Phone
			vUser[3],//Email
			vUser[4],//User name
			clsUtil::DecryptText(vUser[5]),//Decrypt the password
			
		    stoi(vUser[6]));//Permissions
	}
	static string _ConvertUserDataToLine(clsUser User,string Seperator = "#//#")
	{
		return User.getFirstName() + Seperator + User.getLastName() + Seperator +
			User.getPhone() + Seperator + User.getEmail() + Seperator + User.getUserID() +
			//When you store user passwords in file or datebase it's better to encrypt them.
			Seperator +clsUtil::EncryptText( User.getUserPassword())+ Seperator
			+ to_string(User.getUserPermissions());
	}
	static vector<clsUser>_LoadUsersFromFile(string FileName = "Users.txt")
	{
		vector<clsUser>_vUsers;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//read mode
        
		if (MyFile.is_open())
		{
			string Line = "";
			
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				_vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _vUsers;


	}
	static clsUser _GetEmptyObject()
	{
		return clsUser(
			enMode::ModeEmpty, "", "", "", "", "", "", 0
			);
	}
	
	 static bool _SaveUserDataToFile(clsUser User, string FileName ="Users.txt")
	{
		fstream MyFile;
		MyFile.open(FileName, ios::app);
		if (MyFile.is_open())
		{
			MyFile << _ConvertUserDataToLine(User)<<endl;
			MyFile.close();
			return true;
		}
		return false;


	}
	 bool static _saveUsersDataToFile(vector<clsUser> vUsers, string FileName ="Users.txt")
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);//mode overwrite
		if (MyFile.is_open())
		{
			for (clsUser& User : vUsers)
			{
				if (!User._MarkForDelete)
				{
					MyFile << _ConvertUserDataToLine(User)<<endl;
				}
				
			}
			MyFile.close();
			return true;
		}
		return false;
	}
	bool _Update()
	{
		vector<clsUser>vUsers;
		vUsers = _LoadUsersFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.getUserID() == this->_UserID)
			{
				User = *this;
				break;
			}
		}
		_saveUsersDataToFile(vUsers);//Save User data in datebase
		return true;
	}
	bool _Add()
	{
		this->_eMode = enMode::ModeAddNew;
		_SaveUserDataToFile(*this);
		return true;

	}

	//private Section Users  Login Time
	string _PrePareLoginTime(string Seperator = "#//#")
	{
		string DateTime = clsDate::DateTimeToString();
		string LoginRecordTime;

		LoginRecordTime = this->getUserID() + Seperator;
		//When you store user passwords in file or datebase it's better to encrypt them.
		LoginRecordTime += clsUtil::EncryptText (this->getUserPassword() )+ Seperator;
		LoginRecordTime += to_string(this->getUserPermissions()) + Seperator;
		LoginRecordTime += DateTime;
		return	LoginRecordTime;

	}
	static stLoginRecord _stGetEmptyRecord()
	{
		stLoginRecord LoginRecord;
		LoginRecord.DateTime = "";
		LoginRecord.UserName = "";
		LoginRecord.Password = "";
		LoginRecord.Permissions = 0;
		return LoginRecord;
	} 
	static stLoginRecord _ConvertLineLoginTimeToRecord(string Line , string Seperator="#//#")
	{
		stLoginRecord LoginRecord;
		vector<string>vUserLoginTime = clsString::Split(Line, Seperator);

		
		if (vUserLoginTime.size() !=4)
			return _stGetEmptyRecord();

		LoginRecord.UserName = vUserLoginTime[0];//UserID
		LoginRecord.Password =clsUtil::DecryptText( vUserLoginTime[1]);//password
		LoginRecord.Permissions = stoi(vUserLoginTime[2]);//Permissions
		LoginRecord.DateTime = vUserLoginTime[3];//Date and time
		return LoginRecord;
	}

public:
	
	clsUser(enMode eMode , string FirstName, string LastName, string Phone, string Email, string UserID,
		   string Password, int Permissions) :clsPerson(FirstName, LastName, Phone, Email)
	{
		_eMode = eMode;
	    _UserID = UserID;
		_Password = Password;
		_Permissions = Permissions;
	}

	void setUserID(string UserID)
	{
		_UserID = UserID;
	}
	string getUserID()
	{
		return _UserID;
	}
	_declspec(property (get = getUserID, put = setUserID)) string UserID;

	void setUserPassword(string Password)
	{
		_Password = Password;
	}
	string getUserPassword()
	{
		return _Password;
	}
	_declspec(property (get = getUserPassword, put = setUserPassword)) string UserPassword;

	void setUserPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int getUserPermissions()
	{
		return _Permissions;
	}

	_declspec(property (get = getUserPermissions, put = setUserPermissions)) int UserPermissions;
	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersFromFile();
	}
	static clsUser Find(string UserID)
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersFromFile();
		for (clsUser _User : _vUsers)
		{
			if (_User.getUserID() == UserID)
			{
				return _User;
			}
		}
		return _GetEmptyObject();
	}
	static clsUser Find(string UserName , string Password)
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersFromFile();
		for (clsUser _User : _vUsers)
		{

			if (_User.getUserID() == UserName && _User.getUserPassword()==Password )
			{
				return _User;
			}
		}
		return _GetEmptyObject();
	}
	static clsUser _GetAddNewObject(string UserID)
	{
		return clsUser(enMode::ModeAddNew, "", "", "", "", UserID, "", 0);
	}
	enum enSaveResults {
		FailedSaveEmptyObject = 1,
		FailedSaveExsitsObject = 2,
		SccessSave = 3
	};
	//Representation Main menu options in binary..
	enum enbMainMenueOptions {
		bShowClientsList = 1,
		bAddClient = 2,
		bDleteclient = 4,
		bUpdateClient = 8,
		bFindClient = 16,
		bMenuTransactions = 32,
		bManageUsers = 64,
		bLoginRegister=128,
	
	};
	bool Delete()
	{
		vector<clsUser> vUsers;
		vUsers = _LoadUsersFromFile();
		for (clsUser& User : vUsers)
		{

			if (User.getUserID() == this->UserID)
			{
				if (clsString::LowerAllString(UserID) == "admin")
					break;//Not allow to delete a admin
				
				User._MarkForDelete = true;
				_saveUsersDataToFile(vUsers);
				*this = _GetEmptyObject();
				return true;
			}
		}
		return false;
	}
	void SaveUserLoginTime(string FileName = "UsersLogin.txt", string Seperator = "#//#")
	{
		fstream Myfile;
		Myfile.open(FileName, ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << _PrePareLoginTime() << endl;
		}
		Myfile.close();
	}
	bool IsAllowedAccess(enbMainMenueOptions Permission)
	{
		//-1 Means full acess on this the application
		if (this->getUserPermissions() == -1)
			return true;//full access

			

		if ( (Permission & this->getUserPermissions())==Permission)
			return true;//Access limit
		else 
		   return false;//Access Denied
		
		


	}
	enSaveResults Save()
	{
		switch (_eMode)
		{
		case enMode::ModeEmpty:
		{
			return enSaveResults::FailedSaveEmptyObject;
		}

		case enMode::ModeUpdate:
		{
			_Update();
			return enSaveResults::SccessSave;
		}
		case enMode::ModeAddNew:
		{
			if (clsUser::IsUserExsits(_UserID))
			{
				return enSaveResults::FailedSaveExsitsObject;
			}
			else
			{
				_eMode = enMode::ModeUpdate;
				_Add();
				return enSaveResults::SccessSave;
			}
		}
		}

	}
	 bool IsEmptyObject()
	{
		return (_eMode == enMode::ModeEmpty);
	}
	static bool IsUserExsits(string UserName)
	{
		clsUser CurrentUser = Find(UserName);
		return (!CurrentUser.IsEmptyObject());
	}

	//public Users  Login Time Section
	static struct stLoginRecord
	{
		string UserName;
		string Password;
		int Permissions;
		string DateTime;

	};
	static vector<stLoginRecord>vLoadUsersLoginTimeFromFile(string FileName = "UsersLogin.txt")
	{
		vector<stLoginRecord> vLoginRecords;
		fstream Myfile;

		Myfile.open(FileName, ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				vLoginRecords.push_back(_ConvertLineLoginTimeToRecord(Line));
			}
		}
		Myfile.close();
		return vLoginRecords;
	}
	
	
	static void EncryptAllUsersPassword()
	{
		vector<clsUser> vUsers = _LoadUsersFromFile();
		for (clsUser& User : vUsers)
		{
			string EncryptedPassword = User.getUserPassword();
			User.setUserPassword(clsUtil::EncryptText(EncryptedPassword));
		}
		_saveUsersDataToFile(vUsers);


	}
};

