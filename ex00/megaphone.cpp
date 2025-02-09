#include <iostream>

void	megaphone(char *str)
{
	int	i = 0;
	char up;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			up = str[i] - 32;
			std::cout << up;
		}
		else
			std::cout << str[i];
		i++;
	}
}

int main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
		megaphone(argv[i++]);
	//std::cout << "\n";
	return (0);
}