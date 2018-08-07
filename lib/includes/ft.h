#ifndef FT_H
# define FT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_game
{
	int grid_x;
	int grid_y;
	int speed;
}				t_game;

int		ft_wrong_input(int ac, char **av);

void	ft_print_args_rules();
void	ft_start_game(int ac, char **av);

#endif
