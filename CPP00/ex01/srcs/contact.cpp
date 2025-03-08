# include "../includes/contact.hpp"
	
	
void	Contact::init()
{
	while (42){
		std::cout << "Enter your first name ." << std::endl;
		if (std::getline(std::cin, firstname) && !firstname.empty())
			break;
	}

	while (42){
		std::cout << "Enter your last name ." << std::endl;
		if (std::getline(std::cin, lastname) && !lastname.empty())
			break;
	}

	while (42){
		std::cout << "Enter your nickname ." << std::endl;
		if (std::getline(std::cin, nickname) && !nickname.empty())
			break;
	}

	while (42){
		std::cout << "Enter your phone number ." << std::endl;
		if (std::getline(std::cin, phoneNumber) && !phoneNumber.empty())
			break;
	}

	while (42){
		std::cout << "Tell me your darkest secret ." << std::endl;
		if (std::getline(std::cin, secret) && !secret.empty())
			break;
	}
}

bool	Contact::isEmpty()
{
	if (firstname.empty() || lastname.empty() || nickname.empty()
			|| phoneNumber.empty() || secret.empty())
			return (true);
	return (false);			
}

std::string	Contact::truncate10character(std::string	info)
{
	if (info.length() >= 10)
		info.at(9) = '.';
	return (info);
}

void	Contact::printContacts(int i)
{
	std::cout << "-----------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(15) << std::right << i << "|";
	std::cout << std::setw(15) << std::right << truncate10character(firstname.substr(0, 10)) << "|";
	std::cout << std::setw(15) << std::right << truncate10character(lastname.substr(0, 10)) << "|";
	std::cout << std::setw(15) << std::right << truncate10character(nickname.substr(0, 10)) << "|" << std::endl;
}

void	Contact::printContactsByIndex()
{
	std::cout << "first name: " << firstname << std::endl;
	std::cout << "last name: " << lastname << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;;
	std::cout << "darkest secret: " << secret << std::endl;
}