#pragma once
#include <iostream>

using namespace std;
class clsPerson
{
private :
	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;

public:
	clsPerson(string FirstName, string LastName, string Phone, string Email)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	string getFirstName()
	{
		return _FirstName;
	}
	_declspec(property (get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName (string LastName)
	{
		_LastName = LastName;
	}
	string  getLastName()
	{
		return _LastName;
	}
	_declspec(property (get = getLastName, put = setLastName)) string LastName;

	string getFullName()
	{
		return _FirstName + " " + _LastName;
	}

	void setPhone(string Phone)
	{
		_Phone = Phone;
	}
	string getPhone()
	{
		return _Phone;
	}
	_declspec(property (get = getPhone, put = setPhone)) string Phone;

	void setEmaile(string Email)
	{
		_Email = Email;
	}
	string getEmail()
	{
		return _Email;
	}
	_declspec(property (get = getEmail, put = setEmaile)) string Email;
};

