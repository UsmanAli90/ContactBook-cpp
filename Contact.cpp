#include "Contact.h"

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	this->address = address;
}


void Contact::SetFirstName(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::SetLastName(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::SetMobileNumber(std::string mobile_number)
{
	int x;
	x = mobile_number.length();
	if (x != 11)
	{
		std::cout << "Enter 11 digit number:" << std::endl;
		std::cin >> mobile_number;
		this->mobile_number = mobile_number;
	}
	else if (x == 11) {
		this->mobile_number = mobile_number;
	}
}

void Contact::set_address(Address* address){ 
	this->address = address; 
}

Address* Contact::GetAddress()
{
	return address;
}

void Contact::SetEmailAdd(std::string email_address)
{
	this->email_address = email_address;
}




std::string Contact::GetFirstName()
{
	return first_name;
}

std::string Contact::GetLastName()
{
	return last_name;
}

std::string Contact::GetMobileNumber()
{
	return mobile_number;
}

std::string Contact::GetEmailAddress()
{
	return email_address;
}

bool Contact::Equals(Contact& contact)
{
	if (first_name == contact.first_name && last_name == contact.last_name && mobile_number == contact.mobile_number && email_address == contact.email_address)
	{

		if (this->address->Equals(*contact.address))
		{
			return 1;
		}
	}
	return 0;
}

Contact* Contact::CopyContact()
{
	
	Contact* object;
	object = new Contact;
	object->first_name = this->first_name;
	object->last_name = this->last_name;
	object->mobile_number = this->mobile_number;
	object->email_address = this->email_address;
	object->address = address->copy_address();
	return object;

}

