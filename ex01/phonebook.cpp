#include <iostream>
#include <vector>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
	
	public:
		Contact(std::string f, std::string l, std::string n, std::string p)
			: firstname(f), lastname(l), nickname(n), phoneNumber(p) {}
		
		void	printcontact()
		{
			std::cout << "first name : " << firstname << std::endl;
			std::cout << "last name : " << lastname << std::endl;
			std::cout << "nickname : " << nickname << std::endl;
			std::cout << "phone number : " << phoneNumber << std::endl;
		}

};

class PhoneBook
{
	private:
		std::vector<Contact> contacts;
	public:
		void	addContact(std::string firstname, std::string lastname,
						std::string nickname, std::string phoneNumber)
		{
			contacts.push_back(Contact(firstname, lastname, nickname, phoneNumber));
		};

		void	printcontacts()
		{
			for (int i = 0; i < contacts.size(); i++)
				contacts[i].printcontact();
		}
};


int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	std::string firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phoneNumber;

	std::cout << "Please enter one of the following three commands: ADD, SEARCH, or EXIT." << std::endl;
	std::getline(std::cin, cmd);
	while (cmd != "EXIT")
	{
		if (cmd == "ADD")
		{
			std::cout << "Enter your first name ." << std::endl;
			std::cin >> firstname;
			std::cout << "Enter your last name ." << std::endl;
			std::cin >> lastname;
			std::cout << "Enter your nickname ." << std::endl;
			std::cin >> nickname;
			std::cout << "Enter your phone number ." << std::endl;
			std::cin >> phoneNumber;
			phonebook.addContact(firstname, lastname, nickname, phoneNumber);
		}
		phonebook.printcontacts();
	}
	return (0);
}
