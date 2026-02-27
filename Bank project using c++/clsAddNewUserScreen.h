#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

using namespace std;

class clsAddNewUserScreen :protected clsScreen
{
private:
	static int _ReadUserPermissions()
	{
		int Permissions = 0;
		string MainMenuOptions[8] =
		{
		" Show Clients List ",
		" Add Client ",
		" Dlete Client ",
		" Update Client ",
		" Find Client ",
		" Transactions Menu ",
		" Manage Users ",
		" Login Register "
		};
		int MainMenuInBinary[8] = {
			clsUser::enbMainMenueOptions::bShowClientsList,
			clsUser::enbMainMenueOptions::bAddClient,
			clsUser::enbMainMenueOptions::bDleteclient,
			clsUser::enbMainMenueOptions::bUpdateClient,
			clsUser::enbMainMenueOptions::bFindClient,
			clsUser::enbMainMenueOptions::bMenuTransactions,
			clsUser::enbMainMenueOptions::bManageUsers,
			clsUser::enbMainMenueOptions::bLoginRegister,

		};

		char Choice = 'Y';
		cout <<"\nDo you want to give this the user full access [Y-N]?";
		cin >> Choice;
		if (tolower(Choice) == 'y')
		{
			return -1;
		}


		for (short i = 0; i < 8 ; i++)
		{

			cout << "Do you want give a user" + MainMenuOptions[i] + "Permissions y/n?";
			cin >> Choice;
			if (tolower(Choice) == 'y')
			{
				Permissions += MainMenuInBinary[i] ;
			}
		}
		return Permissions;
		

	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First name:";
		User.setFirstName(clsString::ReadString());
		cout << "Enter Last name:";
		User.setLastName(clsString::ReadString());
		cout << "Enter Email:";
		User.setEmaile(clsString::ReadString());
		cout << "Enter Phone Numer:";
		User.setPhone(clsString::ReadString());
		cout << "Enter Password:";
		User.setUserPassword(clsString::ReadString());
		cout << "Chosse User permissions:\n";
		User.setUserPermissions(_ReadUserPermissions());
	}
	static void _Print(clsUser User)
	{
		cout << "\n" << "User Data";
		cout << "\n" << "__________________\n";
		cout << "\n" << "First name     : " << User.getFirstName();
		cout << "\n" << "Last name      : " << User.getLastName();
		cout << "\n" << "Full name      : " << User.getFullName();
		cout << "\n" << "Email          : " << User.getEmail();
		cout << "\n" << "Phone          : " << User.getPhone();
		cout << "\n" << "User ID        : " << User.getUserID();
		cout << "\n" << "Password       : " << User.getUserPassword();
		if (User.getUserPermissions() == -2)
		{
			cout << "\n" << "User Permissins: Admin";
		}
		else
		{
			cout << "\n" << "User Permissins: " << User.getUserPermissions();
		}


		cout << "\n" << "__________________\n";
	}

public:
	static void ShowAddUserScreen()
	{
		string Title = "\tAdd User Screen";
		_DrawMainScreenHeader(Title);

		cout << "\nEnter new user ID number :";
		string UserID;
		cin >> UserID;

		while (clsUser::IsUserExsits(UserID))
		{
			cout << "\nthe User ID is already exsits.Enter a different ID: ";
			cin >> UserID;
		}
		cout << "\nAdd New User";
		cout << "\n---------------\n";
		clsUser User = clsUser::_GetAddNewObject(UserID);
		_ReadUserInfo(User);

		clsUser::enSaveResults Save;
		Save = User.Save();
		switch (Save)
		{
		  case clsUser::enSaveResults::SccessSave:
		  {
			  _Print(User);
			  cout << "\nThe user added successfully:-)";
			  break;
		  }
		  case clsUser::enSaveResults::FailedSaveEmptyObject:
		  {
			  _Print(User);
			  cout << "\nFailed! user Not added becase,empty object";
			  break;
		  }
		  case clsUser::enSaveResults::FailedSaveExsitsObject:
		  {
			  cout << "\nFailed! the user Not added becase,exists object";
			  break;
		  }
		}



		
	}
	

};

