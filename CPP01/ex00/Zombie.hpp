#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
	private:
		std::string	name;

	public:
		Zombie() : name("") {}
		void	announce(void);
};

#endif
