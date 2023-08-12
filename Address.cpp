#include "Address.h"
Address::Address(std::string house, std::string street, std::string city, std::string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}

void Address::SetHouse(std::string house)
{
	this->house = house;
}

void Address::SetStreet(std::string street)
{
	this->street = street;
}

void Address::SetCity(std::string city)
{
	this->city = city;
}

void Address::SetCountry(std::string country) {
	this->country = country;
}

std::string Address::GetHouse()
{
	return house;
}

std::string Address::GetStreet()
{
	return street;
}

std::string  Address::GetCity()
{
	return city;
}

std::string Address::GetCountry()
{
	return country;
}


bool Address::Equals(const Address& address)
{
	if (this->house == address.house && this->street == address.street && this->city == address.city && this->country == address.country)
	{
		return true;
	}

	return false;
}

void Address::print_address()
{
	std::cout << house;
	std::cout << street;
	std::cout << city;
	std::cout << country;
}

Address* Address::copy_address()
{
	Address* obj;
	obj = new Address;
	obj->house = this->house;
	obj->street = this->street;
	obj->city = this->city;
	obj->country = this->country;
	return obj;
}
Address::Address() {}