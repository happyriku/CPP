#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>

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
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << std::right << firstname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << lastname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << nickname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << phoneNumber.substr(0, 10) << "|" << std::endl;
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
			if (firstname.length() >= 10)
				firstname.at(9) = '.';
			if (lastname.length() >= 10)
				lastname.at(9) = '.';
			if (nickname.length() >= 10)
				nickname.at(9) = '.';
			if (phoneNumber.length() >= 10)
				phoneNumber.at(9) = '.';
			contacts.push_back(Contact(firstname, lastname, nickname, phoneNumber));
		};

		void	printcontacts()
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << "first name" << "|";
			std::cout << std::setw(15) << std::right << "last name" << "|";
			std::cout << std::setw(15) << std::right << "nickname" << "|";
			std::cout << std::setw(15) << std::right << "phone number" << "|" << std::endl;
			for (int i = 0; i < contacts.size(); i++)
				contacts[i].printcontact();
			std::cout << "-----------------------------------------------------------------" << std::endl;
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
	std::string secret;

	while (1)
	{
		std::cout << "Please enter one of the following three commands: ADD, SEARCH, or EXIT." << std::endl;
		std::cin >> cmd;
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
		{
			std::cout << "Enter your first name ." << std::endl;
			std::cin >> firstname;
			std::cout << "Enter your last name ." << std::endl;
			std::cin >> lastname;
			std::cout << "Enter your nickname ." << std::endl;
			std::cin >> nickname;
			std::cout << "Enter your phone number ." << std::endl;
			std::cin >> phoneNumber;
			std::cout << "Tell me your darkest secret ." << std::endl;
			std::cin >> secret;
			phonebook.addContact(firstname, lastname, nickname, phoneNumber);
			phonebook.printcontacts();
		}
	}
	return (0);
}
