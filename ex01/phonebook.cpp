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
		std::string	secret;
	
	public:
		Contact(std::string f, std::string l, std::string n, std::string p, std::string s)
			: firstname(f), lastname(l), nickname(n), phoneNumber(p), secret(s) {}
		
		void	printContacts(int i)
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << std::right << i << "|";
			std::cout << std::setw(15) << std::right << firstname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << lastname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << nickname.substr(0, 10) << "|" << std::endl;
		}

		void	printContactsByIndex(int i)
		{
			std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << std::right << i << "|";
			std::cout << std::setw(15) << std::right << firstname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << lastname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << nickname.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << phoneNumber.substr(0, 10) << "|";
			std::cout << std::setw(15) << std::right << secret.substr(0, 10) << "|" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
		}
};

class PhoneBook
{
	private:
		std::vector<Contact> contacts;
	public:
	
	void	addContact(std::string firstname, std::string lastname,
		std::string nickname, std::string phoneNumber, std::string secret)
		{
			if (contacts.size() == 8)
				contacts.erase(contacts.begin());
			if (firstname.length() >= 10)
				firstname.at(9) = '.';
			if (lastname.length() >= 10)
				lastname.at(9) = '.';
			if (nickname.length() >= 10)
				nickname.at(9) = '.';
			if (phoneNumber.length() >= 10)
				phoneNumber.at(9) = '.';
			if (secret.length() >= 10)
				secret.at(9) = '.';
			contacts.push_back(Contact(firstname, lastname, nickname, phoneNumber, secret));
			std::cout << "Successfully registered contact details!" << std::endl;
		}

		void	printListItems()
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << "index" << "|";
			std::cout << std::setw(15) << "first name" << "|";
			std::cout << std::setw(15) << std::right << "last name" << "|";
			std::cout << std::setw(15) << std::right << "nickname" << "|" << std::endl;
			for (int i = 0; i < contacts.size(); i++)
				contacts[i].printContacts(i + 1);
			std::cout << "-----------------------------------------------------------------" << std::endl;
		}

		void	printListItemsByIndex(int index)
		{
			std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << "index" << "|";
			std::cout << std::setw(15) << "first name" << "|";
			std::cout << std::setw(15) << std::right << "last name" << "|";
			std::cout << std::setw(15) << std::right << "nickname" << "|";
			std::cout << std::setw(15) << std::right << "phone number" << "|";
			std::cout << std::setw(15) << std::right << "darkest secret" << "|" << std::endl;
		}

		void	printContactOfIndex(int index)
		{
			if (index < 0 || contacts.size() < index)
			{
				std::cout << "index is out of range or wrong .";
				return ;
			}
			printListItemsByIndex(index + 1);
			contacts[index].printContactsByIndex(index + 1);
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
	int			index;

	while (1)
	{
		std::cout << "Please enter one of the following three commands: ADD, SEARCH, or EXIT." << std::endl;
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			return (0);
		else if (cmd == "ADD")
		{
			std::cout << "Enter your first name ." << std::endl;
			std::getline(std::cin, firstname);
			std::cout << "Enter your last name ." << std::endl;
			std::getline(std::cin, lastname);
			std::cout << "Enter your nickname ." << std::endl;
			std::getline(std::cin, nickname);
			std::cout << "Enter your phone number ." << std::endl;
			std::getline(std::cin, phoneNumber);
			std::cout << "Tell me your darkest secret ." << std::endl;
			std::getline(std::cin, secret);
			phonebook.addContact(firstname, lastname, nickname, phoneNumber, secret);
		}
		else if (cmd == "SEARCH")
		{
			phonebook.printListItems();
			std::cout << "Enter the index of entry ." << std::endl;
			std::cin >> index;
			std::cin.ignore();
			phonebook.printContactOfIndex(index - 1);
		}
	}
	return (0);
}
