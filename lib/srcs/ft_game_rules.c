/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 13:54:35 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/12 14:02:05 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_game_solorules(void)
{
	printf("\t\tSolo mode rules:\n");
	printf("\t 1. Just don't die how long as you can.\n");
}

void	ft_game_botrules(void)
{
	printf("\t\tBot mode rules:\n");
	printf("\t 1. Okay, you play against the bot\n");
	printf("\t 2. Score more points than he in 1 minute.\n");
}

void	ft_game_pvprules(void)
{
	printf("\t\tPVP mode rules:\n");
	printf("\t 1. Okay, you against the human.\n");
	printf("\t 2. Score more points that he in 1 minute.\n");
}
