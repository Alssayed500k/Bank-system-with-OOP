#pragma once
#include<iostream>
#include"Global.h"
#include"clsDate.h"

using namespace std;


class clsScreen
{
private:
	static void _DisPlayUserNameLoginDate()
	{
		cout << "\t\t\t\t\tUser:" << CurrentUser.getFullName();
		clsDate SystemDate;
		cout << "\n\t\t\t\t\tDate:";
		SystemDate.Print();
	}

  protected:

	static void _DrawMainScreenHeader(string Title , string SupTitle ="")
	{
		cout <<"\n\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t " << Title ; 
		 
		if (SupTitle != "")
		{
			cout << "\n\n\t\t\t\t\t " << SupTitle ; 
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		_DisPlayUserNameLoginDate();
	}
	
	static bool _CheckIsAccessRight(clsUser::enbMainMenueOptions Permission)
	{
		if (!CurrentUser.IsAllowedAccess(Permission))
		{
			cout << "\n\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t ";
			cout << "Access Denied,Contact your Admin";
			cout << "\n\n\t\t\t\t\t ";
			cout << "Email:anwr2021alssayed@gmail.com";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;

		}
		else
			return true;
		
	}
		
};

