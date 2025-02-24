#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"
# include <cstdlib>

# define CONTACT_SIZE 8

class PhoneBook
{
	private:
		Contact		contacts[8];
		std::string	index;

	public:
		int		ElemSize();
		void	add(int num);
		void	search();
		void	printListItems();
		void	printContactOfIndex(int index);

};

#endif