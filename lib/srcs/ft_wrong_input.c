#include "../includes/ft.h"

void	ft_print_args_rules()
{
	printf("\n\tArguments for start the game:\n");
	printf("\t 1. Set grid size X.     (min 5 | max 20)\n");
	printf("\t 2. Set grid size Y.     (min 5 | max 20)\n");
	printf("\t 3. Choose game speed.   (min 1 | max 5)\n");
	printf("\nExample: ./exe_snake 10 10 3\n");
}

int		ft_check_args(char **av)
{
	int		check_error;

	game.grid_x = atoi(av[1]);
	game.grid_y = atoi(av[2]);
	game.speed = atoi(av[3]);
	check_error = 0;
	system("clear");
	if (game.grid_x < 5 || game.grid_x > 20)
	{
		check_error++;
		system("echo -n \"\\e[31mKO:\\e[0m\"");
		printf("\tWrong value for X.\n");
		printf("\tYou set X: %d. For start the game needed from 5 to 20.\n", game.grid_x);
	}
	else
	{
		system("echo -n \"\\e[32mOK:\\e[0m\"");
		printf("\tGrid X is optimal size.\n");
	}
	if (game.grid_y < 5 || game.grid_y > 20)
	{
		check_error++;
		system("echo -n \"\\e[31mKO:\\e[0m\"");
		printf("\tWrong value for Y.\n");
		printf("\tYou set Y: %d. For start the game needed from 5 to 20.\n", game.grid_y);
	}
	else
	{
		system("echo -n \"\\e[32mOK:\\e[0m\"");
		printf("\tGrid Y is optimal size.\n");
	}
	if (game.speed < 1 || game.speed > 5)
	{
		check_error++;
		system("echo -n \"\\e[31mKO:\\e[0m\"");
		printf("\tWrong value for speed.\n");
		printf("\tYou set speed: %d, For start the game needed from 1 to 5.\n", game.speed);
	}
	else
	{
		system("echo -n \"\\e[32mOK:\\e[0m\"");
		printf("\tGame speed is optimal.\n");
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
		system("echo \"\\e[31m\t**** PIRATE ****\n\\e[0m\"");
		printf("\n\nor you just stupid...\n");
	}
	else if (ac < 4)
	{
		system("clear");
		system("echo -n \"\\e[31mKO:\\e[0m\"");
		printf("\tNot enough arguments for start the game.\n");
		printf("\tYou wrie %d arguments. For start the game needed 3.\n", ac - 1);
		ft_print_args_rules(ac - 1);
		return (-1);
	}
	else if (ac > 4)
	{
		system("clear");
		system("echo -n \"\\e[31mKO:\\e[0m\"");
		printf("\tToo much arguments for start the game.\n");
		printf("\tYou write %d arguments. For start the game needed 3.\n", ac - 1);
		ft_print_args_rules(ac - 1);
		return (-1);
	}
	else
		if(!ft_check_args(av))
			return (0);
	return (-1);
}
