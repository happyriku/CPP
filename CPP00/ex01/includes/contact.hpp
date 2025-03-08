#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>


class	Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	secret;
	
	public:
		Contact() : firstname(""), lastname(""), nickname(""), phoneNumber(""), secret("") {}

		void		init();
		bool		isEmpty();
		std::string	truncate10character(std::string info);
		void		printContacts(int i);
		void		printContactsByIndex();
};

#endif