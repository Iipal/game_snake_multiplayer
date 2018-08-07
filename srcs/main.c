#include "../lib/includes/ft.h"

int		main(int argc, char **argv)
{
	if (!(ft_wrong_input(argc, argv)))
		ft_start_game(argc, argv);
	return (0);
}
