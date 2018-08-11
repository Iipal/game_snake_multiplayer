/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:32:54 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/10 00:55:12 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_errors.h"
#include "../includes/ft_game.h"
#include "../includes/ft_menu.h"
#include "../includes/ft_settings.h"

short	ft_menu_main()
{
	short	menu;

	menu = FT_ERROR;
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

short	ft_menu_gamemode()
{
	short	gamemode;

	gamemode = FT_ERROR;
	system("clear");
	printf("\t\tChoose game mode:\n");
	printf("\tCooperative:\n");
	printf("\t 1. Solo.\n");
	printf("\t 2. Player1 vs Bot\n");
	printf("\tMultiplayer:\n");
	printf("\t 3. Player1 vs Player2\n\n");
	printf("\t 0. Exit to main menu\n");
	printf("\tChoose something: ");
	scanf("%hi", &gamemode);
	return (gamemode);
}

short	ft_menu_settings()
{
	short	settings;

	settings = FT_ERROR;
	system("clear");
	printf("\tSettings:\n");
	printf("\t 1. Set grid size X (current: %hi). ( min 10 | max 30 )\n", game.grid_x);
	printf("\t 2. Set grid size Y (current: %hi). ( min 10 | max 30 )\n", game.grid_y);
	printf("\t 3. Set game speed  (current: %hi ). ( min 1  | max 5  )\n", game.speed);
	printf("\t 4. Change nickname (current: %s).\n", game.nickname);
	printf("\t 5. Set default settings.\n\n");
	printf("\t 0. Exit to main menu.\n");
	printf("\tChoose something: ");
	scanf("%hi", &settings);
	return (settings);
}

void	ft_switches_main(short menu)
{
	do
	{
		switch (menu)
		{
			case MAIN_GAMEMODE: ft_switches_gamemode(ft_menu_gamemode()); break;
			case MAIN_SETTINGS: ft_switches_settings(ft_menu_settings()); break;
			case MAIN_MENUEXIT:
			{
				printf("\tbye bye =(\n");
				sleep(1);
				system("clear");
				exit(EXIT_SUCCESS);
			}
			default:
			{
				system("echo \"\\e[31mWrong input!\\e[0m\"");
				sleep(1);
				system("clear");
				exit(EXIT_SUCCESS);
			}
		}
	} while (menu >= MAIN_MENUEXIT && menu <= MAIN_SETTINGS);
}

void	ft_switches_gamemode(short gamemode)
{
	do
	{
		switch (gamemode)
		{
			case MODE_SOLO: ft_game_solo(); break;
			case MODE_BOT: ft_game_bot(); break;
			case MODE_PVP: ft_game_pvp(); break;
			case MODE_EXIT: ft_switches_main(ft_menu_main()); break;
			default:
			{
				system("echo \"\\e[31mWrong input!!\\e[0m\"");
				sleep(1);
				system("clear");
				break;
			}
		}
	} while (gamemode >= MODE_EXIT && gamemode <= MODE_PVP);
}

void	ft_switches_settings(short settings)
{
	do
	{
		if (settings != SETTING_EXIT && (settings >= SETTING_EXIT && settings <= SETTING_DEFAULT))
			ft_settings_change(settings);
		else
			ft_switches_main(ft_menu_main());
	} while (settings >= SETTING_EXIT && settings <= SETTING_DEFAULT);
}
