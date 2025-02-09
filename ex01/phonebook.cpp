#include <iostream>
#include <vector>

class PhoneBook
{
	private:
		std::vector<std::vector<std::string>> data;
	public:
		void	addContact()
		{
			std::string firstname, lastname, nickname, phoneNumber;

			std::cout << "Please enter your first name ." << std::endl;
			std::cin >> firstname;

			std::cout << "Please enter your last name ." << std::endl;
			std::cin >> lastname;

			std::cout << "Please enter your nickname ." << std::endl;
			std::cin >> nickname;

			std::cout << "Please enter your phone number ." << std::endl;
			std::cin >> phoneNumber;

			data.push_back({firstname, lastname, nickname, phoneNumber});
		};
		
};

int main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	std::cout << "Please enter one of the following three commands: ADD, SEARCH, or EXIT." << std::endl;
	std::getline(std::cin, cmd);
	while (cmd != "EXIT")
	{
		if (cmd == "ADD")
			phonebook.addContact();
	}
	return (0);
}
