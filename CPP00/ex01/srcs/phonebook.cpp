#include "../includes/phonebook.hpp"

int	PhoneBook::ElemSize()
{
	int	i = -1;

	while (!(contacts[++i].isEmpty()))
		if (i == 8)
			break;
	return (i);
}

void	PhoneBook::add(int num)
{
	contacts[num % CONTACT_SIZE].init();
	std::cout << "Successfully registered contact details!" << std::endl;
}

void	PhoneBook::search()
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

void	PhoneBook::printListItems()
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

void	PhoneBook::printContactOfIndex(int index)
{
	if (index <= 0 || ElemSize() < index){
		std::cout << "number is out of range or wrong ." << std::endl;
		return ;
	}
	contacts[index - 1].printContactsByIndex();
}
