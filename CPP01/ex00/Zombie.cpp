#include "Zombie.hpp"

void	Zombie::announce(void){
	Zombie	zombie;

	std::cout << "<name> : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*newZombie(std::string name){
	Zombie	*new_zombie = new Zombie;

	if (!new_zombie)
		return (NULL);
	new_zombie.announce();
	return (new_zombie);
}

void	randomChump(std::string name){

}
