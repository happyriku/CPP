#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>
#include <cstdlib>

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
		
		void	init()
		{
			while (firstname.empty()){
				std::cout << "Enter your first name ." << std::endl;
				std::getline(std::cin, firstname);
			}

			while (lastname.empty()){
				std::cout << "Enter your last name ." << std::endl;
				std::getline(std::cin, lastname);
			}

			while (nickname.empty()){
				std::cout << "Enter your nickname ." << std::endl;
				std::getline(std::cin, nickname);
			}

			while (phoneNumber.empty()){
				std::cout << "Enter your phone number ." << std::endl;
				std::getline(std::cin, phoneNumber);
			}

			while (secret.empty()){
				std::cout << "Tell me your darkest secret ." << std::endl;
				std::getline(std::cin, secret);
			}
		}

		bool	isEmpty()
		{
			if (firstname.empty() || lastname.empty() || nickname.empty()
					|| phoneNumber.empty() || secret.empty())
					return (true);
			return (false);			
		}

		std::string	truncate10character(std::string	info)
		{
			if (info.length() >= 10)
				info.at(9) = '.';
			return (info);
		}

		void	printContacts(int i)
		{
			std::cout << "-----------------------------------------------------------------" << std::endl;
			std::cout << "|" << std::setw(15) << std::right << i << "|";
			std::cout << std::setw(15) << std::right << truncate10character(firstname.substr(0, 10)) << "|";
			std::cout << std::setw(15) << std::right << truncate10character(lastname.substr(0, 10)) << "|";
			std::cout << std::setw(15) << std::right << truncate10character(nickname.substr(0, 10)) << "|" << std::endl;
		}

		void	printContactsByIndex(int i)
		{
			std::cout << "first name: " << firstname << std::endl;
			std::cout << "last name: " << lastname << std::endl;
			std::cout << "nickname: " << nickname << std::endl;
			std::cout << "phone number: " << phoneNumber << std::endl;;
			std::cout << "darkest secret: " << secret << std::endl;
		}
};

class PhoneBook
{
	private:
		Contact		contacts[8];
		std::string	index;	

	public:

		int	ElemSize()
		{
			int	i = -1;

			while (!(contacts[++i].isEmpty()))
				if (i == 8)
					break;
			return (i);
		}

		void	add(int num)
		{
			contacts[num % CONTACT_SIZE].init();
			std::cout << "Successfully registered contact details!" << std::endl;
		}

		void	search()
		{
			printListItems();
			std::cout << "Enter the index of entry ." << std::endl;
			std::getline(std::cin, index);
			if (!(index >= "0" && index <= "9")){
				std::cout << "Please enter a valid number" << std::endl;
				return ;
			}
			printContactOfIndex(atoi(index.c_str()));
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

		void	printContactOfIndex(int index)
		{
			if (index <= 0 || ElemSize() < index){
				std::cout << "number is out of range or wrong ." << std::endl;
				return ;
			}
			contacts[index - 1].printContactsByIndex(index);
		}
};

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	int			count = 0;
	int			i;

	while (1){
		i = 0;
		std::cout << "Enter a command: (ADD, SEARCH, or EXIT.)" << std::endl;
		std::getline(std::cin, cmd);
		while (std::isspace(cmd[i]))
			i++;
		cmd = cmd.substr(i);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			phonebook.add(count++);
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}
