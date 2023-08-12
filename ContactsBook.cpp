#include "ContactsBook.h"
#include <fstream>
#include"historyobject.h"
#include"Groups.h"
#include<ctime>
#include<time.h>
void ContactsBook::AddContact(Contact& contact)
{
	if (full())
	{
		ResizeList();
		contacts_list[contacts_count] = contact;
		this->contacts_count++;
	}
	else
	{
		contacts_list[contacts_count] = contact;
		this->contacts_count++;

	}

}

int ContactsBook::TotalContacts()
{
	std::cout << "Total contacts are " << contacts_count << std::endl;
	
	return contacts_count;
}

bool ContactsBook::full()
{
	
	if (contacts_count == size_of_contacts)
		return true;
	else
		return false;
}

void ContactsBook::ResizeList()
{
	Contact* arr;
	arr = new Contact[size_of_contacts * 2];
	for (int i = 0; i < size_of_contacts; i++)
	{
		arr[i] = contacts_list[i];
	}
	delete[]contacts_list;
	contacts_list = new Contact[size_of_contacts * 2];
	for (int i = 0; i < size_of_contacts; i++)
	{
		contacts_list[i] = arr[i];
	}
	delete[]arr;


}

void ContactsBook::DisplayHistoryOld(std::string fn, std::string ln)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].GetFirstName() == fn && contacts_list[i].GetLastName() == ln) {
			time_t now = time(NULL);
			char date_time[26];
			ctime_s(date_time, sizeof date_time, &now);
			history[index].RecordHistory(fn, date_time);
			index++;
		}
			
	}
}


void ContactsBook::PrintContact() {
		for (int i = 0; i < contacts_count; i++)
		{
			std::cout <<"First name of contact is " << contacts_list[i].GetFirstName() << std::endl;

		}
		int choice = 0;
		std::cout << "Press 1 to know detail of specific contact"<<std::endl;
		std::cin >> choice;
		if (choice == 1){
			PrintSpecificContact();
		}
			
}

void ContactsBook::UpdateSpecificContact() {
	int choice;
	std::cout << "Enter index 1 less then print contact: ";
	std::cin >> choice;
	std::string temp;
	std::cout << "Enter first name :";
	std::cin >> temp;
	contacts_list[choice].SetFirstName(temp);
	std::cout << "Enter last name:";
	std::cin >> temp;
	contacts_list[choice].SetLastName(temp);
	std::cout << "Enter email address:";
	std::cin >> temp;
	contacts_list[choice].SetEmailAdd(temp);
	std::cout << "Enter Mobile number:";
	std::cin >> temp;
	contacts_list[choice].SetMobileNumber(temp);
	std::cout << "Enter house:";
	std::cin >> temp;
	contacts_list[choice].GetAddress()->SetHouse(temp);
	std::cout << "Enter street :";
	std::cin >> temp;
	contacts_list[choice].GetAddress()->SetStreet(temp);
	std::cout << "Enter city:";
	std::cin >> temp;
	contacts_list[choice].GetAddress()->SetCity(temp);
	std::cout << "Enter country:";
	std::cin >> temp;
	contacts_list[choice].GetAddress()->SetCountry(temp);
	std::cout << "Details updated" << std::endl;
	std::cout << std::endl;
	std::cout << "Press 3 to delete a detail of specific person" << std::endl;
	int x;
	std::cin >> x;
	if (x == 3) {
		DelSpecificContact(choice);
	}
}

void ContactsBook::PrintSpecificContact() {
	int choice;
	std::cout << "Enter index greater then 0: ";
	std::cin >> choice;
	choice = choice - 1;
	std::cout << contacts_list[choice].GetFirstName() << std::endl;
	std::cout << contacts_list[choice].GetLastName() << std::endl;
	std::cout << contacts_list[choice].GetEmailAddress() << std::endl;
	std::cout << contacts_list[choice].GetMobileNumber() << std::endl;

	std::cout << contacts_list[choice].GetAddress()->GetHouse() << std::endl;
	std::cout << contacts_list[choice].GetAddress()->GetStreet() << std::endl;
	std::cout << contacts_list[choice].GetAddress()->GetCity() << std::endl;
	std::cout << contacts_list[choice].GetAddress()->GetCountry() << std::endl;
	std::cout << std::endl;
	std::cout << "Press 2 to change the detail of specific person:" << std::endl;
	int x;
	std::cin >> x;
	if (x == 2) {
		UpdateSpecificContact();
	}
}

void ContactsBook::DelSpecificContact(int x) {
	std::string temp3;
	temp3 = " ";
	int choice1 = x;
	int choice;
	std::cout << "Enter index: ";
	std::cin >> choice;
	contacts_list[choice].SetFirstName(temp3);
	contacts_list[choice].SetLastName(temp3);
	contacts_list[choice].SetEmailAdd(temp3);
	contacts_list[choice].SetMobileNumber("12345678998");
	contacts_list[choice].GetAddress()->SetHouse(temp3);
	contacts_list[choice].GetAddress()->SetStreet(temp3);
	contacts_list[choice].GetAddress()->SetCity(temp3);
	contacts_list[choice].GetAddress()->SetCountry(temp3);

	std::cout << "Contact deleted is " << std::endl;
		contacts_list[choice].SetFirstName(contacts_list[choice].GetFirstName());
		contacts_list[choice].SetLastName(contacts_list[choice].GetLastName());
		contacts_list[choice].SetEmailAdd(contacts_list[choice].GetEmailAddress());
		contacts_list[choice].SetMobileNumber(contacts_list[choice].GetMobileNumber());
		contacts_list[choice].GetAddress()->SetHouse(contacts_list[choice].GetAddress()->GetHouse());
		contacts_list[choice].GetAddress()->SetStreet(contacts_list[choice].GetAddress()->GetStreet());
		contacts_list[choice].GetAddress()->SetCity(contacts_list[choice].GetAddress()->GetCity());
		contacts_list[choice].GetAddress()->SetCountry(contacts_list[choice].GetAddress()->GetCountry());
}

ContactsBook::ContactsBook(int size_of_list) {
	contacts_list = new Contact[size_of_list];
	size_of_contacts = size_of_list;
	contacts_count = 0;
}

Contact* ContactsBook::CopyContacts_list() {
	Contact* temp;
	temp = new Contact[size_of_contacts];

	for (int i = 0; i < size_of_contacts; i++)
	{
		temp[i].SetEmailAdd(contacts_list[i].GetEmailAddress());
		temp[i].SetFirstName(contacts_list[i].GetFirstName());
		temp[i].SetLastName(contacts_list[i].GetLastName());
		temp[i].SetMobileNumber(contacts_list[i].GetMobileNumber());
		temp[i].set_address(contacts_list[i].GetAddress()->copy_address());
	}
	return temp;
}

void ContactsBook::DisplayHistory() {
	for (int i = index; i >= 0; i--) {
		std::cout << "Recent searches: " << history[i].data << " ";
		std::cout << history[i].date << std::endl;
		std::fstream obj;
		obj.open("Recent_searches.txt",std::ios::app);
		obj<<std::endl << history[i].data << " ";
		obj << history[i].date;
	}
}

void ContactsBook::FreqSearched() {
	int x;
	std::fstream obj;
	obj.open("FreqSearched.txt", std::ios::out);
	for (int i = 0; i < index; i++) {
		static int count = 0;
		for (int j = i; j < index; j++) {
			if (history[j+1].data == history[i].data) {
				count++;
				x = j;
			}
		}
		if (count >= 2) {
			obj << "Frequently searched" << std::endl;
			obj << history[x].data << std::endl;
			std::cout << history[x].data << std::endl;
			
		}
		x = 0;
		count = 0;
	}
}

void ContactsBook::AdvanceSearch() {
	std::cout << "Enter anything to search" << std::endl;
	std::string sub_string;
	std::cin >> sub_string;
	int Len = sub_string.size();
	int count = 0;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 0; j < contacts_list[i].GetFirstName().length(); j++)
		{
			if (contacts_list[i].GetFirstName()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetLastName().length(); j++)
		{
			if (contacts_list[i].GetLastName()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetEmailAddress().length(); j++)
		{
			if (contacts_list[i].GetEmailAddress()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetMobileNumber().length(); j++)
		{
			if (contacts_list[i].GetMobileNumber()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetAddress()->GetHouse().length(); j++)
		{
			if (contacts_list[i].GetAddress()->GetHouse()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetAddress()->GetStreet().length(); j++)
		{
			if (contacts_list[i].GetAddress()->GetStreet()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetAddress()->GetCity().length(); j++)
		{
			if (contacts_list[i].GetAddress()->GetCity()[j] == sub_string[count])
			{
				count++;
			}
		}
		for (int j = 0; j < contacts_list[i].GetAddress()->GetCountry().length(); j++)
		{
			if (contacts_list[i].GetAddress()->GetCountry()[j] == sub_string[count])
			{
				count++;
			}
		}
		if (count >= Len)
		{
			std::cout << contacts_list[i].GetFirstName() << std::endl;
			std::cout << contacts_list[i].GetLastName() << std::endl;
			std::cout << contacts_list[i].GetEmailAddress() << std::endl;
			std::cout << contacts_list[i].GetMobileNumber() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetHouse() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetStreet() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetCity() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetCountry() << std::endl;
		}
		count = 0;

	}
}

void ContactsBook::AddintoGroup() {
	static int unique_id=1;
	std::cout << "You can only make 3 Groups for storing contact" << std::endl;
	std::cout << "A Group can only contain 3 contacts" << std::endl;
	std::cout << "How many Groups you want to create" << std::endl;
	int x = 0;
	std::cin >> x;
	for (int i = 1; i <= x; i++) {
		std::cout << "Enter name of Group "<<i << std::endl;
		std::cin >> G1[i].gr_name[i];
	}
	std::cout << "Contacts saved are" << std::endl;
	for (int i = 0; i < contacts_count; i++) {
		std::cout << unique_id << "." << contacts_list[i].GetFirstName() << std::endl;
		unique_id++;
	}
	std::string choice;
	std::cout << "In which group you want to store contact" << std::endl;
	int gr = 0;
	std::cin >> gr;
	if (gr == 1) {
		std::cout << "How many contacts you want to store in Group 1" << std::endl;
		int n = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cout << "Enter unique id of contact you want to store in Group: " << G1[0].gr_name[0] << std::endl;
			std::cin >> choice;
			for (int i = 0; i < n; i++) {
				if (choice == contacts_list[i].GetFirstName()) {
					G1[i].Gr_mem[i] = contacts_list[i].GetFirstName();
				}
			}
		}
	}
	if (gr == 2) {
		std::cout << "How many contacts you want to store in Group 2" << std::endl;
		int n = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cout << "Enter first name of contact you want to store in Group: " <<  std::endl;
			std::cin >> choice;
			for (int i = 1; i < contacts_count; i++) {
				if (choice == contacts_list[i].GetFirstName()) {
					G1[i].Gr_mem[i] = contacts_list[i].GetFirstName();
				}
			}
		}
	}
	if (gr == 3) {
		std::cout << "How many contacts you want to store in Group 3" << std::endl;
		int n = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cout << "Enter first name of contact you want to store in Group: " <<  std::endl;
			std::cin >> choice;
			for (int i = 2; i < contacts_count; i++) {
				if (choice == contacts_list[i].GetFirstName()) {
					G1[i].Gr_mem[i] = contacts_list[i].GetFirstName();
				}
			}
		}
	}
	std::cout << "Enter the group number in which you want to see stored contacts" << std::endl;
	int no = 0;
	std::cin >> no;
	if (no == 1) {
		std::cout << "Contacts stored in 1" << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			std::cout << G1[i].Gr_mem[i] << std::endl;
		}
	}
	if (no == 2) {
		std::cout << "Contacts stored in 2" << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			std::cout << G1[i].Gr_mem[i] << std::endl;
		}
	}
	if (no == 3) {
		std::cout << "Contacts stored in 3" << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			std::cout << G1[i].Gr_mem[i] << std::endl;
		}
	}
}

void ContactsBook::DelGroupContact() {
	std::cout << "Enter the group number you want to delete contact in" << std::endl;
	int y = 0;
	std::cin >> y;
	if (y == 1) {
		std::cout << "Contacts stored in 1" << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			std::cout << G1[i].Gr_mem[i] << std::endl;
		}
		std::cout << "Enter firstname of contact you want to delete" << std::endl;
		std::string choice;
		std::cin >> choice;
		for (int i = 0; i < contacts_count; i++) {
			if (choice == contacts_list[i].GetFirstName()) {
				G1[i].Gr_mem[i] = " ";
			}
		}
		std::cout << "Contacts stored in 1 after deletion" << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			std::cout << G1[i].Gr_mem[i] << std::endl;
		}
		
	}
}

void ContactsBook::DelAGroup() {
	std::cout << "Enter the Group name you want to delete" << std::endl;
	std::string choice;
	std::cin >> choice;
	for (int i = 0; i < contacts_count; i++) {
		if (choice == G1[i].gr_name[i]) {
			G1[i].gr_name[i] = " ";
			std::cout << "Group 1 " << G1[i].gr_name[i] << std::endl;
			std::cout << std::endl;
			std::cout << "Group " << choice << " has been deleted" << std::endl;
		}
	}
}

void ContactsBook::PrintContacts_sorted(std::string choice)
{
	Contact* temp2;
	temp2 = CopyContacts_list();

	SortContactList(temp2, choice);

	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << std::endl << temp2[i].GetFirstName()
		<< " " << temp2[i].GetLastName() << " " <<
		temp2[i].GetMobileNumber() <<" " << temp2[i].GetEmailAddress() <<std::endl;
		temp2[i].GetAddress()->print_address();
	}
}

void ContactsBook::swap(Contact* contacts_list, int choice1, int choice2) {
	Contact* ptr = new Contact;
	*ptr = contacts_list[choice1];
	ptr->set_address(contacts_list[choice1].GetAddress()->copy_address());
	contacts_list[choice1] = contacts_list[choice2];
	contacts_list[choice2].set_address(contacts_list[choice2].GetAddress()->copy_address());
	contacts_list[choice2] = *ptr;
	contacts_list[choice2].set_address(ptr->GetAddress()->copy_address());
}

bool ContactsBook::Compare(std::string choice, Contact& choice1, Contact& choice2) {
	if (choice == "first_name") {

		if (choice1.GetFirstName() >= choice2.GetFirstName()) {
			return true;
		}
		else{
			return 0;
		}
			
	}
	if (choice == "last_name") {
		if (choice1.GetLastName() >= choice2.GetLastName()) {
			return true;
		}
		else {
			return 0;
		}
	}
	else if (choice == "email_address") {
		if (choice1.GetEmailAddress() >= choice2.GetEmailAddress())
			return true;
		else
			return 0;
	}
	else if (choice == "address") {
		if (choice1.GetAddress()->GetCountry() >= choice2.GetAddress()->GetCountry())
		{
			return true;
		}
		else
		{
			return 0;
		}

	}
	return 0;
}

void ContactsBook::SortContactList(Contact* contacts_list, std::string choice)
{
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = 1; j < contacts_count; j++)
		{
			if (Compare(choice, contacts_list[i], contacts_list[j]) == 1) {
				swap(contacts_list, i, j);
			}
		}
	}
}

void ContactsBook::MergeDuplicates()
{
	int* ptr, T_contact = 0;
	ptr = new int[contacts_count];

	for (int i = 0; i < contacts_count - 1; i++)
	{
		for (int j = 1; j < contacts_count; j++)
		{
			if (contacts_list[i].Equals(contacts_list[j])) {
				ptr[T_contact] = j;
				T_contact++;
				std::cout << "The contact that is merged is" << contacts_list[i].GetFirstName()
					<< std::endl << contacts_list[i].GetLastName()
					<< std::endl << contacts_list[i].GetEmailAddress()
					<< std::endl << contacts_list[i].GetMobileNumber()
					<< std::endl << contacts_list[i].GetAddress()->GetHouse()
					<< std::endl << contacts_list[i].GetAddress()->GetStreet()
					<< std::endl << contacts_list[i].GetAddress()->GetCity()
					<< std::endl << contacts_list[i].GetAddress()->GetCountry() << std::endl;
			}
		}
	}
	std::cout << "Merge Contacts= " << T_contact << std::endl;
	std::cout << std::endl;
}

void ContactsBook::SaveToFile(std::string file_name)
{

	std::ofstream us;
	us.open(file_name + ".txt");
	us << contacts_count << std::endl;

	for (int i = 0; i < contacts_count; i++)
	{
		us << contacts_list[i].GetFirstName() << "\n" << contacts_list[i].GetLastName()<<std::endl;
		us << contacts_list[i].GetMobileNumber() << "\n" << contacts_list[i].GetEmailAddress() << std::endl;
		us << contacts_list[i].GetAddress()->GetHouse() << "\n" << contacts_list[i].GetAddress()->GetStreet()<< "\n" << contacts_list[i].GetAddress()->GetCity() << "\n" << contacts_list[i].GetAddress()->GetCountry() << std::endl;
	}



}

void ContactsBook::LoadFromFile(std::string usman)
{
	std::ifstream file1;
	file1.open(usman + ".txt");
	file1 >> contacts_count;
	std::string temp_str;
		for (int i = 0; i<contacts_count; i++) {
			file1 >> temp_str;
			contacts_list[i].SetFirstName(temp_str);
			file1 >> temp_str;
			contacts_list[i].SetLastName(temp_str);
			file1 >> temp_str;
			contacts_list[i].SetMobileNumber(temp_str);
			file1 >> temp_str;
			contacts_list[i].SetEmailAdd(temp_str);
			file1 >> temp_str;
			contacts_list[i].GetAddress()->SetHouse(temp_str);
			file1 >> temp_str;
			contacts_list[i].GetAddress()->SetStreet(temp_str);
			file1 >> temp_str;
			contacts_list[i].GetAddress()->SetCity(temp_str);
			file1 >> temp_str;
			contacts_list[i].GetAddress()->SetCountry(temp_str);
		}
		for (int i = 0; i < contacts_count; i++) {
			std::cout << contacts_list[i].GetFirstName() << std::endl;
			std::cout << contacts_list[i].GetLastName() << std::endl;
			std::cout << contacts_list[i].GetEmailAddress() << std::endl;
			std::cout << contacts_list[i].GetMobileNumber() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetHouse() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetStreet() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetCity() << std::endl;
			std::cout << contacts_list[i].GetAddress()->GetCountry() << std::endl;
		}

	file1.close();
}

void input(ContactsBook& obj) {
	static int unique_id=0;
	std::string data_c;
	Contact* temp = new Contact;
	std::cout << "Enter contact with unique id " <<unique_id << std::endl;
	std::cout << "Enter first name :";
	std::cin >> data_c;
	temp->SetFirstName(data_c);
	std::cout << "Enter last name:";
	std::cin >> data_c;
	temp->SetLastName(data_c);
	std::cout << "Enter email address:";
	std::cin >> data_c;
	temp->SetEmailAdd(data_c);
	std::cout << "Enter Mobile number:";
	std::cin >> data_c;
	temp->SetMobileNumber(data_c);
	std::cout << "Enter house:";
	std::cin >> data_c;
	temp->GetAddress()->SetHouse(data_c);
	std::cout << "Enter street :";
	std::cin >> data_c;
	temp->GetAddress()->SetStreet(data_c);
	std::cout << "Enter city:";
	std::cin >> data_c;
	temp->GetAddress()->SetCity(data_c);
	std::cout << "Enter country:";
	std::cin >> data_c;
	temp->GetAddress()->SetCountry(data_c);
	obj.id = unique_id;
	obj.AddContact(*temp);
	unique_id++;
}
