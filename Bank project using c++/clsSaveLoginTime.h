#pragma once
#include<iostream>
#include"clsDate.h";
#include<fstream>
#include"clsUser.h"

using namespace std;

class clsSaveLoginTime
{
public:
	static bool SaveLoginTimeToFile(clsUser CurrentUser, string FileName = "FileLoginTime.txt" ,string Seperator="#//#")
	{ 
		string Date, Time;
		Date = clsDate::DateToString(clsDate());
		Time = clsDate::TimeToString(clsDate::GetSystemTime());
		fstream MyFile;
		MyFile.open(FileName, ios::app);//Write mode

		if (MyFile.is_open())
		{
			MyFile << CurrentUser.getUserID() + Seperator + to_string(CurrentUser.getUserPermissions()) +Seperator+Date+Seperator+Time<<endl;

		}
		MyFile.close();
		return true;

	}

};

