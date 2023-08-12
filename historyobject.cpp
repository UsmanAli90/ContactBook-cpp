#include"historyobject.h"
#include<iostream>
#include"ContactsBook.h"
#include"Contact.h"
void historyobject::RecordHistory(std::string data_n, std::string date_n) {
	data = data_n;
	date = date_n;
}