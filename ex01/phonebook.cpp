#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>

# define CONTACT_SIZE 8

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	secret;
	
	public:
		Contact() : firstname(""), lastname(""), nickname(""), phoneNumber(""), secret("") {}
		
		void	setContactInfo(std::string f, std::string l,
					std::string n, std::string p, std::string s)
		{
			firstname = f;
			lastname = l;
			nickname = n;
			phoneNumber = p;
			secret = s;	
		}

		bool	isEmpty()
		{
			if (firstname.empty() || lastname.empty() || nickname.empty()
					|| phoneNumber.empty() || secret.empty())
					return (true);
			return (false);			
		}

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
		Contact contacts[8];

	public:
	
		int		ElemSize()
		{
			int	i = -1;

			while (!(contacts[++i].isEmpty()))
				if (i == 8)
					break;
			return (i);
		}

		std::string	replace(std::string info)
		{
			if (info.length() >= 10)
				info.at(9) = '.';
			return (info);
		}

		void	addContact(std::string firstname, std::string lastname,
			std::string nickname, std::string phoneNumber, std::string secret, int num)
			{
				contacts[num % CONTACT_SIZE].setContactInfo(replace(firstname), replace(lastname),
							replace(nickname), replace(phoneNumber), replace(secret));
				std::cout << "Successfully registered contact details!" << std::endl;
			}

		void	printListItems()
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << "index" << "|";
			std::cout << std::setw(15) << "first name" << "|";
			std::cout << std::setw(15) << std::right << "last name" << "|";
			std::cout << std::setw(15) << std::right << "nickname" << "|" << std::endl;
			for (int i = 0; i < ElemSize(); i++)
				contacts[i].printContacts(i + 1);
			std::cout << "-----------------------------------------------------------------" << std::endl;
		}

		void	printListItemsByIndex()
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
			if (index <= 0 || ElemSize() < index)
			{
				std::cout << "index is out of range or wrong ." << std::endl;
				return ;
			}
			printListItemsByIndex();
			contacts[index - 1].printContactsByIndex(index);
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
	int			count = 0;

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
			phonebook.addContact(firstname, lastname,
						nickname, phoneNumber, secret, count++);
		}
		else if (cmd == "SEARCH")
		{
			phonebook.printListItems();
			std::cout << "Enter the index of entry ." << std::endl;
			std::cin >> index;
			std::cin.ignore();
			phonebook.printContactOfIndex(index);
		}
	}
	return (0);
}
