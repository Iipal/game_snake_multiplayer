/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_gameplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: _ipal <malkoleyplay@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 04:22:21 by _ipal             #+#    #+#             */
/*   Updated: 2018/08/14 17:53:18 by _ipal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_game.h"

void	ft_generate_food(char **g_playfield)
{
	const int	max_food = (pos.x * pos.y) / FOOD_RARITY + 1;
	short				gen_y;
	short				gen_x;

	if (g_food_counter <= max_food)
	{
		gen_y = rand() % pos.y;
		gen_x = rand() % pos.x;
		if (g_playfield[gen_y][gen_x] == ' ')
		{
			g_playfield[gen_y][gen_x] = '@';
			g_food_counter++;
		}
		else
			ft_generate_food(g_playfield);
	}
}

void	ft_level_up(t_snake *snake)
{
	short upped_already = 0;

	if (snake->length % LVLUP_LENGTH == 0)
	{
		if (!upped_already)
		{
			g_level++;
			upped_already = 1;
		}
	}
	else
		upped_already = 0;
}
