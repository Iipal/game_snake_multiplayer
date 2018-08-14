/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:20:17 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/14 17:30:32 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_menu.h"
#include "../includes/ft_rules.h"
#include "../includes/ft_game.h"

void	ft_game_solo(void)
{
	system(ECHO_OK("Solo mode activated"));
	sleep(1);
	system("clear");
	ft_game_solorules();
	sleep(2);
	ft_start_solo();
	exit(EXIT_SUCCESS);
}

void	ft_game_bot(void)
{
	system(ECHO_OK("Bot mode activated"));
	sleep(1);
	system("clear");
	ft_game_botrules();
	exit(EXIT_SUCCESS);
}

void	ft_game_pvp(void)
{
	system(ECHO_OK("PVP mode activated"));
	sleep(1);
	system("clear");
	ft_game_pvprules();
	exit(EXIT_SUCCESS);
}
