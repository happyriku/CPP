#include "../includes/phonebook.hpp"
#include "../includes/contact.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	int			num = 0;
	int			i;

	while (42){
		i = 0;
		std::cout << "Enter a command: (ADD, SEARCH, or EXIT.)" << std::endl;
		std::getline(std::cin, cmd);
		while (std::isspace(cmd[i]))
			i++;
		cmd = cmd.substr(i);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			phonebook.add(num++);
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}