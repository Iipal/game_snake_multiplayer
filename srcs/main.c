/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:25:24 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 15:31:52 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/includes/ft_game.h"
#include "../lib/includes/ft_menu.h"
#include "../lib/includes/ft_settings.h"

int		main(void)
{
	short	menu;

	ft_settings_default();
	ft_settings_save();
	menu = ft_main_menu();
	if (menu == 1)
		ft_mode_menu();
	else if (menu == 2)
		ft_settings_menu();
	else if (menu == 0)
	{
		system("clear");
		printf("\tbye bye =(\n");
		sleep(1);
		system("clear");
	}
	else
	{
		system("clear");
		system("echo \"\\e[31mWrong input!\\e[0m\"");
		sleep(1);
		system("clear");
	}
	return (0);
}
