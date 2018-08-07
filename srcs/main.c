/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:25:24 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/07 23:35:56 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/includes/ft_game.h"
#include "../lib/includes/ft_menu.h"

int		main(void)
{
	short	menu;

	ft_settings_default();
	menu = ft_main_menu();
	if (menu == 1)
		ft_game_start();
	else if (menu == 2)
		ft_settings_menu();
	else if (menu == 0)
		printf("bye bye =(\n");
	else
		system("echo \"\\e[31mWrong input!\\e[0m\"");
	return (0);
}
