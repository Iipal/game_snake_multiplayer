/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:20:17 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/12 14:04:28 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rules.h"
#include "../includes/ft_game.h"

void	ft_game_solo(void)
{
	system("echo \"\\e[32mSolo mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_solorules();
	exit(EXIT_SUCCESS);
}

void	ft_game_bot(void)
{
	system("echo \"\\e[32mBot mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_botrules();
	exit(EXIT_SUCCESS);
}

void	ft_game_pvp(void)
{
	system("echo \"\\e[32mPVP mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_pvprules();
	exit(EXIT_SUCCESS);
}
