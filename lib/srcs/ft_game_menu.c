/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:32:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 15:27:00 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"

short	ft_main_menu()
{
	short	menu;

	menu = -1;
	system("clear");
	printf("\t\tWelcome, %s!\n", game.nickname);
	printf("\tMenu:\n");
	printf("\t 1. Start.\n");
	printf("\t 2. Settings.\n");
	printf("\t 0. Quit.\n");
	printf("\tChoose something: ");
	scanf("%hi", &menu);
	return (menu);
}

void	ft_mode_menu()
{
	short	mode;

	mode = -1;
	system("clear");
	printf("\t\tChoose game mode:\n");
	printf("\tCooperative:\n");
	printf("\t 1. Solo.\n");
	printf("\t 2. Player1 vs Bot\n");
	printf("\tMultiplayer:\n");
	printf("\t 3. Player1 vs Player2\n\n");
	printf("\t 0. Exit to main menu\n");
	printf("\tChoose something: ");
	scanf("%hi", &mode);
	if (mode == 1)
		ft_game_solo();
	else if (mode == 2)
		ft_game_bot();
	else if (mode == 3)
		ft_game_pvp();
	else if (mode == 0)
		ft_main_menu();
	else
	{
		system("clear");
		system("echo \"\\e[31mWrong input!!\\e[0m\"");
		sleep(1);
		system("clear");
	}
}

void	ft_settings_menu()
{
	short	setting;

	setting = 0;
	system("clear");
	printf("\tSettings:\n");
	printf("\t 1. Set grid size X (current: %hi). ( min 10 | max 30 )\n", game.grid_x);
	printf("\t 2. Set grid size Y (current: %hi). ( min 10 | max 30 )\n", game.grid_y);
	printf("\t 3. Set game speed  (current: %hi). ( min 1  | max 5  )\n", game.speed);
	printf("\t 4. Change nickname (current: %s).", game.nickname);
	printf("\t 5. Set default settings.\n\n");
	printf("\t 0. Exit to main menu.\n");
	printf("\tChoose something: ");
	scanf("%hi", &setting);
	if (setting != 0)
		ft_settings_change(setting);
	else
		ft_main_menu();
}
