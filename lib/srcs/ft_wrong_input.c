#include "../includes/ft.h"

void	ft_print_args_rules()
{
	printf("\tArguments for start the game:\n");
	printf("\t 1. Set grid size X.     (min 5 | max 20)\n");
	printf("\t 2. Set grid size Y.     (min 5 | max 20)\n");
	printf("\t 3. Choose game speed.   (min 1 | max 5)\n");
	printf("\nExmaple: ./exe_snake 10 10 3\n");
}

int		ft_check_args(char **av)
{
	int		check_X;
	int		check_Y;
	int		check_speed;
	int		check_error;

	check_X = atoi(av[1]);
	check_Y = atoi(av[2]);
	check_speed = atoi(av[3]);
	check_error = 0;
	system("clear");
	if (check_X < 5 || check_X > 20)
	{
		check_error = 1;
		printf("ERROR:\tWrong input for X.\n");
		printf("\tYou set X: %d, but needed from 5 to 20.\n\n", check_X);
	}
	if (check_Y < 5 || check_Y > 20)
	{
		check_error = 1;
		printf("ERROR:\tWrong input for Y.\n");
		printf("\tYou set Y: %d, but needed from 5 to 20.\n\n", check_Y);
	}
	if (check_speed < 1 || check_speed > 5)
	{
		check_error = 1;
		printf("ERROR:\tWrong input for speed.\n");
		printf("\tYou set speed: %d, but needed from 1 to 5.\n\n", check_speed);
	}
	if (check_error)
	{
		ft_print_args_rules();
		return (-1);
	}
	return (0);
}

int		ft_wrong_input(int ac, char **av)
{
	if (strcmp(av[0], "./exe_snake") != 0)
	{
		printf("\t**** PIRATE ****\n\n");
		printf("\n\nor you just stupid...\n");
	}
	else if (ac < 4)
	{
		system("clear");
		printf("ERROR:\tNot enough arguments for start game.\n");
		printf("\tYou wrie %d arguments, but needed 3.\n\n", ac - 1);
		ft_print_args_rules(ac - 1);
		return (-1);
	}
	else if (ac > 4)
	{
		system("clear");
		printf("ERROR:\tToo much arguments for start game.\n");
		printf("\tYou write %d arguments, but needed 3.\n\n", ac - 1);
		ft_print_args_rules(ac - 1);
		return (-1);
	}
	else
		if(!ft_check_args(av))
			return (0);
	return (-1);
}
