/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 22:20:17 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/08 20:30:13 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rules.h"
#include "../includes/ft_game.h"

void	ft_game_solo()
{
	system("clear");
	system("echo \"\\e[32mSolo mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_solorules();
}

void	ft_game_bot()
{
	system("clear");
	system("echo \"\\e[32mBot mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_botrules();
}

void	ft_game_pvp()
{
	system("clear");
	system("echo \"\\e[32mPVP mode activated.\\e[0m\"");
	sleep(1);
	system("clear");
	ft_game_pvprules();
}
