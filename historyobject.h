#pragma once
#include<iostream>
class historyobject {
public:
	std::string data;
	std::string date;
	void RecordHistory(std::string data, std::string date);
	std::string freq[10];
	
};

