#pragma once
#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;

public:
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);

	Address* GetAddress();
	void set_address(Address* address);
	void SetFirstName(std::string first_name);
	void SetLastName(std::string last_name);
	void SetMobileNumber(std::string mobile_number);
	void SetEmailAdd(std::string email_address);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetMobileNumber();
	std::string GetEmailAddress();
	bool Equals(Contact& contact);
	Contact* CopyContact();
	Contact() {
		address = new Address;
	}

};
