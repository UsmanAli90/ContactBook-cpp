#include<iostream>
#include<string>
#include<iomanip>
#include"ContactsBook.h"
#include"Address.h"
#include"Contact.h"
#include"historyobject.h"
int main()
{
	std::string choice;
	bool flag = true;
	ContactsBook* contactBook;
	contactBook = new ContactsBook(1);
	std::cout <<std::setw(70) << "Welcome to Contackbooks in C++" << std::endl;
	std::cout << std::endl;
	while (flag) {
		std::cout << "Press 1 to create list of contacts" << std::endl;
		std::cout << "Press 2 to add new contact" << std::endl;
		std::cout << "Press 3 to merge and duplicate contact" << std::endl;
		std::cout << "Press 4 to store contact in a file" << std::endl;
		std::cout << "Press 5 to load contact from file" << std::endl;
		std::cout << "Press 6 to print sorted contact" << std::endl;
		std::cout << "Press 7 to print non-sorted contact" << std::endl;
		std::cout << "Press 8 to display count of contacts created till now" << std::endl;
		std::cout << "Press 9 to do Advance search" << std::endl;
		std::cout << "Press 10 to display search history" << std::endl;
		std::cout << "Press 11 to display frequently searched contacts" << std::endl;
		std::cout << "Press 12 to add contact in a group" << std::endl;
		std::cout << "Press 13 to delete a specific wcontact from a Group" << std::endl;
		std::cout << "Press 14 to delete a whole Group" << std::endl;
		std::cin >> choice;
		if (choice == "1")
		{
			system("cls");
			std::cout << "Enter the size of array to store contacts:";
			int size = 0;
			std::cin >> size;
			contactBook = new ContactsBook(size);
		}
		else if (choice == "2")
		{
			system("cls");
			input(*contactBook);
		}
		else if (choice == "3")
		{
			system("cls");
			contactBook->MergeDuplicates();
		}
		else if (choice == "4")
		{
			system("cls");
			contactBook->SaveToFile("Store");
		}
		else if (choice == "5")
		{
			system("cls");
			contactBook->LoadFromFile("Store");
		}
		else if (choice == "6")
		{
			system("cls");
			std::string ch;
			std::cout << "ENter first name or last name :";
			std::cin >> ch;
			contactBook->PrintContacts_sorted(ch);
		}
		else if (choice == "7")
		{
			system("cls");
			contactBook->PrintContact();
		}
		else if (choice == "8")
		{
			system("cls");
			contactBook->TotalContacts();
		}
		else if (choice == "9") {
			system("cls");
			contactBook->AdvanceSearch();
			
		}
		else if (choice == "10") {
			system("cls");
			std::cout << "Enter first name and last name" << std::endl;
			std::string fn, ln;
			std::cin >> fn;
			std::cin >> ln;
			contactBook->DisplayHistoryOld(fn, ln);
			contactBook->DisplayHistory();
			
		}
		else if (choice == "11") {
			system("cls");
			contactBook->FreqSearched();
		}
		else if (choice == "12") {
			system("cls");
			contactBook->AddintoGroup();
		}
		else if (choice == "13"){
			system("cls");
			contactBook->DelGroupContact();
		}
		else if (choice == "14") {
			system("cls");
			contactBook->DelAGroup();
		}
		else
			exit(0);
	}

}