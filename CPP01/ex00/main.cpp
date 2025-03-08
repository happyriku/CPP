#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie;
	int	i ;

	std::cout << "Welcome to Zombie World !" << std::endl;
	std::cout << "Enter a command: (CREATE, EXIT)" << std::endl;

	while (42){
		i = 0;
		std::getline(std::cin, cmd);
		while (std::isspace(cmd[i]))
			i++;
		cmd = cmd.substr(i);
		if (cmd == "CREATE"){
			std::cout << "Enter a zombie name" << std::endl;
			std::getline(std::cin, name);
			zombie.newZombie(name);
		}
		else if (cmd == "EXIT"){
			break;
		}
	}
	return (0);
}
