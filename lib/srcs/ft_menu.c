/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:32:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/07 23:34:45 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"

short	ft_main_menu()
{
	short	menu;

	menu = -1;
	system("clear");
	printf("\t\tWelcome!\n");
	printf("\tMenu:\n");
	printf("\t 1. Start.\n");
	printf("\t 2. Settings.\n");
	printf("\t 0. Quit.\n");
	scanf("%hi", &menu);
	return (menu);
}

void	ft_settings_default()
{
	game.grid_x = 10;
	game.grid_y = 10;
	game.speed = 3;
}

void	ft_settings_change(short setting)
{
	t_game	temp;

	if (setting == 1)
	{
		printf("Set X to: ");
		scanf("%hi", &temp.grid_x);
		if (temp.grid_x >= 10 && temp.grid_x <= 30)
			game.grid_x = temp.grid_x;
	}
	else if (setting == 2)
	{
		printf("Set Y to: ");
		scanf("%hi", &temp.grid_y);
		if (temp.grid_y >= 10 && temp.grid_y <= 30)
			game.grid_y = temp.grid_y;
	}
	else if (setting == 3)
	{
		printf("Set game speed to: ");
		scanf("%hi", &temp.speed);
		if (temp.speed <= 5 && temp.speed >= 1)
			game.speed = temp.speed;
	}
	else if (setting == 4)
		ft_settings_default();
	ft_settings_menu();
}

void	ft_settings_menu()
{
	short	setting;

	setting = 0;
	system("clear");
	printf("\tSettings:\n");
	printf("\t 1. Set grid size X (current: %hi). / min 10 | max 30 \\\n", game.grid_x);
	printf("\t 2. Set grid size Y (current: %hi). * min 10 | max 30 *\n", game.grid_y);
	printf("\t 3. Set game speed  (current: %hi).  \\ min 1  | max 5  /\n", game.speed);
	printf("\t 4. Set default settings.\n");
	printf("\t 0. Exit to menu.\n");
	printf("\tChoose something:\n");
	scanf("%hi", &setting);
	if (setting != 0)
		ft_settings_change(setting);
	else
		ft_main_menu();
}
