#pragma once
#include "Address.h"
#include "Contact.h"
#include"historyobject.h"
#include"Groups.h"
#include<ctime>
#include<time.h>
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB


class ContactsBook {
private:
	Contact* contacts_list; 
	int size_of_contacts;   
	int contacts_count;     

public:
	friend void input(ContactsBook& ref);
	void AddContact(Contact& contact);
	int TotalContacts();
	int id;

	//Contact* search_contact(std::string first_name, std::string last_name);
	/*Contact* search_contact(std::string phone);
	Contact* search_contact(Address address);*/
	void PrintContact();
	void MergeDuplicates();
	ContactsBook(){}
	ContactsBook(int size_of_list);
	void PrintSpecificContact();
	void UpdateSpecificContact();
	void DelSpecificContact(int x);
	void PrintContacts_sorted(std::string choice); 
	void LoadFromFile(std::string file_name);
	void SaveToFile(std::string file_name);
	bool Compare(std::string choice, Contact& choice1, Contact& choice2);
	void swap(Contact* contacts_list, int i, int j);
	historyobject history[10];
	void DisplayHistoryOld(std::string fn, std::string ln);
	int index = 0;
	void DisplayHistory();
	void FreqSearched();
	void AdvanceSearch();
	void AddintoGroup();
	void DelGroupContact();
	void DelAGroup();
	Groups G1[3];
private:
	bool full();
	void ResizeList();
	void SortContactList(Contact* contacts_list, std::string choice);
	Contact* CopyContacts_list();
};
