#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	bool Equals(const Address& address);
	void print_address();
	Address(std::string house, std::string street, std::string city, std::string country);
	void SetHouse(std::string house);
	void SetStreet(std::string street);
	void SetCity(std::string city);
	void SetCountry(std::string country);
	std::string GetHouse();
	std::string GetStreet();
	std::string  GetCity();
	std::string GetCountry();
	Address* copy_address();
	Address();
};
